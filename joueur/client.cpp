#include <iostream>
#include <sstream>
#include <boost/asio.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/lexical_cast.hpp>

#include "client.h"
#include "basePlayer.h"
#include "baseGame.h"
#include "baseAI.h"
#include "errorCode.h"
#include "ansiColorCoder.h"

#pragma region Singleton Pattern
bool Joueur::Client::instanceFlag = false;
Joueur::Client* Joueur::Client::single = nullptr;
Joueur::Client* Joueur::Client::getInstance()
{
    if(! instanceFlag)
    {
        single = new Client();
        instanceFlag = true;
        return single;
    }
    else
    {
        return single;
    }
}
#pragma endregion

void Joueur::Client::start()
{
    this->started = true;
}

void Joueur::Client::play()
{
    this->waitForEvent("");
}

void Joueur::Client::connect(const std::string server, const std::string port, bool printIO)
{
    this->printIO = printIO;

    try
    {
        this->ioService = new boost::asio::io_service();

        boost::asio::ip::tcp::resolver resolver(*ioService);
        boost::asio::ip::tcp::resolver::query query(boost::asio::ip::tcp::v4(), server, port);
        boost::asio::ip::tcp::resolver::iterator iterator = resolver.resolve(query);

        this->socket = new boost::asio::ip::tcp::socket(*ioService);

        boost::asio::connect(*socket, iterator);
    }
    catch (std::exception& e)
    {
        this->handleError(e, ErrorCode::COULD_NOT_CONNECT, "Could not connect to " + server + ":" + port);
    }
}

void Joueur::Client::setup(Joueur::BaseGame* game, BaseAI* ai, Joueur::BaseGameManager* gameManager)
{
    this->ai = ai;
    this->game = game;
    this->gameManager = gameManager;
}

void Joueur::Client::sendRaw(const std::string& str)
{
    if (this->printIO)
    {
        std::cout << Joueur::ANSIColorCoder::MagentaText << "TO SERVER <--" << str << Joueur::ANSIColorCoder::Reset <<"\n";
    }
    boost::asio::write(*(this->socket), boost::asio::buffer(str, str.length()));
}

void Joueur::Client::send(const std::string& eventName)
{
    this->send(eventName, nullptr);
}

void Joueur::Client::send(const std::string& eventName, boost::property_tree::ptree& data)
{
    this->send(eventName, &data);
}

void Joueur::Client::send(const std::string& eventName, boost::property_tree::ptree* data)
{
    boost::property_tree::ptree jsonNode;
    jsonNode.add_child("event", boost::property_tree::ptree(eventName));
    if (data != nullptr)
    {
        jsonNode.add_child("data", *data);
    }

    jsonNode.add_child("sentTime", boost::property_tree::ptree(boost::lexical_cast<std::string>(std::time(0))));

    std::stringstream ss;
    boost::property_tree::write_json(ss, jsonNode, false);
    ss << Joueur::Client::EOT_CHAR;
    this->sendRaw(ss.str());
}

void Joueur::Client::handleError(std::exception e, int errorCode, std::string errorMessage)
{
    this->disconnect();
    Joueur::ErrorCode::handleError(&e, errorCode, errorMessage);
}

void Joueur::Client::disconnect()
{
    try
    {
        this->socket->shutdown(boost::asio::ip::tcp::socket::shutdown_both);
        this->socket->close();
    }
    catch (...)
    {
        // ignore exceptions if we are disconnecting, because we are about to exit anyways
    }
}

boost::property_tree::ptree* Joueur::Client::waitForEvent(const std::string& eventName)
{
    while (true)
    {
        this->waitForEvents();

        while (!this->eventsStack.empty())
        {
            auto serverEvent = eventsStack.top();
            eventsStack.pop();

            if (eventName != "" && eventName == serverEvent.eventName)
            {
                return serverEvent.data;
            }
            else
            {
                this->autoHandle(serverEvent.eventName, serverEvent.data);
            }
        }
    }
}

void Joueur::Client::waitForEvents()
{
    if (!this->eventsStack.empty())
    {
        return; // as we already have events to handle, no need to wait for more
    }

    while (true)
    {
        char chars[Client::BUFFER_SIZE];
        try
        {
            size_t charsRead = this->socket->read_some(boost::asio::buffer(chars, Client::BUFFER_SIZE));
            if (charsRead > 0) // then we actually read some data from the server, so parse it
            {
                std::string responseString(chars, charsRead);

                if (this->printIO)
                {
                    std::cout << Joueur::ANSIColorCoder::MagentaText << "FROM SERVER --> " << responseString << Joueur::ANSIColorCoder::Reset << std::endl;
                }

                std::string total = this->receivedBuffer + responseString;

                std::vector<std::string> split;
                std::string tempStr = "";
                for (char c : total)
                {
                    if (c == Joueur::Client::EOT_CHAR)
                    {
                        split.push_back(tempStr);
                        tempStr = "";
                    }
                    else
                    {
                        tempStr += c;
                    }
                }
                split.push_back(tempStr); // as it's going to have any remaining chars that have not been EOT terminated in it

                this->receivedBuffer = split.back();
                split.pop_back();

                for (auto rit = split.rbegin(); rit != split.rend(); ++rit) // we are pushing events onto a stack, which is FIFO, so we want the top to be the first recieved event, which is at the beginning of 'split'
                {
                    auto jsonStr = *rit;
                    std::stringstream ss;
                    ss << jsonStr;

                    boost::property_tree::ptree* pt = new boost::property_tree::ptree();

                    try
                    {
                        boost::property_tree::read_json(ss, *pt);
                    }
                    catch (std::exception& e)
                    {
                        this->handleError(e, ErrorCode::MALFORMED_JSON, "Malformed json '" + jsonStr + "'.");
                    }

                    ServerEvent serverEvent;
                    serverEvent.eventName = pt->get_child("event").data();
                    boost::optional<boost::property_tree::ptree&> optionalData = pt->get_child_optional("data");
                    if (optionalData)
                    {
                        serverEvent.data = &optionalData.get();
                    }

                    this->eventsStack.push(serverEvent);
                }

                if (!this->eventsStack.empty())
                {
                    return; // as we now have events to handle...
                }
            }
            // else read no chars from socket...
        }
        catch (std::exception& e)
        {
            this->handleError(e, ErrorCode::CANNOT_READ_SOCKET, "Could not read from socket");
        }
    }
}

void Joueur::Client::autoHandle(const std::string& eventName, boost::property_tree::ptree* data)
{
    if (eventName == "delta")
    {
        this->autoHandleDelta(*data);
    }
    else if (eventName == "order")
    {
        this->autoHandleOrder(*data);
    }
    else if (eventName == "over")
    {
        this->autoHandleOver(*data);
    }
    else if (eventName == "invalid")
    {
        this->autoHandleInvalid(*data);
    }
    else if (eventName == "fatal")
    {
        this->autoHandleFatal(*data);
    }
}

void Joueur::Client::autoHandleDelta(boost::property_tree::ptree data)
{
    try
    {
        this->gameManager->deltaUpdate(data);

        if (this->started)
        {
            this->ai->gameUpdated();
        }
    }
    catch (std::exception& e)
    {
        this->handleError(e, Joueur::ErrorCode::DELTA_MERGE_FAILURE, "Error handling delta");
    }
}

void Joueur::Client::autoHandleOrder(boost::property_tree::ptree data)
{
    std::string order = data.get_child("name").data();
    boost::property_tree::ptree* returnedData = nullptr;

    try
    {
        auto optionalOrderArgs = data.get_child_optional("args");
        boost::property_tree::ptree* args = nullptr;
        if (optionalOrderArgs)
        {
            args = optionalOrderArgs.get_ptr();
        }
        returnedData = gameManager->orderAI(order, args);
    }
    catch (std::exception& e)
    {
        this->handleError(e, Joueur::ErrorCode::AI_ERRORED, "AI errored on order '" + order + "'.");
    }
    catch (std::string& s)
    {
        this->handleError(std::runtime_error(s.c_str()), Joueur::ErrorCode::AI_ERRORED, "AI errored on order '" + order + "'.");
    }
    catch (...)
    {
        this->handleError(std::runtime_error("Unknown exception thrown"), Joueur::ErrorCode::AI_ERRORED, "AI errored on order '" + order + "'.");
    }

    boost::property_tree::ptree finishedData;
    finishedData.add_child("orderIndex", boost::property_tree::ptree(data.get_child("index").data()));
    if (returnedData != nullptr)
    {
        finishedData.add_child("returned", *returnedData);
    }

    this->send("finished", finishedData);
    delete returnedData;
}

void Joueur::Client::autoHandleOver(boost::property_tree::ptree data)
{
    bool won = false;
    std::string reason = "";

    if (this->gameManager->basePlayer)
    {
        won = this->gameManager->basePlayer->won;
        reason = won ? this->gameManager->basePlayer->reasonWon : this->gameManager->basePlayer->reasonLost;
    }

    this->ai->ended(won, reason);

    std::cout << Joueur::ANSIColorCoder::GreenText << "Game is over. " << (won ? "I won!" : "I Lost :(") << " because: " <<  reason << Joueur::ANSIColorCoder::Reset << std::endl;

    auto message = data.get_optional<std::string>("message");
    if (message)
    {
        std::cout << Joueur::ANSIColorCoder::CyanText << message << Joueur::ANSIColorCoder::Reset << std::endl;
    }

    this->disconnect();
    exit(0);
}

void Joueur::Client::autoHandleInvalid(boost::property_tree::ptree data)
{
    try
    {
        this->ai->invalid(data.get_child("message").data());
    }
    catch (std::exception& e)
    {
        this->handleError(e, Joueur::ErrorCode::AI_ERRORED, "AI errored when running invalid().");
    }
    catch (std::string& s)
    {
        this->handleError(std::runtime_error(s.c_str()), Joueur::ErrorCode::AI_ERRORED, "AI errored when running invalid().");
    }
    catch (...)
    {
        this->handleError(std::runtime_error("AI Errored on Invalid"), Joueur::ErrorCode::AI_ERRORED, "AI errored when running invalid().");
    }
}

void Joueur::Client::autoHandleFatal(boost::property_tree::ptree data)
{
    this->handleError(std::runtime_error("Fatal Error"), Joueur::ErrorCode::FATAL_EVENT, data.get_child("message").data());
}

#include <iostream>
#include <sstream>
#include <boost/asio.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/optional/optional.hpp>

#include "client.h"
#include "baseGame.h"
#include "baseAI.h"

using boost::asio::ip::tcp;
using namespace std;
using namespace Joueur;

#pragma region Singleton Pattern
bool Client::instanceFlag = false;
Client* Client::single = NULL;
Client* Client::getInstance()
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

void Client::method()
{
    std::cout << "Method of the Client class" << std::endl;
}

void Client::connectTo(BaseGame game, BaseAI ai, char* server, char* port, bool printIO)
{
    try
    {
        this->ioService = new boost::asio::io_service();
        tcp::resolver resolver(*this->ioService);
        tcp::resolver::query query(tcp::v4(), server, port);
        tcp::resolver::iterator iterator = resolver.resolve(query);

        this->socket = new tcp::socket(*this->ioService);

        boost::asio::connect(*this->socket, iterator);
    }
    catch (std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << "\n";
    }
}

void Client::sendRaw(char* chars, size_t length)
{
    boost::asio::write(*this->socket, boost::asio::buffer(chars, length));
}

void Client::handleError(std::exception& e, ErrorCode errorCode, std::string errorMessage)
{
    throw new std::exception("Not Yet Implimented");
}

void Client::disconnect()
{
    throw new std::exception("Not Yet Implimented");
}

boost::property_tree::ptree Client::waitForEvent(char* eventName)
{
    while (true)
    {
        this->waitForEvents();

        while (!this->eventsStack.empty())
        {
            auto serverEvent = eventsStack.top();
            eventsStack.pop();

            if (eventName == serverEvent.eventName)
            {
                return *serverEvent.data;
            }
            else
            {
                this->autoHandle(serverEvent.eventName, *serverEvent.data);
            }
        }
    }
}

void Client::waitForEvents()
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
            size_t charsRead = boost::asio::read(*this->socket, boost::asio::buffer(chars, Client::BUFFER_SIZE));

            if (charsRead > 0)
            {
                std::string responseString(chars, charsRead);
                std::string total = this->receivedBuffer + responseString;

                vector<string> split;
                boost::algorithm::split(split, total, boost::algorithm::is_any_of(" "));

                this->receivedBuffer = split.back();

                for (auto jsonStr : split)
                {
                    stringstream ss;
                    ss << jsonStr;

                    boost::property_tree::ptree pt;
                    boost::property_tree::read_json(ss, pt);

                    ServerEvent serverEvent;
                    serverEvent.eventName = pt.get_child("event").data();
                    boost::optional<boost::property_tree::ptree&> optionalData = pt.get_child_optional("data");
                    if (optionalData)
                    {
                        *serverEvent.data = optionalData.get();
                    }

                    this->eventsStack.push(serverEvent);
                }
            }
        }
        catch (exception& e)
        {
            this->handleError(e, ErrorCode::CANNOT_READ_SOCKET, "Could not read from socket");
        }
    }
}

void Client::autoHandle(string eventName, boost::property_tree::ptree data)
{
    if (eventName == "delta")
    {
        //this->autoHandleDelta(data);
    }
    else if (eventName == "over")
    {
        //this->autoHandleOver();
    }
    else if (eventName == "invalid")
    {
        //this->autoHandleInvalid(data);
    }
}

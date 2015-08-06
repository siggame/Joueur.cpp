#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include "joueur/client.h"
#include "joueur/baseGame.h"
#include "joueur/baseGameManager.h"
#include "currentGame.h"

int main()
{
    std::string gameName = "Checkers";
    std::string server = "localhost";
    std::string port = "3000";
    std::string playerName;
    std::string requestedSession = "*";
    bool printIO = true;

    Joueur::Client *client = Joueur::Client::getInstance();

    CurrentGame c = getCurrentGame(gameName);

    if (c.game == nullptr || c.ai == nullptr || c.gameManager == nullptr) {
        Joueur::ErrorCode::handleError(Joueur::ErrorCode::GAME_NOT_FOUND, "Game '" + gameName + "' not found.");
    }

    Joueur::BaseGame* game = c.game;
    Joueur::BaseAI* ai = c.ai;
    Joueur::BaseGameManager* gameManager = c.gameManager;

    client->connectTo(game, ai, gameManager, server, port, printIO);

    std::cout << "connected to " << server << ":" << port << ".\n";

    if (playerName.empty())
    {
        playerName == ai->getName();

        if (playerName.empty())
        {
            playerName = "C++ Player";
        }
    }

    boost::property_tree::ptree playData;
    playData.add_child("gameName", boost::property_tree::ptree(gameName));
    playData.add_child("playerName", boost::property_tree::ptree(playerName));
    playData.add_child("requestedSession", boost::property_tree::ptree(requestedSession));
    playData.add_child("clientType", boost::property_tree::ptree("C++"));
    client->send("play", playData);

    boost::property_tree::ptree* lobbiedData = client->waitForEvent("lobbied");
    gameName = lobbiedData->get_child("gameName").data();
    std::string gameSession = lobbiedData->get_child("gameSession").data();
    gameManager->setConstants(lobbiedData->get_child("constants"));
    //delete lobbiedData;

    std::cout << "In lobby for game '" << gameName << "' in session '" << gameSession << "'." << std::endl;

    boost::property_tree::ptree* startData = client->waitForEvent("start");

    client->start();
    gameManager->setupAI(startData->get_child("playerID").data());
    ai->start();
    ai->gameUpdated();
    //delete startData;

    while (true)
    {
        boost::property_tree::ptree* orderData = client->waitForEvent("order");

        std::string order = orderData->get_child("order").data();
        boost::property_tree::ptree* returnedData = nullptr;

        try
        {
           returnedData = gameManager->orderAI(order, orderData->get_child_optional("args"));
        }
        catch (std::exception& e)
        {
            client->handleError(e, Joueur::ErrorCode::AI_ERRORED, "AI errored on order '" + order + "'.");
        }
        catch (std::string& s)
        {
            client->handleError(std::exception(s.c_str()), Joueur::ErrorCode::AI_ERRORED, "AI errored on order '" + order + "'.");
        }
        catch (...)
        {
            client->handleError(std::exception("Unknown exception thrown"), Joueur::ErrorCode::AI_ERRORED, "AI errored on order '" + order + "'.");
        }

        boost::property_tree::ptree finishedData;
        finishedData.add_child("finished", boost::property_tree::ptree(order));
        if (returnedData != nullptr)
        {
            finishedData.add_child("returned", *returnedData);
        }

        client->send("finished", finishedData);
        delete returnedData;
    }

    return 0;
}

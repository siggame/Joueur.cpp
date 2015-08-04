#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include "joueur/client.h"
#include "joueur/baseGame.h"
#include "joueur/gameManager.h"
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

    Joueur::BaseGame* game = c.game;
    Joueur::BaseAI* ai = c.ai;

    client->connectTo(game, ai, server, port, printIO);

    std::cout << "connected to " << server << ":" << port << ".\n";

    if (playerName.empty()) {
        playerName == ai->getName();
        if (playerName.empty()) {
            playerName = "C++ Player";
        }
    }

    boost::property_tree::ptree playData;
    playData.add_child("gameName", boost::property_tree::ptree(gameName));
    playData.add_child("playerName", boost::property_tree::ptree(playerName));
    playData.add_child("requestedSession", boost::property_tree::ptree(requestedSession));
    playData.add_child("clientType", boost::property_tree::ptree("C++"));
    client->send("play", playData);

    boost::property_tree::ptree& lobbiedData = client->waitForEvent("lobbied");

    gameName = lobbiedData.get_child("gameName").data();
    std::string gameSession = lobbiedData.get_child("gameSession").data();
    client->gameManager->setConstants(lobbiedData.get_child("constants"));

    std::cout << "In lobby for game '" << gameName << "' in session '" << gameSession << "'." << std::endl;

    boost::property_tree::ptree& startData = client->waitForEvent("start");

    client->start();
    client->gameManager->setupAI(startData.get_child("playerID").data());
    ai->start();
    ai->gameUpdated();

    while (true)
    {
        boost::property_tree::ptree& orderData = client->waitForEvent("order");

        std::string order = orderData.get_child("order").data();
        boost::property_tree::ptree* returnedData = client->gameManager->orderAI(order, orderData.get_child_optional("args"));

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

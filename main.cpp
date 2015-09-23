#include <iostream>
#include <string>
#include <boost/program_options.hpp>
#include "joueur/client.h"
#include "joueur/baseGame.h"
#include "joueur/baseGameManager.h"
#include "currentGame.h"

int main(int argc, char* argv[])
{
    namespace po = boost::program_options;
    po::options_description desc("Runs the C++ client with options. Must a provide a game name to play on the server.");
    desc.add_options()
        ("help", "produce help message")
        ("game", po::value<std::string>(), "the name of the game you want to play on the server")
        ("server,s", po::value<std::string>()->default_value("localhost"), "the url to the server you want to connect to e.g. locahost:3000")
        ("port,p", po::value<std::string>()->default_value("3000"), "the port to connect to on the server. Can be defined on the server arg via server:port")
        ("playerName,n", po::value<std::string>()->default_value(""), "the name you want to use as your AI\'s player name. This over-rides the name you set in your code")
        ("password,w", po::value<std::string>()->default_value(""), "the password required for authentication on official servers")
        ("gameSettings", po::value<std::string>()->default_value(""), "Any settings for the game server to force. Must be url parms formatted (key=value&otherKey=otherValue)")
        ("session,r", po::value<std::string>()->default_value("*"), "the requested game session you want to play on the server")
        ("printIO", "(debugging) print IO through the TCP socket to the terminal");

    po::positional_options_description p;
    p.add("game", 1);
    po::variables_map vm;
    po::store(po::command_line_parser(argc, argv).options(desc).positional(p).run(), vm);
    po::notify(vm);

    bool help = (vm.count("help") > 0);
    if (!vm.count("game") && !help)
    {
        std::cerr << "Error: game name not supplied. Inlcude the name of the game you want as the first positional argument.\n";
        help = true;
    }

    if (help)
    {
        std::cout << desc << "\n";
        return 1;
    }

    std::string gameName = vm["game"].as<std::string>();
    std::string server = vm["server"].as<std::string>();
    std::string port = vm["port"].as<std::string>();
    std::string playerName = vm["playerName"].as<std::string>();
    std::string password = vm["password"].as<std::string>();
    std::string gameSettings = vm["gameSettings"].as<std::string>();
    std::string requestedSession = vm["session"].as<std::string>();
    bool printIO = (vm.count("printIO") > 0);

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
    playData.add_child("password", boost::property_tree::ptree(password));
    playData.add_child("gameSettings", boost::property_tree::ptree(gameSettings));
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

    try
    {
        ai->start();
        ai->gameUpdated();
    }
    catch (std::exception& e)
    {
        client->handleError(e, Joueur::ErrorCode::AI_ERRORED, "AI erroed during inital game start.");
    }
    catch (std::string& s)
    {
        client->handleError(std::exception(s.c_str()), Joueur::ErrorCode::AI_ERRORED, "AI erroed during inital game start.");
    }
    catch (...)
    {
        client->handleError(std::exception("Unknown exception thrown"), Joueur::ErrorCode::AI_ERRORED, "AI erroed during inital game start.");
    }

    //delete startData;

    client->play();

    return 1;
}

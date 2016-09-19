#ifndef JOUEUR_CLIENT_H
#define JOUEUR_CLIENT_H

#include <stack>
#include <string>
#include <memory>
#include <boost/asio.hpp>
#include "joueur.h"
#include "errorCode.h"
#include "baseAI.h"
#include "baseGame.h"
#include "baseGameManager.h"

class Joueur::Client
{
    private:
        #pragma region Singleton Pattern
        static bool instanceFlag;
        static Client *single;
        Client() {}
        #pragma endregion

        static const int BUFFER_SIZE = 1024;
        static const char EOT_CHAR = char(4);

        Joueur::BaseAI* ai;
        Joueur::BaseGame* game;

        boost::asio::io_service* ioService;
        boost::asio::ip::tcp::socket* socket;
        std::string receivedBuffer;
        bool started = false;
        bool printIO = false;
        std::stack<ServerEvent> eventsStack;

        void sendRaw(const std::string& str);
        void waitForEvents();

        void autoHandle(const std::string& eventName, boost::property_tree::ptree* data);
        void autoHandleDelta(boost::property_tree::ptree data);
        void autoHandleOrder(boost::property_tree::ptree data);
        void autoHandleOver(boost::property_tree::ptree data);
        void autoHandleInvalid(boost::property_tree::ptree data);
        void autoHandleFatal(boost::property_tree::ptree data);

    public:
        #pragma region Singleton Pattern
        static Client* getInstance();
        void method();
        ~Client()
        {
            instanceFlag = false;
        }
        #pragma endregion

        Joueur::BaseGameManager* gameManager;

        void connect(const std::string server, const std::string port, bool printIO);
        void setup(Joueur::BaseGame* game, Joueur::BaseAI* ai, Joueur::BaseGameManager* gameManager);
        void send(const std::string& eventName);
        void send(const std::string& eventName, boost::property_tree::ptree& data);
        void send(const std::string& eventName, boost::property_tree::ptree* data);
        void start();
        void play();
        void disconnect();
        void handleError(std::exception e, int errorCode, std::string errorMessage);
        boost::property_tree::ptree* waitForEvent(const std::string& eventName);
        boost::property_tree::ptree* runOnServer(BaseGameObject caller, std::string functionName, boost::property_tree::ptree args);
};

#endif

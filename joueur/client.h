#ifndef JOUEUR_CLIENT_H
#define JOUEUR_CLIENT_H

#include <stack>
#include <string>
#include <memory>
#include <boost/asio.hpp>
#include "joueur.h"
#include "errorCode.h"
//#include "gameManager.h"

class Joueur::Client
{
    private:
        #pragma region Singleton Pattern
        static bool instanceFlag;
        static Client *single;
        Client()
        {
        }
        #pragma endregion

        static const int BUFFER_SIZE = 1024;

        boost::asio::io_service* ioService;
        boost::asio::ip::tcp::socket* socket;
        std::string receivedBuffer;
        bool started = false;
        std::stack<ServerEvent> eventsStack;

        void sendRaw(char* chars, size_t length);
        void waitForEvents();
        
        void autoHandle(std::string eventName, boost::property_tree::ptree data);
        void autoHandleDelta(boost::property_tree::ptree data);
        void autoHandleInvalid(boost::property_tree::ptree data);
        void autoHandleOver();

    public:
        #pragma region Singleton Pattern
        static Client* getInstance();
        void method();
        ~Client()
        {
            instanceFlag = false;
        }
        #pragma endregion

        //std::shared_ptr<Joueur::GameManager> gameManager;

        void connectTo(BaseGame game, BaseAI ai, char* server, char* port, bool printIO);
        void start();
        void send(char* eventName, boost::property_tree::ptree data);
        void disconnect();
        void handleError(std::exception& e, ErrorCode errorCode, std::string errorMessage);
        boost::property_tree::ptree waitForEvent(char* eventName);
        boost::property_tree::ptree runOnServer(BaseGameObject caller, std::string functionName, boost::property_tree::ptree args);
};

#endif

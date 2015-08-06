#ifndef JOUEUR_ERRORCODE_H
#define JOUEUR_ERRORCODE_H

#include <iostream>
#include "joueur.h"

namespace Joueur
{
    namespace ErrorCode
    {
        const static int NONE = 0;
        const static int INVALID_ARGS = 20;
        const static int COULD_NOT_CONNECT = 21;
        const static int DISCONNECTED_UNEXPECTEDLY = 22;
        const static int CANNOT_READ_SOCKET = 23;
        const static int DELTA_MERGE_FAILURE = 24;
        const static int REFLECTION_FAILED = 25; // impossible with c++?
        const static int UNKNOWN_EVENT_FROM_SERVER = 26;
        const static int SERVER_TIMEOUT = 27;
        const static int INVALID_EVENT = 28;
        const static int GAME_NOT_FOUND = 29;
        const static int MALFORMED_JSON = 30;
        const static int AI_ERRORED = 42;

        static void handleError(std::exception* e, int errorCode, const std::string& errorMessage)
        {
            std::string name = "NO ERROR CODE";
            switch (errorCode)
            {
                case Joueur::ErrorCode::NONE:
                    name = "None";
                    break;
                case Joueur::ErrorCode::INVALID_ARGS:
                    name = "INVALID_ARGS";
                    break;
                case Joueur::ErrorCode::COULD_NOT_CONNECT:
                    name = "Could Not Connect";
                    break;
                case Joueur::ErrorCode::DISCONNECTED_UNEXPECTEDLY:
                    name = "Disconnected Unexpectedly";
                    break;
                case Joueur::ErrorCode::CANNOT_READ_SOCKET:
                    name = "Cannot Read Socket";
                    break;
                case Joueur::ErrorCode::DELTA_MERGE_FAILURE:
                    name = "Delta Merge Failure";
                    break;
                case Joueur::ErrorCode::REFLECTION_FAILED:
                    name = "Reflection Failed";
                    break;
                case Joueur::ErrorCode::UNKNOWN_EVENT_FROM_SERVER:
                    name = "Unknown Event From Server";
                    break;
                case Joueur::ErrorCode::SERVER_TIMEOUT:
                    name = "Server Timeout";
                    break;
                case Joueur::ErrorCode::INVALID_EVENT:
                    name = "Invalid Event";
                    break;
                case Joueur::ErrorCode::GAME_NOT_FOUND:
                    name = "Game Not Found";
                    break;
                case Joueur::ErrorCode::AI_ERRORED:
                    name = "AI Errored";
                    break;

            }

            std::cerr << "Exception: '" << name << "' " << errorMessage << "\n";
            if (e != nullptr)
            {
                std::cerr << e->what() << "\n";
            }
            exit(errorCode);
        }

        static void handleError(int errorCode, const std::string& errorMessage)
        {
            Joueur::ErrorCode::handleError(nullptr, errorCode, errorMessage);
        }

    }
};

#endif

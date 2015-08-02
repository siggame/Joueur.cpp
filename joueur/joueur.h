#ifndef JOUEUR_H
#define JOUEUR_H

#include <string>
#include <memory>
#include <boost/property_tree/ptree.hpp>

namespace Joueur
{
    class DeltaMergeable;
    class BaseGameObject;
    class BaseGame;
    class BasePlayer;
    class BaseAI;
    class Client;
    class GameManager;

    enum ErrorCode;
    enum DeltaType { Bool, Int, Float, String, GameObject, List, Dictionary };

    struct ServerEvent { std::string eventName; std::shared_ptr<boost::property_tree::ptree> data; };
}

#endif



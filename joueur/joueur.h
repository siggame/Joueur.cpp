#ifndef JOUEUR_H
#define JOUEUR_H

#include <string>
#include <boost/optional/optional.hpp>
#include <boost/property_tree/ptree.hpp>

namespace Joueur
{
    class DeltaMergeable;
    class BaseGameObject;
    class BaseGame;
    class BasePlayer;
    class BaseAI;
    class Client;
    class BaseGameManager;

    struct ServerEvent { std::string eventName; boost::property_tree::ptree* data = nullptr; };
}

#endif

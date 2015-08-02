#ifndef CHECKERS_PLAYER_H
#define CHECKERS_PLAYER_H

#include "checkers.h"
#include "gameObject.h"
#include "../../joueur/basePlayer.h"

class Checkers::Player : public Checkers::GameObject, public Joueur::BasePlayer
{
    protected:
        virtual void deltaUpdateField(const std::string& fieldName, boost::property_tree::ptree& delta);

    public:
        std::vector<Checkers::Checker*> checkers;
        std::string clientType;
        std::string name;
        float timeRemaining;
        int yDirection;
};


#endif

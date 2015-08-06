#ifndef CHECKERS_GAMEMANAGER_H
#define CHECKERS_GAMEMANAGER_H

#include "checkers.h"
#include "../../joueur/baseGameManager.h"

class Checkers::GameManager : public Joueur::BaseGameManager
{
    private:
        Checkers::AI* checkersAI;
        Checkers::Game* checkersGame;

        Joueur::BaseGameObject* createGameObject(const std::string& gameObjectName);

    public:
        GameManager(Checkers::Game* game, Checkers::AI* ai);

        void setupAI(const std::string& playerID);
        boost::property_tree::ptree* orderAI(const std::string& order, boost::optional<boost::property_tree::ptree&> args);
};


#endif

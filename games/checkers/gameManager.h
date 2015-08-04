#ifndef CHECKERS_GAMEMANAGER_H
#define CHECKERS_GAMEMANAGER_H

#include "checkers.h"
#include "../../joueur/gameManager.h"

class Checkers::GameManager : public Joueur::GameManager
{
    private:
        Checkers::AI* checkersAI;
        Checkers::Game* checkersGame;

        Joueur::BaseGameObject* createGameObject(const std::string& gameObjectName);

    public:
        void setupAI(const std::string& playerID);
        boost::property_tree::ptree* orderAI(const std::string& order, boost::optional<boost::property_tree::ptree&> args);
};


#endif

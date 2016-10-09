// This is a class that manages the Saloon Game and it's GameObjects. Competitors should never have to care about this class's existance.
// DO NOT MODIFY THIS FILE
#ifndef JOUEUR_SALOON_GAMEMANAGER_H
#define JOUEUR_SALOON_GAMEMANAGER_H

#include "saloon.h"
#include "../../joueur/baseGameManager.h"

/// <summary>
/// This is a class that manages the Saloon Game and it's GameObjects. Competitors should never have to care about this class's existance.
/// </summary>
class Saloon::GameManager : public Joueur::BaseGameManager
{
    private:
        Saloon::AI* saloonAI;
        Saloon::Game* saloonGame;

        Joueur::BaseGameObject* createGameObject(const std::string& gameObjectName);

    public:
        GameManager();

        void setupAI(const std::string& playerID);
        boost::property_tree::ptree* orderAI(const std::string& order, boost::property_tree::ptree* args);
};

#include "registry.h"

#endif

// This is a class that manages the ${game_name} Game and it's GameObjects. Competitors should never have to care about this class's existance.
// DO NOT MODIFY THIS FILE<%include file="functions.noCreer" />
#ifndef JOUEUR_${game_name.upper()}_GAMEMANAGER_H
#define JOUEUR_${game_name.upper()}_GAMEMANAGER_H

#include "${lowercase_first(game_name)}.h"
#include "../../joueur/baseGameManager.h"

/// <summary>
/// This is a class that manages the ${game_name} Game and it's GameObjects. Competitors should never have to care about this class's existance.
/// </summary>
class ${game_name}::GameManager : public Joueur::BaseGameManager
{
    private:
        ${game_name}::AI* ${lowercase_first(game_name)}AI;
        ${game_name}::Game* ${lowercase_first(game_name)}Game;

        Joueur::BaseGameObject* createGameObject(const std::string& gameObjectName);

    public:
        GameManager();

        void setupAI(const std::string& playerID);
        boost::property_tree::ptree* orderAI(const std::string& order, boost::property_tree::ptree* args);
};

#include "registry.h"

#endif

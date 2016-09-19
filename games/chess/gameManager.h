// This is a class that manages the Chess Game and it's GameObjects. Competitors should never have to care about this class's existance.

#ifndef JOUEUR_CHESS_GAMEMANAGER_H
#define JOUEUR_CHESS_GAMEMANAGER_H

#include "chess.h"
#include "../../joueur/baseGameManager.h"

/// <summary>
/// This is a class that manages the Chess Game and it's GameObjects. Competitors should never have to care about this class's existance.
/// </summary>
class Chess::GameManager : public Joueur::BaseGameManager
{
    private:
        Chess::AI* chessAI;
        Chess::Game* chessGame;

        Joueur::BaseGameObject* createGameObject(const std::string& gameObjectName);

    public:
        GameManager();

        void setupAI(const std::string& playerID);
        boost::property_tree::ptree* orderAI(const std::string& order, boost::property_tree::ptree* args);
};

#include "registry.h"

#endif

#ifndef CURRENTGAME_H
#define CURRENTGAME_H

// This file will need to be manually edited when a new game is created

#include "games/checkers/game.h"
#include "games/checkers/ai.h"
#include "games/checkers/gameManager.h"

struct CurrentGame
{
    Joueur::BaseGame* game = nullptr;
    Joueur::BaseAI* ai = nullptr;
    Joueur::BaseGameManager* gameManager = nullptr;
};

CurrentGame getCurrentGame(std::string gameName)
{
    CurrentGame c;
    if (gameName == "Checkers")
    {
        c.gameManager = new Checkers::GameManager();
    }

    if (c.gameManager != nullptr)
    {
        c.game = c.gameManager->game;
        c.ai = c.gameManager->ai;
    }

    return c;
}

#endif

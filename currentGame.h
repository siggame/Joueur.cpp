#ifndef CURRENTGAME_H
#define CURRENTGAME_H

// This file will need to be manually edited when a new game is created

#include "games/anarchy/game.h"
#include "games/anarchy/ai.h"
#include "games/anarchy/gameManager.h"

struct CurrentGame
{
    Joueur::BaseGame* game = nullptr;
    Joueur::BaseAI* ai = nullptr;
    Joueur::BaseGameManager* gameManager = nullptr;
};

CurrentGame getCurrentGame(std::string gameName)
{
    CurrentGame c;
    if (gameName == "Anarchy")
    {
        c.gameManager = new Anarchy::GameManager();
    }

    if (c.gameManager != nullptr)
    {
        c.game = c.gameManager->game;
        c.ai = c.gameManager->ai;
    }

    return c;
}

#endif

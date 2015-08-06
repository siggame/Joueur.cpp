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
    if (gameName == "Checkers") {
        c.game = new Checkers::Game();
        c.ai = new Checkers::AI();
        c.gameManager = new Checkers::GameManager((Checkers::Game*)c.game, (Checkers::AI*)c.ai);
    }

    return c;
}

#endif

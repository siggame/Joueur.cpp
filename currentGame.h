#ifndef CURRENTGAME_H
#define CURRENTGAME_H

// This file will need to be manually edited when a new game is created

#include "games/checkers/game.h"
#include "games/checkers/ai.h"

struct CurrentGame
{
    Joueur::BaseGame* game;
    Joueur::BaseAI* ai;
};

CurrentGame getCurrentGame(std::string gameName)
{
    CurrentGame c;
    if (gameName == "Checkers") {
        c.game = new Checkers::Game();
        c.ai = new Checkers::AI();
    }
    
    return c;
}

#endif

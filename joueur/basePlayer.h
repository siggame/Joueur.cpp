#ifndef JOUEUR_BASEPLAYER_H
#define JOUEUR_BASEPLAYER_H

#include "joueur.h"

// A basic container so the game over data about players is surfaced for all games for AI:over()
class Joueur::BasePlayer
{
    public:
        bool lost;
        std::string reasonLost;
        std::string reasonWon;
        bool won;
};


#endif

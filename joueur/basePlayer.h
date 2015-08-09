#ifndef JOUEUR_BASEPLAYER_H
#define JOUEUR_BASEPLAYER_H

#include "joueur.h"

// A basic container so the game over data about players is surfaced for all games for AI:over()
class Joueur::BasePlayer
{
    public:
        /// <summary>
        /// if the player lost the game or not
        /// </summary>
        bool lost;

        /// <summary>
        /// the reason why the player lost the game
        /// </summary>
        std::string reasonLost;

        /// <summary>
        /// the reason why the player won the game
        /// </summary>
        std::string reasonWon;

        /// <summary>
        /// if the player won the game or not
        /// </summary>
        bool won;
};


#endif

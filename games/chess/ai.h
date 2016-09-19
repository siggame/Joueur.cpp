// This is where you build your AI for the Chess game.


#ifndef JOUEUR_CHESS_AI_H
#define JOUEUR_CHESS_AI_H

#include "chess.h"
#include "game.h"
#include "gameObject.h"
#include "move.h"
#include "piece.h"
#include "player.h"

#include "../../joueur/baseAI.h"


/// <summary>
/// This the header file for where you build your AI for the Chess game.
/// </summary>
class Chess::AI : public Joueur::BaseAI
{
    public:
        /// <summary>
        /// This is a pointer to the Game object itself, it contains all the information about the current game
        /// </summary>
        Chess::Game* game;

        /// <summary>
        /// This is a pointer to your AI's player. This AI class is not a player, but it should command this Player.
        /// </summary>
        Chess::Player* player;


        /// <summary>
        /// This returns your AI's name to the game server. Just replace the string.
        /// </summary>
        /// <returns>string of you AI's name.</returns>
        std::string getName();

        /// <summary>
        /// This is automatically called when the game first starts, once the Game object and all GameObjects have been initialized, but before any players do anything.
        /// </summary>
        void start();

        /// <summary>
        /// This is automatically called every time the game (or anything in it) updates.
        /// </summary>
        void gameUpdated();

        /// <summary>
        /// This is automatically called when the game ends.
        /// </summary>
        /// <param name="won">true if your player won, false otherwise</param>
        /// <param name="reason">a string explaining why you won or lost</param>
        void ended(bool won, std::string reason);


        /// <summary>
        /// This is called every time it is this AI.player's turn.
        /// </summary>
        /// <returns>Represents if you want to end your turn. True means end your turn, False means to keep your turn going and re-call this function.</returns>
        bool runTurn();
};

#endif

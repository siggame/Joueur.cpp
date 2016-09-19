// A player in this game. Every AI controls one player.

#ifndef JOUEUR_CHESS_PLAYER_H
#define JOUEUR_CHESS_PLAYER_H

#include "chess.h"
#include "gameObject.h"
#include "../../joueur/basePlayer.h"

// <<-- Creer-Merge: includes -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
// you can add addtional #includes(s) here.
// <<-- /Creer-Merge: includes -->>

/// <summary>
/// A player in this game. Every AI controls one player.
/// </summary>
class Chess::Player : public Chess::GameObject, public Joueur::BasePlayer
{
    friend Chess::GameManager;

    protected:
        virtual void deltaUpdateField(const std::string& fieldName, boost::property_tree::ptree& delta);
        Player() {};
        ~Player() {};

    public:
        /// <summary>
        /// What type of client this is, e.g. 'Python', 'JavaScript', or some other language. For potential data mining purposes.
        /// </summary>
        std::string clientType;

        /// <summary>
        /// The color (side) of this player. Either 'White' or 'Black', with the 'White' player having the first move.
        /// </summary>
        std::string color;

        /// <summary>
        /// True if this player is currently in check, and must move out of check, false otherwise.
        /// </summary>
        bool inCheck;

        /// <summary>
        /// If the Player has made their move for the turn. true means they can no longer move a Piece this turn.
        /// </summary>
        bool madeMove;

        /// <summary>
        /// The name of the player.
        /// </summary>
        std::string name;

        /// <summary>
        /// This player's opponent in the game.
        /// </summary>
        Chess::Player* opponent;

        /// <summary>
        /// All the unpcaptured chess Pieces owned by this player.
        /// </summary>
        std::vector<Chess::Piece*> pieces;

        /// <summary>
        /// The direction your Pieces must go along the rank axis until they reach the other side.
        /// </summary>
        int rankDirection;

        /// <summary>
        /// The amount of time (in ns) remaining for this AI to send commands.
        /// </summary>
        double timeRemaining;


        // <<-- Creer-Merge: fields -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
        // you can add addtional fields(s) here. None of them will be tracked or updated by the server.
        // <<-- /Creer-Merge: fields -->>


        // <<-- Creer-Merge: methods -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
        // you can add addtional method(s) here.
        // <<-- /Creer-Merge: methods -->>
};

#endif

// The traditional 8x8 chess board with pieces.

#ifndef JOUEUR_CHESS_GAME_H
#define JOUEUR_CHESS_GAME_H

#include "chess.h"
#include "../../joueur/baseGame.h"

// <<-- Creer-Merge: includes -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
// you can add addtional #includes(s) here.
// <<-- /Creer-Merge: includes -->>

/// <summary>
/// The traditional 8x8 chess board with pieces.
/// </summary>
class Chess::Game : public Joueur::BaseGame
{
    friend Chess::GameManager;

    protected:
        virtual void deltaUpdateField(const std::string& fieldName, boost::property_tree::ptree& delta);
        Game() { this->name = "Chess"; };
        ~Game() {};

    public:
        /// <summary>
        /// The player whose turn it is currently. That player can send commands. Other players cannot.
        /// </summary>
        Chess::Player* currentPlayer;

        /// <summary>
        /// The current turn number, starting at 0 for the first player's turn.
        /// </summary>
        int currentTurn;

        /// <summary>
        /// Forsyth–Edwards Notation, a notation that describes the game board.
        /// </summary>
        std::string fen;

        /// <summary>
        /// The maximum number of turns before the game will automatically end.
        /// </summary>
        int maxTurns;

        /// <summary>
        ///  The list of Moves that have occured, in order.
        /// </summary>
        std::vector<Chess::Move*> moves;

        /// <summary>
        /// All the uncaptured Pieces in the game.
        /// </summary>
        std::vector<Chess::Piece*> pieces;

        /// <summary>
        /// List of all the players in the game.
        /// </summary>
        std::vector<Chess::Player*> players;

        /// <summary>
        /// A unique identifier for the game instance that is being played.
        /// </summary>
        std::string session;

        /// <summary>
        /// How many turns until the game ends because no pawn has moved and no Piece has been taken.
        /// </summary>
        int turnsToDraw;


        // <<-- Creer-Merge: fields -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
        // you can add addtional fields(s) here. None of them will be tracked or updated by the server.
        // <<-- /Creer-Merge: fields -->>


        // <<-- Creer-Merge: methods -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
        // you can add addtional method(s) here.
        // <<-- /Creer-Merge: methods -->>
};

#endif

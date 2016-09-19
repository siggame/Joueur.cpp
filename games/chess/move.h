// Contains all details about a Piece's move in the game.

#ifndef JOUEUR_CHESS_MOVE_H
#define JOUEUR_CHESS_MOVE_H

#include "chess.h"
#include "gameObject.h"

// <<-- Creer-Merge: includes -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
// you can add addtional #includes(s) here.
// <<-- /Creer-Merge: includes -->>

/// <summary>
/// Contains all details about a Piece's move in the game.
/// </summary>
class Chess::Move : public Chess::GameObject
{
    friend Chess::GameManager;

    protected:
        virtual void deltaUpdateField(const std::string& fieldName, boost::property_tree::ptree& delta);
        Move() {};
        ~Move() {};

    public:
        /// <summary>
        /// The Piece captured by this Move, null if no capture.
        /// </summary>
        Chess::Piece* captured;

        /// <summary>
        /// The file the Piece moved from.
        /// </summary>
        std::string fromFile;

        /// <summary>
        /// The rank the Piece moved from.
        /// </summary>
        int fromRank;

        /// <summary>
        /// The Piece that was moved.
        /// </summary>
        Chess::Piece* piece;

        /// <summary>
        /// The Piece type this Move's Piece was promoted to from a Pawn, empty string if no promotion occured.
        /// </summary>
        std::string promotion;

        /// <summary>
        /// The standard algebraic notation (SAN) representation of the move.
        /// </summary>
        std::string san;

        /// <summary>
        /// The file the Piece moved to.
        /// </summary>
        std::string toFile;

        /// <summary>
        /// The rank the Piece moved to.
        /// </summary>
        int toRank;


        // <<-- Creer-Merge: fields -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
        // you can add addtional fields(s) here. None of them will be tracked or updated by the server.
        // <<-- /Creer-Merge: fields -->>


        // <<-- Creer-Merge: methods -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
        // you can add addtional method(s) here.
        // <<-- /Creer-Merge: methods -->>
};

#endif

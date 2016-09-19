// A chess piece.

#ifndef JOUEUR_CHESS_PIECE_H
#define JOUEUR_CHESS_PIECE_H

#include "chess.h"
#include "gameObject.h"

// <<-- Creer-Merge: includes -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
// you can add addtional #includes(s) here.
// <<-- /Creer-Merge: includes -->>

/// <summary>
/// A chess piece.
/// </summary>
class Chess::Piece : public Chess::GameObject
{
    friend Chess::GameManager;

    protected:
        virtual void deltaUpdateField(const std::string& fieldName, boost::property_tree::ptree& delta);
        Piece() {};
        ~Piece() {};

    public:
        /// <summary>
        /// When the Piece has been captured (removed from the board) this is true. Otherwise false.
        /// </summary>
        bool captured;

        /// <summary>
        /// The file (column) coordinate of the Piece represented as a letter [a-h], with 'a' starting at the left of the board.
        /// </summary>
        std::string file;

        /// <summary>
        /// If the Piece has moved from its starting position.
        /// </summary>
        bool hasMoved;

        /// <summary>
        /// The player that controls this chess Piece.
        /// </summary>
        Chess::Player* owner;

        /// <summary>
        /// The rank (row) coordinate of the Piece represented as a number [1-8], with 1 starting at the bottom of the board.
        /// </summary>
        int rank;

        /// <summary>
        /// The type of chess Piece this is, either: 'King', 'Queen', 'Knight', 'Rook', 'Bishop', or 'Pawn'.
        /// </summary>
        std::string type;


        // <<-- Creer-Merge: fields -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
        // you can add addtional fields(s) here. None of them will be tracked or updated by the server.
        // <<-- /Creer-Merge: fields -->>

        /// <summary>
        /// Moves the Piece from its current location to the given rank and file.
        /// </summary>
        /// <param name="file">The file coordinate to move to. Must be [a-h].</param>
        /// <param name="rank">The rank coordinate to move to. Must be [1-8].</param>
        /// <param name="promotionType">If this is a Pawn moving to the end of the board then this parameter is what to promote it to. When used must be 'Queen', 'Knight', 'Rook', or 'Bishop'.</param>
        /// <returns>The Move you did if successful, otherwise null if invalid. In addition if your move was invalid you will lose.</returns>
        Chess::Move* move(std::string file, int rank, std::string promotionType = "");


        // <<-- Creer-Merge: methods -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
        // you can add addtional method(s) here.
        // <<-- /Creer-Merge: methods -->>
};

#endif

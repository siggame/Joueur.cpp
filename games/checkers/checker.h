// A checker on the game board.

// DO NOT MODIFY THIS FILE
// Never try to directly create an instance of this class, or modify its member variables.
// Instead, you should only be reading its variables and calling its functions.

#ifndef JOUEUR_CHECKERS_CHECKER_H
#define JOUEUR_CHECKERS_CHECKER_H

#include "checkers.h"
#include "gameObject.h"

// <<-- Creer-Merge: includes -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
// you can add additional #includes(s) here.
// <<-- /Creer-Merge: includes -->>

/// <summary>
/// A checker on the game board.
/// </summary>
class Checkers::Checker : public Checkers::GameObject
{
    friend Checkers::GameManager;

    protected:
        virtual void deltaUpdateField(const std::string& fieldName, boost::property_tree::ptree& delta);
        Checker() {};
        ~Checker() {};

    public:
        /// <summary>
        /// If the checker has been kinged and can move backwards.
        /// </summary>
        bool kinged;

        /// <summary>
        /// The player that controls this Checker.
        /// </summary>
        Checkers::Player* owner;

        /// <summary>
        /// The x coordinate of the checker.
        /// </summary>
        int x;

        /// <summary>
        /// The y coordinate of the checker.
        /// </summary>
        int y;


        // <<-- Creer-Merge: fields -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
        // you can add additional fields(s) here. None of them will be tracked or updated by the server.
        // <<-- /Creer-Merge: fields -->>

        /// <summary>
        /// Returns if the checker is owned by your player or not.
        /// </summary>
        /// <returns>True if it is yours, false if it is not yours.</returns>
        bool isMine();

        /// <summary>
        /// Moves the checker from its current location to the given (x, y).
        /// </summary>
        /// <param name="x">The x coordinate to move to.</param>
        /// <param name="y">The y coordinate to move to.</param>
        /// <returns>Returns the same checker that moved if the move was successful. nullptr otherwise.</returns>
        Checkers::Checker* move(int x, int y);


        // <<-- Creer-Merge: methods -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
        // you can add additional method(s) here.
        // <<-- /Creer-Merge: methods -->>
};

#endif

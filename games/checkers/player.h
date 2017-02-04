// A player in this game. Every AI controls one player.

// DO NOT MODIFY THIS FILE
// Never try to directly create an instance of this class, or modify its member variables.
// Instead, you should only be reading its variables and calling its functions.

#ifndef JOUEUR_CHECKERS_PLAYER_H
#define JOUEUR_CHECKERS_PLAYER_H

#include "checkers.h"
#include "gameObject.h"
#include "../../joueur/basePlayer.h"

// <<-- Creer-Merge: includes -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
// you can add additional #includes(s) here.
// <<-- /Creer-Merge: includes -->>

/// <summary>
/// A player in this game. Every AI controls one player.
/// </summary>
class Checkers::Player : public Checkers::GameObject, public Joueur::BasePlayer
{
    friend Checkers::GameManager;

    protected:
        virtual void deltaUpdateField(const std::string& fieldName, boost::property_tree::ptree& delta);
        Player() {};
        ~Player() {};

    public:
        /// <summary>
        /// All the checkers currently in the game owned by this player.
        /// </summary>
        std::vector<Checkers::Checker*> checkers;

        /// <summary>
        /// What type of client this is, e.g. 'Python', 'JavaScript', or some other language. For potential data mining purposes.
        /// </summary>
        std::string clientType;

        /// <summary>
        /// The name of the player.
        /// </summary>
        std::string name;

        /// <summary>
        /// This player's opponent in the game.
        /// </summary>
        Checkers::Player* opponent;

        /// <summary>
        /// The amount of time (in ns) remaining for this AI to send commands.
        /// </summary>
        double timeRemaining;

        /// <summary>
        /// The direction your checkers must go along the y-axis until kinged.
        /// </summary>
        int yDirection;


        // <<-- Creer-Merge: fields -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
        // you can add additional fields(s) here. None of them will be tracked or updated by the server.
        // <<-- /Creer-Merge: fields -->>


        // <<-- Creer-Merge: methods -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
        // you can add additional method(s) here.
        // <<-- /Creer-Merge: methods -->>
};

#endif

// A player in this game. Every AI controls one player.

// DO NOT MODIFY THIS FILE
// Never try to directly create an instance of this class, or modify its member variables.
// Instead, you should only be reading its variables and calling its functions.

#ifndef JOUEUR_SALOON_PLAYER_H
#define JOUEUR_SALOON_PLAYER_H

#include "saloon.h"
#include "gameObject.h"
#include "../../joueur/basePlayer.h"

// <<-- Creer-Merge: includes -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
// you can add additional #includes(s) here.
// <<-- /Creer-Merge: includes -->>

/// <summary>
/// A player in this game. Every AI controls one player.
/// </summary>
class Saloon::Player : public Saloon::GameObject, public Joueur::BasePlayer
{
    friend Saloon::GameManager;

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
        /// Every Cowboy owned by this Player.
        /// </summary>
        std::vector<Saloon::Cowboy*> cowboys;

        /// <summary>
        /// How many enemy Cowboys this player's team has killed.
        /// </summary>
        int kills;

        /// <summary>
        /// The name of the player.
        /// </summary>
        std::string name;

        /// <summary>
        /// This player's opponent in the game.
        /// </summary>
        Saloon::Player* opponent;

        /// <summary>
        /// How rowdy their team is. When it gets too high their team takes a collective siesta.
        /// </summary>
        int rowdiness;

        /// <summary>
        /// How many times their team has played a piano.
        /// </summary>
        int score;

        /// <summary>
        /// 0 when not having a team siesta. When greater than 0 represents how many turns left for the team siesta to complete.
        /// </summary>
        int siesta;

        /// <summary>
        /// The amount of time (in ns) remaining for this AI to send commands.
        /// </summary>
        double timeRemaining;

        /// <summary>
        /// The YoungGun this Player uses to call in new Cowboys.
        /// </summary>
        Saloon::YoungGun* youngGun;


        // <<-- Creer-Merge: fields -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
        // you can add additional fields(s) here. None of them will be tracked or updated by the server.
        // <<-- /Creer-Merge: fields -->>


        // <<-- Creer-Merge: methods -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
        // you can add additional method(s) here.
        // <<-- /Creer-Merge: methods -->>
};

#endif

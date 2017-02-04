// An furnishing in the Saloon that must be pathed around, or destroyed.

// DO NOT MODIFY THIS FILE
// Never try to directly create an instance of this class, or modify its member variables.
// Instead, you should only be reading its variables and calling its functions.

#ifndef JOUEUR_SALOON_FURNISHING_H
#define JOUEUR_SALOON_FURNISHING_H

#include "saloon.h"
#include "gameObject.h"

// <<-- Creer-Merge: includes -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
// you can add additional #includes(s) here.
// <<-- /Creer-Merge: includes -->>

/// <summary>
/// An furnishing in the Saloon that must be pathed around, or destroyed.
/// </summary>
class Saloon::Furnishing : public Saloon::GameObject
{
    friend Saloon::GameManager;

    protected:
        virtual void deltaUpdateField(const std::string& fieldName, boost::property_tree::ptree& delta);
        Furnishing() {};
        ~Furnishing() {};

    public:
        /// <summary>
        /// How much health this Furnishing currently has.
        /// </summary>
        int health;

        /// <summary>
        /// If this Furnishing has been destroyed, and has been removed from the game.
        /// </summary>
        bool isDestroyed;

        /// <summary>
        /// True if this Furnishing is a piano and can be played, False otherwise.
        /// </summary>
        bool isPiano;

        /// <summary>
        /// If this is a piano and a Cowboy is playing it this turn.
        /// </summary>
        bool isPlaying;

        /// <summary>
        /// The Tile that this Furnishing is located on.
        /// </summary>
        Saloon::Tile* tile;


        // <<-- Creer-Merge: fields -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
        // you can add additional fields(s) here. None of them will be tracked or updated by the server.
        // <<-- /Creer-Merge: fields -->>


        // <<-- Creer-Merge: methods -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
        // you can add additional method(s) here.
        // <<-- /Creer-Merge: methods -->>
};

#endif

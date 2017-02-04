// A bottle thrown by a bartender at a Tile.

// DO NOT MODIFY THIS FILE
// Never try to directly create an instance of this class, or modify its member variables.
// Instead, you should only be reading its variables and calling its functions.

#ifndef JOUEUR_SALOON_BOTTLE_H
#define JOUEUR_SALOON_BOTTLE_H

#include "saloon.h"
#include "gameObject.h"

// <<-- Creer-Merge: includes -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
// you can add additional #includes(s) here.
// <<-- /Creer-Merge: includes -->>

/// <summary>
/// A bottle thrown by a bartender at a Tile.
/// </summary>
class Saloon::Bottle : public Saloon::GameObject
{
    friend Saloon::GameManager;

    protected:
        virtual void deltaUpdateField(const std::string& fieldName, boost::property_tree::ptree& delta);
        Bottle() {};
        ~Bottle() {};

    public:
        /// <summary>
        /// The Direction this Bottle is flying and will move to between turns, can be 'North', 'East', 'South', or 'West'.
        /// </summary>
        std::string direction;

        /// <summary>
        /// The direction any Cowboys hit by this will move, can be 'North', 'East', 'South', or 'West'.
        /// </summary>
        std::string drunkDirection;

        /// <summary>
        /// True if this Bottle has impacted and has been destroyed (removed from the Game). False if still in the game flying through the saloon.
        /// </summary>
        bool isDestroyed;

        /// <summary>
        /// The Tile this bottle is currently flying over.
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

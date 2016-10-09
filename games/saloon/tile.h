// A Tile in the game that makes up the 2D map grid.

// DO NOT MODIFY THIS FILE
// Never try to directly create an instance of this class, or modify its member variables.
// Instead, you should only be reading its variables and calling its functions.

#ifndef JOUEUR_SALOON_TILE_H
#define JOUEUR_SALOON_TILE_H

#include "saloon.h"
#include "gameObject.h"

// <<-- Creer-Merge: includes -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
// you can add addtional #includes(s) here.
// <<-- /Creer-Merge: includes -->>

/// <summary>
/// A Tile in the game that makes up the 2D map grid.
/// </summary>
class Saloon::Tile : public Saloon::GameObject
{
    friend Saloon::GameManager;

    protected:
        virtual void deltaUpdateField(const std::string& fieldName, boost::property_tree::ptree& delta);
        Tile() {};
        ~Tile() {};

    public:
        /// <summary>
        /// The beer Bottle currently flying over this Tile.
        /// </summary>
        Saloon::Bottle* bottle;

        /// <summary>
        /// The Cowboy that is on this Tile, nullptr otherwise.
        /// </summary>
        Saloon::Cowboy* cowboy;

        /// <summary>
        /// The furnishing that is on this Tile, nullptr otherwise.
        /// </summary>
        Saloon::Furnishing* furnishing;

        /// <summary>
        /// If this Tile is pathable, but has a hazard that damages Cowboys that path through it.
        /// </summary>
        bool hasHazard;

        /// <summary>
        /// If this Tile is a balcony of the Saloon that YoungGuns walk around on, and can never be pathed through by Cowboys.
        /// </summary>
        bool isBalcony;

        /// <summary>
        /// The Tile to the 'East' of this one (x+1, y). nullptr if out of bounds of the map.
        /// </summary>
        Saloon::Tile* tileEast;

        /// <summary>
        /// The Tile to the 'North' of this one (x, y-1). nullptr if out of bounds of the map.
        /// </summary>
        Saloon::Tile* tileNorth;

        /// <summary>
        /// The Tile to the 'South' of this one (x, y+1). nullptr if out of bounds of the map.
        /// </summary>
        Saloon::Tile* tileSouth;

        /// <summary>
        /// The Tile to the 'West' of this one (x-1, y). nullptr if out of bounds of the map.
        /// </summary>
        Saloon::Tile* tileWest;

        /// <summary>
        /// The x (horizontal) position of this Tile.
        /// </summary>
        int x;

        /// <summary>
        /// The y (vertical) position of this Tile.
        /// </summary>
        int y;

        /// <summary>
        /// The YoungGun on this tile, nullptr otherwise.
        /// </summary>
        Saloon::YoungGun* youngGun;


        // <<-- Creer-Merge: fields -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
        // you can add addtional fields(s) here. None of them will be tracked or updated by the server.
        // <<-- /Creer-Merge: fields -->>


        // <<-- Creer-Merge: methods -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
        // you can add addtional method(s) here.
        // <<-- /Creer-Merge: methods -->>
};

#endif

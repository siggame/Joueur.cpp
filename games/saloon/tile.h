// A Tile in the game that makes up the 2D map grid.

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
        /// All the beer Bottles currently flying over this Tile.
        /// </summary>
        std::vector<Saloon::Bottle*> bottles;

        /// <summary>
        /// The Cowboy that is on this Tile, or null if empty.
        /// </summary>
        Saloon::Cowboy* cowboy;

        /// <summary>
        /// The furnishing that is on this Tile, or null if empty.
        /// </summary>
        Saloon::Furnishing* furnishing;

        /// <summary>
        /// If this Tile is pathable, but has a hazard that damages Cowboys that path through it.
        /// </summary>
        bool hasHazard;

        /// <summary>
        /// If this Tile is a wall of the Saloon, and can never be pathed through.
        /// </summary>
        bool isWall;

        /// <summary>
        /// The Tile above this one (x, y-1). Null if out of bounds of the map.
        /// </summary>
        Saloon::Tile* tileAbove;

        /// <summary>
        /// The Tile below this one (x, y+1). Null if out of bounds of the map.
        /// </summary>
        Saloon::Tile* tileBelow;

        /// <summary>
        /// The Tile to the left of this one (x-1, y). Null if out of bounds of the map.
        /// </summary>
        Saloon::Tile* tileLeft;

        /// <summary>
        /// The Tile to the right of this one (x+1, y). Null if out of bounds of the map.
        /// </summary>
        Saloon::Tile* tileRight;

        /// <summary>
        /// The x (horizontal) position of this Tile.
        /// </summary>
        int x;

        /// <summary>
        /// The y (vertical) position of this Tile.
        /// </summary>
        int y;


        // <<-- Creer-Merge: fields -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
        // you can add addtional fields(s) here. None of them will be tracked or updated by the server.
        // <<-- /Creer-Merge: fields -->>


        // <<-- Creer-Merge: methods -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
        // you can add addtional method(s) here.
        // <<-- /Creer-Merge: methods -->>
};

#endif

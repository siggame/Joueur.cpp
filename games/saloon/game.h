// Use cowboys to have a good time and play some music on a Piano, while brawling with enemy Coyboys.

// DO NOT MODIFY THIS FILE
// Never try to directly create an instance of this class, or modify its member variables.
// Instead, you should only be reading its variables and calling its functions.

#ifndef JOUEUR_SALOON_GAME_H
#define JOUEUR_SALOON_GAME_H

#include "saloon.h"
#include "../../joueur/baseGame.h"

// <<-- Creer-Merge: includes -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
// you can add addtional #includes(s) here.
// <<-- /Creer-Merge: includes -->>

/// <summary>
/// Use cowboys to have a good time and play some music on a Piano, while brawling with enemy Coyboys.
/// </summary>
class Saloon::Game : public Joueur::BaseGame
{
    friend Saloon::GameManager;

    protected:
        virtual void deltaUpdateField(const std::string& fieldName, boost::property_tree::ptree& delta);
        Game() { this->name = "Saloon"; };
        ~Game() {};

    public:
        /// <summary>
        /// All the beer Bottles currently flying across the saloon in the game.
        /// </summary>
        std::vector<Saloon::Bottle*> bottles;

        /// <summary>
        /// Every Cowboy in the game.
        /// </summary>
        std::vector<Saloon::Cowboy*> cowboys;

        /// <summary>
        /// The player whose turn it is currently. That player can send commands. Other players cannot.
        /// </summary>
        Saloon::Player* currentPlayer;

        /// <summary>
        /// The current turn number, starting at 0 for the first player's turn.
        /// </summary>
        int currentTurn;

        /// <summary>
        /// Every furnishing in the game.
        /// </summary>
        std::vector<Saloon::Furnishing*> furnishings;

        /// <summary>
        /// All the jobs that Cowboys can be called in with.
        /// </summary>
        std::vector<std::string> jobs;

        /// <summary>
        /// The number of Tiles in the map along the y (vertical) axis.
        /// </summary>
        int mapHeight;

        /// <summary>
        /// The number of Tiles in the map along the x (horizontal) axis.
        /// </summary>
        int mapWidth;

        /// <summary>
        /// The maximum number of Cowboys a Player can bring into the saloon of each specific job.
        /// </summary>
        int maxCowboysPerJob;

        /// <summary>
        /// The maximum number of turns before the game will automatically end.
        /// </summary>
        int maxTurns;

        /// <summary>
        /// Vector of all the players in the game.
        /// </summary>
        std::vector<Saloon::Player*> players;

        /// <summary>
        /// When a player's rowdyness reaches or exceeds this number their Cowboys take a collective siesta.
        /// </summary>
        int rowdynessToSiesta;

        /// <summary>
        /// A unique identifier for the game instance that is being played.
        /// </summary>
        std::string session;

        /// <summary>
        /// How long siestas are for a player's team.
        /// </summary>
        int siestaLength;

        /// <summary>
        /// All the tiles in the map, stored in Row-major order. Use `x + y * mapWidth` to access the correct index.
        /// </summary>
        std::vector<Saloon::Tile*> tiles;


        // <<-- Creer-Merge: fields -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
        // you can add addtional fields(s) here. None of them will be tracked or updated by the server.
        // <<-- /Creer-Merge: fields -->>


        // <<-- Creer-Merge: methods -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
        // you can add addtional method(s) here.
        // <<-- /Creer-Merge: methods -->>
};

#endif

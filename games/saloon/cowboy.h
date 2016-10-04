// A person on the map that can move around and interact within the saloon.

#ifndef JOUEUR_SALOON_COWBOY_H
#define JOUEUR_SALOON_COWBOY_H

#include "saloon.h"
#include "gameObject.h"

// <<-- Creer-Merge: includes -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
// you can add addtional #includes(s) here.
// <<-- /Creer-Merge: includes -->>

/// <summary>
/// A person on the map that can move around and interact within the saloon.
/// </summary>
class Saloon::Cowboy : public Saloon::GameObject
{
    friend Saloon::GameManager;

    protected:
        virtual void deltaUpdateField(const std::string& fieldName, boost::property_tree::ptree& delta);
        Cowboy() {};
        ~Cowboy() {};

    public:
        /// <summary>
        /// If the Cowboy can be moved this turn via its owner.
        /// </summary>
        bool canMove;

        /// <summary>
        /// The direction this Cowboy is moving while drunk. Will be 'North', 'East', 'South', or 'West' when drunk; or '' (empty string) when not drunk.
        /// </summary>
        std::string drunkDirection;

        /// <summary>
        /// How much focus this Cowboy has. Different Jobs do different things with their Cowboy's focus.
        /// </summary>
        int focus;

        /// <summary>
        /// How much health this Cowboy currently has.
        /// </summary>
        int health;

        /// <summary>
        /// If this Cowboy is dead and has been removed from the game.
        /// </summary>
        bool isDead;

        /// <summary>
        /// If this Cowboy is drunk, and will automatically walk.
        /// </summary>
        bool isDrunk;

        /// <summary>
        /// The job that this Cowboy does, and dictates how they fight and interact within the Saloon.
        /// </summary>
        std::string job;

        /// <summary>
        /// The Player that owns and can control this Cowboy.
        /// </summary>
        Saloon::Player* owner;

        /// <summary>
        /// The Tile that this Cowboy is located on.
        /// </summary>
        Saloon::Tile* tile;

        /// <summary>
        /// How many times this unit has been drunk before taking their siesta and reseting this to 0.
        /// </summary>
        int tolerance;

        /// <summary>
        /// How many turns this unit has remaining before it is no longer busy and can `act()` or `play()` again.
        /// </summary>
        int turnsBusy;


        // <<-- Creer-Merge: fields -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
        // you can add addtional fields(s) here. None of them will be tracked or updated by the server.
        // <<-- /Creer-Merge: fields -->>

        /// <summary>
        /// Does their job's action on a Tile.
        /// </summary>
        /// <param name="tile">The Tile you want this Cowboy to act on.</param>
        /// <param name="drunkDirection">The direction the bottle will cause drunk cowboys to be in, can be 'North', 'East', 'South', or 'West'.</param>
        /// <returns>True if the act worked, false otherwise.</returns>
        bool act(Saloon::Tile* tile, std::string drunkDirection = "");

        /// <summary>
        /// Moves this Cowboy from its current Tile to an adjacent Tile.
        /// </summary>
        /// <param name="tile">The Tile you want to move this Cowboy to.</param>
        /// <returns>True if the move worked, false otherwise.</returns>
        bool move(Saloon::Tile* tile);

        /// <summary>
        /// Sits down and plays a piano.
        /// </summary>
        /// <param name="piano">The Furnishing that is a piano you want to play.</param>
        /// <returns>True if the play worked, false otherwise.</returns>
        bool play(Saloon::Furnishing* piano);


        // <<-- Creer-Merge: methods -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
        // you can add addtional method(s) here.
        // <<-- /Creer-Merge: methods -->>
};

#endif

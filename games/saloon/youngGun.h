// An eager young person that wants to join your gang, and will call in the veteran Cowboys you need to win the brawl in the saloon.

// DO NOT MODIFY THIS FILE
// Never try to directly create an instance of this class, or modify its member variables.
// Instead, you should only be reading its variables and calling its functions.

#ifndef JOUEUR_SALOON_YOUNGGUN_H
#define JOUEUR_SALOON_YOUNGGUN_H

#include "saloon.h"
#include "gameObject.h"

// <<-- Creer-Merge: includes -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
// you can add addtional #includes(s) here.
// <<-- /Creer-Merge: includes -->>

/// <summary>
/// An eager young person that wants to join your gang, and will call in the veteran Cowboys you need to win the brawl in the saloon.
/// </summary>
class Saloon::YoungGun : public Saloon::GameObject
{
    friend Saloon::GameManager;

    protected:
        virtual void deltaUpdateField(const std::string& fieldName, boost::property_tree::ptree& delta);
        YoungGun() {};
        ~YoungGun() {};

    public:
        /// <summary>
        /// True if the YoungGun can call in a Cowboy, false otherwise.
        /// </summary>
        bool canCallIn;

        /// <summary>
        /// The Player that owns and can control this YoungGun.
        /// </summary>
        Saloon::Player* owner;

        /// <summary>
        /// The Tile this YoungGun is currently on. Cowboys they send in will be on the nearest non-balcony Tile.
        /// </summary>
        Saloon::Tile* tile;


        // <<-- Creer-Merge: fields -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
        // you can add addtional fields(s) here. None of them will be tracked or updated by the server.
        // <<-- /Creer-Merge: fields -->>

        /// <summary>
        /// Tells the YoungGun to call in a new Cowbow of the given job to the open Tile nearest to them.
        /// </summary>
        /// <param name="job">The job you want the Cowboy being brought to have.</param>
        /// <returns>The new Cowboy that was called in if valid. They will not be added to any `cowboys` vectors until the turn ends. nullptr otherwise.</returns>
        Saloon::Cowboy* callIn(std::string job);


        // <<-- Creer-Merge: methods -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
        // you can add addtional method(s) here.
        // <<-- /Creer-Merge: methods -->>
};

#endif

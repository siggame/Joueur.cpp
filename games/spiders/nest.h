// A location (node) connected to other Nests via Webs (edges) in the game that Spiders can converge on, regardless of owner.

// DO NOT MODIFY THIS FILE
// Never try to directly create an instance of this class, or modify its member variables.
// Instead, you should only be reading its variables and calling its functions.

#ifndef JOUEUR_SPIDERS_NEST_H
#define JOUEUR_SPIDERS_NEST_H

#include "spiders.h"
#include "gameObject.h"

// <<-- Creer-Merge: includes -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
// you can add additional #includes(s) here.
// <<-- /Creer-Merge: includes -->>

/// <summary>
/// A location (node) connected to other Nests via Webs (edges) in the game that Spiders can converge on, regardless of owner.
/// </summary>
class Spiders::Nest : public Spiders::GameObject
{
    friend Spiders::GameManager;

    protected:
        virtual void deltaUpdateField(const std::string& fieldName, boost::property_tree::ptree& delta);
        Nest() {};
        ~Nest() {};

    public:
        /// <summary>
        /// All the Spiders currently located on this Nest.
        /// </summary>
        std::vector<Spiders::Spider*> spiders;

        /// <summary>
        /// Webs that connect to this Nest.
        /// </summary>
        std::vector<Spiders::Web*> webs;

        /// <summary>
        /// The X coordinate of the Nest. Used for distance calculations.
        /// </summary>
        int x;

        /// <summary>
        /// The Y coordinate of the Nest. Used for distance calculations.
        /// </summary>
        int y;


        // <<-- Creer-Merge: fields -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
        // you can add additional fields(s) here. None of them will be tracked or updated by the server.
        // <<-- /Creer-Merge: fields -->>


        // <<-- Creer-Merge: methods -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
        // you can add additional method(s) here.
        // <<-- /Creer-Merge: methods -->>
};

#endif

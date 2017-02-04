// The Spider Queen. She alone can spawn Spiderlings for each Player, and if she dies the owner loses.

// DO NOT MODIFY THIS FILE
// Never try to directly create an instance of this class, or modify its member variables.
// Instead, you should only be reading its variables and calling its functions.

#ifndef JOUEUR_SPIDERS_BROODMOTHER_H
#define JOUEUR_SPIDERS_BROODMOTHER_H

#include "spiders.h"
#include "spider.h"

// <<-- Creer-Merge: includes -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
// you can add additional #includes(s) here.
// <<-- /Creer-Merge: includes -->>

/// <summary>
/// The Spider Queen. She alone can spawn Spiderlings for each Player, and if she dies the owner loses.
/// </summary>
class Spiders::BroodMother : public Spiders::Spider
{
    friend Spiders::GameManager;

    protected:
        virtual void deltaUpdateField(const std::string& fieldName, boost::property_tree::ptree& delta);
        BroodMother() {};
        ~BroodMother() {};

    public:
        /// <summary>
        /// How many eggs the BroodMother has to spawn Spiderlings this turn.
        /// </summary>
        double eggs;

        /// <summary>
        /// How much health this BroodMother has left. When it reaches 0, she dies and her owner loses.
        /// </summary>
        int health;


        // <<-- Creer-Merge: fields -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
        // you can add additional fields(s) here. None of them will be tracked or updated by the server.
        // <<-- /Creer-Merge: fields -->>

        /// <summary>
        /// Consumes a Spiderling of the same owner to regain some eggs to spawn more Spiderlings.
        /// </summary>
        /// <param name="spiderling">The Spiderling to consume. It must be on the same Nest as this BroodMother.</param>
        /// <returns>True if the Spiderling was consumed. False otherwise.</returns>
        bool consume(Spiders::Spiderling* spiderling);

        /// <summary>
        /// Spawns a new Spiderling on the same Nest as this BroodMother, consuming an egg.
        /// </summary>
        /// <param name="spiderlingType">The string name of the Spiderling class you want to Spawn. Must be 'Spitter', 'Weaver', or 'Cutter'.</param>
        /// <returns>The newly spwaned Spiderling if successful. nullptr otherwise.</returns>
        Spiders::Spiderling* spawn(std::string spiderlingType);


        // <<-- Creer-Merge: methods -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
        // you can add additional method(s) here.
        // <<-- /Creer-Merge: methods -->>
};

#endif

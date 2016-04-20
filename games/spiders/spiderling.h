// Generated by Creer at 12:18AM on April 20, 2016 UTC, git hash: 'f74143f3f89eebeaa381aba30a8afbda7d0e1d89'
// A Spider spawned by the BroodMother.

#ifndef JOUEUR_SPIDERS_SPIDERLING_H
#define JOUEUR_SPIDERS_SPIDERLING_H

#include "spiders.h"
#include "spider.h"

// <<-- Creer-Merge: includes -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
// you can add addtional #includes(s) here.
// <<-- /Creer-Merge: includes -->>

/// <summary>
/// A Spider spawned by the BroodMother.
/// </summary>
class Spiders::Spiderling : public Spiders::Spider
{
    friend Spiders::GameManager;

    protected:
        virtual void deltaUpdateField(const std::string& fieldName, boost::property_tree::ptree& delta);
        Spiderling() {};
        ~Spiderling() {};

    public:
        /// <summary>
        /// When empty string this Spiderling is not busy, and can act. Otherwise a string representing what it is busy with, e.g. 'Moving', 'Attacking'.
        /// </summary>
        std::string busy;

        /// <summary>
        /// All the Spiderlings busy with the same work this Spiderling is doing, speeding up the task.
        /// </summary>
        std::vector<Spiders::Spiderling*> coworkers;

        /// <summary>
        /// The Web this Spiderling is using to move. Null if it is not moving.
        /// </summary>
        Spiders::Web* movingOnWeb;

        /// <summary>
        /// The Nest this Spiderling is moving to. Null if it is not moving.
        /// </summary>
        Spiders::Nest* movingToNest;

        /// <summary>
        /// How much work needs to be done for this Spiderling to finish being busy. See docs for the Work forumla.
        /// </summary>
        int workRemaining;


        // <<-- Creer-Merge: fields -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
        // you can add addtional fields(s) here. None of them will be tracked or updated by the server.
        // <<-- /Creer-Merge: fields -->>

        /// <summary>
        /// Attacks another Spiderling
        /// </summary>
        /// <param name="spiderling">The Spiderling to attack.</param>
        /// <returns>True if the attack was successful, false otherwise.</returns>
        bool attack(Spiders::Spiderling* spiderling);

        /// <summary>
        /// Starts moving the Spiderling across a Web to another Nest.
        /// </summary>
        /// <param name="web">The Web you want to move across to the other Nest.</param>
        /// <returns>True if the move was successful, false otherwise.</returns>
        bool move(Spiders::Web* web);


        // <<-- Creer-Merge: methods -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
        // you can add addtional method(s) here.
        // <<-- /Creer-Merge: methods -->>
};

#endif
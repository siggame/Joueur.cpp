// A Spiderling that can cut existing Webs.

// DO NOT MODIFY THIS FILE
// Never try to directly create an instance of this class, or modify its member variables.
// Instead, you should only be reading its variables and calling its functions.

#ifndef JOUEUR_SPIDERS_CUTTER_H
#define JOUEUR_SPIDERS_CUTTER_H

#include "spiders.h"
#include "spiderling.h"

// <<-- Creer-Merge: includes -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
// you can add additional #includes(s) here.
// <<-- /Creer-Merge: includes -->>

/// <summary>
/// A Spiderling that can cut existing Webs.
/// </summary>
class Spiders::Cutter : public Spiders::Spiderling
{
    friend Spiders::GameManager;

    protected:
        virtual void deltaUpdateField(const std::string& fieldName, boost::property_tree::ptree& delta);
        Cutter() {};
        ~Cutter() {};

    public:
        /// <summary>
        /// The Web that this Cutter is trying to cut. nullptr if not cutting.
        /// </summary>
        Spiders::Web* cuttingWeb;


        // <<-- Creer-Merge: fields -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
        // you can add additional fields(s) here. None of them will be tracked or updated by the server.
        // <<-- /Creer-Merge: fields -->>

        /// <summary>
        /// Cuts a web, destroying it, and any Spiderlings on it.
        /// </summary>
        /// <param name="web">The web you want to Cut. Must be connected to the Nest this Cutter is currently on.</param>
        /// <returns>True if the cut was successfully started, false otherwise.</returns>
        bool cut(Spiders::Web* web);


        // <<-- Creer-Merge: methods -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
        // you can add additional method(s) here.
        // <<-- /Creer-Merge: methods -->>
};

#endif

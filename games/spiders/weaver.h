// A Spiderling that can alter existing Webs by weaving to add or remove silk from the Webs, thus altering its strength.

// DO NOT MODIFY THIS FILE
// Never try to directly create an instance of this class, or modify its member variables.
// Instead, you should only be reading its variables and calling its functions.

#ifndef JOUEUR_SPIDERS_WEAVER_H
#define JOUEUR_SPIDERS_WEAVER_H

#include "spiders.h"
#include "spiderling.h"

// <<-- Creer-Merge: includes -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
// you can add additional #includes(s) here.
// <<-- /Creer-Merge: includes -->>

/// <summary>
/// A Spiderling that can alter existing Webs by weaving to add or remove silk from the Webs, thus altering its strength.
/// </summary>
class Spiders::Weaver : public Spiders::Spiderling
{
    friend Spiders::GameManager;

    protected:
        virtual void deltaUpdateField(const std::string& fieldName, boost::property_tree::ptree& delta);
        Weaver() {};
        ~Weaver() {};

    public:
        /// <summary>
        /// The Web that this Weaver is strengthening. nullptr if not strengthening.
        /// </summary>
        Spiders::Web* strengtheningWeb;

        /// <summary>
        /// The Web that this Weaver is weakening. nullptr if not weakening.
        /// </summary>
        Spiders::Web* weakeningWeb;


        // <<-- Creer-Merge: fields -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
        // you can add additional fields(s) here. None of them will be tracked or updated by the server.
        // <<-- /Creer-Merge: fields -->>

        /// <summary>
        /// Weaves more silk into an existing Web to strengthen it.
        /// </summary>
        /// <param name="web">The web you want to strengthen. Must be connected to the Nest this Weaver is currently on.</param>
        /// <returns>True if the strengthen was successfully started, false otherwise.</returns>
        bool strengthen(Spiders::Web* web);

        /// <summary>
        /// Weaves more silk into an existing Web to strengthen it.
        /// </summary>
        /// <param name="web">The web you want to weaken. Must be connected to the Nest this Weaver is currently on.</param>
        /// <returns>True if the weaken was successfully started, false otherwise.</returns>
        bool weaken(Spiders::Web* web);


        // <<-- Creer-Merge: methods -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
        // you can add additional method(s) here.
        // <<-- /Creer-Merge: methods -->>
};

#endif

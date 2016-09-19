#ifndef JOUEUR_BASEGAMEOBJECT_H
#define JOUEUR_BASEGAMEOBJECT_H

#include <string>
#include "joueur.h"
#include "deltaMergeable.h"

/// <summary>
/// The base class all GameObjects inherit from, regardless of game.
/// </summary>
class Joueur::BaseGameObject : public Joueur::DeltaMergeable
{
    public:
        /// <summary>
        /// A unique identifier for each game object. During any game IDs will never be re-used.
        /// </summary>
        std::string id;

        /// <summary>
        /// String representing the top level Class that this game object is an instance of. Used for reflection to create new instances on clients, but exposed for convenience should AIs want this data.
        /// </summary>
        std::string gameObjectName;

    protected:
        virtual void deltaUpdateField(const std::string& fieldName, boost::property_tree::ptree& delta);
        void runOnServer();
};

#endif

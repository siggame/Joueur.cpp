#ifndef JOUEUR_BASEGAME_H
#define JOUEUR_BASEGAME_H

#include <map>
#include "joueur.h"
#include "deltaMergeable.h"

class Joueur::BaseGame : public Joueur::DeltaMergeable
{
    protected:
        virtual void deltaUpdateField(const std::string& fieldName, boost::property_tree::ptree& delta);

    public:
        /// <summary>
        /// The name of the game.
        /// </summary>
        std::string name;

        /// <summary>
        /// A mapping of every game object's ID to the actual game object. Primarily used by the server and client to easily refer to the game objects via ID.
        /// </summary>
        std::map<std::string, BaseGameObject*> gameObjects;

        BaseGame()
        {
            this->name = "NO_NAME";
        }
};

#endif

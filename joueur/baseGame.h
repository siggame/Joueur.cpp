#ifndef JOUEUR_BASEGAME_H
#define JOUEUR_BASEGAME_H

#include <string>
#include <map>
#include "joueur.h"
#include "deltaMergeable.h"

class Joueur::BaseGame : public Joueur::DeltaMergeable
{
    protected:
        virtual void deltaUpdateField(const std::string& fieldName, boost::property_tree::ptree& delta);

    public:
        std::string name;
        std::map<std::string, BaseGameObject*> gameObjects;

        BaseGame()
        {
            this->name = "NO_NAME";
        }
};

#endif

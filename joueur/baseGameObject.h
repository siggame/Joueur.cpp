#ifndef JOUEUR_BASEGAMEOBJECT_H
#define JOUEUR_BASEGAMEOBJECT_H

#include <string>
#include "joueur.h"
#include "deltaMergeable.h"

class Joueur::BaseGameObject : public Joueur::DeltaMergeable
{
    public:
        std::string id;
        std::string gameObjectName;

    protected:
        virtual void deltaUpdateField(const std::string& fieldName, boost::property_tree::ptree& delta);
        void runOnServer(); // TODO: finish...
};

#endif

#ifndef CHECKERS_GAMEOBJECT_H
#define CHECKERS_GAMEOBJECT_H

#include "checkers.h"
#include "../../joueur/baseGameObject.h"

class Checkers::GameObject : public Joueur::BaseGameObject
{
    protected:
        virtual void deltaUpdateField(const std::string& fieldName, boost::property_tree::ptree& delta);

    public:
        std::vector<std::string> logs;
};


#endif

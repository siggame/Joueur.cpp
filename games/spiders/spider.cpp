// A Spider in the game. The most basic unit.

// DO NOT MODIFY THIS FILE
// Never try to directly create an instance of this class, or modify its member variables.
// Instead, you should only be reading its variables and calling its functions.

#include "spider.h"
#include "gameManager.h"

// <<-- Creer-Merge: includes -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
// you can add additional #includes(s) here.
// <<-- /Creer-Merge: includes -->>




void Spiders::Spider::deltaUpdateField(const std::string& fieldName, boost::property_tree::ptree& delta)
{
    Spiders::GameObject::deltaUpdateField(fieldName, delta);

    if (fieldName == "isDead")
    {
        this->isDead = this->gameManager->unserializeBool(delta);
    }
    else if (fieldName == "nest")
    {
        this->nest = (Spiders::Nest*)this->gameManager->unserializeGameObject(delta);
    }
    else if (fieldName == "owner")
    {
        this->owner = (Spiders::Player*)this->gameManager->unserializeGameObject(delta);
    }
}




// <<-- Creer-Merge: methods -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
// if you forward declared additional methods to the Spider then you can code them here.
// <<-- /Creer-Merge: methods -->>

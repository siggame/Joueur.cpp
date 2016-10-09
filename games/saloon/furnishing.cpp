// An furnishing in the Saloon that must be pathed around, or destroyed.

// DO NOT MODIFY THIS FILE
// Never try to directly create an instance of this class, or modify its member variables.
// Instead, you should only be reading its variables and calling its functions.

#include "furnishing.h"
#include "gameManager.h"

// <<-- Creer-Merge: includes -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
// you can add additional #includes(s) here.
// <<-- /Creer-Merge: includes -->>




void Saloon::Furnishing::deltaUpdateField(const std::string& fieldName, boost::property_tree::ptree& delta)
{
    Saloon::GameObject::deltaUpdateField(fieldName, delta);

    if (fieldName == "health")
    {
        this->health = this->gameManager->unserializeInt(delta);
    }
    else if (fieldName == "isDestroyed")
    {
        this->isDestroyed = this->gameManager->unserializeBool(delta);
    }
    else if (fieldName == "isPiano")
    {
        this->isPiano = this->gameManager->unserializeBool(delta);
    }
    else if (fieldName == "tile")
    {
        this->tile = (Saloon::Tile*)this->gameManager->unserializeGameObject(delta);
    }
}




// <<-- Creer-Merge: methods -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
// if you forward declaired additional methods to the Furnishing then you can code them here.
// <<-- /Creer-Merge: methods -->>

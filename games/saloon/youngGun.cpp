// An eager young person that wants to join your gang, and will call in the veteran Cowboys you need to win the brawl in the saloon.

// DO NOT MODIFY THIS FILE
// Never try to directly create an instance of this class, or modify its member variables.
// Instead, you should only be reading its variables and calling its functions.

#include "youngGun.h"
#include "gameManager.h"

// <<-- Creer-Merge: includes -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
// you can add additional #includes(s) here.
// <<-- /Creer-Merge: includes -->>




void Saloon::YoungGun::deltaUpdateField(const std::string& fieldName, boost::property_tree::ptree& delta)
{
    Saloon::GameObject::deltaUpdateField(fieldName, delta);

    if (fieldName == "callInTile")
    {
        this->callInTile = (Saloon::Tile*)this->gameManager->unserializeGameObject(delta);
    }
    else if (fieldName == "canCallIn")
    {
        this->canCallIn = this->gameManager->unserializeBool(delta);
    }
    else if (fieldName == "owner")
    {
        this->owner = (Saloon::Player*)this->gameManager->unserializeGameObject(delta);
    }
    else if (fieldName == "tile")
    {
        this->tile = (Saloon::Tile*)this->gameManager->unserializeGameObject(delta);
    }
}



Saloon::Cowboy* Saloon::YoungGun::callIn(std::string job)
{
    boost::property_tree::ptree args;
    args.put_child("job", *this->gameManager->serialize((job)));

    auto returned = this->gameManager->runOnServer(*this, "callIn", args);
    return (Saloon::Cowboy*)this->gameManager->unserializeGameObject(*returned);
}


// <<-- Creer-Merge: methods -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
// if you forward declaired additional methods to the YoungGun then you can code them here.
// <<-- /Creer-Merge: methods -->>

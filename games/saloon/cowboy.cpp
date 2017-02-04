// A person on the map that can move around and interact within the saloon.

// DO NOT MODIFY THIS FILE
// Never try to directly create an instance of this class, or modify its member variables.
// Instead, you should only be reading its variables and calling its functions.

#include "cowboy.h"
#include "gameManager.h"

#include "tile.h"
#include "tile.h"
#include "furnishing.h"

// <<-- Creer-Merge: includes -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
// you can add additional #includes(s) here.
// <<-- /Creer-Merge: includes -->>




void Saloon::Cowboy::deltaUpdateField(const std::string& fieldName, boost::property_tree::ptree& delta)
{
    Saloon::GameObject::deltaUpdateField(fieldName, delta);

    if (fieldName == "canMove")
    {
        this->canMove = this->gameManager->unserializeBool(delta);
    }
    else if (fieldName == "drunkDirection")
    {
        this->drunkDirection = this->gameManager->unserializeString(delta);
    }
    else if (fieldName == "focus")
    {
        this->focus = this->gameManager->unserializeInt(delta);
    }
    else if (fieldName == "health")
    {
        this->health = this->gameManager->unserializeInt(delta);
    }
    else if (fieldName == "isDead")
    {
        this->isDead = this->gameManager->unserializeBool(delta);
    }
    else if (fieldName == "isDrunk")
    {
        this->isDrunk = this->gameManager->unserializeBool(delta);
    }
    else if (fieldName == "job")
    {
        this->job = this->gameManager->unserializeString(delta);
    }
    else if (fieldName == "owner")
    {
        this->owner = (Saloon::Player*)this->gameManager->unserializeGameObject(delta);
    }
    else if (fieldName == "tile")
    {
        this->tile = (Saloon::Tile*)this->gameManager->unserializeGameObject(delta);
    }
    else if (fieldName == "tolerance")
    {
        this->tolerance = this->gameManager->unserializeInt(delta);
    }
    else if (fieldName == "turnsBusy")
    {
        this->turnsBusy = this->gameManager->unserializeInt(delta);
    }
}



bool Saloon::Cowboy::act(Saloon::Tile* tile, std::string drunkDirection)
{
    boost::property_tree::ptree args;
    args.put_child("tile", *this->gameManager->serialize(static_cast<BaseGameObject*>(tile)));
    args.put_child("drunkDirection", *this->gameManager->serialize((drunkDirection)));

    auto returned = this->gameManager->runOnServer(*this, "act", args);
    return this->gameManager->unserializeBool(*returned);
}

bool Saloon::Cowboy::move(Saloon::Tile* tile)
{
    boost::property_tree::ptree args;
    args.put_child("tile", *this->gameManager->serialize(static_cast<BaseGameObject*>(tile)));

    auto returned = this->gameManager->runOnServer(*this, "move", args);
    return this->gameManager->unserializeBool(*returned);
}

bool Saloon::Cowboy::play(Saloon::Furnishing* piano)
{
    boost::property_tree::ptree args;
    args.put_child("piano", *this->gameManager->serialize(static_cast<BaseGameObject*>(piano)));

    auto returned = this->gameManager->runOnServer(*this, "play", args);
    return this->gameManager->unserializeBool(*returned);
}


// <<-- Creer-Merge: methods -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
// if you forward declared additional methods to the Cowboy then you can code them here.
// <<-- /Creer-Merge: methods -->>

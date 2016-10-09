// A Tile in the game that makes up the 2D map grid.

// DO NOT MODIFY THIS FILE
// Never try to directly create an instance of this class, or modify its member variables.
// Instead, you should only be reading its variables and calling its functions.

#include "tile.h"
#include "gameManager.h"

// <<-- Creer-Merge: includes -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
// you can add additional #includes(s) here.
// <<-- /Creer-Merge: includes -->>




void Saloon::Tile::deltaUpdateField(const std::string& fieldName, boost::property_tree::ptree& delta)
{
    Saloon::GameObject::deltaUpdateField(fieldName, delta);

    if (fieldName == "bottle")
    {
        this->bottle = (Saloon::Bottle*)this->gameManager->unserializeGameObject(delta);
    }
    else if (fieldName == "cowboy")
    {
        this->cowboy = (Saloon::Cowboy*)this->gameManager->unserializeGameObject(delta);
    }
    else if (fieldName == "furnishing")
    {
        this->furnishing = (Saloon::Furnishing*)this->gameManager->unserializeGameObject(delta);
    }
    else if (fieldName == "hasHazard")
    {
        this->hasHazard = this->gameManager->unserializeBool(delta);
    }
    else if (fieldName == "isBalcony")
    {
        this->isBalcony = this->gameManager->unserializeBool(delta);
    }
    else if (fieldName == "tileEast")
    {
        this->tileEast = (Saloon::Tile*)this->gameManager->unserializeGameObject(delta);
    }
    else if (fieldName == "tileNorth")
    {
        this->tileNorth = (Saloon::Tile*)this->gameManager->unserializeGameObject(delta);
    }
    else if (fieldName == "tileSouth")
    {
        this->tileSouth = (Saloon::Tile*)this->gameManager->unserializeGameObject(delta);
    }
    else if (fieldName == "tileWest")
    {
        this->tileWest = (Saloon::Tile*)this->gameManager->unserializeGameObject(delta);
    }
    else if (fieldName == "x")
    {
        this->x = this->gameManager->unserializeInt(delta);
    }
    else if (fieldName == "y")
    {
        this->y = this->gameManager->unserializeInt(delta);
    }
    else if (fieldName == "youngGun")
    {
        this->youngGun = (Saloon::YoungGun*)this->gameManager->unserializeGameObject(delta);
    }
}




// <<-- Creer-Merge: methods -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
// if you forward declaired additional methods to the Tile then you can code them here.
// <<-- /Creer-Merge: methods -->>

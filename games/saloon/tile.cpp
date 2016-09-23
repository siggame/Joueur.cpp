// A Tile in the game that makes up the 2D map grid.

#include "tile.h"
#include "gameManager.h"

// <<-- Creer-Merge: includes -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
// you can add additional #includes(s) here.
// <<-- /Creer-Merge: includes -->>




void Saloon::Tile::deltaUpdateField(const std::string& fieldName, boost::property_tree::ptree& delta)
{
    Saloon::GameObject::deltaUpdateField(fieldName, delta);

    if (fieldName == "bottles")
    {
        this->bottles = this->gameManager->unserializeVectorOfGameObjects<Saloon::Bottle*>(delta, &this->bottles);
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
    else if (fieldName == "isWall")
    {
        this->isWall = this->gameManager->unserializeBool(delta);
    }
    else if (fieldName == "tileAbove")
    {
        this->tileAbove = (Saloon::Tile*)this->gameManager->unserializeGameObject(delta);
    }
    else if (fieldName == "tileBelow")
    {
        this->tileBelow = (Saloon::Tile*)this->gameManager->unserializeGameObject(delta);
    }
    else if (fieldName == "tileLeft")
    {
        this->tileLeft = (Saloon::Tile*)this->gameManager->unserializeGameObject(delta);
    }
    else if (fieldName == "tileRight")
    {
        this->tileRight = (Saloon::Tile*)this->gameManager->unserializeGameObject(delta);
    }
    else if (fieldName == "x")
    {
        this->x = this->gameManager->unserializeInt(delta);
    }
    else if (fieldName == "y")
    {
        this->y = this->gameManager->unserializeInt(delta);
    }
}




// <<-- Creer-Merge: methods -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
// if you forward declaired additional methods to the Tile then you can code them here.
// <<-- /Creer-Merge: methods -->>

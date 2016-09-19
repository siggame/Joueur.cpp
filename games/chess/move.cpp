// Contains all details about a Piece's move in the game.

#include "move.h"
#include "gameManager.h"

// <<-- Creer-Merge: includes -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
// you can add additional #includes(s) here.
// <<-- /Creer-Merge: includes -->>




void Chess::Move::deltaUpdateField(const std::string& fieldName, boost::property_tree::ptree& delta)
{
    Chess::GameObject::deltaUpdateField(fieldName, delta);

    if (fieldName == "captured")
    {
        this->captured = (Chess::Piece*)this->gameManager->unserializeGameObject(delta);
    }
    else if (fieldName == "fromFile")
    {
        this->fromFile = this->gameManager->unserializeString(delta);
    }
    else if (fieldName == "fromRank")
    {
        this->fromRank = this->gameManager->unserializeInt(delta);
    }
    else if (fieldName == "piece")
    {
        this->piece = (Chess::Piece*)this->gameManager->unserializeGameObject(delta);
    }
    else if (fieldName == "promotion")
    {
        this->promotion = this->gameManager->unserializeString(delta);
    }
    else if (fieldName == "san")
    {
        this->san = this->gameManager->unserializeString(delta);
    }
    else if (fieldName == "toFile")
    {
        this->toFile = this->gameManager->unserializeString(delta);
    }
    else if (fieldName == "toRank")
    {
        this->toRank = this->gameManager->unserializeInt(delta);
    }
}




// <<-- Creer-Merge: methods -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
// if you forward declaired additional methods to the Move then you can code them here.
// <<-- /Creer-Merge: methods -->>

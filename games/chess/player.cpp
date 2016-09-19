// A player in this game. Every AI controls one player.

#include "player.h"
#include "gameManager.h"

// <<-- Creer-Merge: includes -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
// you can add additional #includes(s) here.
// <<-- /Creer-Merge: includes -->>




void Chess::Player::deltaUpdateField(const std::string& fieldName, boost::property_tree::ptree& delta)
{
    Chess::GameObject::deltaUpdateField(fieldName, delta);

    if (fieldName == "clientType")
    {
        this->clientType = this->gameManager->unserializeString(delta);
    }
    else if (fieldName == "color")
    {
        this->color = this->gameManager->unserializeString(delta);
    }
    else if (fieldName == "inCheck")
    {
        this->inCheck = this->gameManager->unserializeBool(delta);
    }
    else if (fieldName == "lost")
    {
        this->lost = this->gameManager->unserializeBool(delta);
    }
    else if (fieldName == "madeMove")
    {
        this->madeMove = this->gameManager->unserializeBool(delta);
    }
    else if (fieldName == "name")
    {
        this->name = this->gameManager->unserializeString(delta);
    }
    else if (fieldName == "opponent")
    {
        this->opponent = (Chess::Player*)this->gameManager->unserializeGameObject(delta);
    }
    else if (fieldName == "pieces")
    {
        this->pieces = this->gameManager->unserializeVectorOfGameObjects<Chess::Piece*>(delta, &this->pieces);
    }
    else if (fieldName == "rankDirection")
    {
        this->rankDirection = this->gameManager->unserializeInt(delta);
    }
    else if (fieldName == "reasonLost")
    {
        this->reasonLost = this->gameManager->unserializeString(delta);
    }
    else if (fieldName == "reasonWon")
    {
        this->reasonWon = this->gameManager->unserializeString(delta);
    }
    else if (fieldName == "timeRemaining")
    {
        this->timeRemaining = this->gameManager->unserializeDouble(delta);
    }
    else if (fieldName == "won")
    {
        this->won = this->gameManager->unserializeBool(delta);
    }
}




// <<-- Creer-Merge: methods -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
// if you forward declaired additional methods to the Player then you can code them here.
// <<-- /Creer-Merge: methods -->>

// A player in this game. Every AI controls one player.

// DO NOT MODIFY THIS FILE
// Never try to directly create an instance of this class, or modify its member variables.
// Instead, you should only be reading its variables and calling its functions.

#include "player.h"
#include "gameManager.h"

// <<-- Creer-Merge: includes -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
// you can add additional #includes(s) here.
// <<-- /Creer-Merge: includes -->>




void Checkers::Player::deltaUpdateField(const std::string& fieldName, boost::property_tree::ptree& delta)
{
    Checkers::GameObject::deltaUpdateField(fieldName, delta);

    if (fieldName == "checkers")
    {
        this->checkers = this->gameManager->unserializeVectorOfGameObjects<Checkers::Checker*>(delta, &this->checkers);
    }
    else if (fieldName == "clientType")
    {
        this->clientType = this->gameManager->unserializeString(delta);
    }
    else if (fieldName == "lost")
    {
        this->lost = this->gameManager->unserializeBool(delta);
    }
    else if (fieldName == "name")
    {
        this->name = this->gameManager->unserializeString(delta);
    }
    else if (fieldName == "opponent")
    {
        this->opponent = (Checkers::Player*)this->gameManager->unserializeGameObject(delta);
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
    else if (fieldName == "yDirection")
    {
        this->yDirection = this->gameManager->unserializeInt(delta);
    }
}




// <<-- Creer-Merge: methods -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
// if you forward declared additional methods to the Player then you can code them here.
// <<-- /Creer-Merge: methods -->>

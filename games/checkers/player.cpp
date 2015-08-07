#include "player.h"
#include "gameManager.h"

void Checkers::Player::deltaUpdateField(const std::string& fieldName, boost::property_tree::ptree& delta)
{
    Checkers::GameObject::deltaUpdateField(fieldName, delta);

    if (fieldName == "checkers") {
        this->checkers = this->gameManager->getDeltaVectorOfGameObjects<Checkers::Checker*>(delta, this->checkers);
    }
    else if (fieldName == "clientType") {
        this->clientType = this->gameManager->getDeltaString(delta);
    }
    else if (fieldName == "name") {
        this->name = this->gameManager->getDeltaString(delta);
    }
    else if (fieldName == "timeRemaining") {
        this->timeRemaining = this->gameManager->getDeltaFloat(delta);
    }
    else if (fieldName == "yDirection") {
        this->yDirection = this->gameManager->getDeltaInt(delta);
    }
    else if (fieldName == "lost") {
        this->lost = this->gameManager->getDeltaBool(delta);
    }
    else if (fieldName == "reasonLost") {
        this->reasonLost = this->gameManager->getDeltaString(delta);
    }
    else if (fieldName == "reasonWon") {
        this->reasonWon = this->gameManager->getDeltaString(delta);
    }
    else if (fieldName == "won") {
        this->won = this->gameManager->getDeltaBool(delta);
    }
}

#include "checker.h"
#include "gameManager.h"

void Checkers::Checker::deltaUpdateField(const std::string& fieldName, boost::property_tree::ptree& delta)
{
    Checkers::GameObject::deltaUpdateField(fieldName, delta);

    if (fieldName == "kinged") {
        this->kinged = this->gameManager->getDeltaBool(delta);
    }
    else if (fieldName == "owner") {
        this->owner = (Player*)(this->gameManager->getDeltaGameObject(delta));
    }
    else if (fieldName == "x")
    {
        this->x = this->gameManager->getDeltaInt(delta);
    }
    else if (fieldName == "y")
    {
        this->y = this->gameManager->getDeltaInt(delta);
    }
}

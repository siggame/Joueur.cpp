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

Checkers::Checker* Checkers::Checker::move(int x, int y)
{
    boost::property_tree::ptree args;
    args.put_child("x", *this->gameManager->serialize(x));
    args.put_child("y", *this->gameManager->serialize(y));

    return (Checkers::Checker*)this->gameManager->unserializeGameObject(*this->gameManager->runOnServer(*this, "move", args));
}

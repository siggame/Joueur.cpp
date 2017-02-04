// A checker on the game board.

// DO NOT MODIFY THIS FILE
// Never try to directly create an instance of this class, or modify its member variables.
// Instead, you should only be reading its variables and calling its functions.

#include "checker.h"
#include "gameManager.h"

// <<-- Creer-Merge: includes -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
// you can add additional #includes(s) here.
// <<-- /Creer-Merge: includes -->>




void Checkers::Checker::deltaUpdateField(const std::string& fieldName, boost::property_tree::ptree& delta)
{
    Checkers::GameObject::deltaUpdateField(fieldName, delta);

    if (fieldName == "kinged")
    {
        this->kinged = this->gameManager->unserializeBool(delta);
    }
    else if (fieldName == "owner")
    {
        this->owner = (Checkers::Player*)this->gameManager->unserializeGameObject(delta);
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



bool Checkers::Checker::isMine()
{
    boost::property_tree::ptree args;

    auto returned = this->gameManager->runOnServer(*this, "isMine", args);
    return this->gameManager->unserializeBool(*returned);
}

Checkers::Checker* Checkers::Checker::move(int x, int y)
{
    boost::property_tree::ptree args;
    args.put_child("x", *this->gameManager->serialize((x)));
    args.put_child("y", *this->gameManager->serialize((y)));

    auto returned = this->gameManager->runOnServer(*this, "move", args);
    return (Checkers::Checker*)this->gameManager->unserializeGameObject(*returned);
}


// <<-- Creer-Merge: methods -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
// if you forward declared additional methods to the Checker then you can code them here.
// <<-- /Creer-Merge: methods -->>

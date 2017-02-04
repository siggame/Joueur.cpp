// An object in the game. The most basic class that all game classes should inherit from automatically.

// DO NOT MODIFY THIS FILE
// Never try to directly create an instance of this class, or modify its member variables.
// Instead, you should only be reading its variables and calling its functions.

#include "gameObject.h"
#include "gameManager.h"

// <<-- Creer-Merge: includes -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
// you can add additional #includes(s) here.
// <<-- /Creer-Merge: includes -->>




void Anarchy::GameObject::deltaUpdateField(const std::string& fieldName, boost::property_tree::ptree& delta)
{
    Joueur::BaseGameObject::deltaUpdateField(fieldName, delta);

    if (fieldName == "logs")
    {
        this->logs = this->gameManager->unserializeVector(delta, &this->logs);
    }
}



void Anarchy::GameObject::log(std::string message)
{
    boost::property_tree::ptree args;
    args.put_child("message", *this->gameManager->serialize((message)));

    auto returned = this->gameManager->runOnServer(*this, "log", args);
}


// <<-- Creer-Merge: methods -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
// if you forward declared additional methods to the GameObject then you can code them here.
// <<-- /Creer-Merge: methods -->>

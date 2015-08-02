#include "baseGameObject.h"
#include "gameManager.h"

void Joueur::BaseGameObject::deltaUpdateField(const std::string& fieldName, boost::property_tree::ptree& delta)
{
    if (fieldName == "id")
    {
        this->id = this->gameManager->getDeltaString(delta);
    }
    else if (fieldName == "gameObjectName")
    {
        this->gameObjectName = this->gameManager->getDeltaString(delta);
    }
}
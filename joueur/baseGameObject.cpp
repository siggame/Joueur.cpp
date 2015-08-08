#include "baseGameObject.h"
#include "baseGameManager.h"

void Joueur::BaseGameObject::deltaUpdateField(const std::string& fieldName, boost::property_tree::ptree& delta)
{
    if (fieldName == "id")
    {
        this->id = this->gameManager->unserializeString(delta);
    }
    else if (fieldName == "gameObjectName")
    {
        this->gameObjectName = this->gameManager->unserializeString(delta);
    }
}

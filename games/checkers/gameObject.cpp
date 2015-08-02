#include "gameObject.h"
#include "gameManager.h"

void Checkers::GameObject::deltaUpdateField(const std::string& fieldName, boost::property_tree::ptree& delta)
{
    Joueur::BaseGameObject::deltaUpdateField(fieldName, delta);

    if (fieldName == "logs") {
        this->logs = this->gameManager->getDeltaVector(delta, this->logs);
    }
}

#include "baseGame.h"
#include "baseGameManager.h"

void Joueur::BaseGame::deltaUpdateField(const std::string& fieldName, boost::property_tree::ptree& delta)
{
    if (fieldName == "name") {
        this->name = this->gameManager->unserializeString(delta);
    }
    // gameObjects was already handled specially in BaseGameManager::initGameObjects
}

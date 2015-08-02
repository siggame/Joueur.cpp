#include "baseGame.h"
#include "gameManager.h"

void Joueur::BaseGame::deltaUpdateField(const std::string& fieldName, boost::property_tree::ptree& delta)
{
    if (fieldName == "name") {
        this->name = this->gameManager->getDeltaString(delta);
    }
    // gameObjects was already handled specially
}

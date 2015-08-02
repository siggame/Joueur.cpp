#include "gameManager.h"
#include "gameObject.h"
#include "checker.h"
#include "player.h"

// @overrides
Joueur::BaseGameObject* Checkers::GameManager::createGameObject(const std::string& gameObjectName)
{
    if (gameObjectName == "GameObject") {
        return new Checkers::GameObject();
    }
    else if (gameObjectName == "Checker") {
        return new Checkers::Checker();
    }
    else if (gameObjectName == "Player") {
        return new Checkers::Player();
    }

    return nullptr;
}


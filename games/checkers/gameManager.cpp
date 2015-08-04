#include "gameManager.h"
#include "gameObject.h"
#include "checker.h"
#include "player.h"
#include "ai.h"

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

// @overrides
void Checkers::GameManager::setupAI(const std::string& playerID)
{
    Joueur::GameManager::setupAI(playerID);

    this->checkersAI->player = (Checkers::Player*)(this->getGameObject(playerID));
    this->checkersAI->game = (Checkers::Game*)(this->game.get());
}

// @overrides
boost::property_tree::ptree* Checkers::GameManager::orderAI(const std::string& order, boost::optional<boost::property_tree::ptree&> args)
{
    if (order == "runTurn") {
        auto returned = this->checkersAI->runTurn(
        );

        return this->serialize(returned);
    }

    return nullptr;
}


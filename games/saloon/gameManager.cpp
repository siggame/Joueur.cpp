// This is a class that manages the Saloon Game and its GameObjects. Competitors should never have to care about this class's existance.
// DO NOT MODIFY THIS FILE


#include "gameManager.h"
#include "ai.h"
// The Game Objects
#include "bottle.h"
#include "cowboy.h"
#include "furnishing.h"
#include "gameObject.h"
#include "player.h"
#include "tile.h"
#include "youngGun.h"

Saloon::GameManager::GameManager() :
    Joueur::BaseGameManager()
{
    this->saloonGame = new Saloon::Game();
    this->saloonAI = new Saloon::AI();

    this->setup(this->saloonGame, this->saloonAI);
}

// @overrides
Joueur::BaseGameObject* Saloon::GameManager::createGameObject(const std::string& gameObjectName)
{
    if (gameObjectName == "Bottle")
    {
        return new Saloon::Bottle();
    }
    else if (gameObjectName == "Cowboy")
    {
        return new Saloon::Cowboy();
    }
    else if (gameObjectName == "Furnishing")
    {
        return new Saloon::Furnishing();
    }
    else if (gameObjectName == "GameObject")
    {
        return new Saloon::GameObject();
    }
    else if (gameObjectName == "Player")
    {
        return new Saloon::Player();
    }
    else if (gameObjectName == "Tile")
    {
        return new Saloon::Tile();
    }
    else if (gameObjectName == "YoungGun")
    {
        return new Saloon::YoungGun();
    }

    throw new std::runtime_error(("Game object '" + gameObjectName + "' not found to create new instance of").c_str());
}

// @overrides
void Saloon::GameManager::setupAI(const std::string& playerID)
{
    Joueur::BaseGameManager::setupAI(playerID);

    this->saloonAI->player = (Saloon::Player*)(this->getGameObject(playerID));
    this->saloonAI->game = this->saloonGame;
}

// @overrides
boost::property_tree::ptree* Saloon::GameManager::orderAI(const std::string& order, boost::property_tree::ptree* args)
{
    auto ptrees = this->getOrderArgsPtrees(args);

    if (order == "runTurn")
    {
        auto returned = this->saloonAI->runTurn(
        );

        return this->serialize(returned);
    }

    delete ptrees;
    return nullptr;
}

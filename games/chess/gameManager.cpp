// $This is a class that manages the Chess Game and it's GameObjects. Competitors should never have to care about this class's existance.


#include "gameManager.h"
#include "ai.h"
// The Game Objects
#include "gameObject.h"
#include "move.h"
#include "piece.h"
#include "player.h"

Chess::GameManager::GameManager() :
    Joueur::BaseGameManager()
{
    this->chessGame = new Chess::Game();
    this->chessAI = new Chess::AI();

    this->setup(this->chessGame, this->chessAI);
}

// @overrides
Joueur::BaseGameObject* Chess::GameManager::createGameObject(const std::string& gameObjectName)
{
    if (gameObjectName == "GameObject")
    {
        return new Chess::GameObject();
    }
    else if (gameObjectName == "Move")
    {
        return new Chess::Move();
    }
    else if (gameObjectName == "Piece")
    {
        return new Chess::Piece();
    }
    else if (gameObjectName == "Player")
    {
        return new Chess::Player();
    }

    throw new std::runtime_error(("Game object '" + gameObjectName + "' not found to create new instance of").c_str());
}

// @overrides
void Chess::GameManager::setupAI(const std::string& playerID)
{
    Joueur::BaseGameManager::setupAI(playerID);

    this->chessAI->player = (Chess::Player*)(this->getGameObject(playerID));
    this->chessAI->game = this->chessGame;
}

// @overrides
boost::property_tree::ptree* Chess::GameManager::orderAI(const std::string& order, boost::property_tree::ptree* args)
{
    auto ptrees = this->getOrderArgsPtrees(args);

    if (order == "runTurn")
    {
        auto returned = this->chessAI->runTurn(
        );

        return this->serialize(returned);
    }

    delete ptrees;
    return nullptr;
}

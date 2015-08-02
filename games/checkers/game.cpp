#include "game.h"
#include "gameManager.h"

Checkers::Game::Game()
{
    this->name = "Checkers";
}

void Checkers::Game::deltaUpdateField(const std::string& fieldName, boost::property_tree::ptree& delta)
{
    Joueur::BaseGame::deltaUpdateField(fieldName, delta);

    if (fieldName == "boardHeight") {
        this->boardHeight = this->gameManager->getDeltaInt(delta);
    }
    else if (fieldName == "boardWidth") {
        this->boardWidth = this->gameManager->getDeltaInt(delta);
    }
    else if (fieldName == "checkerMoved")
    {
        this->checkerMoved = (Checkers::Checker*)this->gameManager->getDeltaGameObject(delta);
    }
    else if (fieldName == "checkerMovedJumped")
    {
        this->checkerMovedJumped = this->gameManager->getDeltaBool(delta);
    }
    else if (fieldName == "checkers")
    {
        this->checkers = this->gameManager->getDeltaVectorOfGameObjects<Checkers::Checker*>(delta, this->checkers);
    }
    else if (fieldName == "currentPlayer")
    {
        this->currentPlayer = (Checkers::Player*)this->gameManager->getDeltaGameObject(delta);
    }
    else if (fieldName == "currentTurn")
    {
        this->currentTurn = this->gameManager->getDeltaInt(delta);
    }
    else if (fieldName == "maxTurns")
    {
        this->maxTurns = this->gameManager->getDeltaInt(delta);
    }
    else if (fieldName == "players")
    {
        this->players = this->gameManager->getDeltaVectorOfGameObjects<Player*>(delta, this->players);
    }
    else if (fieldName == "session")
    {
        this->session = this->gameManager->getDeltaString(delta);
    }
}

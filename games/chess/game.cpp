// The traditional 8x8 chess board with pieces.

#include "game.h"
#include "gameManager.h"

// <<-- Creer-Merge: includes -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
// you can add additional #includes(s) here.
// <<-- /Creer-Merge: includes -->>




void Chess::Game::deltaUpdateField(const std::string& fieldName, boost::property_tree::ptree& delta)
{
    Joueur::BaseGame::deltaUpdateField(fieldName, delta);

    if (fieldName == "currentPlayer")
    {
        this->currentPlayer = (Chess::Player*)this->gameManager->unserializeGameObject(delta);
    }
    else if (fieldName == "currentTurn")
    {
        this->currentTurn = this->gameManager->unserializeInt(delta);
    }
    else if (fieldName == "fen")
    {
        this->fen = this->gameManager->unserializeString(delta);
    }
    else if (fieldName == "maxTurns")
    {
        this->maxTurns = this->gameManager->unserializeInt(delta);
    }
    else if (fieldName == "moves")
    {
        this->moves = this->gameManager->unserializeVectorOfGameObjects<Chess::Move*>(delta, &this->moves);
    }
    else if (fieldName == "pieces")
    {
        this->pieces = this->gameManager->unserializeVectorOfGameObjects<Chess::Piece*>(delta, &this->pieces);
    }
    else if (fieldName == "players")
    {
        this->players = this->gameManager->unserializeVectorOfGameObjects<Chess::Player*>(delta, &this->players);
    }
    else if (fieldName == "session")
    {
        this->session = this->gameManager->unserializeString(delta);
    }
    else if (fieldName == "turnsToDraw")
    {
        this->turnsToDraw = this->gameManager->unserializeInt(delta);
    }
}




// <<-- Creer-Merge: methods -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
// if you forward declaired additional methods to the Game then you can code them here.
// <<-- /Creer-Merge: methods -->>

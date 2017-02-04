// Use cowboys to have a good time and play some music on a Piano, while brawling with enemy Cowboys.

// DO NOT MODIFY THIS FILE
// Never try to directly create an instance of this class, or modify its member variables.
// Instead, you should only be reading its variables and calling its functions.

#include "game.h"
#include "gameManager.h"

// <<-- Creer-Merge: includes -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
// you can add additional #includes(s) here.
// <<-- /Creer-Merge: includes -->>




void Saloon::Game::deltaUpdateField(const std::string& fieldName, boost::property_tree::ptree& delta)
{
    Joueur::BaseGame::deltaUpdateField(fieldName, delta);

    if (fieldName == "bartenderCooldown")
    {
        this->bartenderCooldown = this->gameManager->unserializeInt(delta);
    }
    else if (fieldName == "bottles")
    {
        this->bottles = this->gameManager->unserializeVectorOfGameObjects<Saloon::Bottle*>(delta, &this->bottles);
    }
    else if (fieldName == "brawlerDamage")
    {
        this->brawlerDamage = this->gameManager->unserializeInt(delta);
    }
    else if (fieldName == "cowboys")
    {
        this->cowboys = this->gameManager->unserializeVectorOfGameObjects<Saloon::Cowboy*>(delta, &this->cowboys);
    }
    else if (fieldName == "currentPlayer")
    {
        this->currentPlayer = (Saloon::Player*)this->gameManager->unserializeGameObject(delta);
    }
    else if (fieldName == "currentTurn")
    {
        this->currentTurn = this->gameManager->unserializeInt(delta);
    }
    else if (fieldName == "furnishings")
    {
        this->furnishings = this->gameManager->unserializeVectorOfGameObjects<Saloon::Furnishing*>(delta, &this->furnishings);
    }
    else if (fieldName == "jobs")
    {
        this->jobs = this->gameManager->unserializeVector(delta, &this->jobs);
    }
    else if (fieldName == "mapHeight")
    {
        this->mapHeight = this->gameManager->unserializeInt(delta);
    }
    else if (fieldName == "mapWidth")
    {
        this->mapWidth = this->gameManager->unserializeInt(delta);
    }
    else if (fieldName == "maxCowboysPerJob")
    {
        this->maxCowboysPerJob = this->gameManager->unserializeInt(delta);
    }
    else if (fieldName == "maxTurns")
    {
        this->maxTurns = this->gameManager->unserializeInt(delta);
    }
    else if (fieldName == "players")
    {
        this->players = this->gameManager->unserializeVectorOfGameObjects<Saloon::Player*>(delta, &this->players);
    }
    else if (fieldName == "rowdinessToSiesta")
    {
        this->rowdinessToSiesta = this->gameManager->unserializeInt(delta);
    }
    else if (fieldName == "session")
    {
        this->session = this->gameManager->unserializeString(delta);
    }
    else if (fieldName == "sharpshooterDamage")
    {
        this->sharpshooterDamage = this->gameManager->unserializeInt(delta);
    }
    else if (fieldName == "siestaLength")
    {
        this->siestaLength = this->gameManager->unserializeInt(delta);
    }
    else if (fieldName == "tiles")
    {
        this->tiles = this->gameManager->unserializeVectorOfGameObjects<Saloon::Tile*>(delta, &this->tiles);
    }
    else if (fieldName == "turnsDrunk")
    {
        this->turnsDrunk = this->gameManager->unserializeInt(delta);
    }
}




// <<-- Creer-Merge: methods -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
// if you forward declared additional methods to the Game then you can code them here.
// <<-- /Creer-Merge: methods -->>

#include "baseGameManager.h"
#include "baseGame.h"
#include "baseGameObject.h"
#include "basePlayer.h"
#include "client.h"
#include <string>

Joueur::BaseGameManager::BaseGameManager(Joueur::BaseGame* game, Joueur::BaseAI* ai)
{
    this->game = game;
    this->ai = ai;
    this->client = Joueur::Client::getInstance();
    this->gameObjects = &(game->gameObjects);
    this->game->gameManager = this;
}

void Joueur::BaseGameManager::setConstants(boost::property_tree::ptree& constants)
{
    this->DELTA_LIST_LENGTH = constants.get_child("DELTA_ARRAY_LENGTH").data(); // TODO: update the ptree key when moved from ARRAY -> LIST
    this->DELTA_REMOVED = constants.get_child("DELTA_REMOVED").data();
}

void Joueur::BaseGameManager::setupAI(const std::string& playerID)
{
    this->basePlayer = dynamic_cast<Joueur::BasePlayer*>(this->getGameObject(playerID));
}

boost::property_tree::ptree* Joueur::BaseGameManager::orderAI(const std::string& order, boost::optional<boost::property_tree::ptree&> args)
{
    throw new std::exception("Joueur::BaseGameManager::orderAI should not be called directly");
}

// Serialization \\

boost::property_tree::ptree* Joueur::BaseGameManager::serialize(bool boolean)
{
    return new boost::property_tree::ptree(boolean ? "true" : "false");
}

boost::property_tree::ptree* Joueur::BaseGameManager::serialize(int number)
{
    return new boost::property_tree::ptree(std::to_string(number));
}

boost::property_tree::ptree* Joueur::BaseGameManager::serialize(float number)
{
    return new boost::property_tree::ptree(std::to_string(number));
}

boost::property_tree::ptree* Joueur::BaseGameManager::serialize(BaseGameObject* gameObject)
{
    boost::property_tree::ptree* node = new boost::property_tree::ptree();
    node->add_child("id", boost::property_tree::ptree(gameObject->id));

    return node;
}

// TODO: serialize List and Dictionary



// Delta Updating \\

void Joueur::BaseGameManager::deltaUpdate(boost::property_tree::ptree& delta)
{
    this->initGameObjects(delta);

    this->game->deltaUpdate(delta);
}

void Joueur::BaseGameManager::initGameObjects(boost::property_tree::ptree& delta)
{
    auto gameObjects = delta.get_child_optional("gameObjects");
    if (gameObjects)
    {
        for (auto kv : *gameObjects)
        {
            std::string id = kv.first;

            if (!this->hasGameObject(id)) // we've never heard of a game object with that id, so create it now!
            {
                const std::string gameObjectName = kv.second.get_child("gameObjectName").data();
                Joueur::BaseGameObject* newGameObject = this->createGameObject(gameObjectName);
                newGameObject->gameManager = this;
                this->gameObjects->insert(std::pair<std::string, Joueur::BaseGameObject*>(id, newGameObject));
            }
        }

        for (auto kv : *gameObjects)
        {
            const std::string id = kv.first;
            const std::string data = kv.second.data();
            if (data == this->DELTA_REMOVED)
            {
                (*this->gameObjects).erase(id);
            }
            else
            {
                (*this->gameObjects)[id]->deltaUpdate(kv.second);
            }
        }

        delta.erase("gameObjects");
    }
}

bool Joueur::BaseGameManager::hasGameObject(const std::string& id)
{
    return (this->gameObjects->find(id) != this->gameObjects->end());
}

Joueur::BaseGameObject* Joueur::BaseGameManager::createGameObject(const std::string& gameObjectName)
{
    throw new std::exception("Call to Joueur::BaseGameManager::createGameObject(str) is illegal!");
}

Joueur::BaseGameObject* Joueur::BaseGameManager::getGameObject(const std::string& id)
{
    if (this->hasGameObject(id))
    {
        return (*this->gameObjects)[id];
    }

    return nullptr;
}

bool Joueur::BaseGameManager::getDeltaBool(boost::property_tree::ptree& delta)
{
    return (delta.data() == "true");
}

int Joueur::BaseGameManager::getDeltaInt(boost::property_tree::ptree& delta)
{
    return stoi(delta.data());
}

float Joueur::BaseGameManager::getDeltaFloat(boost::property_tree::ptree& delta)
{
    return stof(delta.data());
}

std::string Joueur::BaseGameManager::getDeltaString(boost::property_tree::ptree& delta)
{
    auto data = delta.data();
    if (data == this->DELTA_REMOVED) {
        return "";
    }

    return data;
}

Joueur::BaseGameObject* Joueur::BaseGameManager::getDeltaGameObject(boost::property_tree::ptree& delta)
{
    if (delta.size() == 1 && delta.get_child_optional("id")) // then it's a game object reference
    {
        return this->getGameObject(delta.get_child("id").data());
    }

    return nullptr;
}

// setting lists
// TODO: none of this is DRY at all, currently can't figure out a type safe way to do it :P
std::vector<bool>& Joueur::BaseGameManager::getDeltaVector(boost::property_tree::ptree& delta, std::vector<bool>& list)
{
    this->resizeVectorFromDelta<bool>(list, delta);

    for (auto kv : delta)
    {
        unsigned int index = stoi(kv.first);
        if (index <= list.size())
        {
            list[index] = this->getDeltaBool(kv.second);
        }
    }

    return list;
}

std::vector<int>& Joueur::BaseGameManager::getDeltaVector(boost::property_tree::ptree& delta, std::vector<int>& list)
{
    this->resizeVectorFromDelta<int>(list, delta);

    for (auto kv : delta)
    {
        unsigned int index = stoi(kv.first);
        if (index <= list.size())
        {
            list[index] = this->getDeltaInt(kv.second);
        }
    }

    return list;
}

std::vector<float>& Joueur::BaseGameManager::getDeltaVector(boost::property_tree::ptree& delta, std::vector<float>& list)
{
    this->resizeVectorFromDelta<float>(list, delta);

    for (auto kv : delta)
    {
        unsigned int index = stoi(kv.first);
        if (index <= list.size())
        {
            list[index] = this->getDeltaFloat(kv.second);
        }
    }

    return list;
}

std::vector<std::string>& Joueur::BaseGameManager::getDeltaVector(boost::property_tree::ptree& delta, std::vector<std::string>& list)
{
    this->resizeVectorFromDelta<std::string>(list, delta);

    for (auto kv : delta)
    {
        unsigned int index = stoi(kv.first);
        if (index <= list.size())
        {
            list[index] = this->getDeltaString(kv.second);
        }
    }

    return list;
}


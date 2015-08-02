#include <boost/optional/optional.hpp>
#include "gameManager.h"
#include "baseGame.h"
#include "baseGameObject.h"
#include "client.h"

Joueur::GameManager::GameManager(Joueur::BaseGame* game)
{
    *this->game = *game;
    *this->client = *Joueur::Client::getInstance();
}

void Joueur::GameManager::setConstants(boost::property_tree::ptree& constants)
{
    this->DELTA_LIST_LENGTH = constants.get_child_optional("DELTA_ARRAY_LENGTH")->data();
    this->DELTA_REMOVED = constants.get_child_optional("DELTA_REMOVED")->data();
}

void Joueur::GameManager::deltaUpdate(boost::property_tree::ptree& delta)
{
    this->initGameObjects(delta);

    this->game->deltaUpdate(delta);
}

void Joueur::GameManager::initGameObjects(boost::property_tree::ptree& delta)
{
    auto gameObjects = delta.get_child_optional("gameObjects");
    if (gameObjects)
    {
        for (auto kv : *gameObjects)
        {
            const std::string id = kv.first;

            if (!this->hasGameObject(id)) // we've never heard of a game object with that id, so create it now!
            {
                const std::string gameObjectName = kv.second.get_child("gameObjectName").data();
                Joueur::BaseGameObject* newGameObject = this->createGameObject(gameObjectName);
                *newGameObject->gameManager = *this;
                (*this->gameObjects)[id] = newGameObject;
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

bool Joueur::GameManager::hasGameObject(const std::string& id)
{
    return (this->gameObjects->find(id) != this->gameObjects->end());
}

Joueur::BaseGameObject* Joueur::GameManager::createGameObject(const std::string& gameObjectName)
{
    throw new std::exception("Call to Joueur::GameManager::createGameObject(str) is illegal!");
}

Joueur::BaseGameObject* Joueur::GameManager::getGameObject(const std::string& id)
{
    if (this->hasGameObject(id))
    {
        return (*this->gameObjects)[id];
    }

    return nullptr;
}

bool Joueur::GameManager::getDeltaBool(boost::property_tree::ptree& delta)
{
    return (delta.data() == "true");
}

int Joueur::GameManager::getDeltaInt(boost::property_tree::ptree& delta)
{
    return stoi(delta.data());
}

float Joueur::GameManager::getDeltaFloat(boost::property_tree::ptree& delta)
{
    return stof(delta.data());
}

std::string Joueur::GameManager::getDeltaString(boost::property_tree::ptree& delta)
{
    auto data = delta.data();
    if (data == this->DELTA_REMOVED) {
        return "";
    }

    return data;
}

Joueur::BaseGameObject* Joueur::GameManager::getDeltaGameObject(boost::property_tree::ptree& delta)
{
    if (delta.size() == 1 && delta.get_child_optional("id")) // then it's a game object reference
    {
        return this->getGameObject(delta.get_child("id").data());
    }

    return nullptr;
}

// setting lists
// TODO: none of this is DRY at all, currently can't figure out a type safe way to do it :P
std::vector<bool>& Joueur::GameManager::getDeltaVector(boost::property_tree::ptree& delta, std::vector<bool>& list)
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

std::vector<int>& Joueur::GameManager::getDeltaVector(boost::property_tree::ptree& delta, std::vector<int>& list)
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

std::vector<float>& Joueur::GameManager::getDeltaVector(boost::property_tree::ptree& delta, std::vector<float>& list)
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

std::vector<std::string>& Joueur::GameManager::getDeltaVector(boost::property_tree::ptree& delta, std::vector<std::string>& list)
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


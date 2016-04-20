#include "baseGameManager.h"
#include "baseGame.h"
#include "baseGameObject.h"
#include "basePlayer.h"
#include "client.h"

void Joueur::BaseGameManager::setup(Joueur::BaseGame* game, Joueur::BaseAI* ai)
{
    this->game = game;
    this->ai = ai;
    this->client = Joueur::Client::getInstance();
    this->gameObjects = &(game->gameObjects);
    this->game->gameManager = this;
}

void Joueur::BaseGameManager::setConstants(boost::property_tree::ptree& constants)
{
    this->DELTA_LIST_LENGTH = constants.get_child("DELTA_LIST_LENGTH").data();
    this->DELTA_REMOVED = constants.get_child("DELTA_REMOVED").data();
}

void Joueur::BaseGameManager::setupAI(const std::string& playerID)
{
    this->basePlayer = dynamic_cast<Joueur::BasePlayer*>(this->getGameObject(playerID));
}

boost::property_tree::ptree* Joueur::BaseGameManager::orderAI(const std::string& order, boost::property_tree::ptree* args)
{
    throw new std::runtime_error("Joueur::BaseGameManager::orderAI should not be called directly");
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

boost::property_tree::ptree* Joueur::BaseGameManager::serialize(double number)
{
    return new boost::property_tree::ptree(std::to_string(number));
}

boost::property_tree::ptree* Joueur::BaseGameManager::serialize(std::string str)
{
    return new boost::property_tree::ptree(str);
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

std::vector<boost::property_tree::ptree*>* Joueur::BaseGameManager::getOrderArgsPtrees(boost::property_tree::ptree* args)
{
    auto ptrees = new std::vector<boost::property_tree::ptree*>;

    if (args != nullptr)
    {
        for (auto kv : *args)
        {
            ptrees->push_back(&kv.second);
        }
    }

    return ptrees;
}

bool Joueur::BaseGameManager::hasGameObject(const std::string& id)
{
    return (this->gameObjects->find(id) != this->gameObjects->end());
}

Joueur::BaseGameObject* Joueur::BaseGameManager::createGameObject(const std::string& gameObjectName)
{
    throw new std::runtime_error("Call to Joueur::BaseGameManager::createGameObject(str) is illegal!");
}

Joueur::BaseGameObject* Joueur::BaseGameManager::getGameObject(const std::string& id)
{
    if (this->hasGameObject(id))
    {
        return (*this->gameObjects)[id];
    }

    return nullptr;
}

boost::property_tree::ptree* Joueur::BaseGameManager::runOnServer(Joueur::BaseGameObject& caller, const std::string& functionName, boost::property_tree::ptree& args)
{
    boost::property_tree::ptree runData;
    runData.put_child("caller", *this->serialize(&caller));
    runData.put_child("functionName", *this->serialize(functionName));
    runData.put_child("args", args);

    this->client->send("run", runData);

    return client->waitForEvent("ran"); // blocks here until we get the data from the run event back from the server
}

bool Joueur::BaseGameManager::unserializeBool(boost::property_tree::ptree& ptree)
{
    return (ptree.data() == "true");
}

int Joueur::BaseGameManager::unserializeInt(boost::property_tree::ptree& ptree)
{
    return stoi(ptree.data());
}

double Joueur::BaseGameManager::unserializeDouble(boost::property_tree::ptree& ptree)
{
    return stod(ptree.data());
}

std::string Joueur::BaseGameManager::unserializeString(boost::property_tree::ptree& ptree)
{
    auto data = ptree.data();
    if (data == this->DELTA_REMOVED)
    {
        return "";
    }

    return data;
}

Joueur::BaseGameObject* Joueur::BaseGameManager::unserializeGameObject(boost::property_tree::ptree& ptree)
{
    if (&ptree != nullptr && ptree.size() == 1 && ptree.get_child_optional("id")) // then it's a game object reference
    {
        return this->getGameObject(ptree.get_child("id").data());
    }

    return nullptr;
}

// setting lists
// TODO: none of this is DRY at all, currently can't figure out a type safe way to do it :P
std::vector<bool>& Joueur::BaseGameManager::unserializeVector(boost::property_tree::ptree& delta, std::vector<bool>* list)
{
    list = this->resizeVectorFromDelta<bool>(list, delta);

    for (auto kv : delta)
    {
        unsigned int index = stoi(kv.first);
        if (index < list->size())
        {
            (*list)[index] = this->unserializeBool(kv.second);
        }
    }

    return *list;
}

std::vector<int>& Joueur::BaseGameManager::unserializeVector(boost::property_tree::ptree& delta, std::vector<int>* list)
{
    list = this->resizeVectorFromDelta<int>(list, delta);

    for (auto kv : delta)
    {
        unsigned int index = stoi(kv.first);
        if (index < list->size())
        {
            (*list)[index] = this->unserializeInt(kv.second);
        }
    }

    return *list;
}

std::vector<double>& Joueur::BaseGameManager::unserializeVector(boost::property_tree::ptree& delta, std::vector<double>* list)
{
    list = this->resizeVectorFromDelta<double>(list, delta);

    for (auto kv : delta)
    {
        unsigned int index = stoi(kv.first);
        if (index < list->size())
        {
            (*list)[index] = this->unserializeDouble(kv.second);
        }
    }

    return *list;
}

std::vector<std::string>& Joueur::BaseGameManager::unserializeVector(boost::property_tree::ptree& delta, std::vector<std::string>* list)
{
    list = this->resizeVectorFromDelta<std::string>(list, delta);

    for (auto kv : delta)
    {
        unsigned int index = stoi(kv.first);
        if (index < list->size())
        {
            (*list)[index] = this->unserializeString(kv.second);
        }
    }

    return *list;
}

#ifndef JOUEUR_GAMEMANAGER_H
#define JOUEUR_GAMEMANAGER_H

#include <string>
#include "joueur.h"
#include "client.h"

class Joueur::GameManager
{
    private:
        std::shared_ptr<std::map<std::string, BaseGameObject*>> gameObjects;
        std::string DELTA_LIST_LENGTH;
        std::string DELTA_REMOVED;

        bool hasGameObject(const std::string& id);

    protected:
        virtual BaseGameObject* createGameObject(const std::string& gameObjectName);
        std::shared_ptr<Joueur::Client> client;
        std::shared_ptr<Joueur::BaseGame> game;

    public:
        std::shared_ptr<Joueur::BasePlayer> basePlayer;
        GameManager(BaseGame* game);
        void setConstants(boost::property_tree::ptree& constants);

        virtual void setupAI(const std::string& playerID);
        virtual boost::property_tree::ptree* orderAI(const std::string& order, boost::optional<boost::property_tree::ptree&> args);

        void deltaUpdate(boost::property_tree::ptree& delta);
        void initGameObjects(boost::property_tree::ptree& delta);

        boost::property_tree::ptree* serialize(bool boolean);
        boost::property_tree::ptree* serialize(int number);
        boost::property_tree::ptree* serialize(float number);
        boost::property_tree::ptree* serialize(BaseGameObject* gameObject);

        Joueur::BaseGameObject* getGameObject(const std::string& id);
        bool getDeltaBool(boost::property_tree::ptree& delta);
        int getDeltaInt(boost::property_tree::ptree& delta);
        float getDeltaFloat(boost::property_tree::ptree& delta);
        std::string getDeltaString(boost::property_tree::ptree& delta);
        Joueur::BaseGameObject* getDeltaGameObject(boost::property_tree::ptree& delta);

        // vectors
        template<typename T> void resizeVectorFromDelta(std::vector<T>& list, boost::property_tree::ptree& delta);
        std::vector<bool>& getDeltaVector(boost::property_tree::ptree& delta, std::vector<bool>& list);
        std::vector<int>& getDeltaVector(boost::property_tree::ptree& delta, std::vector<int>& list);
        std::vector<float>& getDeltaVector(boost::property_tree::ptree& delta, std::vector<float>& list);
        std::vector<std::string>& getDeltaVector(boost::property_tree::ptree& delta, std::vector<std::string>& list);
        template<typename T> std::vector<T>& getDeltaVectorOfGameObjects(boost::property_tree::ptree& delta, std::vector<T>& list);

        // maps
        template<typename T> std::map<std::string, T>& getDeltaStringMapOfGameObjects(boost::property_tree::ptree& delta, std::map<std::string, T>& dict);
};

template<typename T>
void Joueur::GameManager::resizeVectorFromDelta(std::vector<T>& list, boost::property_tree::ptree& delta)
{
    int listLength = stoi(delta.get_child(this->DELTA_LIST_LENGTH).data());
    list.resize(listLength);
    delta.erase(this->DELTA_LIST_LENGTH);
}

template<typename T>
std::vector<T>& Joueur::GameManager::getDeltaVectorOfGameObjects(boost::property_tree::ptree& delta, std::vector<T>& list)
{
    this->resizeVectorFromDelta<T>(list, delta);

    for (auto kv : delta)
    {
        unsigned int index = stoi(kv.first);
        if (index <= list.size())
        {
            list[index] = (T)this->getDeltaGameObject(kv.second);
        }
    }

    return list;
}


template<typename T>
std::map<std::string, T>& Joueur::GameManager::getDeltaStringMapOfGameObjects(boost::property_tree::ptree& delta, std::map<std::string, T>& dict)
{
    for (auto kv : delta)
    {
        if (kv.second.data() == this->DELTA_REMOVED) {
            dict.erase(kv.first);
        }
        else {
            dict[kv.first] = (T)this->getDeltaGameObject(kv.second);
        }
    }

    return dict;
}

#endif

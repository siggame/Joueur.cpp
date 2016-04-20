#ifndef JOUEUR_BASEGAMEMANAGER_H
#define JOUEUR_BASEGAMEMANAGER_H

#include <string>
#include "joueur.h"
#include "client.h"

class Joueur::BaseGameManager
{
    private:
        std::map<std::string, BaseGameObject*>* gameObjects;
        std::string DELTA_LIST_LENGTH;
        std::string DELTA_REMOVED;

        bool hasGameObject(const std::string& id);

    protected:
        Joueur::Client* client;

        BaseGameManager() {};
        void setup(Joueur::BaseGame* game, Joueur::BaseAI* ai);
        virtual BaseGameObject* createGameObject(const std::string& gameObjectName);
        std::vector<boost::property_tree::ptree*>* getOrderArgsPtrees(boost::property_tree::ptree* args);

    public:
        Joueur::BaseGame* game;
        Joueur::BaseAI* ai;
        Joueur::BasePlayer* basePlayer;

        void setConstants(boost::property_tree::ptree& constants);

        virtual void setupAI(const std::string& playerID);
        virtual boost::property_tree::ptree* orderAI(const std::string& order, boost::property_tree::ptree* args);


        void deltaUpdate(boost::property_tree::ptree& ptree);
        void initGameObjects(boost::property_tree::ptree& ptree);
        boost::property_tree::ptree* runOnServer(Joueur::BaseGameObject& caller, const std::string& functionName, boost::property_tree::ptree& args);

        boost::property_tree::ptree* serialize(bool boolean);
        boost::property_tree::ptree* serialize(int number);
        boost::property_tree::ptree* serialize(double number);
        boost::property_tree::ptree* serialize(std::string str);
        boost::property_tree::ptree* serialize(BaseGameObject* gameObject);

        Joueur::BaseGameObject* getGameObject(const std::string& id);
        bool unserializeBool(boost::property_tree::ptree& ptree);
        int unserializeInt(boost::property_tree::ptree& ptree);
        double unserializeDouble(boost::property_tree::ptree& ptree);
        std::string unserializeString(boost::property_tree::ptree& ptree);
        Joueur::BaseGameObject* unserializeGameObject(boost::property_tree::ptree& ptree);

        // vectors
        template<typename T> std::vector<T>* resizeVectorFromDelta(std::vector<T>* list, boost::property_tree::ptree& ptree);
        std::vector<bool>& unserializeVector(boost::property_tree::ptree& ptree, std::vector<bool>* list);
        std::vector<int>& unserializeVector(boost::property_tree::ptree& ptree, std::vector<int>* list);
        std::vector<double>& unserializeVector(boost::property_tree::ptree& ptree, std::vector<double>* list);
        std::vector<std::string>& unserializeVector(boost::property_tree::ptree& ptree, std::vector<std::string>* list);
        template<typename T> std::vector<T>& unserializeVectorOfGameObjects(boost::property_tree::ptree& ptree, std::vector<T>* list);

        // maps
        template<typename T> std::map<std::string, T>& unserializeStringMapOfGameObjects(boost::property_tree::ptree& ptree, std::map<std::string, T>& dict);
};

template<typename T>
std::vector<T>* Joueur::BaseGameManager::resizeVectorFromDelta(std::vector<T>* list, boost::property_tree::ptree& ptree)
{
    if (list == nullptr)
    {
        list = new std::vector<T>();
    }

    int listLength = stoi(ptree.get_child(this->DELTA_LIST_LENGTH).data());
    list->resize(listLength);
    ptree.erase(this->DELTA_LIST_LENGTH);

    return list;
}

template<typename T>
std::vector<T>& Joueur::BaseGameManager::unserializeVectorOfGameObjects(boost::property_tree::ptree& ptree, std::vector<T>* list)
{
    list = this->resizeVectorFromDelta<T>(list, ptree);

    for (auto kv : ptree)
    {
        unsigned int index = stoi(kv.first);
        if (index < list->size())
        {
            (*list)[index] = (T)this->unserializeGameObject(kv.second);
        }
    }

    return *list;
}

// Maps are untested
template<typename T>
std::map<std::string, T>& Joueur::BaseGameManager::unserializeStringMapOfGameObjects(boost::property_tree::ptree& ptree, std::map<std::string, T>& dict)
{
    for (auto kv : ptree)
    {
        if (kv.second.data() == this->DELTA_REMOVED) {
            dict.erase(kv.first);
        }
        else {
            dict[kv.first] = (T)this->unserializeGameObject(kv.second);
        }
    }

    return dict;
}

#endif

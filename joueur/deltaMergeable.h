#ifndef JOUEUR_DELTAMERGEABLE_H
#define JOUEUR_DELTAMERGEABLE_H

#include <memory>
#include <vector>
#include "joueur.h"

class Joueur::DeltaMergeable
{
    friend Joueur::GameManager;

    public:
        std::shared_ptr<Joueur::GameManager> gameManager;

    private:
        void deltaUpdate(boost::property_tree::ptree& delta); // intended to be called by the GameManager, hidden to competitors

    protected:
        void virtual deltaUpdateField(const std::string& fieldName, boost::property_tree::ptree& delta);
};

#endif

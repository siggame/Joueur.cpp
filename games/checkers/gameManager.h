#ifndef CHECKERS_GAMEMANAGER_H
#define CHECKERS_GAMEMANAGER_H

#include "checkers.h"
#include "../../joueur/gameManager.h"

class Checkers::GameManager : public Joueur::GameManager
{
    Joueur::BaseGameObject* Checkers::GameManager::createGameObject(const std::string& gameObjectName);
};


#endif

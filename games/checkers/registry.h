#ifndef JOUEUR_CHECKERS_REGISTERY_H
#define JOUEUR_CHECKERS_REGISTERY_H

#include "../../joueur/baseGameManager.h"
#include "gameManager.h"

REGISTER_FUNCTION(gamesRegistry, Checkers, []() -> Joueur::BaseGameManager* { return new Checkers::GameManager(); })

#endif

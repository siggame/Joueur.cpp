#ifndef JOUEUR_ANARCHY_REGISTERY_H
#define JOUEUR_ANARCHY_REGISTERY_H

#include "../../joueur/baseGameManager.h"
#include "gameManager.h"

REGISTER_FUNCTION(gamesRegistry, Anarchy, []() -> Joueur::BaseGameManager* { return new Anarchy::GameManager(); })

#endif

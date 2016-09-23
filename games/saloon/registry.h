#ifndef JOUEUR_SALOON_REGISTERY_H
#define JOUEUR_SALOON_REGISTERY_H

#include "../../joueur/baseGameManager.h"
#include "gameManager.h"

REGISTER_FUNCTION(gamesRegistry, Saloon, []() -> Joueur::BaseGameManager* { return new Saloon::GameManager(); })

#endif

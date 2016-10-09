// This allows us to do a pre-compiler assisted version of Relflection
// DO NOT MODIFY THIS FILE
#ifndef JOUEUR_SALOON_REGISTERY_H
#define JOUEUR_SALOON_REGISTERY_H

#include "../../joueur/baseGameManager.h"
#include "gameManager.h"

REGISTER_FUNCTION(gamesRegistry, Saloon, []() -> Joueur::BaseGameManager* { return new Saloon::GameManager(); })

#endif

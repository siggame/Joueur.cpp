// This allows us to do a pre-compiler assisted version of Reflection
// DO NOT MODIFY THIS FILE
#ifndef JOUEUR_SPIDERS_REGISTERY_H
#define JOUEUR_SPIDERS_REGISTERY_H

#include "../../joueur/baseGameManager.h"
#include "gameManager.h"

REGISTER_FUNCTION(gamesRegistry, Spiders, []() -> Joueur::BaseGameManager* { return new Spiders::GameManager(); })

#endif

// This allows us to do a pre-compiler assisted version of Reflection
// DO NOT MODIFY THIS FILE
#ifndef JOUEUR_${game_name.upper()}_REGISTERY_H
#define JOUEUR_${game_name.upper()}_REGISTERY_H

#include "../../joueur/baseGameManager.h"
#include "gameManager.h"

REGISTER_FUNCTION(gamesRegistry, ${game_name}, []() -> Joueur::BaseGameManager* { return new ${game_name}::GameManager(); })

#endif

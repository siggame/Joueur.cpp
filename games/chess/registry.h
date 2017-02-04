// This allows us to do a pre-compiler assisted version of Reflection
// DO NOT MODIFY THIS FILE
#ifndef JOUEUR_CHESS_REGISTERY_H
#define JOUEUR_CHESS_REGISTERY_H

#include "../../joueur/baseGameManager.h"
#include "gameManager.h"

REGISTER_FUNCTION(gamesRegistry, Chess, []() -> Joueur::BaseGameManager* { return new Chess::GameManager(); })

#endif

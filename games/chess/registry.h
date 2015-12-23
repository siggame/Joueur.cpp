#ifndef JOUEUR_CHESS_REGISTERY_H
#define JOUEUR_CHESS_REGISTERY_H

#include "../../joueur/baseGameManager.h"
#include "gameManager.h"

REGISTER_FUNCTION(gamesRegistry, Chess, []() -> Joueur::BaseGameManager* { return new Chess::GameManager(); })

#endif

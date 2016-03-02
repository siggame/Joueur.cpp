#ifndef JOUEUR_SPIDERS_REGISTERY_H
#define JOUEUR_SPIDERS_REGISTERY_H

#include "../../joueur/baseGameManager.h"
#include "gameManager.h"

REGISTER_FUNCTION(gamesRegistry, Spiders, []() -> Joueur::BaseGameManager* { return new Spiders::GameManager(); })

#endif

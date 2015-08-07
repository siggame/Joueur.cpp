#ifndef CHECKERS_AI_H
#define CHECKERS_AI_H

#include "checkers.h"
#include "../../joueur/baseAI.h"

class Checkers::AI : public Joueur::BaseAI
{
    public:
        Checkers::Player* player;
        Checkers::Game* game;

        AI() {};
        std::string getName();
        void start();
        void ended(const bool& won, const std::string& reason);
        void gameUpdated();

        bool runTurn();
};

#endif

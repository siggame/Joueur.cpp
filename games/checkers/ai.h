#ifndef CHECKERS_AI_H
#define CHECKERS_AI_H

#include <string>

#include "checkers.h"
#include "../../joueur/baseAI.h"

class Checkers::AI : public Joueur::BaseAI
{
    public:
        AI() {};
        std::string getName();
};

#endif

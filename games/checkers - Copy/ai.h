#ifndef CHECKERS_AI_H
#define CHECKERS_AI_H

#include <string>

#include "checkers.h"
#include "../../joueur/baseAI.h"

using namespace std;

class Checkers::AI : Joueur::BaseAI
{
    public:
        AI() {};
        string getName();
};

#endif

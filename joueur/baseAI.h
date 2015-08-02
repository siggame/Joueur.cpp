#ifndef JOUEUR_BASEAI_H
#define JOUEUR_BASEAI_H

#include <string>

#include "joueur.h"

using namespace std;

class Joueur::BaseAI
{
    public:
        BaseAI() {};

        virtual string getName();
        void start();
        void ended(bool won, string reason);
        void ended();
        void gameUpdated();
        void* doOrder(string order /*someJsonObject data */);
};

#endif

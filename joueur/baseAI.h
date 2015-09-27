#ifndef JOUEUR_BASEAI_H
#define JOUEUR_BASEAI_H

#include "joueur.h"


class Joueur::BaseAI
{
    public:
        BaseAI() {};

        virtual std::string getName();
        virtual void start();
        virtual void ended(bool won, std::string reason);
        virtual void invalid(std::string message);
        virtual void gameUpdated();
};

#endif

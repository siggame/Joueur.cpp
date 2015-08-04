#ifndef JOUEUR_BASEAI_H
#define JOUEUR_BASEAI_H

#include <string>
#include <boost/optional/optional.hpp>
#include "joueur.h"


class Joueur::BaseAI
{
    public:
        BaseAI() {};

        virtual std::string getName();
        virtual void start();
        virtual void ended(const bool& won, const std::string& reason);
        virtual void gameUpdated();
};

#endif

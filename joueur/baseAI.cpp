#include "baseAI.h"
#include <iostream>

std::string Joueur::BaseAI::getName()
{
    return "C++ Player";
}

void Joueur::BaseAI::start()
{
    // empty, used as an interface function for competitiors
}

void Joueur::BaseAI::invalid(std::string message)
{
    std::cerr << "INVALID: " << message << std::endl;
    // used as an interface function for competitiors
}

void Joueur::BaseAI::gameUpdated()
{
    // empty, used as an interface function for competitiors
}

void Joueur::BaseAI::ended(bool won, std::string reason)
{
    // empty, used as an interface function for competitiors
}


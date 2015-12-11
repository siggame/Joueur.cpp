#include "baseAI.h"
#include "ansiColorCoder.h"
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
    // used as an interface function for competitiors
    std::cerr << Joueur::ANSIColorCoder::YellowText << "Invalid: " << message << Joueur::ANSIColorCoder::Reset << std::endl;
}

void Joueur::BaseAI::gameUpdated()
{
    // empty, used as an interface function for competitiors
}

void Joueur::BaseAI::ended(bool won, std::string reason)
{
    // empty, used as an interface function for competitiors
}


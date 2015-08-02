#ifndef CHECKERS_GAME_H
#define CHECKERS_GAME_H

#include "checkers.h"
#include "../../joueur/baseGame.h"

class Checkers::Game : public Joueur::BaseGame
{
    protected:
        virtual void deltaUpdateField(const std::string& fieldName, boost::property_tree::ptree& delta);

    public:
        Game();

        int boardHeight;
        int boardWidth;
        Checkers::Checker* checkerMoved;
        bool checkerMovedJumped;
        std::vector<Checkers::Checker*> checkers;
        Checkers::Player* currentPlayer;
        int currentTurn;
        int maxTurns;
        std::vector<Checkers::Player*> players;
        std::string session;
};


#endif

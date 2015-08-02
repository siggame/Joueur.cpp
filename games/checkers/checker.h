#ifndef CHECKERS_GAME_H
#define CHECKERS_GAME_H

#include "checkers.h"
#include "gameObject.h"
#include "player.h"

class Checkers::Checker : public Checkers::GameObject
{
    protected:
        virtual void deltaUpdateField(const std::string& fieldName, boost::property_tree::ptree& delta);

    public:
        bool kinged;
        Checkers::Player* owner;
        int x;
        int y;
};


#endif

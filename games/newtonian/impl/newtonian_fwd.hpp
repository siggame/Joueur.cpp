// DO NOT MODIFY THIS FILE
// Never try to directly create an instance of this class, or modify its member variables.
// This contains implementation details, written by code, and only useful to code

#ifndef GAMES_NEWTONIAN_FWD_H
#define GAMES_NEWTONIAN_FWD_H

//include declarations for all of the internal classes in the game's namespace
#include <memory>

namespace cpp_client
{

namespace newtonian
{


class Game_object_;
using Game_object = std::shared_ptr<Game_object_>;

class Job_;
using Job = std::shared_ptr<Job_>;

class Machine_;
using Machine = std::shared_ptr<Machine_>;

class Player_;
using Player = std::shared_ptr<Player_>;

class Tile_;
using Tile = std::shared_ptr<Tile_>;

class Unit_;
using Unit = std::shared_ptr<Unit_>;

class Game_;
using Game = Game_*;

}

}

#endif // GAMES_NEWTONIAN_H

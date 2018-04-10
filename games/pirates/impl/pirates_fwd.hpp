// DO NOT MODIFY THIS FILE
// Never try to directly create an instance of this class, or modify its member variables.
// This contains implementation details, written by code, and only useful to code

#ifndef GAMES_PIRATES_FWD_H
#define GAMES_PIRATES_FWD_H

//include declarations for all of the internal classes in the game's namespace
#include <memory>

namespace cpp_client
{

namespace pirates
{


class Game_object_;
using Game_object = std::shared_ptr<Game_object_>;

class Player_;
using Player = std::shared_ptr<Player_>;

class Port_;
using Port = std::shared_ptr<Port_>;

class Tile_;
using Tile = std::shared_ptr<Tile_>;

class Unit_;
using Unit = std::shared_ptr<Unit_>;

class Game_;
using Game = Game_*;

}

}

#endif // GAMES_PIRATES_H

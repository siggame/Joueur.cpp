// DO NOT MODIFY THIS FILE
// Never try to directly create an instance of this class, or modify its member variables.
// This contains implementation details, written by code, and only useful to code

#ifndef GAMES_COREMINER_FWD_H
#define GAMES_COREMINER_FWD_H

//include declarations for all of the internal classes in the game's namespace
#include <memory>

namespace cpp_client
{

namespace coreminer
{


class Bomb_;
using Bomb = std::shared_ptr<Bomb_>;

class Game_object_;
using Game_object = std::shared_ptr<Game_object_>;

class Miner_;
using Miner = std::shared_ptr<Miner_>;

class Player_;
using Player = std::shared_ptr<Player_>;

class Tile_;
using Tile = std::shared_ptr<Tile_>;

class Upgrade_;
using Upgrade = std::shared_ptr<Upgrade_>;

class Game_;
using Game = Game_*;

}

}

#endif // GAMES_COREMINER_H

// DO NOT MODIFY THIS FILE
// Never try to directly create an instance of this class, or modify its member variables.
// This contains implementation details, written by code, and only useful to code

#ifndef GAMES_STUMPED_FWD_H
#define GAMES_STUMPED_FWD_H

//include declarations for all of the internal classes in the game's namespace
#include <memory>

namespace cpp_client
{

namespace stumped
{


class Beaver_;
using Beaver = std::shared_ptr<Beaver_>;

class Game_object_;
using Game_object = std::shared_ptr<Game_object_>;

class Job_;
using Job = std::shared_ptr<Job_>;

class Player_;
using Player = std::shared_ptr<Player_>;

class Spawner_;
using Spawner = std::shared_ptr<Spawner_>;

class Tile_;
using Tile = std::shared_ptr<Tile_>;

class Game_;
using Game = Game_*;

}

}

#endif // GAMES_STUMPED_H

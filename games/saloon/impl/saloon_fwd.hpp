// DO NOT MODIFY THIS FILE
// Never try to directly create an instance of this class, or modify its member variables.
// This contains implementation details, written by code, and only useful to code

#ifndef GAMES_SALOON_FWD_H
#define GAMES_SALOON_FWD_H

//include declarations for all of the internal classes in the game's namespace
#include <memory>

namespace cpp_client
{

namespace saloon
{


class Bottle_;
using Bottle = std::shared_ptr<Bottle_>;

class Cowboy_;
using Cowboy = std::shared_ptr<Cowboy_>;

class Furnishing_;
using Furnishing = std::shared_ptr<Furnishing_>;

class Game_object_;
using Game_object = std::shared_ptr<Game_object_>;

class Player_;
using Player = std::shared_ptr<Player_>;

class Tile_;
using Tile = std::shared_ptr<Tile_>;

class Young_gun_;
using Young_gun = std::shared_ptr<Young_gun_>;

class Game_;
using Game = Game_*;

}

}

#endif // GAMES_SALOON_H

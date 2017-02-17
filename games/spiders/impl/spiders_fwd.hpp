// DO NOT MODIFY THIS FILE
// Never try to directly create an instance of this class, or modify its member variables.
// This contains implementation details, written by code, and only useful to code

#ifndef GAMES_SPIDERS_FWD_H
#define GAMES_SPIDERS_FWD_H

//include declarations for all of the internal classes in the game's namespace
#include <memory>

namespace cpp_client
{

namespace spiders
{


class Brood_mother_;
using Brood_mother = std::shared_ptr<Brood_mother_>;

class Cutter_;
using Cutter = std::shared_ptr<Cutter_>;

class Game_object_;
using Game_object = std::shared_ptr<Game_object_>;

class Nest_;
using Nest = std::shared_ptr<Nest_>;

class Player_;
using Player = std::shared_ptr<Player_>;

class Spider_;
using Spider = std::shared_ptr<Spider_>;

class Spiderling_;
using Spiderling = std::shared_ptr<Spiderling_>;

class Spitter_;
using Spitter = std::shared_ptr<Spitter_>;

class Weaver_;
using Weaver = std::shared_ptr<Weaver_>;

class Web_;
using Web = std::shared_ptr<Web_>;

class Game_;
using Game = Game_*;

}

}

#endif // GAMES_SPIDERS_H

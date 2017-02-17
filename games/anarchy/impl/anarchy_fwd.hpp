// DO NOT MODIFY THIS FILE
// Never try to directly create an instance of this class, or modify its member variables.
// This contains implementation details, written by code, and only useful to code

#ifndef GAMES_ANARCHY_FWD_H
#define GAMES_ANARCHY_FWD_H

//include declarations for all of the internal classes in the game's namespace
#include <memory>

namespace cpp_client
{

namespace anarchy
{


class Building_;
using Building = std::shared_ptr<Building_>;

class Fire_department_;
using Fire_department = std::shared_ptr<Fire_department_>;

class Forecast_;
using Forecast = std::shared_ptr<Forecast_>;

class Game_object_;
using Game_object = std::shared_ptr<Game_object_>;

class Player_;
using Player = std::shared_ptr<Player_>;

class Police_department_;
using Police_department = std::shared_ptr<Police_department_>;

class Warehouse_;
using Warehouse = std::shared_ptr<Warehouse_>;

class Weather_station_;
using Weather_station = std::shared_ptr<Weather_station_>;

class Game_;
using Game = Game_*;

}

}

#endif // GAMES_ANARCHY_H

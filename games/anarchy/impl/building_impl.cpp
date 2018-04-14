// DO NOT MODIFY THIS FILE
// Never try to directly create an instance of this class, or modify its member variables.
// This contains implementation details, written by code, and only useful to code



#include "../building.hpp"
#include "../../../joueur/src/base_ai.hpp"
#include "../../../joueur/src/any.hpp"
#include "../../../joueur/src/exceptions.hpp"
#include "../../../joueur/src/delta.hpp"
#include "../building.hpp"
#include "../fire_department.hpp"
#include "../forecast.hpp"
#include "../game_object.hpp"
#include "../player.hpp"
#include "../police_department.hpp"
#include "../warehouse.hpp"
#include "../weather_station.hpp"
#include "anarchy.hpp"

#include <type_traits>

namespace cpp_client
{

namespace anarchy
{


Building_::Building_(std::initializer_list<std::pair<std::string, Any&&>> init) :
    Game_object_{
        {"bribed", Any{std::decay<decltype(bribed)>::type{}}},
        {"buildingEast", Any{std::decay<decltype(building_east)>::type{}}},
        {"buildingNorth", Any{std::decay<decltype(building_north)>::type{}}},
        {"buildingSouth", Any{std::decay<decltype(building_south)>::type{}}},
        {"buildingWest", Any{std::decay<decltype(building_west)>::type{}}},
        {"fire", Any{std::decay<decltype(fire)>::type{}}},
        {"health", Any{std::decay<decltype(health)>::type{}}},
        {"isHeadquarters", Any{std::decay<decltype(is_headquarters)>::type{}}},
        {"owner", Any{std::decay<decltype(owner)>::type{}}},
        {"x", Any{std::decay<decltype(x)>::type{}}},
        {"y", Any{std::decay<decltype(y)>::type{}}},
    },
    bribed(variables_["bribed"].as<std::decay<decltype(bribed)>::type>()),
    building_east(variables_["buildingEast"].as<std::decay<decltype(building_east)>::type>()),
    building_north(variables_["buildingNorth"].as<std::decay<decltype(building_north)>::type>()),
    building_south(variables_["buildingSouth"].as<std::decay<decltype(building_south)>::type>()),
    building_west(variables_["buildingWest"].as<std::decay<decltype(building_west)>::type>()),
    fire(variables_["fire"].as<std::decay<decltype(fire)>::type>()),
    health(variables_["health"].as<std::decay<decltype(health)>::type>()),
    is_headquarters(variables_["isHeadquarters"].as<std::decay<decltype(is_headquarters)>::type>()),
    owner(variables_["owner"].as<std::decay<decltype(owner)>::type>()),
    x(variables_["x"].as<std::decay<decltype(x)>::type>()),
    y(variables_["y"].as<std::decay<decltype(y)>::type>())
{
    for(auto&& obj : init)
    {
      variables_.emplace(std::make_pair(std::move(obj.first), std::move(obj.second)));
    }
}

Building_::~Building_() = default;

void Building_::resize(const std::string& name, std::size_t size)
{
    try
    {
        Game_object_::resize(name, size);
        return;
    }
    catch(...){}
    throw Bad_manipulation(name + " in Building treated as a vector, but it is not a vector.");
}

void Building_::change_vec_values(const std::string& name, std::vector<std::pair<std::size_t, Any>>& values)
{
    try
    {
        Game_object_::change_vec_values(name, values);
        return;
    }
    catch(...){}
    throw Bad_manipulation(name + " in Building treated as a vector, but it is not a vector.");
}

void Building_::remove_key(const std::string& name, Any& key)
{
    try
    {
        Game_object_::remove_key(name, key);
        return;
    }
    catch(...){}
    throw Bad_manipulation(name + " in Building treated as a map, but it is not a map.");
}

std::unique_ptr<Any> Building_::add_key_value(const std::string& name, Any& key, Any& value)
{
    try
    {
        return Game_object_::add_key_value(name, key, value);
    }
    catch(...){}
    throw Bad_manipulation(name + " in Building treated as a map, but it is not a map.");
}

bool Building_::is_map(const std::string& name)
{
    try
    {
        return Game_object_::is_map(name);
    }
    catch(...){}
    return false;
}

void Building_::rebind_by_name(Any* to_change, const std::string& member, std::shared_ptr<Base_object> ref)
{
   if(member == "buildingEast")
   { 
      to_change->as<Building>() = std::static_pointer_cast<Building_>(ref);
      return;
   }
   if(member == "buildingNorth")
   { 
      to_change->as<Building>() = std::static_pointer_cast<Building_>(ref);
      return;
   }
   if(member == "buildingSouth")
   { 
      to_change->as<Building>() = std::static_pointer_cast<Building_>(ref);
      return;
   }
   if(member == "buildingWest")
   { 
      to_change->as<Building>() = std::static_pointer_cast<Building_>(ref);
      return;
   }
   if(member == "owner")
   { 
      to_change->as<Player>() = std::static_pointer_cast<Player_>(ref);
      return;
   }
   try
   {
      Game_object_::rebind_by_name(to_change, member, ref);
      return;
   }
   catch(...){}
   throw Bad_manipulation(member + " in Building treated as a reference, but it is not a reference.");
}


} // anarchy

} // cpp_client

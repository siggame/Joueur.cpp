// DO NOT MODIFY THIS FILE
// Never try to directly create an instance of this class, or modify its member variables.
// This contains implementation details, written by code, and only useful to code

#include "../tile.hpp"
#include "../../../joueur/src/base_ai.hpp"
#include "../../../joueur/src/any.hpp"
#include "../../../joueur/src/exceptions.hpp"
#include "../../../joueur/src/delta.hpp"
#include "../beaver.hpp"
#include "../game_object.hpp"
#include "../job.hpp"
#include "../player.hpp"
#include "../spawner.hpp"
#include "../tile.hpp"
#include "stumped.hpp"

#include <type_traits>

namespace cpp_client
{

namespace stumped
{


Tile_::Tile_(std::initializer_list<std::pair<std::string, Any&&>> init) :
    Game_object_{
        {"beaver", Any{std::decay<decltype(beaver)>::type{}}},
        {"branches", Any{std::decay<decltype(branches)>::type{}}},
        {"flowDirection", Any{std::decay<decltype(flow_direction)>::type{}}},
        {"food", Any{std::decay<decltype(food)>::type{}}},
        {"lodgeOwner", Any{std::decay<decltype(lodge_owner)>::type{}}},
        {"spawner", Any{std::decay<decltype(spawner)>::type{}}},
        {"tileEast", Any{std::decay<decltype(tile_east)>::type{}}},
        {"tileNorth", Any{std::decay<decltype(tile_north)>::type{}}},
        {"tileSouth", Any{std::decay<decltype(tile_south)>::type{}}},
        {"tileWest", Any{std::decay<decltype(tile_west)>::type{}}},
        {"type", Any{std::decay<decltype(type)>::type{}}},
        {"x", Any{std::decay<decltype(x)>::type{}}},
        {"y", Any{std::decay<decltype(y)>::type{}}},
    },
    beaver(variables_["beaver"].as<std::decay<decltype(beaver)>::type>()),
    branches(variables_["branches"].as<std::decay<decltype(branches)>::type>()),
    flow_direction(variables_["flowDirection"].as<std::decay<decltype(flow_direction)>::type>()),
    food(variables_["food"].as<std::decay<decltype(food)>::type>()),
    lodge_owner(variables_["lodgeOwner"].as<std::decay<decltype(lodge_owner)>::type>()),
    spawner(variables_["spawner"].as<std::decay<decltype(spawner)>::type>()),
    tile_east(variables_["tileEast"].as<std::decay<decltype(tile_east)>::type>()),
    tile_north(variables_["tileNorth"].as<std::decay<decltype(tile_north)>::type>()),
    tile_south(variables_["tileSouth"].as<std::decay<decltype(tile_south)>::type>()),
    tile_west(variables_["tileWest"].as<std::decay<decltype(tile_west)>::type>()),
    type(variables_["type"].as<std::decay<decltype(type)>::type>()),
    x(variables_["x"].as<std::decay<decltype(x)>::type>()),
    y(variables_["y"].as<std::decay<decltype(y)>::type>())
{
    for(auto&& obj : init)
    {
      variables_.emplace(std::make_pair(std::move(obj.first), std::move(obj.second)));
    }
}

Tile_::~Tile_() = default;

void Tile_::resize(const std::string& name, std::size_t size)
{
    try
    {
        Game_object_::resize(name, size);
        return;
    }
    catch(...){}
    throw Bad_manipulation(name + " in Tile treated as a vector, but it is not a vector.");
}

void Tile_::change_vec_values(const std::string& name, std::vector<std::pair<std::size_t, Any>>& values)
{
    try
    {
        Game_object_::change_vec_values(name, values);
        return;
    }
    catch(...){}
    throw Bad_manipulation(name + " in Tile treated as a vector, but it is not a vector.");
}

void Tile_::remove_key(const std::string& name, Any& key)
{
    try
    {
        Game_object_::remove_key(name, key);
        return;
    }
    catch(...){}
    throw Bad_manipulation(name + " in Tile treated as a map, but it is not a map.");
}

std::unique_ptr<Any> Tile_::add_key_value(const std::string& name, Any& key, Any& value)
{
    try
    {
        return Game_object_::add_key_value(name, key, value);
    }
    catch(...){}
    throw Bad_manipulation(name + " in Tile treated as a map, but it is not a map.");
}

bool Tile_::is_map(const std::string& name)
{
    try
    {
        return Game_object_::is_map(name);
    }
    catch(...){}
    return false;
}

void Tile_::rebind_by_name(Any* to_change, const std::string& member, std::shared_ptr<Base_object> ref)
{
   if(member == "beaver")
   { 
      to_change->as<Beaver>() = std::static_pointer_cast<Beaver_>(ref);
      return;
   }
   if(member == "lodgeOwner")
   { 
      to_change->as<Player>() = std::static_pointer_cast<Player_>(ref);
      return;
   }
   if(member == "spawner")
   { 
      to_change->as<Spawner>() = std::static_pointer_cast<Spawner_>(ref);
      return;
   }
   if(member == "tileEast")
   { 
      to_change->as<Tile>() = std::static_pointer_cast<Tile_>(ref);
      return;
   }
   if(member == "tileNorth")
   { 
      to_change->as<Tile>() = std::static_pointer_cast<Tile_>(ref);
      return;
   }
   if(member == "tileSouth")
   { 
      to_change->as<Tile>() = std::static_pointer_cast<Tile_>(ref);
      return;
   }
   if(member == "tileWest")
   { 
      to_change->as<Tile>() = std::static_pointer_cast<Tile_>(ref);
      return;
   }
   try
   {
      Game_object_::rebind_by_name(to_change, member, ref);
      return;
   }
   catch(...){}
   throw Bad_manipulation(member + " in Tile treated as a reference, but it is not a reference.");
}


} // stumped

} // cpp_client

// DO NOT MODIFY THIS FILE
// Never try to directly create an instance of this class, or modify its member variables.
// This contains implementation details, written by code, and only useful to code



#include "../furnishing.hpp"
#include "../../../joueur/src/base_ai.hpp"
#include "../../../joueur/src/any.hpp"
#include "../../../joueur/src/exceptions.hpp"
#include "../../../joueur/src/delta.hpp"
#include "../bottle.hpp"
#include "../cowboy.hpp"
#include "../furnishing.hpp"
#include "../game_object.hpp"
#include "../player.hpp"
#include "../tile.hpp"
#include "../young_gun.hpp"
#include "saloon.hpp"

#include <type_traits>

namespace cpp_client
{

namespace saloon
{


Furnishing_::Furnishing_(std::initializer_list<std::pair<std::string, Any&&>> init) :
    Game_object_{
        {"health", Any{std::decay<decltype(health)>::type{}}},
        {"isDestroyed", Any{std::decay<decltype(is_destroyed)>::type{}}},
        {"isPiano", Any{std::decay<decltype(is_piano)>::type{}}},
        {"isPlaying", Any{std::decay<decltype(is_playing)>::type{}}},
        {"tile", Any{std::decay<decltype(tile)>::type{}}},
    },
    health(variables_["health"].as<std::decay<decltype(health)>::type>()),
    is_destroyed(variables_["isDestroyed"].as<std::decay<decltype(is_destroyed)>::type>()),
    is_piano(variables_["isPiano"].as<std::decay<decltype(is_piano)>::type>()),
    is_playing(variables_["isPlaying"].as<std::decay<decltype(is_playing)>::type>()),
    tile(variables_["tile"].as<std::decay<decltype(tile)>::type>())
{
    for(auto&& obj : init)
    {
      variables_.emplace(std::make_pair(std::move(obj.first), std::move(obj.second)));
    }
}

Furnishing_::~Furnishing_() = default;

void Furnishing_::resize(const std::string& name, std::size_t size)
{
    try
    {
        Game_object_::resize(name, size);
        return;
    }
    catch(...){}
    throw Bad_manipulation(name + " in Furnishing treated as a vector, but it is not a vector.");
}

void Furnishing_::change_vec_values(const std::string& name, std::vector<std::pair<std::size_t, Any>>& values)
{
    try
    {
        Game_object_::change_vec_values(name, values);
        return;
    }
    catch(...){}
    throw Bad_manipulation(name + " in Furnishing treated as a vector, but it is not a vector.");
}

void Furnishing_::remove_key(const std::string& name, Any& key)
{
    try
    {
        Game_object_::remove_key(name, key);
        return;
    }
    catch(...){}
    throw Bad_manipulation(name + " in Furnishing treated as a map, but it is not a map.");
}

std::unique_ptr<Any> Furnishing_::add_key_value(const std::string& name, Any& key, Any& value)
{
    try
    {
        return Game_object_::add_key_value(name, key, value);
    }
    catch(...){}
    throw Bad_manipulation(name + " in Furnishing treated as a map, but it is not a map.");
}

bool Furnishing_::is_map(const std::string& name)
{
    try
    {
        return Game_object_::is_map(name);
    }
    catch(...){}
    return false;
}

void Furnishing_::rebind_by_name(Any* to_change, const std::string& member, std::shared_ptr<Base_object> ref)
{
   if(member == "tile")
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
   throw Bad_manipulation(member + " in Furnishing treated as a reference, but it is not a reference.");
}


} // saloon

} // cpp_client

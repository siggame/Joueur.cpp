// DO NOT MODIFY THIS FILE
// Never try to directly create an instance of this class, or modify its member variables.
// This contains implementation details, written by code, and only useful to code



#include "../tile.hpp"
#include "../../../joueur/src/base_ai.hpp"
#include "../../../joueur/src/any.hpp"
#include "../../../joueur/src/exceptions.hpp"
#include "../../../joueur/src/delta.hpp"
#include "../bomb.hpp"
#include "../game_object.hpp"
#include "../miner.hpp"
#include "../player.hpp"
#include "../tile.hpp"
#include "../upgrade.hpp"
#include "coreminer.hpp"

#include <type_traits>

namespace cpp_client
{

namespace coreminer
{


Tile_::Tile_(std::initializer_list<std::pair<std::string, Any&&>> init) :
    Game_object_{
        {"bombs", Any{std::decay<decltype(bombs)>::type{}}},
        {"dirt", Any{std::decay<decltype(dirt)>::type{}}},
        {"isBase", Any{std::decay<decltype(is_base)>::type{}}},
        {"isFalling", Any{std::decay<decltype(is_falling)>::type{}}},
        {"isHopper", Any{std::decay<decltype(is_hopper)>::type{}}},
        {"isLadder", Any{std::decay<decltype(is_ladder)>::type{}}},
        {"isSupport", Any{std::decay<decltype(is_support)>::type{}}},
        {"miners", Any{std::decay<decltype(miners)>::type{}}},
        {"ore", Any{std::decay<decltype(ore)>::type{}}},
        {"owner", Any{std::decay<decltype(owner)>::type{}}},
        {"shielding", Any{std::decay<decltype(shielding)>::type{}}},
        {"tileEast", Any{std::decay<decltype(tile_east)>::type{}}},
        {"tileNorth", Any{std::decay<decltype(tile_north)>::type{}}},
        {"tileSouth", Any{std::decay<decltype(tile_south)>::type{}}},
        {"tileWest", Any{std::decay<decltype(tile_west)>::type{}}},
        {"x", Any{std::decay<decltype(x)>::type{}}},
        {"y", Any{std::decay<decltype(y)>::type{}}},
    },
    bombs(variables_["bombs"].as<std::decay<decltype(bombs)>::type>()),
    dirt(variables_["dirt"].as<std::decay<decltype(dirt)>::type>()),
    is_base(variables_["isBase"].as<std::decay<decltype(is_base)>::type>()),
    is_falling(variables_["isFalling"].as<std::decay<decltype(is_falling)>::type>()),
    is_hopper(variables_["isHopper"].as<std::decay<decltype(is_hopper)>::type>()),
    is_ladder(variables_["isLadder"].as<std::decay<decltype(is_ladder)>::type>()),
    is_support(variables_["isSupport"].as<std::decay<decltype(is_support)>::type>()),
    miners(variables_["miners"].as<std::decay<decltype(miners)>::type>()),
    ore(variables_["ore"].as<std::decay<decltype(ore)>::type>()),
    owner(variables_["owner"].as<std::decay<decltype(owner)>::type>()),
    shielding(variables_["shielding"].as<std::decay<decltype(shielding)>::type>()),
    tile_east(variables_["tileEast"].as<std::decay<decltype(tile_east)>::type>()),
    tile_north(variables_["tileNorth"].as<std::decay<decltype(tile_north)>::type>()),
    tile_south(variables_["tileSouth"].as<std::decay<decltype(tile_south)>::type>()),
    tile_west(variables_["tileWest"].as<std::decay<decltype(tile_west)>::type>()),
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
    if(name == "bombs")
    {
        auto& vec = variables_["bombs"].as<std::decay<decltype(bombs)>::type>();
        vec.resize(size);
        return;
    }
    else if(name == "miners")
    {
        auto& vec = variables_["miners"].as<std::decay<decltype(miners)>::type>();
        vec.resize(size);
        return;
    }
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
    if(name == "bombs")
    {
        using type = std::decay<decltype(bombs)>::type;
        auto& vec = variables_["bombs"].as<type>();
        for(auto&& val : values)
        { 
            vec[val.first] = std::static_pointer_cast<type::value_type::element_type>(get_game()->get_objects()[val.second.as<std::string>()]);
        }
        return;
    } 
    else if(name == "miners")
    {
        using type = std::decay<decltype(miners)>::type;
        auto& vec = variables_["miners"].as<type>();
        for(auto&& val : values)
        { 
            vec[val.first] = std::static_pointer_cast<type::value_type::element_type>(get_game()->get_objects()[val.second.as<std::string>()]);
        }
        return;
    } 
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
   if(member == "owner")
   { 
      to_change->as<Player>() = std::static_pointer_cast<Player_>(ref);
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


} // coreminer

} // cpp_client

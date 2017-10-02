// DO NOT MODIFY THIS FILE
// Never try to directly create an instance of this class, or modify its member variables.
// This contains implementation details, written by code, and only useful to code



#include "../structure.hpp"
#include "../../../joueur/src/base_ai.hpp"
#include "../../../joueur/src/any.hpp"
#include "../../../joueur/src/exceptions.hpp"
#include "../../../joueur/src/delta.hpp"
#include "../game_object.hpp"
#include "../job.hpp"
#include "../player.hpp"
#include "../structure.hpp"
#include "../tile.hpp"
#include "../unit.hpp"
#include "catastrophe.hpp"

#include <type_traits>

namespace cpp_client
{

namespace catastrophe
{


Structure_::Structure_(std::initializer_list<std::pair<std::string, Any&&>> init) :
    Game_object_{
        {"effectRadius", Any{std::decay<decltype(effect_radius)>::type{}}},
        {"materials", Any{std::decay<decltype(materials)>::type{}}},
        {"owner", Any{std::decay<decltype(owner)>::type{}}},
        {"tile", Any{std::decay<decltype(tile)>::type{}}},
        {"type", Any{std::decay<decltype(type)>::type{}}},
    },
    effect_radius(variables_["effectRadius"].as<std::decay<decltype(effect_radius)>::type>()),
    materials(variables_["materials"].as<std::decay<decltype(materials)>::type>()),
    owner(variables_["owner"].as<std::decay<decltype(owner)>::type>()),
    tile(variables_["tile"].as<std::decay<decltype(tile)>::type>()),
    type(variables_["type"].as<std::decay<decltype(type)>::type>())
{
    for(auto&& obj : init)
    {
      variables_.emplace(std::make_pair(std::move(obj.first), std::move(obj.second)));
    }
}

Structure_::~Structure_() = default;

void Structure_::resize(const std::string& name, std::size_t size)
{
    try
    {
        Game_object_::resize(name, size);
        return;
    }
    catch(...){}
    throw Bad_manipulation(name + " in Structure treated as a vector, but it is not a vector.");
}

void Structure_::change_vec_values(const std::string& name, std::vector<std::pair<std::size_t, Any>>& values)
{
    try
    {
        Game_object_::change_vec_values(name, values);
        return;
    }
    catch(...){}
    throw Bad_manipulation(name + " in Structure treated as a vector, but it is not a vector.");
}

void Structure_::remove_key(const std::string& name, Any& key)
{
    try
    {
        Game_object_::remove_key(name, key);
        return;
    }
    catch(...){}
    throw Bad_manipulation(name + " in Structure treated as a map, but it is not a map.");
}

std::unique_ptr<Any> Structure_::add_key_value(const std::string& name, Any& key, Any& value)
{
    try
    {
        return Game_object_::add_key_value(name, key, value);
    }
    catch(...){}
    throw Bad_manipulation(name + " in Structure treated as a map, but it is not a map.");
}

bool Structure_::is_map(const std::string& name)
{
    try
    {
        return Game_object_::is_map(name);
    }
    catch(...){}
    return false;
}

void Structure_::rebind_by_name(Any* to_change, const std::string& member, std::shared_ptr<Base_object> ref)
{
   if(member == "owner")
   { 
      to_change->as<Player>() = std::static_pointer_cast<Player_>(ref);
      return;
   }
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
   throw Bad_manipulation(member + " in Structure treated as a reference, but it is not a reference.");
}


} // catastrophe

} // cpp_client

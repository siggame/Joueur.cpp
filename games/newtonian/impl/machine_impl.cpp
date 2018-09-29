// DO NOT MODIFY THIS FILE
// Never try to directly create an instance of this class, or modify its member variables.
// This contains implementation details, written by code, and only useful to code



#include "../machine.hpp"
#include "../../../joueur/src/base_ai.hpp"
#include "../../../joueur/src/any.hpp"
#include "../../../joueur/src/exceptions.hpp"
#include "../../../joueur/src/delta.hpp"
#include "../game_object.hpp"
#include "../job.hpp"
#include "../machine.hpp"
#include "../player.hpp"
#include "../tile.hpp"
#include "../unit.hpp"
#include "newtonian.hpp"

#include <type_traits>

namespace cpp_client
{

namespace newtonian
{


Machine_::Machine_(std::initializer_list<std::pair<std::string, Any&&>> init) :
    Game_object_{
        {"oreType", Any{std::decay<decltype(ore_type)>::type{}}},
        {"refineInput", Any{std::decay<decltype(refine_input)>::type{}}},
        {"refineOutput", Any{std::decay<decltype(refine_output)>::type{}}},
        {"refineTime", Any{std::decay<decltype(refine_time)>::type{}}},
        {"tile", Any{std::decay<decltype(tile)>::type{}}},
        {"worked", Any{std::decay<decltype(worked)>::type{}}},
    },
    ore_type(variables_["oreType"].as<std::decay<decltype(ore_type)>::type>()),
    refine_input(variables_["refineInput"].as<std::decay<decltype(refine_input)>::type>()),
    refine_output(variables_["refineOutput"].as<std::decay<decltype(refine_output)>::type>()),
    refine_time(variables_["refineTime"].as<std::decay<decltype(refine_time)>::type>()),
    tile(variables_["tile"].as<std::decay<decltype(tile)>::type>()),
    worked(variables_["worked"].as<std::decay<decltype(worked)>::type>())
{
    for(auto&& obj : init)
    {
      variables_.emplace(std::make_pair(std::move(obj.first), std::move(obj.second)));
    }
}

Machine_::~Machine_() = default;

void Machine_::resize(const std::string& name, std::size_t size)
{
    try
    {
        Game_object_::resize(name, size);
        return;
    }
    catch(...){}
    throw Bad_manipulation(name + " in Machine treated as a vector, but it is not a vector.");
}

void Machine_::change_vec_values(const std::string& name, std::vector<std::pair<std::size_t, Any>>& values)
{
    try
    {
        Game_object_::change_vec_values(name, values);
        return;
    }
    catch(...){}
    throw Bad_manipulation(name + " in Machine treated as a vector, but it is not a vector.");
}

void Machine_::remove_key(const std::string& name, Any& key)
{
    try
    {
        Game_object_::remove_key(name, key);
        return;
    }
    catch(...){}
    throw Bad_manipulation(name + " in Machine treated as a map, but it is not a map.");
}

std::unique_ptr<Any> Machine_::add_key_value(const std::string& name, Any& key, Any& value)
{
    try
    {
        return Game_object_::add_key_value(name, key, value);
    }
    catch(...){}
    throw Bad_manipulation(name + " in Machine treated as a map, but it is not a map.");
}

bool Machine_::is_map(const std::string& name)
{
    try
    {
        return Game_object_::is_map(name);
    }
    catch(...){}
    return false;
}

void Machine_::rebind_by_name(Any* to_change, const std::string& member, std::shared_ptr<Base_object> ref)
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
   throw Bad_manipulation(member + " in Machine treated as a reference, but it is not a reference.");
}


} // newtonian

} // cpp_client

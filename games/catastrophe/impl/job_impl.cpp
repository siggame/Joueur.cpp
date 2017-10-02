// DO NOT MODIFY THIS FILE
// Never try to directly create an instance of this class, or modify its member variables.
// This contains implementation details, written by code, and only useful to code



#include "../job.hpp"
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


Job_::Job_(std::initializer_list<std::pair<std::string, Any&&>> init) :
    Game_object_{
        {"actionCost", Any{std::decay<decltype(action_cost)>::type{}}},
        {"carryLimit", Any{std::decay<decltype(carry_limit)>::type{}}},
        {"moves", Any{std::decay<decltype(moves)>::type{}}},
        {"regenRate", Any{std::decay<decltype(regen_rate)>::type{}}},
        {"title", Any{std::decay<decltype(title)>::type{}}},
        {"upkeep", Any{std::decay<decltype(upkeep)>::type{}}},
    },
    action_cost(variables_["actionCost"].as<std::decay<decltype(action_cost)>::type>()),
    carry_limit(variables_["carryLimit"].as<std::decay<decltype(carry_limit)>::type>()),
    moves(variables_["moves"].as<std::decay<decltype(moves)>::type>()),
    regen_rate(variables_["regenRate"].as<std::decay<decltype(regen_rate)>::type>()),
    title(variables_["title"].as<std::decay<decltype(title)>::type>()),
    upkeep(variables_["upkeep"].as<std::decay<decltype(upkeep)>::type>())
{
    for(auto&& obj : init)
    {
      variables_.emplace(std::make_pair(std::move(obj.first), std::move(obj.second)));
    }
}

Job_::~Job_() = default;

void Job_::resize(const std::string& name, std::size_t size)
{
    try
    {
        Game_object_::resize(name, size);
        return;
    }
    catch(...){}
    throw Bad_manipulation(name + " in Job treated as a vector, but it is not a vector.");
}

void Job_::change_vec_values(const std::string& name, std::vector<std::pair<std::size_t, Any>>& values)
{
    try
    {
        Game_object_::change_vec_values(name, values);
        return;
    }
    catch(...){}
    throw Bad_manipulation(name + " in Job treated as a vector, but it is not a vector.");
}

void Job_::remove_key(const std::string& name, Any& key)
{
    try
    {
        Game_object_::remove_key(name, key);
        return;
    }
    catch(...){}
    throw Bad_manipulation(name + " in Job treated as a map, but it is not a map.");
}

std::unique_ptr<Any> Job_::add_key_value(const std::string& name, Any& key, Any& value)
{
    try
    {
        return Game_object_::add_key_value(name, key, value);
    }
    catch(...){}
    throw Bad_manipulation(name + " in Job treated as a map, but it is not a map.");
}

bool Job_::is_map(const std::string& name)
{
    try
    {
        return Game_object_::is_map(name);
    }
    catch(...){}
    return false;
}

void Job_::rebind_by_name(Any* to_change, const std::string& member, std::shared_ptr<Base_object> ref)
{
   try
   {
      Game_object_::rebind_by_name(to_change, member, ref);
      return;
   }
   catch(...){}
   throw Bad_manipulation(member + " in Job treated as a reference, but it is not a reference.");
}


} // catastrophe

} // cpp_client

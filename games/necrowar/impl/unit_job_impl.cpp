// DO NOT MODIFY THIS FILE
// Never try to directly create an instance of this class, or modify its member variables.
// This contains implementation details, written by code, and only useful to code



#include "../unit_job.hpp"
#include "../../../joueur/src/base_ai.hpp"
#include "../../../joueur/src/any.hpp"
#include "../../../joueur/src/exceptions.hpp"
#include "../../../joueur/src/delta.hpp"
#include "../game_object.hpp"
#include "../player.hpp"
#include "../tile.hpp"
#include "../tower.hpp"
#include "../tower_job.hpp"
#include "../unit.hpp"
#include "../unit_job.hpp"
#include "necrowar.hpp"

#include <type_traits>

namespace cpp_client
{

namespace necrowar
{


Unit_job_::Unit_job_(std::initializer_list<std::pair<std::string, Any&&>> init) :
    Game_object_{
        {"damage", Any{std::decay<decltype(damage)>::type{}}},
        {"goldCost", Any{std::decay<decltype(gold_cost)>::type{}}},
        {"health", Any{std::decay<decltype(health)>::type{}}},
        {"manaCost", Any{std::decay<decltype(mana_cost)>::type{}}},
        {"moves", Any{std::decay<decltype(moves)>::type{}}},
        {"perTile", Any{std::decay<decltype(per_tile)>::type{}}},
        {"range", Any{std::decay<decltype(range)>::type{}}},
        {"title", Any{std::decay<decltype(title)>::type{}}},
    },
    damage(variables_["damage"].as<std::decay<decltype(damage)>::type>()),
    gold_cost(variables_["goldCost"].as<std::decay<decltype(gold_cost)>::type>()),
    health(variables_["health"].as<std::decay<decltype(health)>::type>()),
    mana_cost(variables_["manaCost"].as<std::decay<decltype(mana_cost)>::type>()),
    moves(variables_["moves"].as<std::decay<decltype(moves)>::type>()),
    per_tile(variables_["perTile"].as<std::decay<decltype(per_tile)>::type>()),
    range(variables_["range"].as<std::decay<decltype(range)>::type>()),
    title(variables_["title"].as<std::decay<decltype(title)>::type>())
{
    for(auto&& obj : init)
    {
      variables_.emplace(std::make_pair(std::move(obj.first), std::move(obj.second)));
    }
}

Unit_job_::~Unit_job_() = default;

void Unit_job_::resize(const std::string& name, std::size_t size)
{
    try
    {
        Game_object_::resize(name, size);
        return;
    }
    catch(...){}
    throw Bad_manipulation(name + " in Unit_job treated as a vector, but it is not a vector.");
}

void Unit_job_::change_vec_values(const std::string& name, std::vector<std::pair<std::size_t, Any>>& values)
{
    try
    {
        Game_object_::change_vec_values(name, values);
        return;
    }
    catch(...){}
    throw Bad_manipulation(name + " in Unit_job treated as a vector, but it is not a vector.");
}

void Unit_job_::remove_key(const std::string& name, Any& key)
{
    try
    {
        Game_object_::remove_key(name, key);
        return;
    }
    catch(...){}
    throw Bad_manipulation(name + " in Unit_job treated as a map, but it is not a map.");
}

std::unique_ptr<Any> Unit_job_::add_key_value(const std::string& name, Any& key, Any& value)
{
    try
    {
        return Game_object_::add_key_value(name, key, value);
    }
    catch(...){}
    throw Bad_manipulation(name + " in Unit_job treated as a map, but it is not a map.");
}

bool Unit_job_::is_map(const std::string& name)
{
    try
    {
        return Game_object_::is_map(name);
    }
    catch(...){}
    return false;
}

void Unit_job_::rebind_by_name(Any* to_change, const std::string& member, std::shared_ptr<Base_object> ref)
{
   try
   {
      Game_object_::rebind_by_name(to_change, member, ref);
      return;
   }
   catch(...){}
   throw Bad_manipulation(member + " in Unit_job treated as a reference, but it is not a reference.");
}


} // necrowar

} // cpp_client

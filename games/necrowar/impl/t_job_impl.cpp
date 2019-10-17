// DO NOT MODIFY THIS FILE
// Never try to directly create an instance of this class, or modify its member variables.
// This contains implementation details, written by code, and only useful to code



#include "../t_job.hpp"
#include "../../../joueur/src/base_ai.hpp"
#include "../../../joueur/src/any.hpp"
#include "../../../joueur/src/exceptions.hpp"
#include "../../../joueur/src/delta.hpp"
#include "../game_object.hpp"
#include "../player.hpp"
#include "../tile.hpp"
#include "../tower.hpp"
#include "../unit.hpp"
#include "../t_job.hpp"
#include "../u_job.hpp"
#include "necrowar.hpp"

#include <type_traits>

namespace cpp_client
{

namespace necrowar
{


T_job_::T_job_(std::initializer_list<std::pair<std::string, Any&&>> init) :
    Game_object_{
        {"allUnits", Any{std::decay<decltype(all_units)>::type{}}},
        {"damageVsAbomination", Any{std::decay<decltype(damage_vs_abomination)>::type{}}},
        {"damageVsGhoul", Any{std::decay<decltype(damage_vs_ghoul)>::type{}}},
        {"damageVsHorseman", Any{std::decay<decltype(damage_vs_horseman)>::type{}}},
        {"damageVsHound", Any{std::decay<decltype(damage_vs_hound)>::type{}}},
        {"damageVsWraith", Any{std::decay<decltype(damage_vs_wraith)>::type{}}},
        {"damageVsZombie", Any{std::decay<decltype(damage_vs_zombie)>::type{}}},
        {"goldCost", Any{std::decay<decltype(gold_cost)>::type{}}},
        {"health", Any{std::decay<decltype(health)>::type{}}},
        {"manaCost", Any{std::decay<decltype(mana_cost)>::type{}}},
        {"range", Any{std::decay<decltype(range)>::type{}}},
        {"title", Any{std::decay<decltype(title)>::type{}}},
        {"turnsBetweenAttacks", Any{std::decay<decltype(turns_between_attacks)>::type{}}},
    },
    all_units(variables_["allUnits"].as<std::decay<decltype(all_units)>::type>()),
    damage_vs_abomination(variables_["damageVsAbomination"].as<std::decay<decltype(damage_vs_abomination)>::type>()),
    damage_vs_ghoul(variables_["damageVsGhoul"].as<std::decay<decltype(damage_vs_ghoul)>::type>()),
    damage_vs_horseman(variables_["damageVsHorseman"].as<std::decay<decltype(damage_vs_horseman)>::type>()),
    damage_vs_hound(variables_["damageVsHound"].as<std::decay<decltype(damage_vs_hound)>::type>()),
    damage_vs_wraith(variables_["damageVsWraith"].as<std::decay<decltype(damage_vs_wraith)>::type>()),
    damage_vs_zombie(variables_["damageVsZombie"].as<std::decay<decltype(damage_vs_zombie)>::type>()),
    gold_cost(variables_["goldCost"].as<std::decay<decltype(gold_cost)>::type>()),
    health(variables_["health"].as<std::decay<decltype(health)>::type>()),
    mana_cost(variables_["manaCost"].as<std::decay<decltype(mana_cost)>::type>()),
    range(variables_["range"].as<std::decay<decltype(range)>::type>()),
    title(variables_["title"].as<std::decay<decltype(title)>::type>()),
    turns_between_attacks(variables_["turnsBetweenAttacks"].as<std::decay<decltype(turns_between_attacks)>::type>())
{
    for(auto&& obj : init)
    {
      variables_.emplace(std::make_pair(std::move(obj.first), std::move(obj.second)));
    }
}

T_job_::~T_job_() = default;

void T_job_::resize(const std::string& name, std::size_t size)
{
    try
    {
        Game_object_::resize(name, size);
        return;
    }
    catch(...){}
    throw Bad_manipulation(name + " in T_job treated as a vector, but it is not a vector.");
}

void T_job_::change_vec_values(const std::string& name, std::vector<std::pair<std::size_t, Any>>& values)
{
    try
    {
        Game_object_::change_vec_values(name, values);
        return;
    }
    catch(...){}
    throw Bad_manipulation(name + " in T_job treated as a vector, but it is not a vector.");
}

void T_job_::remove_key(const std::string& name, Any& key)
{
    try
    {
        Game_object_::remove_key(name, key);
        return;
    }
    catch(...){}
    throw Bad_manipulation(name + " in T_job treated as a map, but it is not a map.");
}

std::unique_ptr<Any> T_job_::add_key_value(const std::string& name, Any& key, Any& value)
{
    try
    {
        return Game_object_::add_key_value(name, key, value);
    }
    catch(...){}
    throw Bad_manipulation(name + " in T_job treated as a map, but it is not a map.");
}

bool T_job_::is_map(const std::string& name)
{
    try
    {
        return Game_object_::is_map(name);
    }
    catch(...){}
    return false;
}

void T_job_::rebind_by_name(Any* to_change, const std::string& member, std::shared_ptr<Base_object> ref)
{
   try
   {
      Game_object_::rebind_by_name(to_change, member, ref);
      return;
   }
   catch(...){}
   throw Bad_manipulation(member + " in T_job treated as a reference, but it is not a reference.");
}


} // necrowar

} // cpp_client
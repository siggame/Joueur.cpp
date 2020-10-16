// DO NOT MODIFY THIS FILE
// Never try to directly create an instance of this class, or modify its member variables.
// This contains implementation details, written by code, and only useful to code



#include "../upgrade.hpp"
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


Upgrade_::Upgrade_(std::initializer_list<std::pair<std::string, Any&&>> init) :
    Game_object_{
        {"cargoCapacity", Any{std::decay<decltype(cargo_capacity)>::type{}}},
        {"health", Any{std::decay<decltype(health)>::type{}}},
        {"miningPower", Any{std::decay<decltype(mining_power)>::type{}}},
        {"moves", Any{std::decay<decltype(moves)>::type{}}},
        {"title", Any{std::decay<decltype(title)>::type{}}},
    },
    cargo_capacity(variables_["cargoCapacity"].as<std::decay<decltype(cargo_capacity)>::type>()),
    health(variables_["health"].as<std::decay<decltype(health)>::type>()),
    mining_power(variables_["miningPower"].as<std::decay<decltype(mining_power)>::type>()),
    moves(variables_["moves"].as<std::decay<decltype(moves)>::type>()),
    title(variables_["title"].as<std::decay<decltype(title)>::type>())
{
    for(auto&& obj : init)
    {
      variables_.emplace(std::make_pair(std::move(obj.first), std::move(obj.second)));
    }
}

Upgrade_::~Upgrade_() = default;

void Upgrade_::resize(const std::string& name, std::size_t size)
{
    try
    {
        Game_object_::resize(name, size);
        return;
    }
    catch(...){}
    throw Bad_manipulation(name + " in Upgrade treated as a vector, but it is not a vector.");
}

void Upgrade_::change_vec_values(const std::string& name, std::vector<std::pair<std::size_t, Any>>& values)
{
    try
    {
        Game_object_::change_vec_values(name, values);
        return;
    }
    catch(...){}
    throw Bad_manipulation(name + " in Upgrade treated as a vector, but it is not a vector.");
}

void Upgrade_::remove_key(const std::string& name, Any& key)
{
    try
    {
        Game_object_::remove_key(name, key);
        return;
    }
    catch(...){}
    throw Bad_manipulation(name + " in Upgrade treated as a map, but it is not a map.");
}

std::unique_ptr<Any> Upgrade_::add_key_value(const std::string& name, Any& key, Any& value)
{
    try
    {
        return Game_object_::add_key_value(name, key, value);
    }
    catch(...){}
    throw Bad_manipulation(name + " in Upgrade treated as a map, but it is not a map.");
}

bool Upgrade_::is_map(const std::string& name)
{
    try
    {
        return Game_object_::is_map(name);
    }
    catch(...){}
    return false;
}

void Upgrade_::rebind_by_name(Any* to_change, const std::string& member, std::shared_ptr<Base_object> ref)
{
   try
   {
      Game_object_::rebind_by_name(to_change, member, ref);
      return;
   }
   catch(...){}
   throw Bad_manipulation(member + " in Upgrade treated as a reference, but it is not a reference.");
}


} // coreminer

} // cpp_client

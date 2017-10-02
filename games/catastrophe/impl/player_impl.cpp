// DO NOT MODIFY THIS FILE
// Never try to directly create an instance of this class, or modify its member variables.
// This contains implementation details, written by code, and only useful to code



#include "../player.hpp"
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


Player_::Player_(std::initializer_list<std::pair<std::string, Any&&>> init) :
    Game_object_{
        {"cat", Any{std::decay<decltype(cat)>::type{}}},
        {"clientType", Any{std::decay<decltype(client_type)>::type{}}},
        {"food", Any{std::decay<decltype(food)>::type{}}},
        {"lost", Any{std::decay<decltype(lost)>::type{}}},
        {"name", Any{std::decay<decltype(name)>::type{}}},
        {"opponent", Any{std::decay<decltype(opponent)>::type{}}},
        {"reasonLost", Any{std::decay<decltype(reason_lost)>::type{}}},
        {"reasonWon", Any{std::decay<decltype(reason_won)>::type{}}},
        {"structures", Any{std::decay<decltype(structures)>::type{}}},
        {"timeRemaining", Any{std::decay<decltype(time_remaining)>::type{}}},
        {"units", Any{std::decay<decltype(units)>::type{}}},
        {"upkeep", Any{std::decay<decltype(upkeep)>::type{}}},
        {"won", Any{std::decay<decltype(won)>::type{}}},
    },
    cat(variables_["cat"].as<std::decay<decltype(cat)>::type>()),
    client_type(variables_["clientType"].as<std::decay<decltype(client_type)>::type>()),
    food(variables_["food"].as<std::decay<decltype(food)>::type>()),
    lost(variables_["lost"].as<std::decay<decltype(lost)>::type>()),
    name(variables_["name"].as<std::decay<decltype(name)>::type>()),
    opponent(variables_["opponent"].as<std::decay<decltype(opponent)>::type>()),
    reason_lost(variables_["reasonLost"].as<std::decay<decltype(reason_lost)>::type>()),
    reason_won(variables_["reasonWon"].as<std::decay<decltype(reason_won)>::type>()),
    structures(variables_["structures"].as<std::decay<decltype(structures)>::type>()),
    time_remaining(variables_["timeRemaining"].as<std::decay<decltype(time_remaining)>::type>()),
    units(variables_["units"].as<std::decay<decltype(units)>::type>()),
    upkeep(variables_["upkeep"].as<std::decay<decltype(upkeep)>::type>()),
    won(variables_["won"].as<std::decay<decltype(won)>::type>())
{
    for(auto&& obj : init)
    {
      variables_.emplace(std::make_pair(std::move(obj.first), std::move(obj.second)));
    }
}

Player_::~Player_() = default;

void Player_::resize(const std::string& name, std::size_t size)
{
    if(name == "structures")
    {
        auto& vec = variables_["structures"].as<std::decay<decltype(structures)>::type>();
        vec.resize(size);
        return;
    }
    else if(name == "units")
    {
        auto& vec = variables_["units"].as<std::decay<decltype(units)>::type>();
        vec.resize(size);
        return;
    }
    try
    {
        Game_object_::resize(name, size);
        return;
    }
    catch(...){}
    throw Bad_manipulation(name + " in Player treated as a vector, but it is not a vector.");
}

void Player_::change_vec_values(const std::string& name, std::vector<std::pair<std::size_t, Any>>& values)
{
    if(name == "structures")
    {
        using type = std::decay<decltype(structures)>::type;
        auto& vec = variables_["structures"].as<type>();
        for(auto&& val : values)
        { 
            vec[val.first] = std::static_pointer_cast<type::value_type::element_type>(get_game()->get_objects()[val.second.as<std::string>()]);
        }
        return;
    } 
    else if(name == "units")
    {
        using type = std::decay<decltype(units)>::type;
        auto& vec = variables_["units"].as<type>();
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
    throw Bad_manipulation(name + " in Player treated as a vector, but it is not a vector.");
}

void Player_::remove_key(const std::string& name, Any& key)
{
    try
    {
        Game_object_::remove_key(name, key);
        return;
    }
    catch(...){}
    throw Bad_manipulation(name + " in Player treated as a map, but it is not a map.");
}

std::unique_ptr<Any> Player_::add_key_value(const std::string& name, Any& key, Any& value)
{
    try
    {
        return Game_object_::add_key_value(name, key, value);
    }
    catch(...){}
    throw Bad_manipulation(name + " in Player treated as a map, but it is not a map.");
}

bool Player_::is_map(const std::string& name)
{
    try
    {
        return Game_object_::is_map(name);
    }
    catch(...){}
    return false;
}

void Player_::rebind_by_name(Any* to_change, const std::string& member, std::shared_ptr<Base_object> ref)
{
   if(member == "cat")
   { 
      to_change->as<Unit>() = std::static_pointer_cast<Unit_>(ref);
      return;
   }
   if(member == "opponent")
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
   throw Bad_manipulation(member + " in Player treated as a reference, but it is not a reference.");
}


} // catastrophe

} // cpp_client

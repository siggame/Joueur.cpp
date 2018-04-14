// DO NOT MODIFY THIS FILE
// Never try to directly create an instance of this class, or modify its member variables.
// This contains implementation details, written by code, and only useful to code



#include "../forecast.hpp"
#include "../../../joueur/src/base_ai.hpp"
#include "../../../joueur/src/any.hpp"
#include "../../../joueur/src/exceptions.hpp"
#include "../../../joueur/src/delta.hpp"
#include "../building.hpp"
#include "../fire_department.hpp"
#include "../forecast.hpp"
#include "../game_object.hpp"
#include "../player.hpp"
#include "../police_department.hpp"
#include "../warehouse.hpp"
#include "../weather_station.hpp"
#include "anarchy.hpp"

#include <type_traits>

namespace cpp_client
{

namespace anarchy
{


Forecast_::Forecast_(std::initializer_list<std::pair<std::string, Any&&>> init) :
    Game_object_{
        {"controllingPlayer", Any{std::decay<decltype(controlling_player)>::type{}}},
        {"direction", Any{std::decay<decltype(direction)>::type{}}},
        {"intensity", Any{std::decay<decltype(intensity)>::type{}}},
    },
    controlling_player(variables_["controllingPlayer"].as<std::decay<decltype(controlling_player)>::type>()),
    direction(variables_["direction"].as<std::decay<decltype(direction)>::type>()),
    intensity(variables_["intensity"].as<std::decay<decltype(intensity)>::type>())
{
    for(auto&& obj : init)
    {
      variables_.emplace(std::make_pair(std::move(obj.first), std::move(obj.second)));
    }
}

Forecast_::~Forecast_() = default;

void Forecast_::resize(const std::string& name, std::size_t size)
{
    try
    {
        Game_object_::resize(name, size);
        return;
    }
    catch(...){}
    throw Bad_manipulation(name + " in Forecast treated as a vector, but it is not a vector.");
}

void Forecast_::change_vec_values(const std::string& name, std::vector<std::pair<std::size_t, Any>>& values)
{
    try
    {
        Game_object_::change_vec_values(name, values);
        return;
    }
    catch(...){}
    throw Bad_manipulation(name + " in Forecast treated as a vector, but it is not a vector.");
}

void Forecast_::remove_key(const std::string& name, Any& key)
{
    try
    {
        Game_object_::remove_key(name, key);
        return;
    }
    catch(...){}
    throw Bad_manipulation(name + " in Forecast treated as a map, but it is not a map.");
}

std::unique_ptr<Any> Forecast_::add_key_value(const std::string& name, Any& key, Any& value)
{
    try
    {
        return Game_object_::add_key_value(name, key, value);
    }
    catch(...){}
    throw Bad_manipulation(name + " in Forecast treated as a map, but it is not a map.");
}

bool Forecast_::is_map(const std::string& name)
{
    try
    {
        return Game_object_::is_map(name);
    }
    catch(...){}
    return false;
}

void Forecast_::rebind_by_name(Any* to_change, const std::string& member, std::shared_ptr<Base_object> ref)
{
   if(member == "controllingPlayer")
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
   throw Bad_manipulation(member + " in Forecast treated as a reference, but it is not a reference.");
}


} // anarchy

} // cpp_client

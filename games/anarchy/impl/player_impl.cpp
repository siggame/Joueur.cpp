// DO NOT MODIFY THIS FILE
// Never try to directly create an instance of this class, or modify its member variables.
// This contains implementation details, written by code, and only useful to code



#include "../player.hpp"
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


Player_::Player_(std::initializer_list<std::pair<std::string, Any&&>> init) :
    Game_object_{
        {"bribesRemaining", Any{std::decay<decltype(bribes_remaining)>::type{}}},
        {"buildings", Any{std::decay<decltype(buildings)>::type{}}},
        {"clientType", Any{std::decay<decltype(client_type)>::type{}}},
        {"fireDepartments", Any{std::decay<decltype(fire_departments)>::type{}}},
        {"headquarters", Any{std::decay<decltype(headquarters)>::type{}}},
        {"lost", Any{std::decay<decltype(lost)>::type{}}},
        {"name", Any{std::decay<decltype(name)>::type{}}},
        {"opponent", Any{std::decay<decltype(opponent)>::type{}}},
        {"policeDepartments", Any{std::decay<decltype(police_departments)>::type{}}},
        {"reasonLost", Any{std::decay<decltype(reason_lost)>::type{}}},
        {"reasonWon", Any{std::decay<decltype(reason_won)>::type{}}},
        {"timeRemaining", Any{std::decay<decltype(time_remaining)>::type{}}},
        {"warehouses", Any{std::decay<decltype(warehouses)>::type{}}},
        {"weatherStations", Any{std::decay<decltype(weather_stations)>::type{}}},
        {"won", Any{std::decay<decltype(won)>::type{}}},
    },
    bribes_remaining(variables_["bribesRemaining"].as<std::decay<decltype(bribes_remaining)>::type>()),
    buildings(variables_["buildings"].as<std::decay<decltype(buildings)>::type>()),
    client_type(variables_["clientType"].as<std::decay<decltype(client_type)>::type>()),
    fire_departments(variables_["fireDepartments"].as<std::decay<decltype(fire_departments)>::type>()),
    headquarters(variables_["headquarters"].as<std::decay<decltype(headquarters)>::type>()),
    lost(variables_["lost"].as<std::decay<decltype(lost)>::type>()),
    name(variables_["name"].as<std::decay<decltype(name)>::type>()),
    opponent(variables_["opponent"].as<std::decay<decltype(opponent)>::type>()),
    police_departments(variables_["policeDepartments"].as<std::decay<decltype(police_departments)>::type>()),
    reason_lost(variables_["reasonLost"].as<std::decay<decltype(reason_lost)>::type>()),
    reason_won(variables_["reasonWon"].as<std::decay<decltype(reason_won)>::type>()),
    time_remaining(variables_["timeRemaining"].as<std::decay<decltype(time_remaining)>::type>()),
    warehouses(variables_["warehouses"].as<std::decay<decltype(warehouses)>::type>()),
    weather_stations(variables_["weatherStations"].as<std::decay<decltype(weather_stations)>::type>()),
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
    if(name == "buildings")
    {
        auto& vec = variables_["buildings"].as<std::decay<decltype(buildings)>::type>();
        vec.resize(size);
        return;
    }
    else if(name == "fireDepartments")
    {
        auto& vec = variables_["fireDepartments"].as<std::decay<decltype(fire_departments)>::type>();
        vec.resize(size);
        return;
    }
    else if(name == "policeDepartments")
    {
        auto& vec = variables_["policeDepartments"].as<std::decay<decltype(police_departments)>::type>();
        vec.resize(size);
        return;
    }
    else if(name == "warehouses")
    {
        auto& vec = variables_["warehouses"].as<std::decay<decltype(warehouses)>::type>();
        vec.resize(size);
        return;
    }
    else if(name == "weatherStations")
    {
        auto& vec = variables_["weatherStations"].as<std::decay<decltype(weather_stations)>::type>();
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
    if(name == "buildings")
    {
        using type = std::decay<decltype(buildings)>::type;
        auto& vec = variables_["buildings"].as<type>();
        for(auto&& val : values)
        { 
            vec[val.first] = std::static_pointer_cast<type::value_type::element_type>(get_game()->get_objects()[val.second.as<std::string>()]);
        }
        return;
    } 
    else if(name == "fireDepartments")
    {
        using type = std::decay<decltype(fire_departments)>::type;
        auto& vec = variables_["fireDepartments"].as<type>();
        for(auto&& val : values)
        { 
            vec[val.first] = std::static_pointer_cast<type::value_type::element_type>(get_game()->get_objects()[val.second.as<std::string>()]);
        }
        return;
    } 
    else if(name == "policeDepartments")
    {
        using type = std::decay<decltype(police_departments)>::type;
        auto& vec = variables_["policeDepartments"].as<type>();
        for(auto&& val : values)
        { 
            vec[val.first] = std::static_pointer_cast<type::value_type::element_type>(get_game()->get_objects()[val.second.as<std::string>()]);
        }
        return;
    } 
    else if(name == "warehouses")
    {
        using type = std::decay<decltype(warehouses)>::type;
        auto& vec = variables_["warehouses"].as<type>();
        for(auto&& val : values)
        { 
            vec[val.first] = std::static_pointer_cast<type::value_type::element_type>(get_game()->get_objects()[val.second.as<std::string>()]);
        }
        return;
    } 
    else if(name == "weatherStations")
    {
        using type = std::decay<decltype(weather_stations)>::type;
        auto& vec = variables_["weatherStations"].as<type>();
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
   if(member == "headquarters")
   { 
      to_change->as<Warehouse>() = std::static_pointer_cast<Warehouse_>(ref);
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


} // anarchy

} // cpp_client

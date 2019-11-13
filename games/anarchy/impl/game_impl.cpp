// DO NOT MODIFY THIS FILE
// Never try to directly create an instance of this class, or modify its member variables.
// This contains implementation details, written by code, and only useful to code



#include "../game.hpp"
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


Game_::Game_(std::initializer_list<std::pair<std::string, Any&&>> init) :
    Base_game{
        {"baseBribesPerTurn", Any{std::decay<decltype(base_bribes_per_turn)>::type{}}},
        {"buildings", Any{std::decay<decltype(buildings)>::type{}}},
        {"currentForecast", Any{std::decay<decltype(current_forecast)>::type{}}},
        {"currentPlayer", Any{std::decay<decltype(current_player)>::type{}}},
        {"currentTurn", Any{std::decay<decltype(current_turn)>::type{}}},
        {"forecasts", Any{std::decay<decltype(forecasts)>::type{}}},
        {"gameObjects", Any{std::decay<decltype(game_objects)>::type{}}},
        {"mapHeight", Any{std::decay<decltype(map_height)>::type{}}},
        {"mapWidth", Any{std::decay<decltype(map_width)>::type{}}},
        {"maxFire", Any{std::decay<decltype(max_fire)>::type{}}},
        {"maxForecastIntensity", Any{std::decay<decltype(max_forecast_intensity)>::type{}}},
        {"maxTurns", Any{std::decay<decltype(max_turns)>::type{}}},
        {"nextForecast", Any{std::decay<decltype(next_forecast)>::type{}}},
        {"players", Any{std::decay<decltype(players)>::type{}}},
        {"session", Any{std::decay<decltype(session)>::type{}}},
        {"timeAddedPerTurn", Any{std::decay<decltype(time_added_per_turn)>::type{}}},
    },
    base_bribes_per_turn(variables_["baseBribesPerTurn"].as<std::decay<decltype(base_bribes_per_turn)>::type>()),
    buildings(variables_["buildings"].as<std::decay<decltype(buildings)>::type>()),
    current_forecast(variables_["currentForecast"].as<std::decay<decltype(current_forecast)>::type>()),
    current_player(variables_["currentPlayer"].as<std::decay<decltype(current_player)>::type>()),
    current_turn(variables_["currentTurn"].as<std::decay<decltype(current_turn)>::type>()),
    forecasts(variables_["forecasts"].as<std::decay<decltype(forecasts)>::type>()),
    game_objects(variables_["gameObjects"].as<std::decay<decltype(game_objects)>::type>()),
    map_height(variables_["mapHeight"].as<std::decay<decltype(map_height)>::type>()),
    map_width(variables_["mapWidth"].as<std::decay<decltype(map_width)>::type>()),
    max_fire(variables_["maxFire"].as<std::decay<decltype(max_fire)>::type>()),
    max_forecast_intensity(variables_["maxForecastIntensity"].as<std::decay<decltype(max_forecast_intensity)>::type>()),
    max_turns(variables_["maxTurns"].as<std::decay<decltype(max_turns)>::type>()),
    next_forecast(variables_["nextForecast"].as<std::decay<decltype(next_forecast)>::type>()),
    players(variables_["players"].as<std::decay<decltype(players)>::type>()),
    session(variables_["session"].as<std::decay<decltype(session)>::type>()),
    time_added_per_turn(variables_["timeAddedPerTurn"].as<std::decay<decltype(time_added_per_turn)>::type>())
{
    for(auto&& obj : init)
    {
      variables_.emplace(std::make_pair(std::move(obj.first), std::move(obj.second)));
    }
}

Game_::~Game_() = default;

void Game_::resize(const std::string& name, std::size_t size)
{
    if(name == "buildings")
    {
        auto& vec = variables_["buildings"].as<std::decay<decltype(buildings)>::type>();
        vec.resize(size);
        return;
    }
    else if(name == "forecasts")
    {
        auto& vec = variables_["forecasts"].as<std::decay<decltype(forecasts)>::type>();
        vec.resize(size);
        return;
    }
    else if(name == "players")
    {
        auto& vec = variables_["players"].as<std::decay<decltype(players)>::type>();
        vec.resize(size);
        return;
    }
    throw Bad_manipulation(name + " in Game treated as a vector, but it is not a vector.");
}

void Game_::change_vec_values(const std::string& name, std::vector<std::pair<std::size_t, Any>>& values)
{
    if(name == "buildings")
    {
        using type = std::decay<decltype(buildings)>::type;
        auto& vec = variables_["buildings"].as<type>();
        for(auto&& val : values)
        { 
            vec[val.first] = std::static_pointer_cast<type::value_type::element_type>(get_objects()[val.second.as<std::string>()]);
        }
        return;
    } 
    else if(name == "forecasts")
    {
        using type = std::decay<decltype(forecasts)>::type;
        auto& vec = variables_["forecasts"].as<type>();
        for(auto&& val : values)
        { 
            vec[val.first] = std::static_pointer_cast<type::value_type::element_type>(get_objects()[val.second.as<std::string>()]);
        }
        return;
    } 
    else if(name == "players")
    {
        using type = std::decay<decltype(players)>::type;
        auto& vec = variables_["players"].as<type>();
        for(auto&& val : values)
        { 
            vec[val.first] = std::static_pointer_cast<type::value_type::element_type>(get_objects()[val.second.as<std::string>()]);
        }
        return;
    } 
    throw Bad_manipulation(name + " in Game treated as a vector, but it is not a vector.");
}

void Game_::remove_key(const std::string& name, Any& key)
{
    if(name == "gameObjects")
    {
        auto& map = variables_["gameObjects"].as<std::decay<decltype(game_objects)>::type>();
        using type = std::decay<decltype(map)>::type;
        map.erase(key.as<type::key_type>());
        return;
    }
    throw Bad_manipulation(name + " in Game treated as a map, but it is not a map.");
}

std::unique_ptr<Any> Game_::add_key_value(const std::string& name, Any& key, Any& value)
{
    if(name == "gameObjects")
    {
        auto& map = variables_["gameObjects"].as<std::decay<decltype(game_objects)>::type>();
        using type = std::decay<decltype(map)>::type;
        auto real_key = key.as<type::key_type>();
        if(value)
        {
            map[real_key] = std::move(value.as<type::mapped_type>());
        }
        auto val = std::static_pointer_cast<Base_object>(map[real_key]);
        return std::unique_ptr<Any>(new Any{std::shared_ptr<Base_object>{val}});
    }
    throw Bad_manipulation(name + " in Game treated as a map, but it is not a map.");
}

bool Game_::is_map(const std::string& name)
{
    if(name == "gameObjects")
    {
        return true;
    }
    return false;
}

void Game_::rebind_by_name(Any* to_change, const std::string& member, std::shared_ptr<Base_object> ref)
{
   if(member == "currentForecast")
   { 
      to_change->as<Forecast>() = std::static_pointer_cast<Forecast_>(ref);
      return;
   }
   if(member == "currentPlayer")
   { 
      to_change->as<Player>() = std::static_pointer_cast<Player_>(ref);
      return;
   }
   if(member == "nextForecast")
   { 
      to_change->as<Forecast>() = std::static_pointer_cast<Forecast_>(ref);
      return;
   }
   throw Bad_manipulation(member + " in Game treated as a reference, but it is not a reference.");
}


} // anarchy

} // cpp_client

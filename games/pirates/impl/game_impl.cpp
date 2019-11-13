// DO NOT MODIFY THIS FILE
// Never try to directly create an instance of this class, or modify its member variables.
// This contains implementation details, written by code, and only useful to code



#include "../game.hpp"
#include "../../../joueur/src/base_ai.hpp"
#include "../../../joueur/src/any.hpp"
#include "../../../joueur/src/exceptions.hpp"
#include "../../../joueur/src/delta.hpp"
#include "../game_object.hpp"
#include "../player.hpp"
#include "../port.hpp"
#include "../tile.hpp"
#include "../unit.hpp"
#include "pirates.hpp"

#include <type_traits>

namespace cpp_client
{

namespace pirates
{


Game_::Game_(std::initializer_list<std::pair<std::string, Any&&>> init) :
    Base_game{
        {"buryInterestRate", Any{std::decay<decltype(bury_interest_rate)>::type{}}},
        {"crewCost", Any{std::decay<decltype(crew_cost)>::type{}}},
        {"crewDamage", Any{std::decay<decltype(crew_damage)>::type{}}},
        {"crewHealth", Any{std::decay<decltype(crew_health)>::type{}}},
        {"crewMoves", Any{std::decay<decltype(crew_moves)>::type{}}},
        {"crewRange", Any{std::decay<decltype(crew_range)>::type{}}},
        {"currentPlayer", Any{std::decay<decltype(current_player)>::type{}}},
        {"currentTurn", Any{std::decay<decltype(current_turn)>::type{}}},
        {"gameObjects", Any{std::decay<decltype(game_objects)>::type{}}},
        {"healFactor", Any{std::decay<decltype(heal_factor)>::type{}}},
        {"mapHeight", Any{std::decay<decltype(map_height)>::type{}}},
        {"mapWidth", Any{std::decay<decltype(map_width)>::type{}}},
        {"maxTurns", Any{std::decay<decltype(max_turns)>::type{}}},
        {"merchantGoldRate", Any{std::decay<decltype(merchant_gold_rate)>::type{}}},
        {"merchantInterestRate", Any{std::decay<decltype(merchant_interest_rate)>::type{}}},
        {"minInterestDistance", Any{std::decay<decltype(min_interest_distance)>::type{}}},
        {"players", Any{std::decay<decltype(players)>::type{}}},
        {"ports", Any{std::decay<decltype(ports)>::type{}}},
        {"restRange", Any{std::decay<decltype(rest_range)>::type{}}},
        {"session", Any{std::decay<decltype(session)>::type{}}},
        {"shipCost", Any{std::decay<decltype(ship_cost)>::type{}}},
        {"shipDamage", Any{std::decay<decltype(ship_damage)>::type{}}},
        {"shipHealth", Any{std::decay<decltype(ship_health)>::type{}}},
        {"shipMoves", Any{std::decay<decltype(ship_moves)>::type{}}},
        {"shipRange", Any{std::decay<decltype(ship_range)>::type{}}},
        {"tiles", Any{std::decay<decltype(tiles)>::type{}}},
        {"timeAddedPerTurn", Any{std::decay<decltype(time_added_per_turn)>::type{}}},
        {"units", Any{std::decay<decltype(units)>::type{}}},
    },
    bury_interest_rate(variables_["buryInterestRate"].as<std::decay<decltype(bury_interest_rate)>::type>()),
    crew_cost(variables_["crewCost"].as<std::decay<decltype(crew_cost)>::type>()),
    crew_damage(variables_["crewDamage"].as<std::decay<decltype(crew_damage)>::type>()),
    crew_health(variables_["crewHealth"].as<std::decay<decltype(crew_health)>::type>()),
    crew_moves(variables_["crewMoves"].as<std::decay<decltype(crew_moves)>::type>()),
    crew_range(variables_["crewRange"].as<std::decay<decltype(crew_range)>::type>()),
    current_player(variables_["currentPlayer"].as<std::decay<decltype(current_player)>::type>()),
    current_turn(variables_["currentTurn"].as<std::decay<decltype(current_turn)>::type>()),
    game_objects(variables_["gameObjects"].as<std::decay<decltype(game_objects)>::type>()),
    heal_factor(variables_["healFactor"].as<std::decay<decltype(heal_factor)>::type>()),
    map_height(variables_["mapHeight"].as<std::decay<decltype(map_height)>::type>()),
    map_width(variables_["mapWidth"].as<std::decay<decltype(map_width)>::type>()),
    max_turns(variables_["maxTurns"].as<std::decay<decltype(max_turns)>::type>()),
    merchant_gold_rate(variables_["merchantGoldRate"].as<std::decay<decltype(merchant_gold_rate)>::type>()),
    merchant_interest_rate(variables_["merchantInterestRate"].as<std::decay<decltype(merchant_interest_rate)>::type>()),
    min_interest_distance(variables_["minInterestDistance"].as<std::decay<decltype(min_interest_distance)>::type>()),
    players(variables_["players"].as<std::decay<decltype(players)>::type>()),
    ports(variables_["ports"].as<std::decay<decltype(ports)>::type>()),
    rest_range(variables_["restRange"].as<std::decay<decltype(rest_range)>::type>()),
    session(variables_["session"].as<std::decay<decltype(session)>::type>()),
    ship_cost(variables_["shipCost"].as<std::decay<decltype(ship_cost)>::type>()),
    ship_damage(variables_["shipDamage"].as<std::decay<decltype(ship_damage)>::type>()),
    ship_health(variables_["shipHealth"].as<std::decay<decltype(ship_health)>::type>()),
    ship_moves(variables_["shipMoves"].as<std::decay<decltype(ship_moves)>::type>()),
    ship_range(variables_["shipRange"].as<std::decay<decltype(ship_range)>::type>()),
    tiles(variables_["tiles"].as<std::decay<decltype(tiles)>::type>()),
    time_added_per_turn(variables_["timeAddedPerTurn"].as<std::decay<decltype(time_added_per_turn)>::type>()),
    units(variables_["units"].as<std::decay<decltype(units)>::type>())
{
    for(auto&& obj : init)
    {
      variables_.emplace(std::make_pair(std::move(obj.first), std::move(obj.second)));
    }
}

Game_::~Game_() = default;

void Game_::resize(const std::string& name, std::size_t size)
{
    if(name == "players")
    {
        auto& vec = variables_["players"].as<std::decay<decltype(players)>::type>();
        vec.resize(size);
        return;
    }
    else if(name == "ports")
    {
        auto& vec = variables_["ports"].as<std::decay<decltype(ports)>::type>();
        vec.resize(size);
        return;
    }
    else if(name == "tiles")
    {
        auto& vec = variables_["tiles"].as<std::decay<decltype(tiles)>::type>();
        vec.resize(size);
        return;
    }
    else if(name == "units")
    {
        auto& vec = variables_["units"].as<std::decay<decltype(units)>::type>();
        vec.resize(size);
        return;
    }
    throw Bad_manipulation(name + " in Game treated as a vector, but it is not a vector.");
}

void Game_::change_vec_values(const std::string& name, std::vector<std::pair<std::size_t, Any>>& values)
{
    if(name == "players")
    {
        using type = std::decay<decltype(players)>::type;
        auto& vec = variables_["players"].as<type>();
        for(auto&& val : values)
        { 
            vec[val.first] = std::static_pointer_cast<type::value_type::element_type>(get_objects()[val.second.as<std::string>()]);
        }
        return;
    } 
    else if(name == "ports")
    {
        using type = std::decay<decltype(ports)>::type;
        auto& vec = variables_["ports"].as<type>();
        for(auto&& val : values)
        { 
            vec[val.first] = std::static_pointer_cast<type::value_type::element_type>(get_objects()[val.second.as<std::string>()]);
        }
        return;
    } 
    else if(name == "tiles")
    {
        using type = std::decay<decltype(tiles)>::type;
        auto& vec = variables_["tiles"].as<type>();
        for(auto&& val : values)
        { 
            vec[val.first] = std::static_pointer_cast<type::value_type::element_type>(get_objects()[val.second.as<std::string>()]);
        }
        return;
    } 
    else if(name == "units")
    {
        using type = std::decay<decltype(units)>::type;
        auto& vec = variables_["units"].as<type>();
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
   if(member == "currentPlayer")
   { 
      to_change->as<Player>() = std::static_pointer_cast<Player_>(ref);
      return;
   }
   throw Bad_manipulation(member + " in Game treated as a reference, but it is not a reference.");
}


} // pirates

} // cpp_client

// DO NOT MODIFY THIS FILE
// Never try to directly create an instance of this class, or modify its member variables.
// This contains implementation details, written by code, and only useful to code



#include "../game.hpp"
#include "../../../joueur/src/base_ai.hpp"
#include "../../../joueur/src/any.hpp"
#include "../../../joueur/src/exceptions.hpp"
#include "../../../joueur/src/delta.hpp"
#include "../body.hpp"
#include "../game_object.hpp"
#include "../job.hpp"
#include "../player.hpp"
#include "../projectile.hpp"
#include "../unit.hpp"
#include "stardash.hpp"

#include <type_traits>

namespace cpp_client
{

namespace stardash
{


Game_::Game_(std::initializer_list<std::pair<std::string, Any&&>> init) :
    Base_game{
        {"bodies", Any{std::decay<decltype(bodies)>::type{}}},
        {"currentPlayer", Any{std::decay<decltype(current_player)>::type{}}},
        {"currentTurn", Any{std::decay<decltype(current_turn)>::type{}}},
        {"dashCost", Any{std::decay<decltype(dash_cost)>::type{}}},
        {"dashDistance", Any{std::decay<decltype(dash_distance)>::type{}}},
        {"gameObjects", Any{std::decay<decltype(game_objects)>::type{}}},
        {"genariumValue", Any{std::decay<decltype(genarium_value)>::type{}}},
        {"jobs", Any{std::decay<decltype(jobs)>::type{}}},
        {"legendariumValue", Any{std::decay<decltype(legendarium_value)>::type{}}},
        {"maxAsteroid", Any{std::decay<decltype(max_asteroid)>::type{}}},
        {"maxTurns", Any{std::decay<decltype(max_turns)>::type{}}},
        {"minAsteroid", Any{std::decay<decltype(min_asteroid)>::type{}}},
        {"miningSpeed", Any{std::decay<decltype(mining_speed)>::type{}}},
        {"mythiciteAmount", Any{std::decay<decltype(mythicite_amount)>::type{}}},
        {"orbitsProtected", Any{std::decay<decltype(orbits_protected)>::type{}}},
        {"oreRarityGenarium", Any{std::decay<decltype(ore_rarity_genarium)>::type{}}},
        {"oreRarityLegendarium", Any{std::decay<decltype(ore_rarity_legendarium)>::type{}}},
        {"oreRarityRarium", Any{std::decay<decltype(ore_rarity_rarium)>::type{}}},
        {"planetEnergyCap", Any{std::decay<decltype(planet_energy_cap)>::type{}}},
        {"planetRechargeRate", Any{std::decay<decltype(planet_recharge_rate)>::type{}}},
        {"players", Any{std::decay<decltype(players)>::type{}}},
        {"projectileRadius", Any{std::decay<decltype(projectile_radius)>::type{}}},
        {"projectileSpeed", Any{std::decay<decltype(projectile_speed)>::type{}}},
        {"projectiles", Any{std::decay<decltype(projectiles)>::type{}}},
        {"rariumValue", Any{std::decay<decltype(rarium_value)>::type{}}},
        {"regenerateRate", Any{std::decay<decltype(regenerate_rate)>::type{}}},
        {"session", Any{std::decay<decltype(session)>::type{}}},
        {"shipRadius", Any{std::decay<decltype(ship_radius)>::type{}}},
        {"sizeX", Any{std::decay<decltype(size_x)>::type{}}},
        {"sizeY", Any{std::decay<decltype(size_y)>::type{}}},
        {"timeAddedPerTurn", Any{std::decay<decltype(time_added_per_turn)>::type{}}},
        {"turnsToOrbit", Any{std::decay<decltype(turns_to_orbit)>::type{}}},
        {"units", Any{std::decay<decltype(units)>::type{}}},
    },
    bodies(variables_["bodies"].as<std::decay<decltype(bodies)>::type>()),
    current_player(variables_["currentPlayer"].as<std::decay<decltype(current_player)>::type>()),
    current_turn(variables_["currentTurn"].as<std::decay<decltype(current_turn)>::type>()),
    dash_cost(variables_["dashCost"].as<std::decay<decltype(dash_cost)>::type>()),
    dash_distance(variables_["dashDistance"].as<std::decay<decltype(dash_distance)>::type>()),
    game_objects(variables_["gameObjects"].as<std::decay<decltype(game_objects)>::type>()),
    genarium_value(variables_["genariumValue"].as<std::decay<decltype(genarium_value)>::type>()),
    jobs(variables_["jobs"].as<std::decay<decltype(jobs)>::type>()),
    legendarium_value(variables_["legendariumValue"].as<std::decay<decltype(legendarium_value)>::type>()),
    max_asteroid(variables_["maxAsteroid"].as<std::decay<decltype(max_asteroid)>::type>()),
    max_turns(variables_["maxTurns"].as<std::decay<decltype(max_turns)>::type>()),
    min_asteroid(variables_["minAsteroid"].as<std::decay<decltype(min_asteroid)>::type>()),
    mining_speed(variables_["miningSpeed"].as<std::decay<decltype(mining_speed)>::type>()),
    mythicite_amount(variables_["mythiciteAmount"].as<std::decay<decltype(mythicite_amount)>::type>()),
    orbits_protected(variables_["orbitsProtected"].as<std::decay<decltype(orbits_protected)>::type>()),
    ore_rarity_genarium(variables_["oreRarityGenarium"].as<std::decay<decltype(ore_rarity_genarium)>::type>()),
    ore_rarity_legendarium(variables_["oreRarityLegendarium"].as<std::decay<decltype(ore_rarity_legendarium)>::type>()),
    ore_rarity_rarium(variables_["oreRarityRarium"].as<std::decay<decltype(ore_rarity_rarium)>::type>()),
    planet_energy_cap(variables_["planetEnergyCap"].as<std::decay<decltype(planet_energy_cap)>::type>()),
    planet_recharge_rate(variables_["planetRechargeRate"].as<std::decay<decltype(planet_recharge_rate)>::type>()),
    players(variables_["players"].as<std::decay<decltype(players)>::type>()),
    projectile_radius(variables_["projectileRadius"].as<std::decay<decltype(projectile_radius)>::type>()),
    projectile_speed(variables_["projectileSpeed"].as<std::decay<decltype(projectile_speed)>::type>()),
    projectiles(variables_["projectiles"].as<std::decay<decltype(projectiles)>::type>()),
    rarium_value(variables_["rariumValue"].as<std::decay<decltype(rarium_value)>::type>()),
    regenerate_rate(variables_["regenerateRate"].as<std::decay<decltype(regenerate_rate)>::type>()),
    session(variables_["session"].as<std::decay<decltype(session)>::type>()),
    ship_radius(variables_["shipRadius"].as<std::decay<decltype(ship_radius)>::type>()),
    size_x(variables_["sizeX"].as<std::decay<decltype(size_x)>::type>()),
    size_y(variables_["sizeY"].as<std::decay<decltype(size_y)>::type>()),
    time_added_per_turn(variables_["timeAddedPerTurn"].as<std::decay<decltype(time_added_per_turn)>::type>()),
    turns_to_orbit(variables_["turnsToOrbit"].as<std::decay<decltype(turns_to_orbit)>::type>()),
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
    if(name == "bodies")
    {
        auto& vec = variables_["bodies"].as<std::decay<decltype(bodies)>::type>();
        vec.resize(size);
        return;
    }
    else if(name == "jobs")
    {
        auto& vec = variables_["jobs"].as<std::decay<decltype(jobs)>::type>();
        vec.resize(size);
        return;
    }
    else if(name == "players")
    {
        auto& vec = variables_["players"].as<std::decay<decltype(players)>::type>();
        vec.resize(size);
        return;
    }
    else if(name == "projectiles")
    {
        auto& vec = variables_["projectiles"].as<std::decay<decltype(projectiles)>::type>();
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
    if(name == "bodies")
    {
        using type = std::decay<decltype(bodies)>::type;
        auto& vec = variables_["bodies"].as<type>();
        for(auto&& val : values)
        { 
            vec[val.first] = std::static_pointer_cast<type::value_type::element_type>(get_objects()[val.second.as<std::string>()]);
        }
        return;
    } 
    else if(name == "jobs")
    {
        using type = std::decay<decltype(jobs)>::type;
        auto& vec = variables_["jobs"].as<type>();
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
    else if(name == "projectiles")
    {
        using type = std::decay<decltype(projectiles)>::type;
        auto& vec = variables_["projectiles"].as<type>();
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


} // stardash

} // cpp_client

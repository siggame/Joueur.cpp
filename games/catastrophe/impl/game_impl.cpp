// DO NOT MODIFY THIS FILE
// Never try to directly create an instance of this class, or modify its member variables.
// This contains implementation details, written by code, and only useful to code



#include "../game.hpp"
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


Game_::Game_(std::initializer_list<std::pair<std::string, Any&&>> init) :
    Base_game{
        {"catEnergyMult", Any{std::decay<decltype(cat_energy_mult)>::type{}}},
        {"currentPlayer", Any{std::decay<decltype(current_player)>::type{}}},
        {"currentTurn", Any{std::decay<decltype(current_turn)>::type{}}},
        {"gameObjects", Any{std::decay<decltype(game_objects)>::type{}}},
        {"harvestCooldown", Any{std::decay<decltype(harvest_cooldown)>::type{}}},
        {"jobs", Any{std::decay<decltype(jobs)>::type{}}},
        {"lowerHarvestAmount", Any{std::decay<decltype(lower_harvest_amount)>::type{}}},
        {"mapHeight", Any{std::decay<decltype(map_height)>::type{}}},
        {"mapWidth", Any{std::decay<decltype(map_width)>::type{}}},
        {"maxTurns", Any{std::decay<decltype(max_turns)>::type{}}},
        {"monumentCostMult", Any{std::decay<decltype(monument_cost_mult)>::type{}}},
        {"monumentMaterials", Any{std::decay<decltype(monument_materials)>::type{}}},
        {"neutralMaterials", Any{std::decay<decltype(neutral_materials)>::type{}}},
        {"players", Any{std::decay<decltype(players)>::type{}}},
        {"session", Any{std::decay<decltype(session)>::type{}}},
        {"shelterMaterials", Any{std::decay<decltype(shelter_materials)>::type{}}},
        {"startingFood", Any{std::decay<decltype(starting_food)>::type{}}},
        {"starvingEnergyMult", Any{std::decay<decltype(starving_energy_mult)>::type{}}},
        {"structures", Any{std::decay<decltype(structures)>::type{}}},
        {"tiles", Any{std::decay<decltype(tiles)>::type{}}},
        {"timeAddedPerTurn", Any{std::decay<decltype(time_added_per_turn)>::type{}}},
        {"turnsBetweenHarvests", Any{std::decay<decltype(turns_between_harvests)>::type{}}},
        {"turnsToCreateHuman", Any{std::decay<decltype(turns_to_create_human)>::type{}}},
        {"turnsToLowerHarvest", Any{std::decay<decltype(turns_to_lower_harvest)>::type{}}},
        {"units", Any{std::decay<decltype(units)>::type{}}},
        {"wallMaterials", Any{std::decay<decltype(wall_materials)>::type{}}},
    },
    cat_energy_mult(variables_["catEnergyMult"].as<std::decay<decltype(cat_energy_mult)>::type>()),
    current_player(variables_["currentPlayer"].as<std::decay<decltype(current_player)>::type>()),
    current_turn(variables_["currentTurn"].as<std::decay<decltype(current_turn)>::type>()),
    game_objects(variables_["gameObjects"].as<std::decay<decltype(game_objects)>::type>()),
    harvest_cooldown(variables_["harvestCooldown"].as<std::decay<decltype(harvest_cooldown)>::type>()),
    jobs(variables_["jobs"].as<std::decay<decltype(jobs)>::type>()),
    lower_harvest_amount(variables_["lowerHarvestAmount"].as<std::decay<decltype(lower_harvest_amount)>::type>()),
    map_height(variables_["mapHeight"].as<std::decay<decltype(map_height)>::type>()),
    map_width(variables_["mapWidth"].as<std::decay<decltype(map_width)>::type>()),
    max_turns(variables_["maxTurns"].as<std::decay<decltype(max_turns)>::type>()),
    monument_cost_mult(variables_["monumentCostMult"].as<std::decay<decltype(monument_cost_mult)>::type>()),
    monument_materials(variables_["monumentMaterials"].as<std::decay<decltype(monument_materials)>::type>()),
    neutral_materials(variables_["neutralMaterials"].as<std::decay<decltype(neutral_materials)>::type>()),
    players(variables_["players"].as<std::decay<decltype(players)>::type>()),
    session(variables_["session"].as<std::decay<decltype(session)>::type>()),
    shelter_materials(variables_["shelterMaterials"].as<std::decay<decltype(shelter_materials)>::type>()),
    starting_food(variables_["startingFood"].as<std::decay<decltype(starting_food)>::type>()),
    starving_energy_mult(variables_["starvingEnergyMult"].as<std::decay<decltype(starving_energy_mult)>::type>()),
    structures(variables_["structures"].as<std::decay<decltype(structures)>::type>()),
    tiles(variables_["tiles"].as<std::decay<decltype(tiles)>::type>()),
    time_added_per_turn(variables_["timeAddedPerTurn"].as<std::decay<decltype(time_added_per_turn)>::type>()),
    turns_between_harvests(variables_["turnsBetweenHarvests"].as<std::decay<decltype(turns_between_harvests)>::type>()),
    turns_to_create_human(variables_["turnsToCreateHuman"].as<std::decay<decltype(turns_to_create_human)>::type>()),
    turns_to_lower_harvest(variables_["turnsToLowerHarvest"].as<std::decay<decltype(turns_to_lower_harvest)>::type>()),
    units(variables_["units"].as<std::decay<decltype(units)>::type>()),
    wall_materials(variables_["wallMaterials"].as<std::decay<decltype(wall_materials)>::type>())
{
    for(auto&& obj : init)
    {
      variables_.emplace(std::make_pair(std::move(obj.first), std::move(obj.second)));
    }
}

Game_::~Game_() = default;

void Game_::resize(const std::string& name, std::size_t size)
{
    if(name == "jobs")
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
    else if(name == "structures")
    {
        auto& vec = variables_["structures"].as<std::decay<decltype(structures)>::type>();
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
    if(name == "jobs")
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
    else if(name == "structures")
    {
        using type = std::decay<decltype(structures)>::type;
        auto& vec = variables_["structures"].as<type>();
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


} // catastrophe

} // cpp_client

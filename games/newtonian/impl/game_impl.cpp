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
#include "../machine.hpp"
#include "../player.hpp"
#include "../tile.hpp"
#include "../unit.hpp"
#include "newtonian.hpp"

#include <type_traits>

namespace cpp_client
{

namespace newtonian
{


Game_::Game_(std::initializer_list<std::pair<std::string, Any&&>> init) :
    Base_game{
        {"currentPlayer", Any{std::decay<decltype(current_player)>::type{}}},
        {"currentTurn", Any{std::decay<decltype(current_turn)>::type{}}},
        {"gameObjects", Any{std::decay<decltype(game_objects)>::type{}}},
        {"internCap", Any{std::decay<decltype(intern_cap)>::type{}}},
        {"jobs", Any{std::decay<decltype(jobs)>::type{}}},
        {"machines", Any{std::decay<decltype(machines)>::type{}}},
        {"managerCap", Any{std::decay<decltype(manager_cap)>::type{}}},
        {"mapHeight", Any{std::decay<decltype(map_height)>::type{}}},
        {"mapWidth", Any{std::decay<decltype(map_width)>::type{}}},
        {"materialSpawn", Any{std::decay<decltype(material_spawn)>::type{}}},
        {"maxTurns", Any{std::decay<decltype(max_turns)>::type{}}},
        {"physicistCap", Any{std::decay<decltype(physicist_cap)>::type{}}},
        {"players", Any{std::decay<decltype(players)>::type{}}},
        {"refinedValue", Any{std::decay<decltype(refined_value)>::type{}}},
        {"regenerateRate", Any{std::decay<decltype(regenerate_rate)>::type{}}},
        {"session", Any{std::decay<decltype(session)>::type{}}},
        {"spawnTime", Any{std::decay<decltype(spawn_time)>::type{}}},
        {"stunTime", Any{std::decay<decltype(stun_time)>::type{}}},
        {"tiles", Any{std::decay<decltype(tiles)>::type{}}},
        {"timeAddedPerTurn", Any{std::decay<decltype(time_added_per_turn)>::type{}}},
        {"timeImmune", Any{std::decay<decltype(time_immune)>::type{}}},
        {"units", Any{std::decay<decltype(units)>::type{}}},
        {"victoryAmount", Any{std::decay<decltype(victory_amount)>::type{}}},
    },
    current_player(variables_["currentPlayer"].as<std::decay<decltype(current_player)>::type>()),
    current_turn(variables_["currentTurn"].as<std::decay<decltype(current_turn)>::type>()),
    game_objects(variables_["gameObjects"].as<std::decay<decltype(game_objects)>::type>()),
    intern_cap(variables_["internCap"].as<std::decay<decltype(intern_cap)>::type>()),
    jobs(variables_["jobs"].as<std::decay<decltype(jobs)>::type>()),
    machines(variables_["machines"].as<std::decay<decltype(machines)>::type>()),
    manager_cap(variables_["managerCap"].as<std::decay<decltype(manager_cap)>::type>()),
    map_height(variables_["mapHeight"].as<std::decay<decltype(map_height)>::type>()),
    map_width(variables_["mapWidth"].as<std::decay<decltype(map_width)>::type>()),
    material_spawn(variables_["materialSpawn"].as<std::decay<decltype(material_spawn)>::type>()),
    max_turns(variables_["maxTurns"].as<std::decay<decltype(max_turns)>::type>()),
    physicist_cap(variables_["physicistCap"].as<std::decay<decltype(physicist_cap)>::type>()),
    players(variables_["players"].as<std::decay<decltype(players)>::type>()),
    refined_value(variables_["refinedValue"].as<std::decay<decltype(refined_value)>::type>()),
    regenerate_rate(variables_["regenerateRate"].as<std::decay<decltype(regenerate_rate)>::type>()),
    session(variables_["session"].as<std::decay<decltype(session)>::type>()),
    spawn_time(variables_["spawnTime"].as<std::decay<decltype(spawn_time)>::type>()),
    stun_time(variables_["stunTime"].as<std::decay<decltype(stun_time)>::type>()),
    tiles(variables_["tiles"].as<std::decay<decltype(tiles)>::type>()),
    time_added_per_turn(variables_["timeAddedPerTurn"].as<std::decay<decltype(time_added_per_turn)>::type>()),
    time_immune(variables_["timeImmune"].as<std::decay<decltype(time_immune)>::type>()),
    units(variables_["units"].as<std::decay<decltype(units)>::type>()),
    victory_amount(variables_["victoryAmount"].as<std::decay<decltype(victory_amount)>::type>())
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
    else if(name == "machines")
    {
        auto& vec = variables_["machines"].as<std::decay<decltype(machines)>::type>();
        vec.resize(size);
        return;
    }
    else if(name == "players")
    {
        auto& vec = variables_["players"].as<std::decay<decltype(players)>::type>();
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
    else if(name == "machines")
    {
        using type = std::decay<decltype(machines)>::type;
        auto& vec = variables_["machines"].as<type>();
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


} // newtonian

} // cpp_client

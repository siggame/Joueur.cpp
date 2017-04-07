// DO NOT MODIFY THIS FILE
// Never try to directly create an instance of this class, or modify its member variables.
// This contains implementation details, written by code, and only useful to code

#include "../game.hpp"
#include "../../../joueur/src/base_ai.hpp"
#include "../../../joueur/src/any.hpp"
#include "../../../joueur/src/exceptions.hpp"
#include "../../../joueur/src/delta.hpp"
#include "../beaver.hpp"
#include "../game_object.hpp"
#include "../job.hpp"
#include "../player.hpp"
#include "../spawner.hpp"
#include "../tile.hpp"
#include "stumped.hpp"

#include <type_traits>

namespace cpp_client
{

namespace stumped
{


Game_::Game_(std::initializer_list<std::pair<std::string, Any&&>> init) :
    Base_game{
        {"beavers", Any{std::decay<decltype(beavers)>::type{}}},
        {"currentPlayer", Any{std::decay<decltype(current_player)>::type{}}},
        {"currentTurn", Any{std::decay<decltype(current_turn)>::type{}}},
        {"freeBeaversCount", Any{std::decay<decltype(free_beavers_count)>::type{}}},
        {"gameObjects", Any{std::decay<decltype(game_objects)>::type{}}},
        {"jobs", Any{std::decay<decltype(jobs)>::type{}}},
        {"lodgeCostConstant", Any{std::decay<decltype(lodge_cost_constant)>::type{}}},
        {"lodgesToWin", Any{std::decay<decltype(lodges_to_win)>::type{}}},
        {"mapHeight", Any{std::decay<decltype(map_height)>::type{}}},
        {"mapWidth", Any{std::decay<decltype(map_width)>::type{}}},
        {"maxTurns", Any{std::decay<decltype(max_turns)>::type{}}},
        {"players", Any{std::decay<decltype(players)>::type{}}},
        {"session", Any{std::decay<decltype(session)>::type{}}},
        {"spawner", Any{std::decay<decltype(spawner)>::type{}}},
        {"spawnerHarvestConstant", Any{std::decay<decltype(spawner_harvest_constant)>::type{}}},
        {"spawnerTypes", Any{std::decay<decltype(spawner_types)>::type{}}},
        {"tiles", Any{std::decay<decltype(tiles)>::type{}}},
    },
    beavers(variables_["beavers"].as<std::decay<decltype(beavers)>::type>()),
    current_player(variables_["currentPlayer"].as<std::decay<decltype(current_player)>::type>()),
    current_turn(variables_["currentTurn"].as<std::decay<decltype(current_turn)>::type>()),
    free_beavers_count(variables_["freeBeaversCount"].as<std::decay<decltype(free_beavers_count)>::type>()),
    game_objects(variables_["gameObjects"].as<std::decay<decltype(game_objects)>::type>()),
    jobs(variables_["jobs"].as<std::decay<decltype(jobs)>::type>()),
    lodge_cost_constant(variables_["lodgeCostConstant"].as<std::decay<decltype(lodge_cost_constant)>::type>()),
    lodges_to_win(variables_["lodgesToWin"].as<std::decay<decltype(lodges_to_win)>::type>()),
    map_height(variables_["mapHeight"].as<std::decay<decltype(map_height)>::type>()),
    map_width(variables_["mapWidth"].as<std::decay<decltype(map_width)>::type>()),
    max_turns(variables_["maxTurns"].as<std::decay<decltype(max_turns)>::type>()),
    players(variables_["players"].as<std::decay<decltype(players)>::type>()),
    session(variables_["session"].as<std::decay<decltype(session)>::type>()),
    spawner(variables_["spawner"].as<std::decay<decltype(spawner)>::type>()),
    spawner_harvest_constant(variables_["spawnerHarvestConstant"].as<std::decay<decltype(spawner_harvest_constant)>::type>()),
    spawner_types(variables_["spawnerTypes"].as<std::decay<decltype(spawner_types)>::type>()),
    tiles(variables_["tiles"].as<std::decay<decltype(tiles)>::type>())
{
    for(auto&& obj : init)
    {
      variables_.emplace(std::make_pair(std::move(obj.first), std::move(obj.second)));
    }
}

Game_::~Game_() = default;

void Game_::resize(const std::string& name, std::size_t size)
{
    if(name == "beavers")
    {
        auto& vec = variables_["beavers"].as<std::decay<decltype(beavers)>::type>();
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
    else if(name == "spawner")
    {
        auto& vec = variables_["spawner"].as<std::decay<decltype(spawner)>::type>();
        vec.resize(size);
        return;
    }
    else if(name == "spawnerTypes")
    {
        auto& vec = variables_["spawnerTypes"].as<std::decay<decltype(spawner_types)>::type>();
        vec.resize(size);
        return;
    }
    else if(name == "tiles")
    {
        auto& vec = variables_["tiles"].as<std::decay<decltype(tiles)>::type>();
        vec.resize(size);
        return;
    }
    throw Bad_manipulation(name + " in Game treated as a vector, but it is not a vector.");
}

void Game_::change_vec_values(const std::string& name, std::vector<std::pair<std::size_t, Any>>& values)
{
    if(name == "beavers")
    {
        using type = std::decay<decltype(beavers)>::type;
        auto& vec = variables_["beavers"].as<type>();
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
    else if(name == "spawner")
    {
        using type = std::decay<decltype(spawner)>::type;
        auto& vec = variables_["spawner"].as<type>();
        for(auto&& val : values)
        { 
            vec[val.first] = std::static_pointer_cast<type::value_type::element_type>(get_objects()[val.second.as<std::string>()]);
        }
        return;
    } 
    else if(name == "spawnerTypes")
    {
        using type = std::decay<decltype(spawner_types)>::type;
        auto& vec = variables_["spawnerTypes"].as<type>();
        for(auto&& val : values)
        { 
            vec[val.first] = std::move(val.second.as<type::value_type>());
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


} // stumped

} // cpp_client

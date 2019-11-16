// DO NOT MODIFY THIS FILE
// Never try to directly create an instance of this class, or modify its member variables.
// This contains implementation details, written by code, and only useful to code



#include "../game.hpp"
#include "../../../joueur/src/base_ai.hpp"
#include "../../../joueur/src/any.hpp"
#include "../../../joueur/src/exceptions.hpp"
#include "../../../joueur/src/delta.hpp"
#include "../bottle.hpp"
#include "../cowboy.hpp"
#include "../furnishing.hpp"
#include "../game_object.hpp"
#include "../player.hpp"
#include "../tile.hpp"
#include "../young_gun.hpp"
#include "saloon.hpp"

#include <type_traits>

namespace cpp_client
{

namespace saloon
{


Game_::Game_(std::initializer_list<std::pair<std::string, Any&&>> init) :
    Base_game{
        {"bartenderCooldown", Any{std::decay<decltype(bartender_cooldown)>::type{}}},
        {"bottles", Any{std::decay<decltype(bottles)>::type{}}},
        {"brawlerDamage", Any{std::decay<decltype(brawler_damage)>::type{}}},
        {"cowboys", Any{std::decay<decltype(cowboys)>::type{}}},
        {"currentPlayer", Any{std::decay<decltype(current_player)>::type{}}},
        {"currentTurn", Any{std::decay<decltype(current_turn)>::type{}}},
        {"furnishings", Any{std::decay<decltype(furnishings)>::type{}}},
        {"gameObjects", Any{std::decay<decltype(game_objects)>::type{}}},
        {"jobs", Any{std::decay<decltype(jobs)>::type{}}},
        {"mapHeight", Any{std::decay<decltype(map_height)>::type{}}},
        {"mapWidth", Any{std::decay<decltype(map_width)>::type{}}},
        {"maxCowboysPerJob", Any{std::decay<decltype(max_cowboys_per_job)>::type{}}},
        {"maxTurns", Any{std::decay<decltype(max_turns)>::type{}}},
        {"players", Any{std::decay<decltype(players)>::type{}}},
        {"rowdinessToSiesta", Any{std::decay<decltype(rowdiness_to_siesta)>::type{}}},
        {"session", Any{std::decay<decltype(session)>::type{}}},
        {"sharpshooterDamage", Any{std::decay<decltype(sharpshooter_damage)>::type{}}},
        {"siestaLength", Any{std::decay<decltype(siesta_length)>::type{}}},
        {"tiles", Any{std::decay<decltype(tiles)>::type{}}},
        {"timeAddedPerTurn", Any{std::decay<decltype(time_added_per_turn)>::type{}}},
        {"turnsDrunk", Any{std::decay<decltype(turns_drunk)>::type{}}},
    },
    bartender_cooldown(variables_["bartenderCooldown"].as<std::decay<decltype(bartender_cooldown)>::type>()),
    bottles(variables_["bottles"].as<std::decay<decltype(bottles)>::type>()),
    brawler_damage(variables_["brawlerDamage"].as<std::decay<decltype(brawler_damage)>::type>()),
    cowboys(variables_["cowboys"].as<std::decay<decltype(cowboys)>::type>()),
    current_player(variables_["currentPlayer"].as<std::decay<decltype(current_player)>::type>()),
    current_turn(variables_["currentTurn"].as<std::decay<decltype(current_turn)>::type>()),
    furnishings(variables_["furnishings"].as<std::decay<decltype(furnishings)>::type>()),
    game_objects(variables_["gameObjects"].as<std::decay<decltype(game_objects)>::type>()),
    jobs(variables_["jobs"].as<std::decay<decltype(jobs)>::type>()),
    map_height(variables_["mapHeight"].as<std::decay<decltype(map_height)>::type>()),
    map_width(variables_["mapWidth"].as<std::decay<decltype(map_width)>::type>()),
    max_cowboys_per_job(variables_["maxCowboysPerJob"].as<std::decay<decltype(max_cowboys_per_job)>::type>()),
    max_turns(variables_["maxTurns"].as<std::decay<decltype(max_turns)>::type>()),
    players(variables_["players"].as<std::decay<decltype(players)>::type>()),
    rowdiness_to_siesta(variables_["rowdinessToSiesta"].as<std::decay<decltype(rowdiness_to_siesta)>::type>()),
    session(variables_["session"].as<std::decay<decltype(session)>::type>()),
    sharpshooter_damage(variables_["sharpshooterDamage"].as<std::decay<decltype(sharpshooter_damage)>::type>()),
    siesta_length(variables_["siestaLength"].as<std::decay<decltype(siesta_length)>::type>()),
    tiles(variables_["tiles"].as<std::decay<decltype(tiles)>::type>()),
    time_added_per_turn(variables_["timeAddedPerTurn"].as<std::decay<decltype(time_added_per_turn)>::type>()),
    turns_drunk(variables_["turnsDrunk"].as<std::decay<decltype(turns_drunk)>::type>())
{
    for(auto&& obj : init)
    {
      variables_.emplace(std::make_pair(std::move(obj.first), std::move(obj.second)));
    }
}

Game_::~Game_() = default;

void Game_::resize(const std::string& name, std::size_t size)
{
    if(name == "bottles")
    {
        auto& vec = variables_["bottles"].as<std::decay<decltype(bottles)>::type>();
        vec.resize(size);
        return;
    }
    else if(name == "cowboys")
    {
        auto& vec = variables_["cowboys"].as<std::decay<decltype(cowboys)>::type>();
        vec.resize(size);
        return;
    }
    else if(name == "furnishings")
    {
        auto& vec = variables_["furnishings"].as<std::decay<decltype(furnishings)>::type>();
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
    if(name == "bottles")
    {
        using type = std::decay<decltype(bottles)>::type;
        auto& vec = variables_["bottles"].as<type>();
        for(auto&& val : values)
        { 
            vec[val.first] = std::static_pointer_cast<type::value_type::element_type>(get_objects()[val.second.as<std::string>()]);
        }
        return;
    } 
    else if(name == "cowboys")
    {
        using type = std::decay<decltype(cowboys)>::type;
        auto& vec = variables_["cowboys"].as<type>();
        for(auto&& val : values)
        { 
            vec[val.first] = std::static_pointer_cast<type::value_type::element_type>(get_objects()[val.second.as<std::string>()]);
        }
        return;
    } 
    else if(name == "furnishings")
    {
        using type = std::decay<decltype(furnishings)>::type;
        auto& vec = variables_["furnishings"].as<type>();
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
            vec[val.first] = std::move(val.second.as<type::value_type>());
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


} // saloon

} // cpp_client

// DO NOT MODIFY THIS FILE
// Never try to directly create an instance of this class, or modify its member variables.
// This contains implementation details, written by code, and only useful to code



#include "../game.hpp"
#include "../../../joueur/src/base_ai.hpp"
#include "../../../joueur/src/any.hpp"
#include "../../../joueur/src/exceptions.hpp"
#include "../../../joueur/src/delta.hpp"
#include "../brood_mother.hpp"
#include "../cutter.hpp"
#include "../game_object.hpp"
#include "../nest.hpp"
#include "../player.hpp"
#include "../spider.hpp"
#include "../spiderling.hpp"
#include "../spitter.hpp"
#include "../weaver.hpp"
#include "../web.hpp"
#include "spiders.hpp"

#include <type_traits>

namespace cpp_client
{

namespace spiders
{


Game_::Game_(std::initializer_list<std::pair<std::string, Any&&>> init) :
    Base_game{
        {"currentPlayer", Any{std::decay<decltype(current_player)>::type{}}},
        {"currentTurn", Any{std::decay<decltype(current_turn)>::type{}}},
        {"cutSpeed", Any{std::decay<decltype(cut_speed)>::type{}}},
        {"eggsScalar", Any{std::decay<decltype(eggs_scalar)>::type{}}},
        {"gameObjects", Any{std::decay<decltype(game_objects)>::type{}}},
        {"initialWebStrength", Any{std::decay<decltype(initial_web_strength)>::type{}}},
        {"maxTurns", Any{std::decay<decltype(max_turns)>::type{}}},
        {"maxWebStrength", Any{std::decay<decltype(max_web_strength)>::type{}}},
        {"movementSpeed", Any{std::decay<decltype(movement_speed)>::type{}}},
        {"nests", Any{std::decay<decltype(nests)>::type{}}},
        {"players", Any{std::decay<decltype(players)>::type{}}},
        {"session", Any{std::decay<decltype(session)>::type{}}},
        {"spitSpeed", Any{std::decay<decltype(spit_speed)>::type{}}},
        {"timeAddedPerTurn", Any{std::decay<decltype(time_added_per_turn)>::type{}}},
        {"weavePower", Any{std::decay<decltype(weave_power)>::type{}}},
        {"weaveSpeed", Any{std::decay<decltype(weave_speed)>::type{}}},
        {"webs", Any{std::decay<decltype(webs)>::type{}}},
    },
    current_player(variables_["currentPlayer"].as<std::decay<decltype(current_player)>::type>()),
    current_turn(variables_["currentTurn"].as<std::decay<decltype(current_turn)>::type>()),
    cut_speed(variables_["cutSpeed"].as<std::decay<decltype(cut_speed)>::type>()),
    eggs_scalar(variables_["eggsScalar"].as<std::decay<decltype(eggs_scalar)>::type>()),
    game_objects(variables_["gameObjects"].as<std::decay<decltype(game_objects)>::type>()),
    initial_web_strength(variables_["initialWebStrength"].as<std::decay<decltype(initial_web_strength)>::type>()),
    max_turns(variables_["maxTurns"].as<std::decay<decltype(max_turns)>::type>()),
    max_web_strength(variables_["maxWebStrength"].as<std::decay<decltype(max_web_strength)>::type>()),
    movement_speed(variables_["movementSpeed"].as<std::decay<decltype(movement_speed)>::type>()),
    nests(variables_["nests"].as<std::decay<decltype(nests)>::type>()),
    players(variables_["players"].as<std::decay<decltype(players)>::type>()),
    session(variables_["session"].as<std::decay<decltype(session)>::type>()),
    spit_speed(variables_["spitSpeed"].as<std::decay<decltype(spit_speed)>::type>()),
    time_added_per_turn(variables_["timeAddedPerTurn"].as<std::decay<decltype(time_added_per_turn)>::type>()),
    weave_power(variables_["weavePower"].as<std::decay<decltype(weave_power)>::type>()),
    weave_speed(variables_["weaveSpeed"].as<std::decay<decltype(weave_speed)>::type>()),
    webs(variables_["webs"].as<std::decay<decltype(webs)>::type>())
{
    for(auto&& obj : init)
    {
      variables_.emplace(std::make_pair(std::move(obj.first), std::move(obj.second)));
    }
}

Game_::~Game_() = default;

void Game_::resize(const std::string& name, std::size_t size)
{
    if(name == "nests")
    {
        auto& vec = variables_["nests"].as<std::decay<decltype(nests)>::type>();
        vec.resize(size);
        return;
    }
    else if(name == "players")
    {
        auto& vec = variables_["players"].as<std::decay<decltype(players)>::type>();
        vec.resize(size);
        return;
    }
    else if(name == "webs")
    {
        auto& vec = variables_["webs"].as<std::decay<decltype(webs)>::type>();
        vec.resize(size);
        return;
    }
    throw Bad_manipulation(name + " in Game treated as a vector, but it is not a vector.");
}

void Game_::change_vec_values(const std::string& name, std::vector<std::pair<std::size_t, Any>>& values)
{
    if(name == "nests")
    {
        using type = std::decay<decltype(nests)>::type;
        auto& vec = variables_["nests"].as<type>();
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
    else if(name == "webs")
    {
        using type = std::decay<decltype(webs)>::type;
        auto& vec = variables_["webs"].as<type>();
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


} // spiders

} // cpp_client

// DO NOT MODIFY THIS FILE
// Never try to directly create an instance of this class, or modify its member variables.
// This contains implementation details, written by code, and only useful to code



#include "../player.hpp"
#include "../../../joueur/src/base_ai.hpp"
#include "../../../joueur/src/any.hpp"
#include "../../../joueur/src/exceptions.hpp"
#include "../../../joueur/src/delta.hpp"
#include "../bomb.hpp"
#include "../game_object.hpp"
#include "../miner.hpp"
#include "../player.hpp"
#include "../tile.hpp"
#include "../upgrade.hpp"
#include "coreminer.hpp"

#include <type_traits>

namespace cpp_client
{

namespace coreminer
{

bool Player_::spawn_miner()
{
    std::string order = R"({"event": "run", "data": {"functionName": "spawnMiner", "caller": {"id": ")";
    order += this->id + R"("}, "args": {)";

    order += "}}}";
    Coreminer::instance()->send(order);
    //Go until not a delta
    std::unique_ptr<Any> info;
    //until a not bool is seen (i.e., the delta has been processed)
    do
    {
        info = Coreminer::instance()->handle_response();
    } while(info->type() == typeid(bool));
    auto doc = info->as<rapidjson::Document*>();
    auto loc = doc->FindMember("data");
    if(loc == doc->MemberEnd())
    {
       return {};
    }
    auto& val = loc->value;
    Any to_return;
    morph_any(to_return, val);
    return to_return.as<bool>();
}


Player_::Player_(std::initializer_list<std::pair<std::string, Any&&>> init) :
    Game_object_{
        {"baseTile", Any{std::decay<decltype(base_tile)>::type{}}},
        {"bombs", Any{std::decay<decltype(bombs)>::type{}}},
        {"clientType", Any{std::decay<decltype(client_type)>::type{}}},
        {"hopperTiles", Any{std::decay<decltype(hopper_tiles)>::type{}}},
        {"lost", Any{std::decay<decltype(lost)>::type{}}},
        {"miners", Any{std::decay<decltype(miners)>::type{}}},
        {"money", Any{std::decay<decltype(money)>::type{}}},
        {"name", Any{std::decay<decltype(name)>::type{}}},
        {"opponent", Any{std::decay<decltype(opponent)>::type{}}},
        {"reasonLost", Any{std::decay<decltype(reason_lost)>::type{}}},
        {"reasonWon", Any{std::decay<decltype(reason_won)>::type{}}},
        {"timeRemaining", Any{std::decay<decltype(time_remaining)>::type{}}},
        {"value", Any{std::decay<decltype(value)>::type{}}},
        {"won", Any{std::decay<decltype(won)>::type{}}},
    },
    base_tile(variables_["baseTile"].as<std::decay<decltype(base_tile)>::type>()),
    bombs(variables_["bombs"].as<std::decay<decltype(bombs)>::type>()),
    client_type(variables_["clientType"].as<std::decay<decltype(client_type)>::type>()),
    hopper_tiles(variables_["hopperTiles"].as<std::decay<decltype(hopper_tiles)>::type>()),
    lost(variables_["lost"].as<std::decay<decltype(lost)>::type>()),
    miners(variables_["miners"].as<std::decay<decltype(miners)>::type>()),
    money(variables_["money"].as<std::decay<decltype(money)>::type>()),
    name(variables_["name"].as<std::decay<decltype(name)>::type>()),
    opponent(variables_["opponent"].as<std::decay<decltype(opponent)>::type>()),
    reason_lost(variables_["reasonLost"].as<std::decay<decltype(reason_lost)>::type>()),
    reason_won(variables_["reasonWon"].as<std::decay<decltype(reason_won)>::type>()),
    time_remaining(variables_["timeRemaining"].as<std::decay<decltype(time_remaining)>::type>()),
    value(variables_["value"].as<std::decay<decltype(value)>::type>()),
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
    if(name == "bombs")
    {
        auto& vec = variables_["bombs"].as<std::decay<decltype(bombs)>::type>();
        vec.resize(size);
        return;
    }
    else if(name == "hopperTiles")
    {
        auto& vec = variables_["hopperTiles"].as<std::decay<decltype(hopper_tiles)>::type>();
        vec.resize(size);
        return;
    }
    else if(name == "miners")
    {
        auto& vec = variables_["miners"].as<std::decay<decltype(miners)>::type>();
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
    if(name == "bombs")
    {
        using type = std::decay<decltype(bombs)>::type;
        auto& vec = variables_["bombs"].as<type>();
        for(auto&& val : values)
        { 
            vec[val.first] = std::static_pointer_cast<type::value_type::element_type>(get_game()->get_objects()[val.second.as<std::string>()]);
        }
        return;
    } 
    else if(name == "hopperTiles")
    {
        using type = std::decay<decltype(hopper_tiles)>::type;
        auto& vec = variables_["hopperTiles"].as<type>();
        for(auto&& val : values)
        { 
            vec[val.first] = std::static_pointer_cast<type::value_type::element_type>(get_game()->get_objects()[val.second.as<std::string>()]);
        }
        return;
    } 
    else if(name == "miners")
    {
        using type = std::decay<decltype(miners)>::type;
        auto& vec = variables_["miners"].as<type>();
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
   if(member == "baseTile")
   { 
      to_change->as<Tile>() = std::static_pointer_cast<Tile_>(ref);
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


} // coreminer

} // cpp_client

// DO NOT MODIFY THIS FILE
// Never try to directly create an instance of this class, or modify its member variables.
// This contains implementation details, written by code, and only useful to code



#include "../cowboy.hpp"
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

bool Cowboy_::act(const Tile& tile, const std::string& drunk_direction)
{
    std::string order = R"({"event": "run", "data": {"functionName": "act", "caller": {"id": ")";
    order += this->id + R"("}, "args": {)";

    order += std::string("\"tile\":") + (tile ? (std::string("{\"id\":\"") + tile->id + "\"}") : std::string("null"));

    order += std::string(",\"drunkDirection\":") + std::string("\"") + drunk_direction + "\"";

    order += "}}}";
    Saloon::instance()->send(order);
    //Go until not a delta
    std::unique_ptr<Any> info;
    //until a not bool is seen (i.e., the delta has been processed)
    do
    {
        info = Saloon::instance()->handle_response();
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

bool Cowboy_::move(const Tile& tile)
{
    std::string order = R"({"event": "run", "data": {"functionName": "move", "caller": {"id": ")";
    order += this->id + R"("}, "args": {)";

    order += std::string("\"tile\":") + (tile ? (std::string("{\"id\":\"") + tile->id + "\"}") : std::string("null"));

    order += "}}}";
    Saloon::instance()->send(order);
    //Go until not a delta
    std::unique_ptr<Any> info;
    //until a not bool is seen (i.e., the delta has been processed)
    do
    {
        info = Saloon::instance()->handle_response();
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

bool Cowboy_::play(const Furnishing& piano)
{
    std::string order = R"({"event": "run", "data": {"functionName": "play", "caller": {"id": ")";
    order += this->id + R"("}, "args": {)";

    order += std::string("\"piano\":") + (piano ? (std::string("{\"id\":\"") + piano->id + "\"}") : std::string("null"));

    order += "}}}";
    Saloon::instance()->send(order);
    //Go until not a delta
    std::unique_ptr<Any> info;
    //until a not bool is seen (i.e., the delta has been processed)
    do
    {
        info = Saloon::instance()->handle_response();
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


Cowboy_::Cowboy_(std::initializer_list<std::pair<std::string, Any&&>> init) :
    Game_object_{
        {"canMove", Any{std::decay<decltype(can_move)>::type{}}},
        {"drunkDirection", Any{std::decay<decltype(drunk_direction)>::type{}}},
        {"focus", Any{std::decay<decltype(focus)>::type{}}},
        {"health", Any{std::decay<decltype(health)>::type{}}},
        {"isDead", Any{std::decay<decltype(is_dead)>::type{}}},
        {"isDrunk", Any{std::decay<decltype(is_drunk)>::type{}}},
        {"job", Any{std::decay<decltype(job)>::type{}}},
        {"owner", Any{std::decay<decltype(owner)>::type{}}},
        {"tile", Any{std::decay<decltype(tile)>::type{}}},
        {"tolerance", Any{std::decay<decltype(tolerance)>::type{}}},
        {"turnsBusy", Any{std::decay<decltype(turns_busy)>::type{}}},
    },
    can_move(variables_["canMove"].as<std::decay<decltype(can_move)>::type>()),
    drunk_direction(variables_["drunkDirection"].as<std::decay<decltype(drunk_direction)>::type>()),
    focus(variables_["focus"].as<std::decay<decltype(focus)>::type>()),
    health(variables_["health"].as<std::decay<decltype(health)>::type>()),
    is_dead(variables_["isDead"].as<std::decay<decltype(is_dead)>::type>()),
    is_drunk(variables_["isDrunk"].as<std::decay<decltype(is_drunk)>::type>()),
    job(variables_["job"].as<std::decay<decltype(job)>::type>()),
    owner(variables_["owner"].as<std::decay<decltype(owner)>::type>()),
    tile(variables_["tile"].as<std::decay<decltype(tile)>::type>()),
    tolerance(variables_["tolerance"].as<std::decay<decltype(tolerance)>::type>()),
    turns_busy(variables_["turnsBusy"].as<std::decay<decltype(turns_busy)>::type>())
{
    for(auto&& obj : init)
    {
      variables_.emplace(std::make_pair(std::move(obj.first), std::move(obj.second)));
    }
}

Cowboy_::~Cowboy_() = default;

void Cowboy_::resize(const std::string& name, std::size_t size)
{
    try
    {
        Game_object_::resize(name, size);
        return;
    }
    catch(...){}
    throw Bad_manipulation(name + " in Cowboy treated as a vector, but it is not a vector.");
}

void Cowboy_::change_vec_values(const std::string& name, std::vector<std::pair<std::size_t, Any>>& values)
{
    try
    {
        Game_object_::change_vec_values(name, values);
        return;
    }
    catch(...){}
    throw Bad_manipulation(name + " in Cowboy treated as a vector, but it is not a vector.");
}

void Cowboy_::remove_key(const std::string& name, Any& key)
{
    try
    {
        Game_object_::remove_key(name, key);
        return;
    }
    catch(...){}
    throw Bad_manipulation(name + " in Cowboy treated as a map, but it is not a map.");
}

std::unique_ptr<Any> Cowboy_::add_key_value(const std::string& name, Any& key, Any& value)
{
    try
    {
        return Game_object_::add_key_value(name, key, value);
    }
    catch(...){}
    throw Bad_manipulation(name + " in Cowboy treated as a map, but it is not a map.");
}

bool Cowboy_::is_map(const std::string& name)
{
    try
    {
        return Game_object_::is_map(name);
    }
    catch(...){}
    return false;
}

void Cowboy_::rebind_by_name(Any* to_change, const std::string& member, std::shared_ptr<Base_object> ref)
{
   if(member == "owner")
   { 
      to_change->as<Player>() = std::static_pointer_cast<Player_>(ref);
      return;
   }
   if(member == "tile")
   { 
      to_change->as<Tile>() = std::static_pointer_cast<Tile_>(ref);
      return;
   }
   try
   {
      Game_object_::rebind_by_name(to_change, member, ref);
      return;
   }
   catch(...){}
   throw Bad_manipulation(member + " in Cowboy treated as a reference, but it is not a reference.");
}


} // saloon

} // cpp_client

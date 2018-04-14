// DO NOT MODIFY THIS FILE
// Never try to directly create an instance of this class, or modify its member variables.
// This contains implementation details, written by code, and only useful to code



#include "../unit.hpp"
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

bool Unit_::attack(const Tile& tile, const std::string& target)
{
    std::string order = R"({"event": "run", "data": {"functionName": "attack", "caller": {"id": ")";
    order += this->id + R"("}, "args": {)";

    order += std::string("\"tile\":") + (tile ? (std::string("{\"id\":\"") + tile->id + "\"}") : std::string("null"));

    order += std::string(",\"target\":") + std::string("\"") + target + "\"";

    order += "}}}";
    Pirates::instance()->send(order);
    //Go until not a delta
    std::unique_ptr<Any> info;
    //until a not bool is seen (i.e., the delta has been processed)
    do
    {
        info = Pirates::instance()->handle_response();
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

bool Unit_::bury(int amount)
{
    std::string order = R"({"event": "run", "data": {"functionName": "bury", "caller": {"id": ")";
    order += this->id + R"("}, "args": {)";

    order += std::string("\"amount\":") + std::to_string(amount);

    order += "}}}";
    Pirates::instance()->send(order);
    //Go until not a delta
    std::unique_ptr<Any> info;
    //until a not bool is seen (i.e., the delta has been processed)
    do
    {
        info = Pirates::instance()->handle_response();
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

bool Unit_::deposit(int amount)
{
    std::string order = R"({"event": "run", "data": {"functionName": "deposit", "caller": {"id": ")";
    order += this->id + R"("}, "args": {)";

    order += std::string("\"amount\":") + std::to_string(amount);

    order += "}}}";
    Pirates::instance()->send(order);
    //Go until not a delta
    std::unique_ptr<Any> info;
    //until a not bool is seen (i.e., the delta has been processed)
    do
    {
        info = Pirates::instance()->handle_response();
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

bool Unit_::dig(int amount)
{
    std::string order = R"({"event": "run", "data": {"functionName": "dig", "caller": {"id": ")";
    order += this->id + R"("}, "args": {)";

    order += std::string("\"amount\":") + std::to_string(amount);

    order += "}}}";
    Pirates::instance()->send(order);
    //Go until not a delta
    std::unique_ptr<Any> info;
    //until a not bool is seen (i.e., the delta has been processed)
    do
    {
        info = Pirates::instance()->handle_response();
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

bool Unit_::move(const Tile& tile)
{
    std::string order = R"({"event": "run", "data": {"functionName": "move", "caller": {"id": ")";
    order += this->id + R"("}, "args": {)";

    order += std::string("\"tile\":") + (tile ? (std::string("{\"id\":\"") + tile->id + "\"}") : std::string("null"));

    order += "}}}";
    Pirates::instance()->send(order);
    //Go until not a delta
    std::unique_ptr<Any> info;
    //until a not bool is seen (i.e., the delta has been processed)
    do
    {
        info = Pirates::instance()->handle_response();
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

bool Unit_::rest()
{
    std::string order = R"({"event": "run", "data": {"functionName": "rest", "caller": {"id": ")";
    order += this->id + R"("}, "args": {)";

    order += "}}}";
    Pirates::instance()->send(order);
    //Go until not a delta
    std::unique_ptr<Any> info;
    //until a not bool is seen (i.e., the delta has been processed)
    do
    {
        info = Pirates::instance()->handle_response();
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

bool Unit_::split(const Tile& tile, int amount, int gold)
{
    std::string order = R"({"event": "run", "data": {"functionName": "split", "caller": {"id": ")";
    order += this->id + R"("}, "args": {)";

    order += std::string("\"tile\":") + (tile ? (std::string("{\"id\":\"") + tile->id + "\"}") : std::string("null"));

    order += std::string(",\"amount\":") + std::to_string(amount);

    order += std::string(",\"gold\":") + std::to_string(gold);

    order += "}}}";
    Pirates::instance()->send(order);
    //Go until not a delta
    std::unique_ptr<Any> info;
    //until a not bool is seen (i.e., the delta has been processed)
    do
    {
        info = Pirates::instance()->handle_response();
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

bool Unit_::withdraw(int amount)
{
    std::string order = R"({"event": "run", "data": {"functionName": "withdraw", "caller": {"id": ")";
    order += this->id + R"("}, "args": {)";

    order += std::string("\"amount\":") + std::to_string(amount);

    order += "}}}";
    Pirates::instance()->send(order);
    //Go until not a delta
    std::unique_ptr<Any> info;
    //until a not bool is seen (i.e., the delta has been processed)
    do
    {
        info = Pirates::instance()->handle_response();
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


Unit_::Unit_(std::initializer_list<std::pair<std::string, Any&&>> init) :
    Game_object_{
        {"acted", Any{std::decay<decltype(acted)>::type{}}},
        {"crew", Any{std::decay<decltype(crew)>::type{}}},
        {"crewHealth", Any{std::decay<decltype(crew_health)>::type{}}},
        {"gold", Any{std::decay<decltype(gold)>::type{}}},
        {"moves", Any{std::decay<decltype(moves)>::type{}}},
        {"owner", Any{std::decay<decltype(owner)>::type{}}},
        {"path", Any{std::decay<decltype(path)>::type{}}},
        {"shipHealth", Any{std::decay<decltype(ship_health)>::type{}}},
        {"stunTurns", Any{std::decay<decltype(stun_turns)>::type{}}},
        {"targetPort", Any{std::decay<decltype(target_port)>::type{}}},
        {"tile", Any{std::decay<decltype(tile)>::type{}}},
    },
    acted(variables_["acted"].as<std::decay<decltype(acted)>::type>()),
    crew(variables_["crew"].as<std::decay<decltype(crew)>::type>()),
    crew_health(variables_["crewHealth"].as<std::decay<decltype(crew_health)>::type>()),
    gold(variables_["gold"].as<std::decay<decltype(gold)>::type>()),
    moves(variables_["moves"].as<std::decay<decltype(moves)>::type>()),
    owner(variables_["owner"].as<std::decay<decltype(owner)>::type>()),
    path(variables_["path"].as<std::decay<decltype(path)>::type>()),
    ship_health(variables_["shipHealth"].as<std::decay<decltype(ship_health)>::type>()),
    stun_turns(variables_["stunTurns"].as<std::decay<decltype(stun_turns)>::type>()),
    target_port(variables_["targetPort"].as<std::decay<decltype(target_port)>::type>()),
    tile(variables_["tile"].as<std::decay<decltype(tile)>::type>())
{
    for(auto&& obj : init)
    {
      variables_.emplace(std::make_pair(std::move(obj.first), std::move(obj.second)));
    }
}

Unit_::~Unit_() = default;

void Unit_::resize(const std::string& name, std::size_t size)
{
    if(name == "path")
    {
        auto& vec = variables_["path"].as<std::decay<decltype(path)>::type>();
        vec.resize(size);
        return;
    }
    try
    {
        Game_object_::resize(name, size);
        return;
    }
    catch(...){}
    throw Bad_manipulation(name + " in Unit treated as a vector, but it is not a vector.");
}

void Unit_::change_vec_values(const std::string& name, std::vector<std::pair<std::size_t, Any>>& values)
{
    if(name == "path")
    {
        using type = std::decay<decltype(path)>::type;
        auto& vec = variables_["path"].as<type>();
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
    throw Bad_manipulation(name + " in Unit treated as a vector, but it is not a vector.");
}

void Unit_::remove_key(const std::string& name, Any& key)
{
    try
    {
        Game_object_::remove_key(name, key);
        return;
    }
    catch(...){}
    throw Bad_manipulation(name + " in Unit treated as a map, but it is not a map.");
}

std::unique_ptr<Any> Unit_::add_key_value(const std::string& name, Any& key, Any& value)
{
    try
    {
        return Game_object_::add_key_value(name, key, value);
    }
    catch(...){}
    throw Bad_manipulation(name + " in Unit treated as a map, but it is not a map.");
}

bool Unit_::is_map(const std::string& name)
{
    try
    {
        return Game_object_::is_map(name);
    }
    catch(...){}
    return false;
}

void Unit_::rebind_by_name(Any* to_change, const std::string& member, std::shared_ptr<Base_object> ref)
{
   if(member == "owner")
   { 
      to_change->as<Player>() = std::static_pointer_cast<Player_>(ref);
      return;
   }
   if(member == "targetPort")
   { 
      to_change->as<Port>() = std::static_pointer_cast<Port_>(ref);
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
   throw Bad_manipulation(member + " in Unit treated as a reference, but it is not a reference.");
}


} // pirates

} // cpp_client

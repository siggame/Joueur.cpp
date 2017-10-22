// DO NOT MODIFY THIS FILE
// Never try to directly create an instance of this class, or modify its member variables.
// This contains implementation details, written by code, and only useful to code



#include "../unit.hpp"
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

bool Unit_::attack(const Tile& tile)
{
    std::string order = R"({"event": "run", "data": {"functionName": "attack", "caller": {"id": ")";
    order += this->id + R"("}, "args": {)";

    order += std::string("\"tile\":") + (tile ? (std::string("{\"id\":\"") + tile->id + "\"}") : std::string("null"));

    order += "}}}";
    Catastrophe::instance()->send(order);
    //Go until not a delta
    std::unique_ptr<Any> info;
    //until a not bool is seen (i.e., the delta has been processed)
    do
    {
        info = Catastrophe::instance()->handle_response();
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

bool Unit_::change_job(const std::string& job)
{
    std::string order = R"({"event": "run", "data": {"functionName": "changeJob", "caller": {"id": ")";
    order += this->id + R"("}, "args": {)";

    order += std::string("\"job\":") + std::string("\"") + job + "\"";

    order += "}}}";
    Catastrophe::instance()->send(order);
    //Go until not a delta
    std::unique_ptr<Any> info;
    //until a not bool is seen (i.e., the delta has been processed)
    do
    {
        info = Catastrophe::instance()->handle_response();
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

bool Unit_::construct(const Tile& tile, const std::string& type)
{
    std::string order = R"({"event": "run", "data": {"functionName": "construct", "caller": {"id": ")";
    order += this->id + R"("}, "args": {)";

    order += std::string("\"tile\":") + (tile ? (std::string("{\"id\":\"") + tile->id + "\"}") : std::string("null"));

    order += std::string(",\"type\":") + std::string("\"") + type + "\"";

    order += "}}}";
    Catastrophe::instance()->send(order);
    //Go until not a delta
    std::unique_ptr<Any> info;
    //until a not bool is seen (i.e., the delta has been processed)
    do
    {
        info = Catastrophe::instance()->handle_response();
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

bool Unit_::convert(const Tile& tile)
{
    std::string order = R"({"event": "run", "data": {"functionName": "convert", "caller": {"id": ")";
    order += this->id + R"("}, "args": {)";

    order += std::string("\"tile\":") + (tile ? (std::string("{\"id\":\"") + tile->id + "\"}") : std::string("null"));

    order += "}}}";
    Catastrophe::instance()->send(order);
    //Go until not a delta
    std::unique_ptr<Any> info;
    //until a not bool is seen (i.e., the delta has been processed)
    do
    {
        info = Catastrophe::instance()->handle_response();
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

bool Unit_::deconstruct(const Tile& tile)
{
    std::string order = R"({"event": "run", "data": {"functionName": "deconstruct", "caller": {"id": ")";
    order += this->id + R"("}, "args": {)";

    order += std::string("\"tile\":") + (tile ? (std::string("{\"id\":\"") + tile->id + "\"}") : std::string("null"));

    order += "}}}";
    Catastrophe::instance()->send(order);
    //Go until not a delta
    std::unique_ptr<Any> info;
    //until a not bool is seen (i.e., the delta has been processed)
    do
    {
        info = Catastrophe::instance()->handle_response();
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

bool Unit_::drop(const Tile& tile, const std::string& resource, int amount)
{
    std::string order = R"({"event": "run", "data": {"functionName": "drop", "caller": {"id": ")";
    order += this->id + R"("}, "args": {)";

    order += std::string("\"tile\":") + (tile ? (std::string("{\"id\":\"") + tile->id + "\"}") : std::string("null"));

    order += std::string(",\"resource\":") + std::string("\"") + resource + "\"";

    order += std::string(",\"amount\":") + std::to_string(amount);

    order += "}}}";
    Catastrophe::instance()->send(order);
    //Go until not a delta
    std::unique_ptr<Any> info;
    //until a not bool is seen (i.e., the delta has been processed)
    do
    {
        info = Catastrophe::instance()->handle_response();
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

bool Unit_::harvest(const Tile& tile)
{
    std::string order = R"({"event": "run", "data": {"functionName": "harvest", "caller": {"id": ")";
    order += this->id + R"("}, "args": {)";

    order += std::string("\"tile\":") + (tile ? (std::string("{\"id\":\"") + tile->id + "\"}") : std::string("null"));

    order += "}}}";
    Catastrophe::instance()->send(order);
    //Go until not a delta
    std::unique_ptr<Any> info;
    //until a not bool is seen (i.e., the delta has been processed)
    do
    {
        info = Catastrophe::instance()->handle_response();
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
    Catastrophe::instance()->send(order);
    //Go until not a delta
    std::unique_ptr<Any> info;
    //until a not bool is seen (i.e., the delta has been processed)
    do
    {
        info = Catastrophe::instance()->handle_response();
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

bool Unit_::pickup(const Tile& tile, const std::string& resource, int amount)
{
    std::string order = R"({"event": "run", "data": {"functionName": "pickup", "caller": {"id": ")";
    order += this->id + R"("}, "args": {)";

    order += std::string("\"tile\":") + (tile ? (std::string("{\"id\":\"") + tile->id + "\"}") : std::string("null"));

    order += std::string(",\"resource\":") + std::string("\"") + resource + "\"";

    order += std::string(",\"amount\":") + std::to_string(amount);

    order += "}}}";
    Catastrophe::instance()->send(order);
    //Go until not a delta
    std::unique_ptr<Any> info;
    //until a not bool is seen (i.e., the delta has been processed)
    do
    {
        info = Catastrophe::instance()->handle_response();
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
    Catastrophe::instance()->send(order);
    //Go until not a delta
    std::unique_ptr<Any> info;
    //until a not bool is seen (i.e., the delta has been processed)
    do
    {
        info = Catastrophe::instance()->handle_response();
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
        {"energy", Any{std::decay<decltype(energy)>::type{}}},
        {"food", Any{std::decay<decltype(food)>::type{}}},
        {"job", Any{std::decay<decltype(job)>::type{}}},
        {"materials", Any{std::decay<decltype(materials)>::type{}}},
        {"movementTarget", Any{std::decay<decltype(movement_target)>::type{}}},
        {"moves", Any{std::decay<decltype(moves)>::type{}}},
        {"owner", Any{std::decay<decltype(owner)>::type{}}},
        {"squad", Any{std::decay<decltype(squad)>::type{}}},
        {"starving", Any{std::decay<decltype(starving)>::type{}}},
        {"tile", Any{std::decay<decltype(tile)>::type{}}},
        {"turnsToDie", Any{std::decay<decltype(turns_to_die)>::type{}}},
    },
    acted(variables_["acted"].as<std::decay<decltype(acted)>::type>()),
    energy(variables_["energy"].as<std::decay<decltype(energy)>::type>()),
    food(variables_["food"].as<std::decay<decltype(food)>::type>()),
    job(variables_["job"].as<std::decay<decltype(job)>::type>()),
    materials(variables_["materials"].as<std::decay<decltype(materials)>::type>()),
    movement_target(variables_["movementTarget"].as<std::decay<decltype(movement_target)>::type>()),
    moves(variables_["moves"].as<std::decay<decltype(moves)>::type>()),
    owner(variables_["owner"].as<std::decay<decltype(owner)>::type>()),
    squad(variables_["squad"].as<std::decay<decltype(squad)>::type>()),
    starving(variables_["starving"].as<std::decay<decltype(starving)>::type>()),
    tile(variables_["tile"].as<std::decay<decltype(tile)>::type>()),
    turns_to_die(variables_["turnsToDie"].as<std::decay<decltype(turns_to_die)>::type>())
{
    for(auto&& obj : init)
    {
      variables_.emplace(std::make_pair(std::move(obj.first), std::move(obj.second)));
    }
}

Unit_::~Unit_() = default;

void Unit_::resize(const std::string& name, std::size_t size)
{
    if(name == "squad")
    {
        auto& vec = variables_["squad"].as<std::decay<decltype(squad)>::type>();
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
    if(name == "squad")
    {
        using type = std::decay<decltype(squad)>::type;
        auto& vec = variables_["squad"].as<type>();
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
   if(member == "job")
   { 
      to_change->as<Job>() = std::static_pointer_cast<Job_>(ref);
      return;
   }
   if(member == "movementTarget")
   { 
      to_change->as<Tile>() = std::static_pointer_cast<Tile_>(ref);
      return;
   }
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
   throw Bad_manipulation(member + " in Unit treated as a reference, but it is not a reference.");
}


} // catastrophe

} // cpp_client

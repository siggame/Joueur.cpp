// DO NOT MODIFY THIS FILE
// Never try to directly create an instance of this class, or modify its member variables.
// This contains implementation details, written by code, and only useful to code



#include "../unit.hpp"
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

bool Unit_::attack(const Unit& enemy)
{
    std::string order = R"({"event": "run", "data": {"functionName": "attack", "caller": {"id": ")";
    order += this->id + R"("}, "args": {)";

    order += std::string("\"enemy\":") + (enemy ? (std::string("{\"id\":\"") + enemy->id + "\"}") : std::string("null"));

    order += "}}}";
    Stardash::instance()->send(order);
    //Go until not a delta
    std::unique_ptr<Any> info;
    //until a not bool is seen (i.e., the delta has been processed)
    do
    {
        info = Stardash::instance()->handle_response();
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

bool Unit_::dash(const double& x, const double& y)
{
    std::string order = R"({"event": "run", "data": {"functionName": "dash", "caller": {"id": ")";
    order += this->id + R"("}, "args": {)";

    order += std::string("\"x\":") + std::to_string(x);

    order += std::string(",\"y\":") + std::to_string(y);

    order += "}}}";
    Stardash::instance()->send(order);
    //Go until not a delta
    std::unique_ptr<Any> info;
    //until a not bool is seen (i.e., the delta has been processed)
    do
    {
        info = Stardash::instance()->handle_response();
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

bool Unit_::mine(const Body& body)
{
    std::string order = R"({"event": "run", "data": {"functionName": "mine", "caller": {"id": ")";
    order += this->id + R"("}, "args": {)";

    order += std::string("\"body\":") + (body ? (std::string("{\"id\":\"") + body->id + "\"}") : std::string("null"));

    order += "}}}";
    Stardash::instance()->send(order);
    //Go until not a delta
    std::unique_ptr<Any> info;
    //until a not bool is seen (i.e., the delta has been processed)
    do
    {
        info = Stardash::instance()->handle_response();
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

bool Unit_::move(const double& x, const double& y)
{
    std::string order = R"({"event": "run", "data": {"functionName": "move", "caller": {"id": ")";
    order += this->id + R"("}, "args": {)";

    order += std::string("\"x\":") + std::to_string(x);

    order += std::string(",\"y\":") + std::to_string(y);

    order += "}}}";
    Stardash::instance()->send(order);
    //Go until not a delta
    std::unique_ptr<Any> info;
    //until a not bool is seen (i.e., the delta has been processed)
    do
    {
        info = Stardash::instance()->handle_response();
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

bool Unit_::safe(const double& x, const double& y)
{
    std::string order = R"({"event": "run", "data": {"functionName": "safe", "caller": {"id": ")";
    order += this->id + R"("}, "args": {)";

    order += std::string("\"x\":") + std::to_string(x);

    order += std::string(",\"y\":") + std::to_string(y);

    order += "}}}";
    Stardash::instance()->send(order);
    //Go until not a delta
    std::unique_ptr<Any> info;
    //until a not bool is seen (i.e., the delta has been processed)
    do
    {
        info = Stardash::instance()->handle_response();
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

bool Unit_::shootdown(const Projectile& missile)
{
    std::string order = R"({"event": "run", "data": {"functionName": "shootdown", "caller": {"id": ")";
    order += this->id + R"("}, "args": {)";

    order += std::string("\"missile\":") + (missile ? (std::string("{\"id\":\"") + missile->id + "\"}") : std::string("null"));

    order += "}}}";
    Stardash::instance()->send(order);
    //Go until not a delta
    std::unique_ptr<Any> info;
    //until a not bool is seen (i.e., the delta has been processed)
    do
    {
        info = Stardash::instance()->handle_response();
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

bool Unit_::transfer(const Unit& unit, int amount, const std::string& material)
{
    std::string order = R"({"event": "run", "data": {"functionName": "transfer", "caller": {"id": ")";
    order += this->id + R"("}, "args": {)";

    order += std::string("\"unit\":") + (unit ? (std::string("{\"id\":\"") + unit->id + "\"}") : std::string("null"));

    order += std::string(",\"amount\":") + std::to_string(amount);

    order += std::string(",\"material\":") + std::string("\"") + material + "\"";

    order += "}}}";
    Stardash::instance()->send(order);
    //Go until not a delta
    std::unique_ptr<Any> info;
    //until a not bool is seen (i.e., the delta has been processed)
    do
    {
        info = Stardash::instance()->handle_response();
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
        {"dashX", Any{std::decay<decltype(dash_x)>::type{}}},
        {"dashY", Any{std::decay<decltype(dash_y)>::type{}}},
        {"energy", Any{std::decay<decltype(energy)>::type{}}},
        {"genarium", Any{std::decay<decltype(genarium)>::type{}}},
        {"isBusy", Any{std::decay<decltype(is_busy)>::type{}}},
        {"job", Any{std::decay<decltype(job)>::type{}}},
        {"legendarium", Any{std::decay<decltype(legendarium)>::type{}}},
        {"moves", Any{std::decay<decltype(moves)>::type{}}},
        {"mythicite", Any{std::decay<decltype(mythicite)>::type{}}},
        {"owner", Any{std::decay<decltype(owner)>::type{}}},
        {"protector", Any{std::decay<decltype(protector)>::type{}}},
        {"rarium", Any{std::decay<decltype(rarium)>::type{}}},
        {"shield", Any{std::decay<decltype(shield)>::type{}}},
        {"x", Any{std::decay<decltype(x)>::type{}}},
        {"y", Any{std::decay<decltype(y)>::type{}}},
    },
    acted(variables_["acted"].as<std::decay<decltype(acted)>::type>()),
    dash_x(variables_["dashX"].as<std::decay<decltype(dash_x)>::type>()),
    dash_y(variables_["dashY"].as<std::decay<decltype(dash_y)>::type>()),
    energy(variables_["energy"].as<std::decay<decltype(energy)>::type>()),
    genarium(variables_["genarium"].as<std::decay<decltype(genarium)>::type>()),
    is_busy(variables_["isBusy"].as<std::decay<decltype(is_busy)>::type>()),
    job(variables_["job"].as<std::decay<decltype(job)>::type>()),
    legendarium(variables_["legendarium"].as<std::decay<decltype(legendarium)>::type>()),
    moves(variables_["moves"].as<std::decay<decltype(moves)>::type>()),
    mythicite(variables_["mythicite"].as<std::decay<decltype(mythicite)>::type>()),
    owner(variables_["owner"].as<std::decay<decltype(owner)>::type>()),
    protector(variables_["protector"].as<std::decay<decltype(protector)>::type>()),
    rarium(variables_["rarium"].as<std::decay<decltype(rarium)>::type>()),
    shield(variables_["shield"].as<std::decay<decltype(shield)>::type>()),
    x(variables_["x"].as<std::decay<decltype(x)>::type>()),
    y(variables_["y"].as<std::decay<decltype(y)>::type>())
{
    for(auto&& obj : init)
    {
      variables_.emplace(std::make_pair(std::move(obj.first), std::move(obj.second)));
    }
}

Unit_::~Unit_() = default;

void Unit_::resize(const std::string& name, std::size_t size)
{
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
   if(member == "owner")
   { 
      to_change->as<Player>() = std::static_pointer_cast<Player_>(ref);
      return;
   }
   if(member == "protector")
   { 
      to_change->as<Unit>() = std::static_pointer_cast<Unit_>(ref);
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


} // stardash

} // cpp_client

// DO NOT MODIFY THIS FILE
// Never try to directly create an instance of this class, or modify its member variables.
// This contains implementation details, written by code, and only useful to code



#include "../body.hpp"
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

int Body_::next_x(int num)
{
    std::string order = R"({"event": "run", "data": {"functionName": "nextX", "caller": {"id": ")";
    order += this->id + R"("}, "args": {)";

    order += std::string("\"num\":") + std::to_string(num);

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
    return to_return.as<int>();
}

int Body_::next_y(int num)
{
    std::string order = R"({"event": "run", "data": {"functionName": "nextY", "caller": {"id": ")";
    order += this->id + R"("}, "args": {)";

    order += std::string("\"num\":") + std::to_string(num);

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
    return to_return.as<int>();
}

bool Body_::spawn(const double& x, const double& y, const std::string& title)
{
    std::string order = R"({"event": "run", "data": {"functionName": "spawn", "caller": {"id": ")";
    order += this->id + R"("}, "args": {)";

    order += std::string("\"x\":") + std::to_string(x);

    order += std::string(",\"y\":") + std::to_string(y);

    order += std::string(",\"title\":") + std::string("\"") + title + "\"";

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


Body_::Body_(std::initializer_list<std::pair<std::string, Any&&>> init) :
    Game_object_{
        {"amount", Any{std::decay<decltype(amount)>::type{}}},
        {"bodyType", Any{std::decay<decltype(body_type)>::type{}}},
        {"materialType", Any{std::decay<decltype(material_type)>::type{}}},
        {"owner", Any{std::decay<decltype(owner)>::type{}}},
        {"radius", Any{std::decay<decltype(radius)>::type{}}},
        {"x", Any{std::decay<decltype(x)>::type{}}},
        {"y", Any{std::decay<decltype(y)>::type{}}},
    },
    amount(variables_["amount"].as<std::decay<decltype(amount)>::type>()),
    body_type(variables_["bodyType"].as<std::decay<decltype(body_type)>::type>()),
    material_type(variables_["materialType"].as<std::decay<decltype(material_type)>::type>()),
    owner(variables_["owner"].as<std::decay<decltype(owner)>::type>()),
    radius(variables_["radius"].as<std::decay<decltype(radius)>::type>()),
    x(variables_["x"].as<std::decay<decltype(x)>::type>()),
    y(variables_["y"].as<std::decay<decltype(y)>::type>())
{
    for(auto&& obj : init)
    {
      variables_.emplace(std::make_pair(std::move(obj.first), std::move(obj.second)));
    }
}

Body_::~Body_() = default;

void Body_::resize(const std::string& name, std::size_t size)
{
    try
    {
        Game_object_::resize(name, size);
        return;
    }
    catch(...){}
    throw Bad_manipulation(name + " in Body treated as a vector, but it is not a vector.");
}

void Body_::change_vec_values(const std::string& name, std::vector<std::pair<std::size_t, Any>>& values)
{
    try
    {
        Game_object_::change_vec_values(name, values);
        return;
    }
    catch(...){}
    throw Bad_manipulation(name + " in Body treated as a vector, but it is not a vector.");
}

void Body_::remove_key(const std::string& name, Any& key)
{
    try
    {
        Game_object_::remove_key(name, key);
        return;
    }
    catch(...){}
    throw Bad_manipulation(name + " in Body treated as a map, but it is not a map.");
}

std::unique_ptr<Any> Body_::add_key_value(const std::string& name, Any& key, Any& value)
{
    try
    {
        return Game_object_::add_key_value(name, key, value);
    }
    catch(...){}
    throw Bad_manipulation(name + " in Body treated as a map, but it is not a map.");
}

bool Body_::is_map(const std::string& name)
{
    try
    {
        return Game_object_::is_map(name);
    }
    catch(...){}
    return false;
}

void Body_::rebind_by_name(Any* to_change, const std::string& member, std::shared_ptr<Base_object> ref)
{
   if(member == "owner")
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
   throw Bad_manipulation(member + " in Body treated as a reference, but it is not a reference.");
}


} // stardash

} // cpp_client

// DO NOT MODIFY THIS FILE
// Never try to directly create an instance of this class, or modify its member variables.
// This contains implementation details, written by code, and only useful to code



#include "../spiderling.hpp"
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

bool Spiderling_::attack(const Spiderling& spiderling)
{
    std::string order = R"({"event": "run", "data": {"functionName": "attack", "caller": {"id": ")";
    order += this->id + R"("}, "args": {)";

    order += std::string("\"spiderling\":") + (spiderling ? (std::string("{\"id\":\"") + spiderling->id + "\"}") : std::string("null"));

    order += "}}}";
    Spiders::instance()->send(order);
    //Go until not a delta
    std::unique_ptr<Any> info;
    //until a not bool is seen (i.e., the delta has been processed)
    do
    {
        info = Spiders::instance()->handle_response();
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

bool Spiderling_::move(const Web& web)
{
    std::string order = R"({"event": "run", "data": {"functionName": "move", "caller": {"id": ")";
    order += this->id + R"("}, "args": {)";

    order += std::string("\"web\":") + (web ? (std::string("{\"id\":\"") + web->id + "\"}") : std::string("null"));

    order += "}}}";
    Spiders::instance()->send(order);
    //Go until not a delta
    std::unique_ptr<Any> info;
    //until a not bool is seen (i.e., the delta has been processed)
    do
    {
        info = Spiders::instance()->handle_response();
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


Spiderling_::Spiderling_(std::initializer_list<std::pair<std::string, Any&&>> init) :
    Spider_{
        {"busy", Any{std::decay<decltype(busy)>::type{}}},
        {"movingOnWeb", Any{std::decay<decltype(moving_on_web)>::type{}}},
        {"movingToNest", Any{std::decay<decltype(moving_to_nest)>::type{}}},
        {"numberOfCoworkers", Any{std::decay<decltype(number_of_coworkers)>::type{}}},
        {"workRemaining", Any{std::decay<decltype(work_remaining)>::type{}}},
    },
    busy(variables_["busy"].as<std::decay<decltype(busy)>::type>()),
    moving_on_web(variables_["movingOnWeb"].as<std::decay<decltype(moving_on_web)>::type>()),
    moving_to_nest(variables_["movingToNest"].as<std::decay<decltype(moving_to_nest)>::type>()),
    number_of_coworkers(variables_["numberOfCoworkers"].as<std::decay<decltype(number_of_coworkers)>::type>()),
    work_remaining(variables_["workRemaining"].as<std::decay<decltype(work_remaining)>::type>())
{
    for(auto&& obj : init)
    {
      variables_.emplace(std::make_pair(std::move(obj.first), std::move(obj.second)));
    }
}

Spiderling_::~Spiderling_() = default;

void Spiderling_::resize(const std::string& name, std::size_t size)
{
    try
    {
        Spider_::resize(name, size);
        return;
    }
    catch(...){}
    throw Bad_manipulation(name + " in Spiderling treated as a vector, but it is not a vector.");
}

void Spiderling_::change_vec_values(const std::string& name, std::vector<std::pair<std::size_t, Any>>& values)
{
    try
    {
        Spider_::change_vec_values(name, values);
        return;
    }
    catch(...){}
    throw Bad_manipulation(name + " in Spiderling treated as a vector, but it is not a vector.");
}

void Spiderling_::remove_key(const std::string& name, Any& key)
{
    try
    {
        Spider_::remove_key(name, key);
        return;
    }
    catch(...){}
    throw Bad_manipulation(name + " in Spiderling treated as a map, but it is not a map.");
}

std::unique_ptr<Any> Spiderling_::add_key_value(const std::string& name, Any& key, Any& value)
{
    try
    {
        return Spider_::add_key_value(name, key, value);
    }
    catch(...){}
    throw Bad_manipulation(name + " in Spiderling treated as a map, but it is not a map.");
}

bool Spiderling_::is_map(const std::string& name)
{
    try
    {
        return Spider_::is_map(name);
    }
    catch(...){}
    return false;
}

void Spiderling_::rebind_by_name(Any* to_change, const std::string& member, std::shared_ptr<Base_object> ref)
{
   if(member == "movingOnWeb")
   { 
      to_change->as<Web>() = std::static_pointer_cast<Web_>(ref);
      return;
   }
   if(member == "movingToNest")
   { 
      to_change->as<Nest>() = std::static_pointer_cast<Nest_>(ref);
      return;
   }
   try
   {
      Spider_::rebind_by_name(to_change, member, ref);
      return;
   }
   catch(...){}
   throw Bad_manipulation(member + " in Spiderling treated as a reference, but it is not a reference.");
}


} // spiders

} // cpp_client

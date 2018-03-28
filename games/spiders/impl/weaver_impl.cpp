// DO NOT MODIFY THIS FILE
// Never try to directly create an instance of this class, or modify its member variables.
// This contains implementation details, written by code, and only useful to code



#include "../weaver.hpp"
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

bool Weaver_::strengthen(const Web& web)
{
    std::string order = R"({"event": "run", "data": {"functionName": "strengthen", "caller": {"id": ")";
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

bool Weaver_::weaken(const Web& web)
{
    std::string order = R"({"event": "run", "data": {"functionName": "weaken", "caller": {"id": ")";
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


Weaver_::Weaver_(std::initializer_list<std::pair<std::string, Any&&>> init) :
    Spiderling_{
        {"strengtheningWeb", Any{std::decay<decltype(strengthening_web)>::type{}}},
        {"weakeningWeb", Any{std::decay<decltype(weakening_web)>::type{}}},
    },
    strengthening_web(variables_["strengtheningWeb"].as<std::decay<decltype(strengthening_web)>::type>()),
    weakening_web(variables_["weakeningWeb"].as<std::decay<decltype(weakening_web)>::type>())
{
    for(auto&& obj : init)
    {
      variables_.emplace(std::make_pair(std::move(obj.first), std::move(obj.second)));
    }
}

Weaver_::~Weaver_() = default;

void Weaver_::resize(const std::string& name, std::size_t size)
{
    try
    {
        Spiderling_::resize(name, size);
        return;
    }
    catch(...){}
    throw Bad_manipulation(name + " in Weaver treated as a vector, but it is not a vector.");
}

void Weaver_::change_vec_values(const std::string& name, std::vector<std::pair<std::size_t, Any>>& values)
{
    try
    {
        Spiderling_::change_vec_values(name, values);
        return;
    }
    catch(...){}
    throw Bad_manipulation(name + " in Weaver treated as a vector, but it is not a vector.");
}

void Weaver_::remove_key(const std::string& name, Any& key)
{
    try
    {
        Spiderling_::remove_key(name, key);
        return;
    }
    catch(...){}
    throw Bad_manipulation(name + " in Weaver treated as a map, but it is not a map.");
}

std::unique_ptr<Any> Weaver_::add_key_value(const std::string& name, Any& key, Any& value)
{
    try
    {
        return Spiderling_::add_key_value(name, key, value);
    }
    catch(...){}
    throw Bad_manipulation(name + " in Weaver treated as a map, but it is not a map.");
}

bool Weaver_::is_map(const std::string& name)
{
    try
    {
        return Spiderling_::is_map(name);
    }
    catch(...){}
    return false;
}

void Weaver_::rebind_by_name(Any* to_change, const std::string& member, std::shared_ptr<Base_object> ref)
{
   if(member == "strengtheningWeb")
   { 
      to_change->as<Web>() = std::static_pointer_cast<Web_>(ref);
      return;
   }
   if(member == "weakeningWeb")
   { 
      to_change->as<Web>() = std::static_pointer_cast<Web_>(ref);
      return;
   }
   try
   {
      Spiderling_::rebind_by_name(to_change, member, ref);
      return;
   }
   catch(...){}
   throw Bad_manipulation(member + " in Weaver treated as a reference, but it is not a reference.");
}


} // spiders

} // cpp_client

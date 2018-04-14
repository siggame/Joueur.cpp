// DO NOT MODIFY THIS FILE
// Never try to directly create an instance of this class, or modify its member variables.
// This contains implementation details, written by code, and only useful to code



#include "../spitter.hpp"
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

bool Spitter_::spit(const Nest& nest)
{
    std::string order = R"({"event": "run", "data": {"functionName": "spit", "caller": {"id": ")";
    order += this->id + R"("}, "args": {)";

    order += std::string("\"nest\":") + (nest ? (std::string("{\"id\":\"") + nest->id + "\"}") : std::string("null"));

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


Spitter_::Spitter_(std::initializer_list<std::pair<std::string, Any&&>> init) :
    Spiderling_{
        {"spittingWebToNest", Any{std::decay<decltype(spitting_web_to_nest)>::type{}}},
    },
    spitting_web_to_nest(variables_["spittingWebToNest"].as<std::decay<decltype(spitting_web_to_nest)>::type>())
{
    for(auto&& obj : init)
    {
      variables_.emplace(std::make_pair(std::move(obj.first), std::move(obj.second)));
    }
}

Spitter_::~Spitter_() = default;

void Spitter_::resize(const std::string& name, std::size_t size)
{
    try
    {
        Spiderling_::resize(name, size);
        return;
    }
    catch(...){}
    throw Bad_manipulation(name + " in Spitter treated as a vector, but it is not a vector.");
}

void Spitter_::change_vec_values(const std::string& name, std::vector<std::pair<std::size_t, Any>>& values)
{
    try
    {
        Spiderling_::change_vec_values(name, values);
        return;
    }
    catch(...){}
    throw Bad_manipulation(name + " in Spitter treated as a vector, but it is not a vector.");
}

void Spitter_::remove_key(const std::string& name, Any& key)
{
    try
    {
        Spiderling_::remove_key(name, key);
        return;
    }
    catch(...){}
    throw Bad_manipulation(name + " in Spitter treated as a map, but it is not a map.");
}

std::unique_ptr<Any> Spitter_::add_key_value(const std::string& name, Any& key, Any& value)
{
    try
    {
        return Spiderling_::add_key_value(name, key, value);
    }
    catch(...){}
    throw Bad_manipulation(name + " in Spitter treated as a map, but it is not a map.");
}

bool Spitter_::is_map(const std::string& name)
{
    try
    {
        return Spiderling_::is_map(name);
    }
    catch(...){}
    return false;
}

void Spitter_::rebind_by_name(Any* to_change, const std::string& member, std::shared_ptr<Base_object> ref)
{
   if(member == "spittingWebToNest")
   { 
      to_change->as<Nest>() = std::static_pointer_cast<Nest_>(ref);
      return;
   }
   try
   {
      Spiderling_::rebind_by_name(to_change, member, ref);
      return;
   }
   catch(...){}
   throw Bad_manipulation(member + " in Spitter treated as a reference, but it is not a reference.");
}


} // spiders

} // cpp_client

// DO NOT MODIFY THIS FILE
// Never try to directly create an instance of this class, or modify its member variables.
// This contains implementation details, written by code, and only useful to code



#include "../brood_mother.hpp"
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

bool Brood_mother_::consume(const Spiderling& spiderling)
{
    std::string order = R"({"event": "run", "data": {"functionName": "consume", "caller": {"id": ")";
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

Spiderling Brood_mother_::spawn(const std::string& spiderling_type)
{
    std::string order = R"({"event": "run", "data": {"functionName": "spawn", "caller": {"id": ")";
    order += this->id + R"("}, "args": {)";

    order += std::string("\"spiderlingType\":") + std::string("\"") + spiderling_type + "\"";

    order += "}}}";
    Spiders::instance()->send(order);
    //Go until not a delta
    std::unique_ptr<Any> info;
    //until a not bool is seen (i.e., the delta has been processed)
    do
    {
        info = Spiders::instance()->handle_response();
    } while(info->type() == typeid(bool));
    //reference - just pull the id
    auto doc = info->as<rapidjson::Document*>();
    auto loc = doc->FindMember("data");
    if(loc == doc->MemberEnd())
    {
        return nullptr;
    }
    auto& val = loc->value;
    if(val.IsNull())
    {
        return nullptr;
    }
    else
    {
        auto target = attr_wrapper::get_attribute<std::string>(val, "id");
        return std::dynamic_pointer_cast<Spiderling_>(Spiders::instance()->get_objects()[target]);
    }
}


Brood_mother_::Brood_mother_(std::initializer_list<std::pair<std::string, Any&&>> init) :
    Spider_{
        {"eggs", Any{std::decay<decltype(eggs)>::type{}}},
        {"health", Any{std::decay<decltype(health)>::type{}}},
    },
    eggs(variables_["eggs"].as<std::decay<decltype(eggs)>::type>()),
    health(variables_["health"].as<std::decay<decltype(health)>::type>())
{
    for(auto&& obj : init)
    {
      variables_.emplace(std::make_pair(std::move(obj.first), std::move(obj.second)));
    }
}

Brood_mother_::~Brood_mother_() = default;

void Brood_mother_::resize(const std::string& name, std::size_t size)
{
    try
    {
        Spider_::resize(name, size);
        return;
    }
    catch(...){}
    throw Bad_manipulation(name + " in Brood_mother treated as a vector, but it is not a vector.");
}

void Brood_mother_::change_vec_values(const std::string& name, std::vector<std::pair<std::size_t, Any>>& values)
{
    try
    {
        Spider_::change_vec_values(name, values);
        return;
    }
    catch(...){}
    throw Bad_manipulation(name + " in Brood_mother treated as a vector, but it is not a vector.");
}

void Brood_mother_::remove_key(const std::string& name, Any& key)
{
    try
    {
        Spider_::remove_key(name, key);
        return;
    }
    catch(...){}
    throw Bad_manipulation(name + " in Brood_mother treated as a map, but it is not a map.");
}

std::unique_ptr<Any> Brood_mother_::add_key_value(const std::string& name, Any& key, Any& value)
{
    try
    {
        return Spider_::add_key_value(name, key, value);
    }
    catch(...){}
    throw Bad_manipulation(name + " in Brood_mother treated as a map, but it is not a map.");
}

bool Brood_mother_::is_map(const std::string& name)
{
    try
    {
        return Spider_::is_map(name);
    }
    catch(...){}
    return false;
}

void Brood_mother_::rebind_by_name(Any* to_change, const std::string& member, std::shared_ptr<Base_object> ref)
{
   try
   {
      Spider_::rebind_by_name(to_change, member, ref);
      return;
   }
   catch(...){}
   throw Bad_manipulation(member + " in Brood_mother treated as a reference, but it is not a reference.");
}


} // spiders

} // cpp_client

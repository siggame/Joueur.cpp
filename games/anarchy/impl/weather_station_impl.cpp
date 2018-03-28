// DO NOT MODIFY THIS FILE
// Never try to directly create an instance of this class, or modify its member variables.
// This contains implementation details, written by code, and only useful to code



#include "../weather_station.hpp"
#include "../../../joueur/src/base_ai.hpp"
#include "../../../joueur/src/any.hpp"
#include "../../../joueur/src/exceptions.hpp"
#include "../../../joueur/src/delta.hpp"
#include "../building.hpp"
#include "../fire_department.hpp"
#include "../forecast.hpp"
#include "../game_object.hpp"
#include "../player.hpp"
#include "../police_department.hpp"
#include "../warehouse.hpp"
#include "../weather_station.hpp"
#include "anarchy.hpp"

#include <type_traits>

namespace cpp_client
{

namespace anarchy
{

bool Weather_station_::intensify(bool negative)
{
    std::string order = R"({"event": "run", "data": {"functionName": "intensify", "caller": {"id": ")";
    order += this->id + R"("}, "args": {)";

    order += std::string("\"negative\":") + std::to_string(negative);

    order += "}}}";
    Anarchy::instance()->send(order);
    //Go until not a delta
    std::unique_ptr<Any> info;
    //until a not bool is seen (i.e., the delta has been processed)
    do
    {
        info = Anarchy::instance()->handle_response();
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

bool Weather_station_::rotate(bool counterclockwise)
{
    std::string order = R"({"event": "run", "data": {"functionName": "rotate", "caller": {"id": ")";
    order += this->id + R"("}, "args": {)";

    order += std::string("\"counterclockwise\":") + std::to_string(counterclockwise);

    order += "}}}";
    Anarchy::instance()->send(order);
    //Go until not a delta
    std::unique_ptr<Any> info;
    //until a not bool is seen (i.e., the delta has been processed)
    do
    {
        info = Anarchy::instance()->handle_response();
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


Weather_station_::Weather_station_(std::initializer_list<std::pair<std::string, Any&&>> init) :
    Building_{
    }
{
    for(auto&& obj : init)
    {
      variables_.emplace(std::make_pair(std::move(obj.first), std::move(obj.second)));
    }
}

Weather_station_::~Weather_station_() = default;

void Weather_station_::resize(const std::string& name, std::size_t size)
{
    try
    {
        Building_::resize(name, size);
        return;
    }
    catch(...){}
    throw Bad_manipulation(name + " in Weather_station treated as a vector, but it is not a vector.");
}

void Weather_station_::change_vec_values(const std::string& name, std::vector<std::pair<std::size_t, Any>>& values)
{
    try
    {
        Building_::change_vec_values(name, values);
        return;
    }
    catch(...){}
    throw Bad_manipulation(name + " in Weather_station treated as a vector, but it is not a vector.");
}

void Weather_station_::remove_key(const std::string& name, Any& key)
{
    try
    {
        Building_::remove_key(name, key);
        return;
    }
    catch(...){}
    throw Bad_manipulation(name + " in Weather_station treated as a map, but it is not a map.");
}

std::unique_ptr<Any> Weather_station_::add_key_value(const std::string& name, Any& key, Any& value)
{
    try
    {
        return Building_::add_key_value(name, key, value);
    }
    catch(...){}
    throw Bad_manipulation(name + " in Weather_station treated as a map, but it is not a map.");
}

bool Weather_station_::is_map(const std::string& name)
{
    try
    {
        return Building_::is_map(name);
    }
    catch(...){}
    return false;
}

void Weather_station_::rebind_by_name(Any* to_change, const std::string& member, std::shared_ptr<Base_object> ref)
{
   try
   {
      Building_::rebind_by_name(to_change, member, ref);
      return;
   }
   catch(...){}
   throw Bad_manipulation(member + " in Weather_station treated as a reference, but it is not a reference.");
}


} // anarchy

} // cpp_client

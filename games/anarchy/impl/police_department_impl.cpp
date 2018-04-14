// DO NOT MODIFY THIS FILE
// Never try to directly create an instance of this class, or modify its member variables.
// This contains implementation details, written by code, and only useful to code



#include "../police_department.hpp"
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

int Police_department_::raid(const Warehouse& warehouse)
{
    std::string order = R"({"event": "run", "data": {"functionName": "raid", "caller": {"id": ")";
    order += this->id + R"("}, "args": {)";

    order += std::string("\"warehouse\":") + (warehouse ? (std::string("{\"id\":\"") + warehouse->id + "\"}") : std::string("null"));

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
    return to_return.as<int>();
}


Police_department_::Police_department_(std::initializer_list<std::pair<std::string, Any&&>> init) :
    Building_{
    }
{
    for(auto&& obj : init)
    {
      variables_.emplace(std::make_pair(std::move(obj.first), std::move(obj.second)));
    }
}

Police_department_::~Police_department_() = default;

void Police_department_::resize(const std::string& name, std::size_t size)
{
    try
    {
        Building_::resize(name, size);
        return;
    }
    catch(...){}
    throw Bad_manipulation(name + " in Police_department treated as a vector, but it is not a vector.");
}

void Police_department_::change_vec_values(const std::string& name, std::vector<std::pair<std::size_t, Any>>& values)
{
    try
    {
        Building_::change_vec_values(name, values);
        return;
    }
    catch(...){}
    throw Bad_manipulation(name + " in Police_department treated as a vector, but it is not a vector.");
}

void Police_department_::remove_key(const std::string& name, Any& key)
{
    try
    {
        Building_::remove_key(name, key);
        return;
    }
    catch(...){}
    throw Bad_manipulation(name + " in Police_department treated as a map, but it is not a map.");
}

std::unique_ptr<Any> Police_department_::add_key_value(const std::string& name, Any& key, Any& value)
{
    try
    {
        return Building_::add_key_value(name, key, value);
    }
    catch(...){}
    throw Bad_manipulation(name + " in Police_department treated as a map, but it is not a map.");
}

bool Police_department_::is_map(const std::string& name)
{
    try
    {
        return Building_::is_map(name);
    }
    catch(...){}
    return false;
}

void Police_department_::rebind_by_name(Any* to_change, const std::string& member, std::shared_ptr<Base_object> ref)
{
   try
   {
      Building_::rebind_by_name(to_change, member, ref);
      return;
   }
   catch(...){}
   throw Bad_manipulation(member + " in Police_department treated as a reference, but it is not a reference.");
}


} // anarchy

} // cpp_client

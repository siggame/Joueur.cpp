// DO NOT MODIFY THIS FILE
// Never try to directly create an instance of this class, or modify its member variables.
// This contains implementation details, written by code, and only useful to code



#include "../young_gun.hpp"
#include "../../../joueur/src/base_ai.hpp"
#include "../../../joueur/src/any.hpp"
#include "../../../joueur/src/exceptions.hpp"
#include "../../../joueur/src/delta.hpp"
#include "../bottle.hpp"
#include "../cowboy.hpp"
#include "../furnishing.hpp"
#include "../game_object.hpp"
#include "../player.hpp"
#include "../tile.hpp"
#include "../young_gun.hpp"
#include "saloon.hpp"

#include <type_traits>

namespace cpp_client
{

namespace saloon
{

Cowboy Young_gun_::call_in(const std::string& job)
{
    std::string order = R"({"event": "run", "data": {"functionName": "callIn", "caller": {"id": ")";
    order += this->id + R"("}, "args": {)";

    order += std::string("\"job\":") + std::string("\"") + job + "\"";

    order += "}}}";
    Saloon::instance()->send(order);
    //Go until not a delta
    std::unique_ptr<Any> info;
    //until a not bool is seen (i.e., the delta has been processed)
    do
    {
        info = Saloon::instance()->handle_response();
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
        return std::dynamic_pointer_cast<Cowboy_>(Saloon::instance()->get_objects()[target]);
    }
}


Young_gun_::Young_gun_(std::initializer_list<std::pair<std::string, Any&&>> init) :
    Game_object_{
        {"callInTile", Any{std::decay<decltype(call_in_tile)>::type{}}},
        {"canCallIn", Any{std::decay<decltype(can_call_in)>::type{}}},
        {"owner", Any{std::decay<decltype(owner)>::type{}}},
        {"tile", Any{std::decay<decltype(tile)>::type{}}},
    },
    call_in_tile(variables_["callInTile"].as<std::decay<decltype(call_in_tile)>::type>()),
    can_call_in(variables_["canCallIn"].as<std::decay<decltype(can_call_in)>::type>()),
    owner(variables_["owner"].as<std::decay<decltype(owner)>::type>()),
    tile(variables_["tile"].as<std::decay<decltype(tile)>::type>())
{
    for(auto&& obj : init)
    {
      variables_.emplace(std::make_pair(std::move(obj.first), std::move(obj.second)));
    }
}

Young_gun_::~Young_gun_() = default;

void Young_gun_::resize(const std::string& name, std::size_t size)
{
    try
    {
        Game_object_::resize(name, size);
        return;
    }
    catch(...){}
    throw Bad_manipulation(name + " in Young_gun treated as a vector, but it is not a vector.");
}

void Young_gun_::change_vec_values(const std::string& name, std::vector<std::pair<std::size_t, Any>>& values)
{
    try
    {
        Game_object_::change_vec_values(name, values);
        return;
    }
    catch(...){}
    throw Bad_manipulation(name + " in Young_gun treated as a vector, but it is not a vector.");
}

void Young_gun_::remove_key(const std::string& name, Any& key)
{
    try
    {
        Game_object_::remove_key(name, key);
        return;
    }
    catch(...){}
    throw Bad_manipulation(name + " in Young_gun treated as a map, but it is not a map.");
}

std::unique_ptr<Any> Young_gun_::add_key_value(const std::string& name, Any& key, Any& value)
{
    try
    {
        return Game_object_::add_key_value(name, key, value);
    }
    catch(...){}
    throw Bad_manipulation(name + " in Young_gun treated as a map, but it is not a map.");
}

bool Young_gun_::is_map(const std::string& name)
{
    try
    {
        return Game_object_::is_map(name);
    }
    catch(...){}
    return false;
}

void Young_gun_::rebind_by_name(Any* to_change, const std::string& member, std::shared_ptr<Base_object> ref)
{
   if(member == "callInTile")
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
   throw Bad_manipulation(member + " in Young_gun treated as a reference, but it is not a reference.");
}


} // saloon

} // cpp_client

// DO NOT MODIFY THIS FILE
// Never try to directly create an instance of this class, or modify its member variables.
// This contains implementation details, written by code, and only useful to code

#include "../job.hpp"
#include "../../../joueur/src/base_ai.hpp"
#include "../../../joueur/src/any.hpp"
#include "../../../joueur/src/exceptions.hpp"
#include "../../../joueur/src/delta.hpp"
#include "../beaver.hpp"
#include "../game_object.hpp"
#include "../job.hpp"
#include "../player.hpp"
#include "../spawner.hpp"
#include "../tile.hpp"
#include "stumped.hpp"

#include <type_traits>

namespace cpp_client
{

namespace stumped
{

Beaver Job_::recruit(const Tile& tile)
{
    std::string order = R"({"event": "run", "data": {"functionName": "recruit", "caller": {"id": ")";
    order += this->id + R"("}, "args": {)";

    order += std::string("\"tile\":") + "{\"id\":" + tile->id + "}";

    order += "}}}";
    Stumped::instance()->send(order);
    //Go until not a delta
    std::unique_ptr<Any> info;
    //until a not bool is seen (i.e., the delta has been processed)
    do
    {
        info = std::move(Stumped::instance()->handle_response());
    } while(info->type() == typeid(bool));
    //reference - just pull the id
    auto& val = info->as<rapidjson::Document*>()->FindMember("data")->value;
    if(val.IsNull())
    {
        return nullptr;
    }
    else
    {
        auto target = attr_wrapper::get_attribute<std::string>(val, "id");
        return std::dynamic_pointer_cast<Beaver_>(Stumped::instance()->get_objects()[target]);
    }
}


Job_::Job_(std::initializer_list<std::pair<std::string, Any&&>> init) :
    Game_object_{
        {"actions", Any{std::decay<decltype(actions)>::type{}}},
        {"carryLimit", Any{std::decay<decltype(carry_limit)>::type{}}},
        {"chopping", Any{std::decay<decltype(chopping)>::type{}}},
        {"cost", Any{std::decay<decltype(cost)>::type{}}},
        {"damage", Any{std::decay<decltype(damage)>::type{}}},
        {"distractionPower", Any{std::decay<decltype(distraction_power)>::type{}}},
        {"health", Any{std::decay<decltype(health)>::type{}}},
        {"moves", Any{std::decay<decltype(moves)>::type{}}},
        {"munching", Any{std::decay<decltype(munching)>::type{}}},
        {"title", Any{std::decay<decltype(title)>::type{}}},
    },
    actions(variables_["actions"].as<std::decay<decltype(actions)>::type>()),
    carry_limit(variables_["carryLimit"].as<std::decay<decltype(carry_limit)>::type>()),
    chopping(variables_["chopping"].as<std::decay<decltype(chopping)>::type>()),
    cost(variables_["cost"].as<std::decay<decltype(cost)>::type>()),
    damage(variables_["damage"].as<std::decay<decltype(damage)>::type>()),
    distraction_power(variables_["distractionPower"].as<std::decay<decltype(distraction_power)>::type>()),
    health(variables_["health"].as<std::decay<decltype(health)>::type>()),
    moves(variables_["moves"].as<std::decay<decltype(moves)>::type>()),
    munching(variables_["munching"].as<std::decay<decltype(munching)>::type>()),
    title(variables_["title"].as<std::decay<decltype(title)>::type>())
{
    for(auto&& obj : init)
    {
      variables_.emplace(std::make_pair(std::move(obj.first), std::move(obj.second)));
    }
}

Job_::~Job_() = default;

void Job_::resize(const std::string& name, std::size_t size)
{
    try
    {
        Game_object_::resize(name, size);
        return;
    }
    catch(...){}
    throw Bad_manipulation(name + " in Job treated as a vector, but it is not a vector.");
}

void Job_::change_vec_values(const std::string& name, std::vector<std::pair<std::size_t, Any>>& values)
{
    try
    {
        Game_object_::change_vec_values(name, values);
        return;
    }
    catch(...){}
    throw Bad_manipulation(name + " in Job treated as a vector, but it is not a vector.");
}

void Job_::remove_key(const std::string& name, Any& key)
{
    try
    {
        Game_object_::remove_key(name, key);
        return;
    }
    catch(...){}
    throw Bad_manipulation(name + " in Job treated as a map, but it is not a map.");
}

std::unique_ptr<Any> Job_::add_key_value(const std::string& name, Any& key, Any& value)
{
    try
    {
        return Game_object_::add_key_value(name, key, value);
    }
    catch(...){}
    throw Bad_manipulation(name + " in Job treated as a map, but it is not a map.");
}

bool Job_::is_map(const std::string& name)
{
    try
    {
        return Game_object_::is_map(name);
    }
    catch(...){}
    return false;
}

void Job_::rebind_by_name(Any* to_change, const std::string& member, std::shared_ptr<Base_object> ref)
{
   try
   {
      Game_object_::rebind_by_name(to_change, member, ref);
      return;
   }
   catch(...){}
   throw Bad_manipulation(member + " in Job treated as a reference, but it is not a reference.");
}


} // stumped

} // cpp_client

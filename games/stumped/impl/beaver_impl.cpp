// DO NOT MODIFY THIS FILE
// Never try to directly create an instance of this class, or modify its member variables.
// This contains implementation details, written by code, and only useful to code

#include "../beaver.hpp"
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

bool Beaver_::attack(const Tile& tile)
{
    std::string order = R"({"event": "run", "data": {"functionName": "attack", "caller": {"id": ")";
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
    auto& val = info->as<rapidjson::Document*>()->FindMember("data")->value;
    Any to_return;
    morph_any(to_return, val);
    return to_return.as<bool>();
}

bool Beaver_::build_lodge()
{
    std::string order = R"({"event": "run", "data": {"functionName": "build_lodge", "caller": {"id": ")";
    order += this->id + R"("}, "args": {)";

    order += "}}}";
    Stumped::instance()->send(order);
    //Go until not a delta
    std::unique_ptr<Any> info;
    //until a not bool is seen (i.e., the delta has been processed)
    do
    {
        info = std::move(Stumped::instance()->handle_response());
    } while(info->type() == typeid(bool));
    auto& val = info->as<rapidjson::Document*>()->FindMember("data")->value;
    Any to_return;
    morph_any(to_return, val);
    return to_return.as<bool>();
}

bool Beaver_::drop(const std::string& resource, int amount)
{
    std::string order = R"({"event": "run", "data": {"functionName": "drop", "caller": {"id": ")";
    order += this->id + R"("}, "args": {)";

    order += std::string("\"resource\":") + std::string("\"") + resource + "\"";

    order += std::string(",\"amount\":") + std::to_string(amount);

    order += "}}}";
    Stumped::instance()->send(order);
    //Go until not a delta
    std::unique_ptr<Any> info;
    //until a not bool is seen (i.e., the delta has been processed)
    do
    {
        info = std::move(Stumped::instance()->handle_response());
    } while(info->type() == typeid(bool));
    auto& val = info->as<rapidjson::Document*>()->FindMember("data")->value;
    Any to_return;
    morph_any(to_return, val);
    return to_return.as<bool>();
}

bool Beaver_::harvest(const Tile& tile)
{
    std::string order = R"({"event": "run", "data": {"functionName": "harvest", "caller": {"id": ")";
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
    auto& val = info->as<rapidjson::Document*>()->FindMember("data")->value;
    Any to_return;
    morph_any(to_return, val);
    return to_return.as<bool>();
}

bool Beaver_::move(const Tile& tile)
{
    std::string order = R"({"event": "run", "data": {"functionName": "move", "caller": {"id": ")";
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
    auto& val = info->as<rapidjson::Document*>()->FindMember("data")->value;
    Any to_return;
    morph_any(to_return, val);
    return to_return.as<bool>();
}

bool Beaver_::pickup(const std::string& resource, int amount)
{
    std::string order = R"({"event": "run", "data": {"functionName": "pickup", "caller": {"id": ")";
    order += this->id + R"("}, "args": {)";

    order += std::string("\"resource\":") + std::string("\"") + resource + "\"";

    order += std::string(",\"amount\":") + std::to_string(amount);

    order += "}}}";
    Stumped::instance()->send(order);
    //Go until not a delta
    std::unique_ptr<Any> info;
    //until a not bool is seen (i.e., the delta has been processed)
    do
    {
        info = std::move(Stumped::instance()->handle_response());
    } while(info->type() == typeid(bool));
    auto& val = info->as<rapidjson::Document*>()->FindMember("data")->value;
    Any to_return;
    morph_any(to_return, val);
    return to_return.as<bool>();
}


Beaver_::Beaver_(std::initializer_list<std::pair<std::string, Any&&>> init) :
    Game_object_{
        {"actions", Any{std::decay<decltype(actions)>::type{}}},
        {"branches", Any{std::decay<decltype(branches)>::type{}}},
        {"distracted", Any{std::decay<decltype(distracted)>::type{}}},
        {"fish", Any{std::decay<decltype(fish)>::type{}}},
        {"health", Any{std::decay<decltype(health)>::type{}}},
        {"job", Any{std::decay<decltype(job)>::type{}}},
        {"moves", Any{std::decay<decltype(moves)>::type{}}},
        {"owner", Any{std::decay<decltype(owner)>::type{}}},
        {"tile", Any{std::decay<decltype(tile)>::type{}}},
    },
    actions(variables_["actions"].as<std::decay<decltype(actions)>::type>()),
    branches(variables_["branches"].as<std::decay<decltype(branches)>::type>()),
    distracted(variables_["distracted"].as<std::decay<decltype(distracted)>::type>()),
    fish(variables_["fish"].as<std::decay<decltype(fish)>::type>()),
    health(variables_["health"].as<std::decay<decltype(health)>::type>()),
    job(variables_["job"].as<std::decay<decltype(job)>::type>()),
    moves(variables_["moves"].as<std::decay<decltype(moves)>::type>()),
    owner(variables_["owner"].as<std::decay<decltype(owner)>::type>()),
    tile(variables_["tile"].as<std::decay<decltype(tile)>::type>())
{
    for(auto&& obj : init)
    {
      variables_.emplace(std::make_pair(std::move(obj.first), std::move(obj.second)));
    }
}

Beaver_::~Beaver_() = default;

void Beaver_::resize(const std::string& name, std::size_t size)
{
    try
    {
        Game_object_::resize(name, size);
        return;
    }
    catch(...){}
    throw Bad_manipulation(name + " in Beaver treated as a vector, but it is not a vector.");
}

void Beaver_::change_vec_values(const std::string& name, std::vector<std::pair<std::size_t, Any>>& values)
{
    try
    {
        Game_object_::change_vec_values(name, values);
        return;
    }
    catch(...){}
    throw Bad_manipulation(name + " in Beaver treated as a vector, but it is not a vector.");
}

void Beaver_::remove_key(const std::string& name, Any& key)
{
    try
    {
        Game_object_::remove_key(name, key);
        return;
    }
    catch(...){}
    throw Bad_manipulation(name + " in Beaver treated as a map, but it is not a map.");
}

std::unique_ptr<Any> Beaver_::add_key_value(const std::string& name, Any& key, Any& value)
{
    try
    {
        return Game_object_::add_key_value(name, key, value);
    }
    catch(...){}
    throw Bad_manipulation(name + " in Beaver treated as a map, but it is not a map.");
}

bool Beaver_::is_map(const std::string& name)
{
    return false;
}

void Beaver_::rebind_by_name(Any* to_change, const std::string& member, std::shared_ptr<Base_object> ref)
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
   if(member == "tile")
   { 
      to_change->as<Tile>() = std::static_pointer_cast<Tile_>(ref);
      return;
   }
   throw Bad_manipulation(member + " in Beaver treated as a reference, but it is not a reference.");
}


} // stumped

} // cpp_client

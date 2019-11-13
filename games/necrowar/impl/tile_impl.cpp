// DO NOT MODIFY THIS FILE
// Never try to directly create an instance of this class, or modify its member variables.
// This contains implementation details, written by code, and only useful to code



#include "../tile.hpp"
#include "../../../joueur/src/base_ai.hpp"
#include "../../../joueur/src/any.hpp"
#include "../../../joueur/src/exceptions.hpp"
#include "../../../joueur/src/delta.hpp"
#include "../game_object.hpp"
#include "../player.hpp"
#include "../tile.hpp"
#include "../tower.hpp"
#include "../tower_job.hpp"
#include "../unit.hpp"
#include "../unit_job.hpp"
#include "necrowar.hpp"

#include <type_traits>

namespace cpp_client
{

namespace necrowar
{

bool Tile_::res(int num)
{
    std::string order = R"({"event": "run", "data": {"functionName": "res", "caller": {"id": ")";
    order += this->id + R"("}, "args": {)";

    order += std::string("\"num\":") + std::to_string(num);

    order += "}}}";
    Necrowar::instance()->send(order);
    //Go until not a delta
    std::unique_ptr<Any> info;
    //until a not bool is seen (i.e., the delta has been processed)
    do
    {
        info = Necrowar::instance()->handle_response();
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

bool Tile_::spawn_unit(const std::string& title)
{
    std::string order = R"({"event": "run", "data": {"functionName": "spawnUnit", "caller": {"id": ")";
    order += this->id + R"("}, "args": {)";

    order += std::string("\"title\":") + std::string("\"") + title + "\"";

    order += "}}}";
    Necrowar::instance()->send(order);
    //Go until not a delta
    std::unique_ptr<Any> info;
    //until a not bool is seen (i.e., the delta has been processed)
    do
    {
        info = Necrowar::instance()->handle_response();
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

bool Tile_::spawn_worker()
{
    std::string order = R"({"event": "run", "data": {"functionName": "spawnWorker", "caller": {"id": ")";
    order += this->id + R"("}, "args": {)";

    order += "}}}";
    Necrowar::instance()->send(order);
    //Go until not a delta
    std::unique_ptr<Any> info;
    //until a not bool is seen (i.e., the delta has been processed)
    do
    {
        info = Necrowar::instance()->handle_response();
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


Tile_::Tile_(std::initializer_list<std::pair<std::string, Any&&>> init) :
    Game_object_{
        {"corpses", Any{std::decay<decltype(corpses)>::type{}}},
        {"isCastle", Any{std::decay<decltype(is_castle)>::type{}}},
        {"isGoldMine", Any{std::decay<decltype(is_gold_mine)>::type{}}},
        {"isGrass", Any{std::decay<decltype(is_grass)>::type{}}},
        {"isIslandGoldMine", Any{std::decay<decltype(is_island_gold_mine)>::type{}}},
        {"isPath", Any{std::decay<decltype(is_path)>::type{}}},
        {"isRiver", Any{std::decay<decltype(is_river)>::type{}}},
        {"isTower", Any{std::decay<decltype(is_tower)>::type{}}},
        {"isUnitSpawn", Any{std::decay<decltype(is_unit_spawn)>::type{}}},
        {"isWall", Any{std::decay<decltype(is_wall)>::type{}}},
        {"isWorkerSpawn", Any{std::decay<decltype(is_worker_spawn)>::type{}}},
        {"numGhouls", Any{std::decay<decltype(num_ghouls)>::type{}}},
        {"numHounds", Any{std::decay<decltype(num_hounds)>::type{}}},
        {"numZombies", Any{std::decay<decltype(num_zombies)>::type{}}},
        {"owner", Any{std::decay<decltype(owner)>::type{}}},
        {"tileEast", Any{std::decay<decltype(tile_east)>::type{}}},
        {"tileNorth", Any{std::decay<decltype(tile_north)>::type{}}},
        {"tileSouth", Any{std::decay<decltype(tile_south)>::type{}}},
        {"tileWest", Any{std::decay<decltype(tile_west)>::type{}}},
        {"tower", Any{std::decay<decltype(tower)>::type{}}},
        {"unit", Any{std::decay<decltype(unit)>::type{}}},
        {"x", Any{std::decay<decltype(x)>::type{}}},
        {"y", Any{std::decay<decltype(y)>::type{}}},
    },
    corpses(variables_["corpses"].as<std::decay<decltype(corpses)>::type>()),
    is_castle(variables_["isCastle"].as<std::decay<decltype(is_castle)>::type>()),
    is_gold_mine(variables_["isGoldMine"].as<std::decay<decltype(is_gold_mine)>::type>()),
    is_grass(variables_["isGrass"].as<std::decay<decltype(is_grass)>::type>()),
    is_island_gold_mine(variables_["isIslandGoldMine"].as<std::decay<decltype(is_island_gold_mine)>::type>()),
    is_path(variables_["isPath"].as<std::decay<decltype(is_path)>::type>()),
    is_river(variables_["isRiver"].as<std::decay<decltype(is_river)>::type>()),
    is_tower(variables_["isTower"].as<std::decay<decltype(is_tower)>::type>()),
    is_unit_spawn(variables_["isUnitSpawn"].as<std::decay<decltype(is_unit_spawn)>::type>()),
    is_wall(variables_["isWall"].as<std::decay<decltype(is_wall)>::type>()),
    is_worker_spawn(variables_["isWorkerSpawn"].as<std::decay<decltype(is_worker_spawn)>::type>()),
    num_ghouls(variables_["numGhouls"].as<std::decay<decltype(num_ghouls)>::type>()),
    num_hounds(variables_["numHounds"].as<std::decay<decltype(num_hounds)>::type>()),
    num_zombies(variables_["numZombies"].as<std::decay<decltype(num_zombies)>::type>()),
    owner(variables_["owner"].as<std::decay<decltype(owner)>::type>()),
    tile_east(variables_["tileEast"].as<std::decay<decltype(tile_east)>::type>()),
    tile_north(variables_["tileNorth"].as<std::decay<decltype(tile_north)>::type>()),
    tile_south(variables_["tileSouth"].as<std::decay<decltype(tile_south)>::type>()),
    tile_west(variables_["tileWest"].as<std::decay<decltype(tile_west)>::type>()),
    tower(variables_["tower"].as<std::decay<decltype(tower)>::type>()),
    unit(variables_["unit"].as<std::decay<decltype(unit)>::type>()),
    x(variables_["x"].as<std::decay<decltype(x)>::type>()),
    y(variables_["y"].as<std::decay<decltype(y)>::type>())
{
    for(auto&& obj : init)
    {
      variables_.emplace(std::make_pair(std::move(obj.first), std::move(obj.second)));
    }
}

Tile_::~Tile_() = default;

void Tile_::resize(const std::string& name, std::size_t size)
{
    try
    {
        Game_object_::resize(name, size);
        return;
    }
    catch(...){}
    throw Bad_manipulation(name + " in Tile treated as a vector, but it is not a vector.");
}

void Tile_::change_vec_values(const std::string& name, std::vector<std::pair<std::size_t, Any>>& values)
{
    try
    {
        Game_object_::change_vec_values(name, values);
        return;
    }
    catch(...){}
    throw Bad_manipulation(name + " in Tile treated as a vector, but it is not a vector.");
}

void Tile_::remove_key(const std::string& name, Any& key)
{
    try
    {
        Game_object_::remove_key(name, key);
        return;
    }
    catch(...){}
    throw Bad_manipulation(name + " in Tile treated as a map, but it is not a map.");
}

std::unique_ptr<Any> Tile_::add_key_value(const std::string& name, Any& key, Any& value)
{
    try
    {
        return Game_object_::add_key_value(name, key, value);
    }
    catch(...){}
    throw Bad_manipulation(name + " in Tile treated as a map, but it is not a map.");
}

bool Tile_::is_map(const std::string& name)
{
    try
    {
        return Game_object_::is_map(name);
    }
    catch(...){}
    return false;
}

void Tile_::rebind_by_name(Any* to_change, const std::string& member, std::shared_ptr<Base_object> ref)
{
   if(member == "owner")
   { 
      to_change->as<Player>() = std::static_pointer_cast<Player_>(ref);
      return;
   }
   if(member == "tileEast")
   { 
      to_change->as<Tile>() = std::static_pointer_cast<Tile_>(ref);
      return;
   }
   if(member == "tileNorth")
   { 
      to_change->as<Tile>() = std::static_pointer_cast<Tile_>(ref);
      return;
   }
   if(member == "tileSouth")
   { 
      to_change->as<Tile>() = std::static_pointer_cast<Tile_>(ref);
      return;
   }
   if(member == "tileWest")
   { 
      to_change->as<Tile>() = std::static_pointer_cast<Tile_>(ref);
      return;
   }
   if(member == "tower")
   { 
      to_change->as<Tower>() = std::static_pointer_cast<Tower_>(ref);
      return;
   }
   if(member == "unit")
   { 
      to_change->as<Unit>() = std::static_pointer_cast<Unit_>(ref);
      return;
   }
   try
   {
      Game_object_::rebind_by_name(to_change, member, ref);
      return;
   }
   catch(...){}
   throw Bad_manipulation(member + " in Tile treated as a reference, but it is not a reference.");
}


} // necrowar

} // cpp_client

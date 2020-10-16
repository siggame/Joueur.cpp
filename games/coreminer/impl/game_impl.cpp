// DO NOT MODIFY THIS FILE
// Never try to directly create an instance of this class, or modify its member variables.
// This contains implementation details, written by code, and only useful to code



#include "../game.hpp"
#include "../../../joueur/src/base_ai.hpp"
#include "../../../joueur/src/any.hpp"
#include "../../../joueur/src/exceptions.hpp"
#include "../../../joueur/src/delta.hpp"
#include "../bomb.hpp"
#include "../game_object.hpp"
#include "../miner.hpp"
#include "../player.hpp"
#include "../tile.hpp"
#include "../upgrade.hpp"
#include "coreminer.hpp"

#include <type_traits>

namespace cpp_client
{

namespace coreminer
{


Game_::Game_(std::initializer_list<std::pair<std::string, Any&&>> init) :
    Base_game{
        {"bombPrice", Any{std::decay<decltype(bomb_price)>::type{}}},
        {"bombSize", Any{std::decay<decltype(bomb_size)>::type{}}},
        {"bombs", Any{std::decay<decltype(bombs)>::type{}}},
        {"buildingMaterialPrice", Any{std::decay<decltype(building_material_price)>::type{}}},
        {"currentPlayer", Any{std::decay<decltype(current_player)>::type{}}},
        {"currentTurn", Any{std::decay<decltype(current_turn)>::type{}}},
        {"dirtPrice", Any{std::decay<decltype(dirt_price)>::type{}}},
        {"fallDamage", Any{std::decay<decltype(fall_damage)>::type{}}},
        {"fallWeightDamage", Any{std::decay<decltype(fall_weight_damage)>::type{}}},
        {"gameObjects", Any{std::decay<decltype(game_objects)>::type{}}},
        {"ladderCost", Any{std::decay<decltype(ladder_cost)>::type{}}},
        {"ladderHealth", Any{std::decay<decltype(ladder_health)>::type{}}},
        {"largeCargoSize", Any{std::decay<decltype(large_cargo_size)>::type{}}},
        {"largeMaterialSize", Any{std::decay<decltype(large_material_size)>::type{}}},
        {"mapHeight", Any{std::decay<decltype(map_height)>::type{}}},
        {"mapWidth", Any{std::decay<decltype(map_width)>::type{}}},
        {"maxShielding", Any{std::decay<decltype(max_shielding)>::type{}}},
        {"maxTurns", Any{std::decay<decltype(max_turns)>::type{}}},
        {"maxUpgradeLevel", Any{std::decay<decltype(max_upgrade_level)>::type{}}},
        {"miners", Any{std::decay<decltype(miners)>::type{}}},
        {"orePrice", Any{std::decay<decltype(ore_price)>::type{}}},
        {"oreValue", Any{std::decay<decltype(ore_value)>::type{}}},
        {"players", Any{std::decay<decltype(players)>::type{}}},
        {"session", Any{std::decay<decltype(session)>::type{}}},
        {"shieldCost", Any{std::decay<decltype(shield_cost)>::type{}}},
        {"shieldHealth", Any{std::decay<decltype(shield_health)>::type{}}},
        {"spawnPrice", Any{std::decay<decltype(spawn_price)>::type{}}},
        {"suffocationDamage", Any{std::decay<decltype(suffocation_damage)>::type{}}},
        {"suffocationWeightDamage", Any{std::decay<decltype(suffocation_weight_damage)>::type{}}},
        {"supportCost", Any{std::decay<decltype(support_cost)>::type{}}},
        {"supportHealth", Any{std::decay<decltype(support_health)>::type{}}},
        {"tiles", Any{std::decay<decltype(tiles)>::type{}}},
        {"timeAddedPerTurn", Any{std::decay<decltype(time_added_per_turn)>::type{}}},
        {"upgradePrice", Any{std::decay<decltype(upgrade_price)>::type{}}},
        {"upgrades", Any{std::decay<decltype(upgrades)>::type{}}},
        {"victoryAmount", Any{std::decay<decltype(victory_amount)>::type{}}},
    },
    bomb_price(variables_["bombPrice"].as<std::decay<decltype(bomb_price)>::type>()),
    bomb_size(variables_["bombSize"].as<std::decay<decltype(bomb_size)>::type>()),
    bombs(variables_["bombs"].as<std::decay<decltype(bombs)>::type>()),
    building_material_price(variables_["buildingMaterialPrice"].as<std::decay<decltype(building_material_price)>::type>()),
    current_player(variables_["currentPlayer"].as<std::decay<decltype(current_player)>::type>()),
    current_turn(variables_["currentTurn"].as<std::decay<decltype(current_turn)>::type>()),
    dirt_price(variables_["dirtPrice"].as<std::decay<decltype(dirt_price)>::type>()),
    fall_damage(variables_["fallDamage"].as<std::decay<decltype(fall_damage)>::type>()),
    fall_weight_damage(variables_["fallWeightDamage"].as<std::decay<decltype(fall_weight_damage)>::type>()),
    game_objects(variables_["gameObjects"].as<std::decay<decltype(game_objects)>::type>()),
    ladder_cost(variables_["ladderCost"].as<std::decay<decltype(ladder_cost)>::type>()),
    ladder_health(variables_["ladderHealth"].as<std::decay<decltype(ladder_health)>::type>()),
    large_cargo_size(variables_["largeCargoSize"].as<std::decay<decltype(large_cargo_size)>::type>()),
    large_material_size(variables_["largeMaterialSize"].as<std::decay<decltype(large_material_size)>::type>()),
    map_height(variables_["mapHeight"].as<std::decay<decltype(map_height)>::type>()),
    map_width(variables_["mapWidth"].as<std::decay<decltype(map_width)>::type>()),
    max_shielding(variables_["maxShielding"].as<std::decay<decltype(max_shielding)>::type>()),
    max_turns(variables_["maxTurns"].as<std::decay<decltype(max_turns)>::type>()),
    max_upgrade_level(variables_["maxUpgradeLevel"].as<std::decay<decltype(max_upgrade_level)>::type>()),
    miners(variables_["miners"].as<std::decay<decltype(miners)>::type>()),
    ore_price(variables_["orePrice"].as<std::decay<decltype(ore_price)>::type>()),
    ore_value(variables_["oreValue"].as<std::decay<decltype(ore_value)>::type>()),
    players(variables_["players"].as<std::decay<decltype(players)>::type>()),
    session(variables_["session"].as<std::decay<decltype(session)>::type>()),
    shield_cost(variables_["shieldCost"].as<std::decay<decltype(shield_cost)>::type>()),
    shield_health(variables_["shieldHealth"].as<std::decay<decltype(shield_health)>::type>()),
    spawn_price(variables_["spawnPrice"].as<std::decay<decltype(spawn_price)>::type>()),
    suffocation_damage(variables_["suffocationDamage"].as<std::decay<decltype(suffocation_damage)>::type>()),
    suffocation_weight_damage(variables_["suffocationWeightDamage"].as<std::decay<decltype(suffocation_weight_damage)>::type>()),
    support_cost(variables_["supportCost"].as<std::decay<decltype(support_cost)>::type>()),
    support_health(variables_["supportHealth"].as<std::decay<decltype(support_health)>::type>()),
    tiles(variables_["tiles"].as<std::decay<decltype(tiles)>::type>()),
    time_added_per_turn(variables_["timeAddedPerTurn"].as<std::decay<decltype(time_added_per_turn)>::type>()),
    upgrade_price(variables_["upgradePrice"].as<std::decay<decltype(upgrade_price)>::type>()),
    upgrades(variables_["upgrades"].as<std::decay<decltype(upgrades)>::type>()),
    victory_amount(variables_["victoryAmount"].as<std::decay<decltype(victory_amount)>::type>())
{
    for(auto&& obj : init)
    {
      variables_.emplace(std::make_pair(std::move(obj.first), std::move(obj.second)));
    }
}

Game_::~Game_() = default;

void Game_::resize(const std::string& name, std::size_t size)
{
    if(name == "bombs")
    {
        auto& vec = variables_["bombs"].as<std::decay<decltype(bombs)>::type>();
        vec.resize(size);
        return;
    }
    else if(name == "miners")
    {
        auto& vec = variables_["miners"].as<std::decay<decltype(miners)>::type>();
        vec.resize(size);
        return;
    }
    else if(name == "players")
    {
        auto& vec = variables_["players"].as<std::decay<decltype(players)>::type>();
        vec.resize(size);
        return;
    }
    else if(name == "tiles")
    {
        auto& vec = variables_["tiles"].as<std::decay<decltype(tiles)>::type>();
        vec.resize(size);
        return;
    }
    else if(name == "upgrades")
    {
        auto& vec = variables_["upgrades"].as<std::decay<decltype(upgrades)>::type>();
        vec.resize(size);
        return;
    }
    throw Bad_manipulation(name + " in Game treated as a vector, but it is not a vector.");
}

void Game_::change_vec_values(const std::string& name, std::vector<std::pair<std::size_t, Any>>& values)
{
    if(name == "bombs")
    {
        using type = std::decay<decltype(bombs)>::type;
        auto& vec = variables_["bombs"].as<type>();
        for(auto&& val : values)
        { 
            vec[val.first] = std::static_pointer_cast<type::value_type::element_type>(get_objects()[val.second.as<std::string>()]);
        }
        return;
    } 
    else if(name == "miners")
    {
        using type = std::decay<decltype(miners)>::type;
        auto& vec = variables_["miners"].as<type>();
        for(auto&& val : values)
        { 
            vec[val.first] = std::static_pointer_cast<type::value_type::element_type>(get_objects()[val.second.as<std::string>()]);
        }
        return;
    } 
    else if(name == "players")
    {
        using type = std::decay<decltype(players)>::type;
        auto& vec = variables_["players"].as<type>();
        for(auto&& val : values)
        { 
            vec[val.first] = std::static_pointer_cast<type::value_type::element_type>(get_objects()[val.second.as<std::string>()]);
        }
        return;
    } 
    else if(name == "tiles")
    {
        using type = std::decay<decltype(tiles)>::type;
        auto& vec = variables_["tiles"].as<type>();
        for(auto&& val : values)
        { 
            vec[val.first] = std::static_pointer_cast<type::value_type::element_type>(get_objects()[val.second.as<std::string>()]);
        }
        return;
    } 
    else if(name == "upgrades")
    {
        using type = std::decay<decltype(upgrades)>::type;
        auto& vec = variables_["upgrades"].as<type>();
        for(auto&& val : values)
        { 
            vec[val.first] = std::static_pointer_cast<type::value_type::element_type>(get_objects()[val.second.as<std::string>()]);
        }
        return;
    } 
    throw Bad_manipulation(name + " in Game treated as a vector, but it is not a vector.");
}

void Game_::remove_key(const std::string& name, Any& key)
{
    if(name == "gameObjects")
    {
        auto& map = variables_["gameObjects"].as<std::decay<decltype(game_objects)>::type>();
        using type = std::decay<decltype(map)>::type;
        map.erase(key.as<type::key_type>());
        return;
    }
    throw Bad_manipulation(name + " in Game treated as a map, but it is not a map.");
}

std::unique_ptr<Any> Game_::add_key_value(const std::string& name, Any& key, Any& value)
{
    if(name == "gameObjects")
    {
        auto& map = variables_["gameObjects"].as<std::decay<decltype(game_objects)>::type>();
        using type = std::decay<decltype(map)>::type;
        auto real_key = key.as<type::key_type>();
        if(value)
        {
            map[real_key] = std::move(value.as<type::mapped_type>());
        }
        auto val = std::static_pointer_cast<Base_object>(map[real_key]);
        return std::unique_ptr<Any>(new Any{std::shared_ptr<Base_object>{val}});
    }
    throw Bad_manipulation(name + " in Game treated as a map, but it is not a map.");
}

bool Game_::is_map(const std::string& name)
{
    if(name == "gameObjects")
    {
        return true;
    }
    return false;
}

void Game_::rebind_by_name(Any* to_change, const std::string& member, std::shared_ptr<Base_object> ref)
{
   if(member == "currentPlayer")
   { 
      to_change->as<Player>() = std::static_pointer_cast<Player_>(ref);
      return;
   }
   throw Bad_manipulation(member + " in Game treated as a reference, but it is not a reference.");
}


} // coreminer

} // cpp_client

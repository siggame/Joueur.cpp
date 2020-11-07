#ifndef GAMES_COREMINER_GAME_H
#define GAMES_COREMINER_GAME_H

// Game
// Mine resources to obtain more value than your opponent.

// DO NOT MODIFY THIS FILE
// Never try to directly create an instance of this class, or modify its member variables.
// Instead, you should only be reading its variables and calling its functions.

#include <vector>
#include <queue>
#include <deque>
#include <unordered_map>
#include <string>
#include <initializer_list>

#include "../../joueur/src/any.hpp"


#include "../../joueur/src/base_game.hpp"
#include "impl/coreminer_fwd.hpp"

// <<-- Creer-Merge: includes -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
// you can add additional #includes here
// <<-- /Creer-Merge: includes -->>

namespace cpp_client
{

/// <summary>
/// Mine resources to obtain more value than your opponent.
/// </summary>
namespace coreminer
{

/// <summary>
/// Mine resources to obtain more value than your opponent.
/// </summary>
class Game_ : public Base_game
{
public:

    /// <summary>
    /// The monetary price of a bomb when bought or sold.
    /// </summary>
    const int& bomb_price;

    /// <summary>
    /// The amount of cargo space taken up by a Bomb.
    /// </summary>
    const int& bomb_size;

    /// <summary>
    /// Every Bomb in the game.
    /// </summary>
    const std::vector<Bomb>& bombs;

    /// <summary>
    /// The monetary price of building materials when bought.
    /// </summary>
    const int& building_material_price;

    /// <summary>
    /// The player whose turn it is currently. That player can send commands. Other players cannot.
    /// </summary>
    const Player& current_player;

    /// <summary>
    /// The current turn number, starting at 0 for the first player's turn.
    /// </summary>
    const int& current_turn;

    /// <summary>
    /// The monetary price of dirt when bought or sold.
    /// </summary>
    const int& dirt_price;

    /// <summary>
    /// The amount of damage taken per Tile fallen.
    /// </summary>
    const int& fall_damage;

    /// <summary>
    /// The amount of extra damage taken for falling while carrying a large amount of cargo.
    /// </summary>
    const int& fall_weight_damage;

    /// <summary>
    /// A mapping of every game object's ID to the actual game object. Primarily used by the server and client to easily refer to the game objects via ID.
    /// </summary>
    const std::unordered_map<std::string, Game_object>& game_objects;

    /// <summary>
    /// The amount of building material required to build a ladder.
    /// </summary>
    const int& ladder_cost;

    /// <summary>
    /// The amount of mining power needed to remove a ladder from a Tile.
    /// </summary>
    const int& ladder_health;

    /// <summary>
    /// The amount deemed as a large amount of cargo.
    /// </summary>
    const int& large_cargo_size;

    /// <summary>
    /// The amount deemed as a large amount of material.
    /// </summary>
    const int& large_material_size;

    /// <summary>
    /// The number of Tiles in the map along the y (vertical) axis.
    /// </summary>
    const int& map_height;

    /// <summary>
    /// The number of Tiles in the map along the x (horizontal) axis.
    /// </summary>
    const int& map_width;

    /// <summary>
    /// The maximum amount of shielding possible on a Tile.
    /// </summary>
    const int& max_shielding;

    /// <summary>
    /// The maximum number of turns before the game will automatically end.
    /// </summary>
    const int& max_turns;

    /// <summary>
    /// The highest upgrade level allowed on a Miner.
    /// </summary>
    const int& max_upgrade_level;

    /// <summary>
    /// Every Miner in the game.
    /// </summary>
    const std::vector<Miner>& miners;

    /// <summary>
    /// The amount of money awarded when ore is dumped in the base and sold.
    /// </summary>
    const int& ore_price;

    /// <summary>
    /// The amount of value awarded when ore is dumped in the base and sold.
    /// </summary>
    const int& ore_value;

    /// <summary>
    /// List of all the players in the game.
    /// </summary>
    const std::vector<Player>& players;

    /// <summary>
    /// A unique identifier for the game instance that is being played.
    /// </summary>
    const std::string& session;

    /// <summary>
    /// The amount of building material required to shield a Tile.
    /// </summary>
    const int& shield_cost;

    /// <summary>
    /// The amount of mining power needed to remove one unit of shielding off a Tile.
    /// </summary>
    const int& shield_health;

    /// <summary>
    /// The monetary price of spawning a Miner.
    /// </summary>
    const int& spawn_price;

    /// <summary>
    /// The amount of damage taken when suffocating inside a filled Tile.
    /// </summary>
    const int& suffocation_damage;

    /// <summary>
    /// The amount of extra damage taken for suffocating under a large amount of material.
    /// </summary>
    const int& suffocation_weight_damage;

    /// <summary>
    /// The amount of building material required to build a support.
    /// </summary>
    const int& support_cost;

    /// <summary>
    /// The amount of mining power needed to remove a support from a Tile.
    /// </summary>
    const int& support_health;

    /// <summary>
    /// All the tiles in the map, stored in Row-major order. Use `x + y * mapWidth` to access the correct index.
    /// </summary>
    const std::vector<Tile>& tiles;

    /// <summary>
    /// The amount of time (in nano-seconds) added after each player performs a turn.
    /// </summary>
    const double& time_added_per_turn;

    /// <summary>
    /// The cost to upgrade a Miner.
    /// </summary>
    const int& upgrade_price;

    /// <summary>
    /// Every Upgrade for a Miner in the game.
    /// </summary>
    const std::vector<Upgrade>& upgrades;

    /// <summary>
    /// The amount of victory points (value) required to win.
    /// </summary>
    const int& victory_amount;

    // <<-- Creer-Merge: member variables -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
    // You can add additional member variables here. None of them will be tracked or updated by the server.
    // <<-- /Creer-Merge: member variables -->>


    /// <summary>
    /// Gets the Tile at a specified (x, y) position
    /// </summary>
    /// <param name="x">integer between 0 and the mapWidth</param>
    /// <param name="y">integer between 0 and the mapHeight</param>
    /// <returns>the Tile at (x, y) or null if out of bounds
    Tile get_tile_at(const int x, const int y);

   // <<-- Creer-Merge: methods -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
   // You can add additional methods here.
   // <<-- /Creer-Merge: methods -->>

   ~Game_();

   // ####################
   // Don't edit these!
   // ####################
   /// \cond FALSE
   Game_(std::initializer_list<std::pair<std::string, Any&&>> init);
   Game_() : Game_({}){}
   virtual void resize(const std::string& name, std::size_t size) override;
   virtual void change_vec_values(const std::string& name, std::vector<std::pair<std::size_t, Any>>& values) override;
   virtual void remove_key(const std::string& name, Any& key) override;
   virtual std::unique_ptr<Any> add_key_value(const std::string& name, Any& key, Any& value) override;
   virtual bool is_map(const std::string& name) override;
   virtual void rebind_by_name(Any* to_change, const std::string& member, std::shared_ptr<Base_object> ref) override;
    /// \endcond
    // ####################
    // Don't edit these!
    // ####################
};

} // coreminer

} // cpp_client

#endif // GAMES_COREMINER_GAME_H

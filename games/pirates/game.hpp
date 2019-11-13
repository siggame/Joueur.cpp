#ifndef GAMES_PIRATES_GAME_H
#define GAMES_PIRATES_GAME_H

// Game
// Steal from merchants and become the most infamous pirate.

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
#include "impl/pirates_fwd.hpp"

// <<-- Creer-Merge: includes -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
// you can add additional #includes here
// <<-- /Creer-Merge: includes -->>

namespace cpp_client
{

/// <summary>
/// Steal from merchants and become the most infamous pirate.
/// </summary>
namespace pirates
{

/// <summary>
/// Steal from merchants and become the most infamous pirate.
/// </summary>
class Game_ : public Base_game
{
public:

    /// <summary>
    /// The rate buried gold increases each turn.
    /// </summary>
    const double& bury_interest_rate;

    /// <summary>
    /// How much gold it costs to construct a single crew.
    /// </summary>
    const int& crew_cost;

    /// <summary>
    /// How much damage crew deal to each other.
    /// </summary>
    const int& crew_damage;

    /// <summary>
    /// The maximum amount of health a crew member can have.
    /// </summary>
    const int& crew_health;

    /// <summary>
    /// The number of moves Units with only crew are given each turn.
    /// </summary>
    const int& crew_moves;

    /// <summary>
    /// A crew's attack range. Range is circular.
    /// </summary>
    const double& crew_range;

    /// <summary>
    /// The player whose turn it is currently. That player can send commands. Other players cannot.
    /// </summary>
    const Player& current_player;

    /// <summary>
    /// The current turn number, starting at 0 for the first player's turn.
    /// </summary>
    const int& current_turn;

    /// <summary>
    /// A mapping of every game object's ID to the actual game object. Primarily used by the server and client to easily refer to the game objects via ID.
    /// </summary>
    const std::unordered_map<std::string, Game_object>& game_objects;

    /// <summary>
    /// How much health a Unit recovers when they rest.
    /// </summary>
    const double& heal_factor;

    /// <summary>
    /// The number of Tiles in the map along the y (vertical) axis.
    /// </summary>
    const int& map_height;

    /// <summary>
    /// The number of Tiles in the map along the x (horizontal) axis.
    /// </summary>
    const int& map_width;

    /// <summary>
    /// The maximum number of turns before the game will automatically end.
    /// </summary>
    const int& max_turns;

    /// <summary>
    /// How much gold merchant Ports get each turn.
    /// </summary>
    const double& merchant_gold_rate;

    /// <summary>
    /// When a merchant ship spawns, the amount of additional gold it has relative to the Port's investment.
    /// </summary>
    const double& merchant_interest_rate;

    /// <summary>
    /// The Euclidean distance buried gold must be from the Player's Port to accumulate interest.
    /// </summary>
    const double& min_interest_distance;

    /// <summary>
    /// List of all the players in the game.
    /// </summary>
    const std::vector<Player>& players;

    /// <summary>
    /// Every Port in the game. Merchant ports have owner set to null.
    /// </summary>
    const std::vector<Port>& ports;

    /// <summary>
    /// How far a Unit can be from a Port to rest. Range is circular.
    /// </summary>
    const double& rest_range;

    /// <summary>
    /// A unique identifier for the game instance that is being played.
    /// </summary>
    const std::string& session;

    /// <summary>
    /// How much gold it costs to construct a ship.
    /// </summary>
    const int& ship_cost;

    /// <summary>
    /// How much damage ships deal to ships and ports.
    /// </summary>
    const int& ship_damage;

    /// <summary>
    /// The maximum amount of health a ship can have.
    /// </summary>
    const int& ship_health;

    /// <summary>
    /// The number of moves Units with ships are given each turn.
    /// </summary>
    const int& ship_moves;

    /// <summary>
    /// A ship's attack range. Range is circular.
    /// </summary>
    const double& ship_range;

    /// <summary>
    /// All the tiles in the map, stored in Row-major order. Use `x + y * mapWidth` to access the correct index.
    /// </summary>
    const std::vector<Tile>& tiles;

    /// <summary>
    /// The amount of time (in nano-seconds) added after each player performs a turn.
    /// </summary>
    const int& time_added_per_turn;

    /// <summary>
    /// Every Unit in the game. Merchant units have targetPort set to a port.
    /// </summary>
    const std::vector<Unit>& units;

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

} // pirates

} // cpp_client

#endif // GAMES_PIRATES_GAME_H

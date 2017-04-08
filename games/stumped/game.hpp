#ifndef GAMES_STUMPED_GAME_H
#define GAMES_STUMPED_GAME_H

// Game
// Gather branches and build up your lodge as beavers fight to survive.

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
#include "impl/stumped_fwd.hpp"

// you can add additional #includes here

namespace cpp_client
{

namespace stumped
{

/// <summary>
/// Gather branches and build up your lodge as beavers fight to survive.
/// </summary>
class Game_ : public Base_game
{
public:

    /// <summary>
    /// Every Beaver in the game.
    /// </summary>
    const std::vector<Beaver>& beavers;

    /// <summary>
    /// The player whose turn it is currently. That player can send commands. Other players cannot.
    /// </summary>
    const Player& current_player;

    /// <summary>
    /// The current turn number, starting at 0 for the first player's turn.
    /// </summary>
    const int& current_turn;

    /// <summary>
    /// When a Player has less Beavers than this number, then recruiting other Beavers is free.
    /// </summary>
    const int& free_beavers_count;

    /// <summary>
    /// A mapping of every game object's ID to the actual game object. Primarily used by the server and client to easily refer to the game objects via ID.
    /// </summary>
    const std::unordered_map<std::string, Game_object>& game_objects;

    /// <summary>
    /// All the Jobs that Beavers can have in the game.
    /// </summary>
    const std::vector<Job>& jobs;

    /// <summary>
    /// Constant number used to calculate what it costs to spawn a new lodge.
    /// </summary>
    const double& lodge_cost_constant;

    /// <summary>
    /// How many lodges must be owned by a Player at once to win the game.
    /// </summary>
    const int& lodges_to_win;

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
    /// List of all the players in the game.
    /// </summary>
    const std::vector<Player>& players;

    /// <summary>
    /// A unique identifier for the game instance that is being played.
    /// </summary>
    const std::string& session;

    /// <summary>
    /// Every Spawner in the game.
    /// </summary>
    const std::vector<Spawner>& spawner;

    /// <summary>
    /// Constant number used to calculate how many branches/food Beavers harvest from Spawners.
    /// </summary>
    const double& spawner_harvest_constant;

    /// <summary>
    /// All the types of Spawners in the game.
    /// </summary>
    const std::vector<std::string>& spawner_types;

    /// <summary>
    /// All the tiles in the map, stored in Row-major order. Use `x + y * mapWidth` to access the correct index.
    /// </summary>
    const std::vector<Tile>& tiles;

    // You can add additional member variables here. None of them will be tracked or updated by the server.


    /// <summary>
    /// Gets the Tile at a specified (x, y) position
    /// </summary>
    /// <param name="x">integer between 0 and the mapWidth</param>
    /// <param name="y">integer between 0 and the mapHeight</param>
    /// <returns>the Tile at (x, y) or null if out of bounds
    Tile get_tile_at(const int x, const int y);

   // You can add additional methods here.

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

} // stumped

} // cpp_client

#endif // GAMES_STUMPED_GAME_H

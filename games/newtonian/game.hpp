#ifndef GAMES_NEWTONIAN_GAME_H
#define GAMES_NEWTONIAN_GAME_H

// Game
// Combine elements and be the first scientists to create fusion.

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
#include "impl/newtonian_fwd.hpp"

// <<-- Creer-Merge: includes -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
// you can add additional #includes here
// <<-- /Creer-Merge: includes -->>

namespace cpp_client
{

/// <summary>
/// Combine elements and be the first scientists to create fusion.
/// </summary>
namespace newtonian
{

/// <summary>
/// Combine elements and be the first scientists to create fusion.
/// </summary>
class Game_ : public Base_game
{
public:

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
    /// The maximum number of interns a player can have.
    /// </summary>
    const int& intern_cap;

    /// <summary>
    /// A list of all jobs. The first element is intern, second is physicists, and third is manager.
    /// </summary>
    const std::vector<Job>& jobs;

    /// <summary>
    /// Every Machine in the game.
    /// </summary>
    const std::vector<Machine>& machines;

    /// <summary>
    /// The maximum number of managers a player can have.
    /// </summary>
    const int& manager_cap;

    /// <summary>
    /// The number of Tiles in the map along the y (vertical) axis.
    /// </summary>
    const int& map_height;

    /// <summary>
    /// The number of Tiles in the map along the x (horizontal) axis.
    /// </summary>
    const int& map_width;

    /// <summary>
    /// The number of materials that spawn per spawn cycle.
    /// </summary>
    const int& material_spawn;

    /// <summary>
    /// The maximum number of turns before the game will automatically end.
    /// </summary>
    const int& max_turns;

    /// <summary>
    /// The maximum number of physicists a player can have.
    /// </summary>
    const int& physicist_cap;

    /// <summary>
    /// List of all the players in the game.
    /// </summary>
    const std::vector<Player>& players;

    /// <summary>
    /// The amount of victory points added when a refined ore is consumed by the generator.
    /// </summary>
    const int& refined_value;

    /// <summary>
    /// The percent of max HP regained when a unit end their turn on a tile owned by their player.
    /// </summary>
    const double& regenerate_rate;

    /// <summary>
    /// A unique identifier for the game instance that is being played.
    /// </summary>
    const std::string& session;

    /// <summary>
    /// The amount of turns it takes a unit to spawn.
    /// </summary>
    const int& spawn_time;

    /// <summary>
    /// The amount of turns a unit cannot do anything when stunned.
    /// </summary>
    const int& stun_time;

    /// <summary>
    /// All the tiles in the map, stored in Row-major order. Use `x + y * mapWidth` to access the correct index.
    /// </summary>
    const std::vector<Tile>& tiles;

    /// <summary>
    /// The amount of time (in nano-seconds) added after each player performs a turn.
    /// </summary>
    const int& time_added_per_turn;

    /// <summary>
    /// The number turns a unit is immune to being stunned.
    /// </summary>
    const int& time_immune;

    /// <summary>
    /// Every Unit in the game.
    /// </summary>
    const std::vector<Unit>& units;

    /// <summary>
    /// The amount of combined heat and pressure that you need to win.
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

} // newtonian

} // cpp_client

#endif // GAMES_NEWTONIAN_GAME_H

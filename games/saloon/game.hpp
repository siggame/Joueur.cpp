#ifndef GAMES_SALOON_GAME_H
#define GAMES_SALOON_GAME_H

// Game
// Use cowboys to have a good time and play some music on a Piano, while brawling with enemy Cowboys.

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
#include "impl/saloon_fwd.hpp"

// <<-- Creer-Merge: includes -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
// you can add additional #includes here
// <<-- /Creer-Merge: includes -->>

namespace cpp_client
{

/// <summary>
/// Use cowboys to have a good time and play some music on a Piano, while brawling with enemy Cowboys.
/// </summary>
namespace saloon
{

/// <summary>
/// Use cowboys to have a good time and play some music on a Piano, while brawling with enemy Cowboys.
/// </summary>
class Game_ : public Base_game
{
public:

    /// <summary>
    /// How many turns a Bartender will be busy for after throwing a Bottle.
    /// </summary>
    const int& bartender_cooldown;

    /// <summary>
    /// All the beer Bottles currently flying across the saloon in the game.
    /// </summary>
    const std::vector<Bottle>& bottles;

    /// <summary>
    /// How much damage is applied to neighboring things bit by the Sharpshooter between turns.
    /// </summary>
    const int& brawler_damage;

    /// <summary>
    /// Every Cowboy in the game.
    /// </summary>
    const std::vector<Cowboy>& cowboys;

    /// <summary>
    /// The player whose turn it is currently. That player can send commands. Other players cannot.
    /// </summary>
    const Player& current_player;

    /// <summary>
    /// The current turn number, starting at 0 for the first player's turn.
    /// </summary>
    const int& current_turn;

    /// <summary>
    /// Every furnishing in the game.
    /// </summary>
    const std::vector<Furnishing>& furnishings;

    /// <summary>
    /// A mapping of every game object's ID to the actual game object. Primarily used by the server and client to easily refer to the game objects via ID.
    /// </summary>
    const std::unordered_map<std::string, Game_object>& game_objects;

    /// <summary>
    /// All the jobs that Cowboys can be called in with.
    /// </summary>
    const std::vector<std::string>& jobs;

    /// <summary>
    /// The number of Tiles in the map along the y (vertical) axis.
    /// </summary>
    const int& map_height;

    /// <summary>
    /// The number of Tiles in the map along the x (horizontal) axis.
    /// </summary>
    const int& map_width;

    /// <summary>
    /// The maximum number of Cowboys a Player can bring into the saloon of each specific job.
    /// </summary>
    const int& max_cowboys_per_job;

    /// <summary>
    /// The maximum number of turns before the game will automatically end.
    /// </summary>
    const int& max_turns;

    /// <summary>
    /// List of all the players in the game.
    /// </summary>
    const std::vector<Player>& players;

    /// <summary>
    /// When a player's rowdiness reaches or exceeds this number their Cowboys take a collective siesta.
    /// </summary>
    const int& rowdiness_to_siesta;

    /// <summary>
    /// A unique identifier for the game instance that is being played.
    /// </summary>
    const std::string& session;

    /// <summary>
    /// How much damage is applied to things hit by Sharpshooters when they act.
    /// </summary>
    const int& sharpshooter_damage;

    /// <summary>
    /// How long siestas are for a player's team.
    /// </summary>
    const int& siesta_length;

    /// <summary>
    /// All the tiles in the map, stored in Row-major order. Use `x + y * mapWidth` to access the correct index.
    /// </summary>
    const std::vector<Tile>& tiles;

    /// <summary>
    /// The amount of time (in nano-seconds) added after each player performs a turn.
    /// </summary>
    const int& time_added_per_turn;

    /// <summary>
    /// How many turns a Cowboy will be drunk for if a bottle breaks on it.
    /// </summary>
    const int& turns_drunk;

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

} // saloon

} // cpp_client

#endif // GAMES_SALOON_GAME_H

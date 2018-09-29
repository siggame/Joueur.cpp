#ifndef GAMES_NEWTONIAN_PLAYER_H
#define GAMES_NEWTONIAN_PLAYER_H

// Player
// A player in this game. Every AI controls one player.

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

#include "game_object.hpp"

#include "impl/newtonian_fwd.hpp"

// <<-- Creer-Merge: includes -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
// you can add additional #includes here
// <<-- /Creer-Merge: includes -->>

namespace cpp_client
{

namespace newtonian
{

/// <summary>
/// A player in this game. Every AI controls one player.
/// </summary>
class Player_ : public Game_object_
{
public:

    /// <summary>
    /// What type of client this is, e.g. 'Python', 'JavaScript', or some other language. For potential data mining purposes.
    /// </summary>
    const std::string& client_type;

    /// <summary>
    /// Every generator Tile owned by this Player. (listed from the outer edges inward, from top to bottom).
    /// </summary>
    const std::vector<Tile>& generator_tiles;

    /// <summary>
    /// The amount of heat this Player has.
    /// </summary>
    const int& heat;

    /// <summary>
    /// The time left till a intern spawns. (0 to spawnTime).
    /// </summary>
    const int& intern_spawn;

    /// <summary>
    /// If the player lost the game or not.
    /// </summary>
    const bool& lost;

    /// <summary>
    /// The time left till a manager spawns. (0 to spawnTime).
    /// </summary>
    const int& manager_spawn;

    /// <summary>
    /// The name of the player.
    /// </summary>
    const std::string& name;

    /// <summary>
    /// This player's opponent in the game.
    /// </summary>
    const Player& opponent;

    /// <summary>
    /// The time left till a physicist spawns. (0 to spawnTime).
    /// </summary>
    const int& physicist_spawn;

    /// <summary>
    /// The amount of pressure this Player has.
    /// </summary>
    const int& pressure;

    /// <summary>
    /// The reason why the player lost the game.
    /// </summary>
    const std::string& reason_lost;

    /// <summary>
    /// The reason why the player won the game.
    /// </summary>
    const std::string& reason_won;

    /// <summary>
    /// All the tiles this Player's units can spawn on. (listed from the outer edges inward, from top to bottom).
    /// </summary>
    const std::vector<Tile>& spawn_tiles;

    /// <summary>
    /// The amount of time (in ns) remaining for this AI to send commands.
    /// </summary>
    const double& time_remaining;

    /// <summary>
    /// Every Unit owned by this Player.
    /// </summary>
    const std::vector<Unit>& units;

    /// <summary>
    /// If the player won the game or not.
    /// </summary>
    const bool& won;

    // <<-- Creer-Merge: member variables -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
    // You can add additional member variables here. None of them will be tracked or updated by the server.
    // <<-- /Creer-Merge: member variables -->>



   // <<-- Creer-Merge: methods -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
   // You can add additional methods here.
   // <<-- /Creer-Merge: methods -->>

   ~Player_();

   // ####################
   // Don't edit these!
   // ####################
   /// \cond FALSE
   Player_(std::initializer_list<std::pair<std::string, Any&&>> init);
   Player_() : Player_({}){}
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

#endif // GAMES_NEWTONIAN_PLAYER_H

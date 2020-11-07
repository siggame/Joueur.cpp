#ifndef GAMES_STARDASH_GAME_H
#define GAMES_STARDASH_GAME_H

// Game
// Collect of the most of the rarest mineral orbiting around the sun and out-compete your competitor.

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
#include "impl/stardash_fwd.hpp"

// <<-- Creer-Merge: includes -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
// you can add additional #includes here
// <<-- /Creer-Merge: includes -->>

namespace cpp_client
{

/// <summary>
/// Collect of the most of the rarest mineral orbiting around the sun and out-compete your competitor.
/// </summary>
namespace stardash
{

/// <summary>
/// Collect of the most of the rarest mineral orbiting around the sun and out-compete your competitor.
/// </summary>
class Game_ : public Base_game
{
public:

    /// <summary>
    /// All the celestial bodies in the game. The first two are planets and the third is the sun. The fourth is the VP asteroid. Everything else is normal asteroids.
    /// </summary>
    const std::vector<Body>& bodies;

    /// <summary>
    /// The player whose turn it is currently. That player can send commands. Other players cannot.
    /// </summary>
    const Player& current_player;

    /// <summary>
    /// The current turn number, starting at 0 for the first player's turn.
    /// </summary>
    const int& current_turn;

    /// <summary>
    /// The cost of dashing.
    /// </summary>
    const int& dash_cost;

    /// <summary>
    /// The distance traveled each turn by dashing.
    /// </summary>
    const int& dash_distance;

    /// <summary>
    /// A mapping of every game object's ID to the actual game object. Primarily used by the server and client to easily refer to the game objects via ID.
    /// </summary>
    const std::unordered_map<std::string, Game_object>& game_objects;

    /// <summary>
    /// The value of every unit of genarium.
    /// </summary>
    const double& genarium_value;

    /// <summary>
    /// A list of all jobs. The first element is corvette, second is missileboat, third is martyr, fourth is transport, and fifth is miner.
    /// </summary>
    const std::vector<Job>& jobs;

    /// <summary>
    /// The value of every unit of legendarium.
    /// </summary>
    const double& legendarium_value;

    /// <summary>
    /// The highest amount of material, that can be in a asteroid.
    /// </summary>
    const int& max_asteroid;

    /// <summary>
    /// The maximum number of turns before the game will automatically end.
    /// </summary>
    const int& max_turns;

    /// <summary>
    /// The smallest amount of material, that can be in a asteroid.
    /// </summary>
    const int& min_asteroid;

    /// <summary>
    /// The rate at which miners grab minerals from asteroids.
    /// </summary>
    const int& mining_speed;

    /// <summary>
    /// The amount of mythicite that spawns at the start of the game.
    /// </summary>
    const double& mythicite_amount;

    /// <summary>
    /// The number of orbit updates you cannot mine the mithicite asteroid.
    /// </summary>
    const int& orbits_protected;

    /// <summary>
    /// The rarity modifier of the most common ore. This controls how much spawns.
    /// </summary>
    const double& ore_rarity_genarium;

    /// <summary>
    /// The rarity modifier of the rarest ore. This controls how much spawns.
    /// </summary>
    const double& ore_rarity_legendarium;

    /// <summary>
    /// The rarity modifier of the second rarest ore. This controls how much spawns.
    /// </summary>
    const double& ore_rarity_rarium;

    /// <summary>
    /// The amount of energy a planet can hold at once.
    /// </summary>
    const int& planet_energy_cap;

    /// <summary>
    /// The amount of energy the planets restore each round.
    /// </summary>
    const int& planet_recharge_rate;

    /// <summary>
    /// List of all the players in the game.
    /// </summary>
    const std::vector<Player>& players;

    /// <summary>
    /// The standard size of ships.
    /// </summary>
    const int& projectile_radius;

    /// <summary>
    /// The amount of distance missiles travel through space.
    /// </summary>
    const int& projectile_speed;

    /// <summary>
    /// Every projectile in the game.
    /// </summary>
    const std::vector<Projectile>& projectiles;

    /// <summary>
    /// The value of every unit of rarium.
    /// </summary>
    const double& rarium_value;

    /// <summary>
    /// The regeneration rate of asteroids.
    /// </summary>
    const double& regenerate_rate;

    /// <summary>
    /// A unique identifier for the game instance that is being played.
    /// </summary>
    const std::string& session;

    /// <summary>
    /// The standard size of ships.
    /// </summary>
    const int& ship_radius;

    /// <summary>
    /// The size of the map in the X direction.
    /// </summary>
    const int& size_x;

    /// <summary>
    /// The size of the map in the Y direction.
    /// </summary>
    const int& size_y;

    /// <summary>
    /// The amount of time (in nano-seconds) added after each player performs a turn.
    /// </summary>
    const int& time_added_per_turn;

    /// <summary>
    /// The number of turns it takes for a asteroid to orbit the sun. (Asteroids move after each players turn).
    /// </summary>
    const int& turns_to_orbit;

    /// <summary>
    /// Every Unit in the game.
    /// </summary>
    const std::vector<Unit>& units;

    // <<-- Creer-Merge: member variables -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
    // You can add additional member variables here. None of them will be tracked or updated by the server.
    // <<-- /Creer-Merge: member variables -->>



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

} // stardash

} // cpp_client

#endif // GAMES_STARDASH_GAME_H

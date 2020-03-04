#ifndef GAMES_NECROWAR_TOWER_H
#define GAMES_NECROWAR_TOWER_H

// Tower
// A tower in the game. Used to combat enemy waves.

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

#include "impl/necrowar_fwd.hpp"

// <<-- Creer-Merge: includes -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
// you can add additional #includes here
// <<-- /Creer-Merge: includes -->>

namespace cpp_client
{

namespace necrowar
{

/// <summary>
/// A tower in the game. Used to combat enemy waves.
/// </summary>
class Tower_ : public Game_object_
{
public:

    /// <summary>
    /// Whether this tower has attacked this turn or not.
    /// </summary>
    const bool& attacked;

    /// <summary>
    /// How many turns are left before it can fire again.
    /// </summary>
    const int& cooldown;

    /// <summary>
    /// How much remaining health this tower has.
    /// </summary>
    const int& health;

    /// <summary>
    /// What type of tower this is (it's job).
    /// </summary>
    const Tower_job& job;

    /// <summary>
    /// The player that built / owns this tower.
    /// </summary>
    const Player& owner;

    /// <summary>
    /// The Tile this Tower is on.
    /// </summary>
    const Tile& tile;

    // <<-- Creer-Merge: member variables -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
    // You can add additional member variables here. None of them will be tracked or updated by the server.
    // <<-- /Creer-Merge: member variables -->>


    /// <summary>
    /// attacks an enemy unit on an tile within it's range.
    /// </summary>
    /// <param name="tile"> The Tile to attack. </param>
    bool attack(const Tile& tile);


   // <<-- Creer-Merge: methods -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
   // You can add additional methods here.
   // <<-- /Creer-Merge: methods -->>

   ~Tower_();

   // ####################
   // Don't edit these!
   // ####################
   /// \cond FALSE
   Tower_(std::initializer_list<std::pair<std::string, Any&&>> init);
   Tower_() : Tower_({}){}
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

} // necrowar

} // cpp_client

#endif // GAMES_NECROWAR_TOWER_H

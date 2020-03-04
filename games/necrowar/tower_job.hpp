#ifndef GAMES_NECROWAR_TOWER_JOB_H
#define GAMES_NECROWAR_TOWER_JOB_H

// TowerJob
// Information about a tower's job/type.

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
/// Information about a tower's job/type.
/// </summary>
class Tower_job_ : public Game_object_
{
public:

    /// <summary>
    /// Whether this tower type hits all of the units on a tile (true) or one at a time (false).
    /// </summary>
    const bool& all_units;

    /// <summary>
    /// The amount of damage this type does per attack.
    /// </summary>
    const int& damage;

    /// <summary>
    /// How much does this type cost in gold.
    /// </summary>
    const int& gold_cost;

    /// <summary>
    /// The amount of starting health this type has.
    /// </summary>
    const int& health;

    /// <summary>
    /// How much does this type cost in mana.
    /// </summary>
    const int& mana_cost;

    /// <summary>
    /// The number of tiles this type can attack from.
    /// </summary>
    const int& range;

    /// <summary>
    /// The type title. 'arrow', 'aoe', 'ballista', 'cleansing', or 'castle'.
    /// </summary>
    const std::string& title;

    /// <summary>
    /// How many turns have to take place between this type's attacks.
    /// </summary>
    const int& turns_between_attacks;

    // <<-- Creer-Merge: member variables -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
    // You can add additional member variables here. None of them will be tracked or updated by the server.
    // <<-- /Creer-Merge: member variables -->>



   // <<-- Creer-Merge: methods -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
   // You can add additional methods here.
   // <<-- /Creer-Merge: methods -->>

   ~Tower_job_();

   // ####################
   // Don't edit these!
   // ####################
   /// \cond FALSE
   Tower_job_(std::initializer_list<std::pair<std::string, Any&&>> init);
   Tower_job_() : Tower_job_({}){}
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

#endif // GAMES_NECROWAR_TOWER_JOB_H

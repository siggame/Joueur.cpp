#ifndef GAMES_NECROWAR_UNIT_JOB_H
#define GAMES_NECROWAR_UNIT_JOB_H

// UnitJob
// Information about a unit's job/type.

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
/// Information about a unit's job/type.
/// </summary>
class Unit_job_ : public Game_object_
{
public:

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
    /// The number of moves this type can make per turn.
    /// </summary>
    const int& moves;

    /// <summary>
    /// How many of this type of unit can take up one tile.
    /// </summary>
    const int& per_tile;

    /// <summary>
    /// Amount of tiles away this type has to be in order to be effective.
    /// </summary>
    const int& range;

    /// <summary>
    /// The type title. 'worker', 'zombie', 'ghoul', 'hound', 'abomination', 'wraith' or 'horseman'.
    /// </summary>
    const std::string& title;

    // <<-- Creer-Merge: member variables -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
    // You can add additional member variables here. None of them will be tracked or updated by the server.
    // <<-- /Creer-Merge: member variables -->>



   // <<-- Creer-Merge: methods -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
   // You can add additional methods here.
   // <<-- /Creer-Merge: methods -->>

   ~Unit_job_();

   // ####################
   // Don't edit these!
   // ####################
   /// \cond FALSE
   Unit_job_(std::initializer_list<std::pair<std::string, Any&&>> init);
   Unit_job_() : Unit_job_({}){}
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

#endif // GAMES_NECROWAR_UNIT_JOB_H

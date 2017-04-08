#ifndef GAMES_STUMPED_JOB_H
#define GAMES_STUMPED_JOB_H

// Job
// Information about a beaver's job.

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

#include "impl/stumped_fwd.hpp"

// you can add additional #includes here

namespace cpp_client
{

namespace stumped
{

/// <summary>
/// Information about a beaver's job.
/// </summary>
class Job_ : public Game_object_
{
public:

    /// <summary>
    /// The number of actions this Job can make per turn.
    /// </summary>
    const int& actions;

    /// <summary>
    /// How many combined resources a beaver with this Job can hold at once.
    /// </summary>
    const int& carry_limit;

    /// <summary>
    /// Scalar for how many branches this Job harvests at once.
    /// </summary>
    const int& chopping;

    /// <summary>
    /// How much food this Job costs to recruit.
    /// </summary>
    const int& cost;

    /// <summary>
    /// The amount of damage this Job does per attack.
    /// </summary>
    const int& damage;

    /// <summary>
    /// How many turns a beaver attacked by this Job is distracted by.
    /// </summary>
    const int& distraction_power;

    /// <summary>
    /// The amount of starting health this Job has.
    /// </summary>
    const int& health;

    /// <summary>
    /// The number of moves this Job can make per turn.
    /// </summary>
    const int& moves;

    /// <summary>
    /// Scalar for how much food this Job harvests at once.
    /// </summary>
    const int& munching;

    /// <summary>
    /// The Job title.
    /// </summary>
    const std::string& title;

    // You can add additional member variables here. None of them will be tracked or updated by the server.


    /// <summary>
    /// recruits a _beaver of this _job to a lodge
    /// </summary>
    /// <param name="tile"> The Tile that is a lodge owned by you that you wish to spawn the Beaver of this Job on. </param>
    Beaver recruit(const Tile& tile);


   // You can add additional methods here.

   ~Job_();

   // ####################
   // Don't edit these!
   // ####################
   /// \cond FALSE
   Job_(std::initializer_list<std::pair<std::string, Any&&>> init);
   Job_() : Job_({}){}
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

#endif // GAMES_STUMPED_JOB_H

#ifndef GAMES_SPIDERS_SPIDERLING_H
#define GAMES_SPIDERS_SPIDERLING_H

// Spiderling
// A Spider spawned by the BroodMother.

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

#include "spider.hpp"

#include "impl/spiders_fwd.hpp"

// <<-- Creer-Merge: includes -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
// you can add additional #includes here
// <<-- /Creer-Merge: includes -->>

namespace cpp_client
{

namespace spiders
{

/// <summary>
/// A Spider spawned by the BroodMother.
/// </summary>
class Spiderling_ : public Spider_
{
public:

    /// <summary>
    /// When empty string this Spiderling is not busy, and can act. Otherwise a string representing what it is busy with, e.g. 'Moving', 'Attacking'.
    /// </summary>
    const std::string& busy;

    /// <summary>
    /// The Web this Spiderling is using to move. Null if it is not moving.
    /// </summary>
    const Web& moving_on_web;

    /// <summary>
    /// The Nest this Spiderling is moving to. Null if it is not moving.
    /// </summary>
    const Nest& moving_to_nest;

    /// <summary>
    /// The number of Spiderlings busy with the same work this Spiderling is doing, speeding up the task.
    /// </summary>
    const int& number_of_coworkers;

    /// <summary>
    /// How much work needs to be done for this Spiderling to finish being busy. See docs for the Work formula.
    /// </summary>
    const double& work_remaining;

    // <<-- Creer-Merge: member variables -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
    // You can add additional member variables here. None of them will be tracked or updated by the server.
    // <<-- /Creer-Merge: member variables -->>


    /// <summary>
    /// attacks another _spiderling.
    /// </summary>
    /// <param name="spiderling"> The Spiderling to attack. </param>
    bool attack(const Spiderling& spiderling);

    /// <summary>
    /// starts moving the _spiderling across a _web to another _nest.
    /// </summary>
    /// <param name="web"> The Web you want to move across to the other Nest. </param>
    bool move(const Web& web);


   // <<-- Creer-Merge: methods -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
   // You can add additional methods here.
   // <<-- /Creer-Merge: methods -->>

   ~Spiderling_();

   // ####################
   // Don't edit these!
   // ####################
   /// \cond FALSE
   Spiderling_(std::initializer_list<std::pair<std::string, Any&&>> init);
   Spiderling_() : Spiderling_({}){}
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

} // spiders

} // cpp_client

#endif // GAMES_SPIDERS_SPIDERLING_H

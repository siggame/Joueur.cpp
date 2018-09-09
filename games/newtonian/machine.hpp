#ifndef GAMES_NEWTONIAN_MACHINE_H
#define GAMES_NEWTONIAN_MACHINE_H

// Machine
// A machine on a tile.

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
/// A machine on a tile.
/// </summary>
class Machine_ : public Game_object_
{
public:

    /// <summary>
    /// What type of ore the machine takes it, also determins the type of material it outputs.
    /// </summary>
    const std::string& ore_type;

    /// <summary>
    /// The amount of ore that needs to be inputted into the machine.
    /// </summary>
    const int& refine_input;

    /// <summary>
    /// The amount of material that out of the machine after running.
    /// </summary>
    const int& refine_output;

    /// <summary>
    /// The amount of turns this machine takes to refine the ore.
    /// </summary>
    const int& refine_time;

    /// <summary>
    /// The Tile this Machine is on.
    /// </summary>
    const Tile& tile;

    /// <summary>
    /// Time till the machine finishes running.
    /// </summary>
    const int& time_left;

    /// <summary>
    /// Tracks how many times this machine has been worked.
    /// </summary>
    const int& worked;

    // <<-- Creer-Merge: member variables -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
    // You can add additional member variables here. None of them will be tracked or updated by the server.
    // <<-- /Creer-Merge: member variables -->>



   // <<-- Creer-Merge: methods -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
   // You can add additional methods here.
   // <<-- /Creer-Merge: methods -->>

   ~Machine_();

   // ####################
   // Don't edit these!
   // ####################
   /// \cond FALSE
   Machine_(std::initializer_list<std::pair<std::string, Any&&>> init);
   Machine_() : Machine_({}){}
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

#endif // GAMES_NEWTONIAN_MACHINE_H

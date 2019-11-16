#ifndef GAMES_SPIDERS_NEST_H
#define GAMES_SPIDERS_NEST_H

// Nest
// A location (node) connected to other Nests via Webs (edges) in the game that Spiders can converge on, regardless of owner.

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

#include "impl/spiders_fwd.hpp"

// <<-- Creer-Merge: includes -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
// you can add additional #includes here
// <<-- /Creer-Merge: includes -->>

namespace cpp_client
{

namespace spiders
{

/// <summary>
/// A location (node) connected to other Nests via Webs (edges) in the game that Spiders can converge on, regardless of owner.
/// </summary>
class Nest_ : public Game_object_
{
public:

    /// <summary>
    /// The Player that 'controls' this Nest as they have the most Spiders on this nest.
    /// </summary>
    const Player& controlling_player;

    /// <summary>
    /// All the Spiders currently located on this Nest.
    /// </summary>
    const std::vector<Spider>& spiders;

    /// <summary>
    /// Webs that connect to this Nest.
    /// </summary>
    const std::vector<Web>& webs;

    /// <summary>
    /// The X coordinate of the Nest. Used for distance calculations.
    /// </summary>
    const int& x;

    /// <summary>
    /// The Y coordinate of the Nest. Used for distance calculations.
    /// </summary>
    const int& y;

    // <<-- Creer-Merge: member variables -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
    // You can add additional member variables here. None of them will be tracked or updated by the server.
    // <<-- /Creer-Merge: member variables -->>



   // <<-- Creer-Merge: methods -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
   // You can add additional methods here.
   // <<-- /Creer-Merge: methods -->>

   ~Nest_();

   // ####################
   // Don't edit these!
   // ####################
   /// \cond FALSE
   Nest_(std::initializer_list<std::pair<std::string, Any&&>> init);
   Nest_() : Nest_({}){}
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

#endif // GAMES_SPIDERS_NEST_H

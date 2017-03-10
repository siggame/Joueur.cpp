#ifndef GAMES_SALOON_BOTTLE_H
#define GAMES_SALOON_BOTTLE_H

// Bottle
// A bottle thrown by a bartender at a Tile.

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

#include "impl/saloon_fwd.hpp"

// <<-- Creer-Merge: includes -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
// you can add additional #includes here
// <<-- /Creer-Merge: includes -->>

namespace cpp_client
{

namespace saloon
{

/// <summary>
/// A bottle thrown by a bartender at a Tile.
/// </summary>
class Bottle_ : public Game_object_
{
public:

    /// <summary>
    /// The Direction this Bottle is flying and will move to between turns, can be 'North', 'East', 'South', or 'West'.
    /// </summary>
    const std::string& direction;

    /// <summary>
    /// The direction any Cowboys hit by this will move, can be 'North', 'East', 'South', or 'West'.
    /// </summary>
    const std::string& drunk_direction;

    /// <summary>
    /// True if this Bottle has impacted and has been destroyed (removed from the Game). False if still in the game flying through the saloon.
    /// </summary>
    const bool& is_destroyed;

    /// <summary>
    /// The Tile this bottle is currently flying over.
    /// </summary>
    const Tile& tile;

    // <<-- Creer-Merge: member variables -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
    // You can add additional member variables here. None of them will be tracked or updated by the server.
    // <<-- /Creer-Merge: member variables -->>



   // <<-- Creer-Merge: methods -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
   // You can add additional methods here.
   // <<-- /Creer-Merge: methods -->>

   ~Bottle_();

   // ####################
   // Don't edit these!
   // ####################
   /// \cond FALSE
   Bottle_(std::initializer_list<std::pair<std::string, Any&&>> init);
   Bottle_() : Bottle_({}){}
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

#endif // GAMES_SALOON_BOTTLE_H

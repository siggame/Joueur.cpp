#ifndef GAMES_STUMPED_SPAWNER_H
#define GAMES_STUMPED_SPAWNER_H

// Spawner
// A resource spawner that generates branches or food.

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
/// A resource spawner that generates branches or food.
/// </summary>
class Spawner_ : public Game_object_
{
public:

    /// <summary>
    /// True if this Spawner has been harvested this turn, and it will not heal at the end of the turn, false otherwise.
    /// </summary>
    const bool& has_been_harvested;

    /// <summary>
    /// How much health this Spawner has, which is used to calculate how much of its resource can be harvested.
    /// </summary>
    const int& health;

    /// <summary>
    /// The Tile this Spawner is on.
    /// </summary>
    const Tile& tile;

    /// <summary>
    /// What type of resource this is ('food' or 'branches').
    /// </summary>
    const std::string& type;

    // You can add additional member variables here. None of them will be tracked or updated by the server.



   // You can add additional methods here.

   ~Spawner_();

   // ####################
   // Don't edit these!
   // ####################
   /// \cond FALSE
   Spawner_(std::initializer_list<std::pair<std::string, Any&&>> init);
   Spawner_() : Spawner_({}){}
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

#endif // GAMES_STUMPED_SPAWNER_H

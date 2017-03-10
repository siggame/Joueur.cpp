#ifndef GAMES_SALOON_FURNISHING_H
#define GAMES_SALOON_FURNISHING_H

// Furnishing
// An furnishing in the Saloon that must be pathed around, or destroyed.

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
/// An furnishing in the Saloon that must be pathed around, or destroyed.
/// </summary>
class Furnishing_ : public Game_object_
{
public:

    /// <summary>
    /// How much health this Furnishing currently has.
    /// </summary>
    const int& health;

    /// <summary>
    /// If this Furnishing has been destroyed, and has been removed from the game.
    /// </summary>
    const bool& is_destroyed;

    /// <summary>
    /// True if this Furnishing is a piano and can be played, False otherwise.
    /// </summary>
    const bool& is_piano;

    /// <summary>
    /// If this is a piano and a Cowboy is playing it this turn.
    /// </summary>
    const bool& is_playing;

    /// <summary>
    /// The Tile that this Furnishing is located on.
    /// </summary>
    const Tile& tile;

    // <<-- Creer-Merge: member variables -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
    // You can add additional member variables here. None of them will be tracked or updated by the server.
    // <<-- /Creer-Merge: member variables -->>



   // <<-- Creer-Merge: methods -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
   // You can add additional methods here.
   // <<-- /Creer-Merge: methods -->>

   ~Furnishing_();

   // ####################
   // Don't edit these!
   // ####################
   /// \cond FALSE
   Furnishing_(std::initializer_list<std::pair<std::string, Any&&>> init);
   Furnishing_() : Furnishing_({}){}
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

#endif // GAMES_SALOON_FURNISHING_H

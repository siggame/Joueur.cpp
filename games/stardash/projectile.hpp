#ifndef GAMES_STARDASH_PROJECTILE_H
#define GAMES_STARDASH_PROJECTILE_H

// Projectile
// Tracks any projectiles moving through space.

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

#include "impl/stardash_fwd.hpp"

// <<-- Creer-Merge: includes -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
// you can add additional #includes here
// <<-- /Creer-Merge: includes -->>

namespace cpp_client
{

namespace stardash
{

/// <summary>
/// Tracks any projectiles moving through space.
/// </summary>
class Projectile_ : public Game_object_
{
public:

    /// <summary>
    /// The remaining health of the projectile.
    /// </summary>
    const int& energy;

    /// <summary>
    /// The amount of remaining distance the projectile can move.
    /// </summary>
    const int& fuel;

    /// <summary>
    /// The Player that owns and can control this Projectile.
    /// </summary>
    const Player& owner;

    /// <summary>
    /// The unit that is being attacked by this projectile.
    /// </summary>
    const Unit& target;

    /// <summary>
    /// The x value this projectile is on.
    /// </summary>
    const double& x;

    /// <summary>
    /// The y value this projectile is on.
    /// </summary>
    const double& y;

    // <<-- Creer-Merge: member variables -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
    // You can add additional member variables here. None of them will be tracked or updated by the server.
    // <<-- /Creer-Merge: member variables -->>



   // <<-- Creer-Merge: methods -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
   // You can add additional methods here.
   // <<-- /Creer-Merge: methods -->>

   ~Projectile_();

   // ####################
   // Don't edit these!
   // ####################
   /// \cond FALSE
   Projectile_(std::initializer_list<std::pair<std::string, Any&&>> init);
   Projectile_() : Projectile_({}){}
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

} // stardash

} // cpp_client

#endif // GAMES_STARDASH_PROJECTILE_H

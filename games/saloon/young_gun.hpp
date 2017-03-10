#ifndef GAMES_SALOON_YOUNG_GUN_H
#define GAMES_SALOON_YOUNG_GUN_H

// YoungGun
// An eager young person that wants to join your gang, and will call in the veteran Cowboys you need to win the brawl in the saloon.

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
/// An eager young person that wants to join your gang, and will call in the veteran Cowboys you need to win the brawl in the saloon.
/// </summary>
class Young_gun_ : public Game_object_
{
public:

    /// <summary>
    /// The Tile that a Cowboy will be called in on if this YoungGun calls in a Cowboy.
    /// </summary>
    const Tile& call_in_tile;

    /// <summary>
    /// True if the YoungGun can call in a Cowboy, false otherwise.
    /// </summary>
    const bool& can_call_in;

    /// <summary>
    /// The Player that owns and can control this YoungGun.
    /// </summary>
    const Player& owner;

    /// <summary>
    /// The Tile this YoungGun is currently on.
    /// </summary>
    const Tile& tile;

    // <<-- Creer-Merge: member variables -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
    // You can add additional member variables here. None of them will be tracked or updated by the server.
    // <<-- /Creer-Merge: member variables -->>


    /// <summary>
    /// tells the _young_gun to call in a new _cowboy of the given job to the open _tile nearest to them.
    /// </summary>
    /// <param name="job"> The job you want the Cowboy being brought to have. </param>
    Cowboy call_in(const std::string& job);


   // <<-- Creer-Merge: methods -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
   // You can add additional methods here.
   // <<-- /Creer-Merge: methods -->>

   ~Young_gun_();

   // ####################
   // Don't edit these!
   // ####################
   /// \cond FALSE
   Young_gun_(std::initializer_list<std::pair<std::string, Any&&>> init);
   Young_gun_() : Young_gun_({}){}
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

#endif // GAMES_SALOON_YOUNG_GUN_H

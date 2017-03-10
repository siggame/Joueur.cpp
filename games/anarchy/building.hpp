#ifndef GAMES_ANARCHY_BUILDING_H
#define GAMES_ANARCHY_BUILDING_H

// Building
// A basic building. It does nothing besides burn down. Other Buildings inherit from this class.

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

#include "impl/anarchy_fwd.hpp"

// <<-- Creer-Merge: includes -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
// you can add additional #includes here
// <<-- /Creer-Merge: includes -->>

namespace cpp_client
{

namespace anarchy
{

/// <summary>
/// A basic building. It does nothing besides burn down. Other Buildings inherit from this class.
/// </summary>
class Building_ : public Game_object_
{
public:

    /// <summary>
    /// When true this building has already been bribed this turn and cannot be bribed again this turn.
    /// </summary>
    const bool& bribed;

    /// <summary>
    /// The Building directly to the east of this building, or null if not present.
    /// </summary>
    const Building& building_east;

    /// <summary>
    /// The Building directly to the north of this building, or null if not present.
    /// </summary>
    const Building& building_north;

    /// <summary>
    /// The Building directly to the south of this building, or null if not present.
    /// </summary>
    const Building& building_south;

    /// <summary>
    /// The Building directly to the west of this building, or null if not present.
    /// </summary>
    const Building& building_west;

    /// <summary>
    /// How much fire is currently burning the building, and thus how much damage it will take at the end of its owner's turn. 0 means no fire.
    /// </summary>
    const int& fire;

    /// <summary>
    /// How much health this building currently has. When this reaches 0 the Building has been burned down.
    /// </summary>
    const int& health;

    /// <summary>
    /// True if this is the Headquarters of the owning player, false otherwise. Burning this down wins the game for the other Player.
    /// </summary>
    const bool& is_headquarters;

    /// <summary>
    /// The player that owns this building. If it burns down (health reaches 0) that player gets an additional bribe(s).
    /// </summary>
    const Player& owner;

    /// <summary>
    /// The location of the Building along the x-axis.
    /// </summary>
    const int& x;

    /// <summary>
    /// The location of the Building along the y-axis.
    /// </summary>
    const int& y;

    // <<-- Creer-Merge: member variables -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
    // You can add additional member variables here. None of them will be tracked or updated by the server.
    // <<-- /Creer-Merge: member variables -->>



   // <<-- Creer-Merge: methods -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
   // You can add additional methods here.
   // <<-- /Creer-Merge: methods -->>

   ~Building_();

   // ####################
   // Don't edit these!
   // ####################
   /// \cond FALSE
   Building_(std::initializer_list<std::pair<std::string, Any&&>> init);
   Building_() : Building_({}){}
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

} // anarchy

} // cpp_client

#endif // GAMES_ANARCHY_BUILDING_H

#ifndef GAMES_STARDASH_UNIT_H
#define GAMES_STARDASH_UNIT_H

// Unit
// A unit in the game. May be a corvette, missleboat, martyr, transport, miner.

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
/// A unit in the game. May be a corvette, missleboat, martyr, transport, miner.
/// </summary>
class Unit_ : public Game_object_
{
public:

    /// <summary>
    /// Whether or not this Unit has performed its action this turn.
    /// </summary>
    const bool& acted;

    /// <summary>
    /// The x value this unit is dashing to.
    /// </summary>
    const double& dash_x;

    /// <summary>
    /// The y value this unit is dashing to.
    /// </summary>
    const double& dash_y;

    /// <summary>
    /// The remaining health of the unit.
    /// </summary>
    const int& energy;

    /// <summary>
    /// The amount of Genarium ore carried by this unit. (0 to job carry capacity - other carried items).
    /// </summary>
    const int& genarium;

    /// <summary>
    /// Tracks whether or not the ship is dashing or Mining. If true, it cannot do anything else.
    /// </summary>
    const bool& is_busy;

    /// <summary>
    /// The Job this Unit has.
    /// </summary>
    const Job& job;

    /// <summary>
    /// The amount of Legendarium ore carried by this unit. (0 to job carry capacity - other carried items).
    /// </summary>
    const int& legendarium;

    /// <summary>
    /// The distance this unit can still move.
    /// </summary>
    const double& moves;

    /// <summary>
    /// The amount of Mythicite carried by this unit. (0 to job carry capacity - other carried items).
    /// </summary>
    const int& mythicite;

    /// <summary>
    /// The Player that owns and can control this Unit.
    /// </summary>
    const Player& owner;

    /// <summary>
    /// The martyr ship that is currently shielding this ship if any.
    /// </summary>
    const Unit& protector;

    /// <summary>
    /// The amount of Rarium carried by this unit. (0 to job carry capacity - other carried items).
    /// </summary>
    const int& rarium;

    /// <summary>
    /// The shield that a martyr ship has.
    /// </summary>
    const int& shield;

    /// <summary>
    /// The x value this unit is on.
    /// </summary>
    const double& x;

    /// <summary>
    /// The y value this unit is on.
    /// </summary>
    const double& y;

    // <<-- Creer-Merge: member variables -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
    // You can add additional member variables here. None of them will be tracked or updated by the server.
    // <<-- /Creer-Merge: member variables -->>


    /// <summary>
    /// attacks the specified unit.
    /// </summary>
    /// <param name="enemy"> The Unit being attacked. </param>
    bool attack(const Unit& enemy);

    /// <summary>
    /// causes the unit to dash towards the designated destination.
    /// </summary>
    /// <param name="x"> The x value of the destination's coordinates. </param>
    /// <param name="y"> The y value of the destination's coordinates. </param>
    bool dash(const double& x, const double& y);

    /// <summary>
    /// allows a miner to mine a asteroid.
    /// </summary>
    /// <param name="body"> The object to be mined. </param>
    bool mine(const Body& body);

    /// <summary>
    /// moves this _unit from its current location to the new location specified.
    /// </summary>
    /// <param name="x"> The x value of the destination's coordinates. </param>
    /// <param name="y"> The y value of the destination's coordinates. </param>
    bool move(const double& x, const double& y);

    /// <summary>
    /// tells you if your ship can move to that location from were it is without clipping the sun.
    /// </summary>
    /// <param name="x"> The x position of the location you wish to arrive. </param>
    /// <param name="y"> The y position of the location you wish to arrive. </param>
    bool safe(const double& x, const double& y);

    /// <summary>
    /// attacks the specified projectile.
    /// </summary>
    /// <param name="missile"> The projectile being shot down. </param>
    bool shootdown(const Projectile& missile);

    /// <summary>
    /// grab materials from a friendly unit. _doesn't use a action.
    /// </summary>
    /// <param name="unit"> The unit you are grabbing the resources from. </param>
    /// <param name="amount"> The amount of materials to you with to grab. Amounts <= 0 will pick up all the materials that the unit can. </param>
    /// <param name="material"> The material the unit will pick up. 'genarium', 'rarium', 'legendarium', or 'mythicite'. </param>
    bool transfer(const Unit& unit, int amount, const std::string& material);


   // <<-- Creer-Merge: methods -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
   // You can add additional methods here.
   // <<-- /Creer-Merge: methods -->>

   ~Unit_();

   // ####################
   // Don't edit these!
   // ####################
   /// \cond FALSE
   Unit_(std::initializer_list<std::pair<std::string, Any&&>> init);
   Unit_() : Unit_({}){}
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

#endif // GAMES_STARDASH_UNIT_H

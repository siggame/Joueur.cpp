#ifndef GAMES_CATASTROPHE_UNIT_H
#define GAMES_CATASTROPHE_UNIT_H

// Unit
// A unit in the game.

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

#include "impl/catastrophe_fwd.hpp"

// <<-- Creer-Merge: includes -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
// you can add additional #includes here
// <<-- /Creer-Merge: includes -->>

namespace cpp_client
{

namespace catastrophe
{

/// <summary>
/// A unit in the game.
/// </summary>
class Unit_ : public Game_object_
{
public:

    /// <summary>
    /// Whether this Unit has performed its action this turn.
    /// </summary>
    const bool& acted;

    /// <summary>
    /// The amount of energy this Unit has (from 0.0 to 100.0).
    /// </summary>
    const double& energy;

    /// <summary>
    /// The amount of food this Unit is holding.
    /// </summary>
    const int& food;

    /// <summary>
    /// The Job this Unit was recruited to do.
    /// </summary>
    const Job& job;

    /// <summary>
    /// The amount of materials this Unit is holding.
    /// </summary>
    const int& materials;

    /// <summary>
    /// The tile this Unit is moving to. This only applies to neutral fresh humans spawned on the road. Otherwise, the tile this Unit is on.
    /// </summary>
    const Tile& movement_target;

    /// <summary>
    /// How many moves this Unit has left this turn.
    /// </summary>
    const int& moves;

    /// <summary>
    /// The Player that owns and can control this Unit, or null if the Unit is neutral.
    /// </summary>
    const Player& owner;

    /// <summary>
    /// The Units in the same squad as this Unit. Units in the same squad attack and defend together.
    /// </summary>
    const std::vector<Unit>& squad;

    /// <summary>
    /// Whether this Unit is starving. Starving Units regenerate energy at half the rate they normally would while resting.
    /// </summary>
    const bool& starving;

    /// <summary>
    /// The Tile this Unit is on.
    /// </summary>
    const Tile& tile;

    /// <summary>
    /// The number of turns before this Unit dies. This only applies to neutral fresh humans created from combat. Otherwise, 0.
    /// </summary>
    const int& turns_to_die;

    // <<-- Creer-Merge: member variables -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
    // You can add additional member variables here. None of them will be tracked or updated by the server.
    // <<-- /Creer-Merge: member variables -->>


    /// <summary>
    /// attacks an adjacent _tile. _costs an action for each _unit in this _unit's squad. _units in the squad without an action don't participate in combat. _units in combat cannot move afterwards. _attacking structures will not give materials.
    /// </summary>
    /// <param name="tile"> The Tile to attack. </param>
    bool attack(const Tile& tile);

    /// <summary>
    /// changes this _unit's _job. _must be at max energy (100) to change _jobs.
    /// </summary>
    /// <param name="job"> The name of the Job to change to. </param>
    bool change_job(const std::string& job);

    /// <summary>
    /// constructs a _structure on an adjacent _tile.
    /// </summary>
    /// <param name="tile"> The Tile to construct the Structure on. It must have enough materials on it for a Structure to be constructed. </param>
    /// <param name="type"> The type of Structure to construct on that Tile. </param>
    bool construct(const Tile& tile, const std::string& type);

    /// <summary>
    /// converts an adjacent _unit to your side.
    /// </summary>
    /// <param name="tile"> The Tile with the Unit to convert. </param>
    bool convert(const Tile& tile);

    /// <summary>
    /// removes materials from an adjacent _tile's _structure. _you cannot deconstruct friendly structures (see `_unit.attack`).
    /// </summary>
    /// <param name="tile"> The Tile to deconstruct. It must have a Structure on it. </param>
    bool deconstruct(const Tile& tile);

    /// <summary>
    /// drops some of the given resource on or adjacent to the _unit's _tile. _does not count as an action.
    /// </summary>
    /// <param name="tile"> The Tile to drop materials/food on. </param>
    /// <param name="resource"> The type of resource to drop ('materials' or 'food'). </param>
    /// <param name="amount"> The amount of the resource to drop. Amounts <= 0 will drop as much as possible. </param>
    bool drop(const Tile& tile, const std::string& resource, int amount = 0);

    /// <summary>
    /// harvests the food on an adjacent _tile.
    /// </summary>
    /// <param name="tile"> The Tile you want to harvest. </param>
    bool harvest(const Tile& tile);

    /// <summary>
    /// moves this _unit from its current _tile to an adjacent _tile.
    /// </summary>
    /// <param name="tile"> The Tile this Unit should move to. </param>
    bool move(const Tile& tile);

    /// <summary>
    /// picks up some materials or food on or adjacent to the _unit's _tile. _does not count as an action.
    /// </summary>
    /// <param name="tile"> The Tile to pickup materials/food from. </param>
    /// <param name="resource"> The type of resource to pickup ('materials' or 'food'). </param>
    /// <param name="amount"> The amount of the resource to pickup. Amounts <= 0 will pickup as much as possible. </param>
    bool pickup(const Tile& tile, const std::string& resource, int amount = 0);

    /// <summary>
    /// regenerates energy. _must be in range of a friendly shelter to rest. _costs an action. _units cannot move after resting.
    /// </summary>
    bool rest();


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

} // catastrophe

} // cpp_client

#endif // GAMES_CATASTROPHE_UNIT_H

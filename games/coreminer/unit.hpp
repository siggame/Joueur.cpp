#ifndef GAMES_COREMINER_UNIT_H
#define GAMES_COREMINER_UNIT_H

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

#include "impl/coreminer_fwd.hpp"

// <<-- Creer-Merge: includes -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
// you can add additional #includes here
// <<-- /Creer-Merge: includes -->>

namespace cpp_client
{

namespace coreminer
{

/// <summary>
/// A unit in the game.
/// </summary>
class Unit_ : public Game_object_
{
public:

    /// <summary>
    /// The number of bombs being carried by this Unit. (0 to job cargo capacity - other carried materials).
    /// </summary>
    const int& bombs;

    /// <summary>
    /// The number of building materials carried by this Unit. (0 to job cargo capacity - other carried materials).
    /// </summary>
    const int& building_materials;

    /// <summary>
    /// The amount of dirt carried by this Unit. (0 to job cargo capacity - other carried materials).
    /// </summary>
    const int& dirt;

    /// <summary>
    /// The remaining health of a Unit.
    /// </summary>
    const int& health;

    /// <summary>
    /// The Job this Unit has.
    /// </summary>
    const Job& job;

    /// <summary>
    /// The maximum amount of cargo this Unit can carry.
    /// </summary>
    const int& max_cargo_capacity;

    /// <summary>
    /// The maximum health of this Unit.
    /// </summary>
    const int& max_health;

    /// <summary>
    /// The maximum mining power of this Unit.
    /// </summary>
    const int& max_mining_power;

    /// <summary>
    /// The maximum moves this Unit can have.
    /// </summary>
    const int& max_moves;

    /// <summary>
    /// The remaining mining power this Unit has this turn.
    /// </summary>
    const int& mining_power;

    /// <summary>
    /// The number of moves this Unit has left this turn.
    /// </summary>
    const int& moves;

    /// <summary>
    /// The amount of ore carried by this Unit. (0 to job capacity - other carried materials).
    /// </summary>
    const int& ore;

    /// <summary>
    /// The Player that owns and can control this Unit.
    /// </summary>
    const Player& owner;

    /// <summary>
    /// The Tile this Unit is on.
    /// </summary>
    const Tile& tile;

    // <<-- Creer-Merge: member variables -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
    // You can add additional member variables here. None of them will be tracked or updated by the server.
    // <<-- /Creer-Merge: member variables -->>


    /// <summary>
    /// builds a support, shield, or ladder on _unit's tile, or an adjacent _tile.
    /// </summary>
    /// <param name="tile"> The Tile to build on. </param>
    /// <param name="type"> The structure to build (support, ladder, or shield). </param>
    bool build(const Tile& tile, const std::string& type);

    /// <summary>
    /// dumps materials from cargo to an adjacent tile.
    /// </summary>
    /// <param name="tile"> The tile the materials will be dumped on. </param>
    /// <param name="material"> The material the Unit will drop. 'dirt', 'ore', or 'bomb'. </param>
    /// <param name="amount"> The number of materials to drop. Amounts <= 0 will drop all the materials. </param>
    bool dump(const Tile& tile, const std::string& material, int amount);

    /// <summary>
    /// mines the _tile the _unit is on or an adjacent tile.
    /// </summary>
    /// <param name="tile"> The Tile the materials will be mined from. </param>
    /// <param name="amount"> The amount of material to mine up. Amounts <= 0 will mine all the materials that the Unit can. </param>
    bool mine(const Tile& tile, int amount);

    /// <summary>
    /// moves this _unit from its current _tile to an adjacent _tile.
    /// </summary>
    /// <param name="tile"> The Tile this Unit should move to. </param>
    bool move(const Tile& tile);

    /// <summary>
    /// upgrade an attribute of this _unit. "health", "mining_power", "moves", or "capacity".
    /// </summary>
    /// <param name="attribute"> The attribute of the Unit to be upgraded. </param>
    bool upgrade(const std::string& attribute);


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

} // coreminer

} // cpp_client

#endif // GAMES_COREMINER_UNIT_H

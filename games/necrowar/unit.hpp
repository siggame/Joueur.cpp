#ifndef GAMES_NECROWAR_UNIT_H
#define GAMES_NECROWAR_UNIT_H

// Unit
// A unit in the game. May be a worker, zombie, ghoul, hound, abomination, wraith or horseman.

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

#include "impl/necrowar_fwd.hpp"

// <<-- Creer-Merge: includes -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
// you can add additional #includes here
// <<-- /Creer-Merge: includes -->>

namespace cpp_client
{

namespace necrowar
{

/// <summary>
/// A unit in the game. May be a worker, zombie, ghoul, hound, abomination, wraith or horseman.
/// </summary>
class Unit_ : public Game_object_
{
public:

    /// <summary>
    /// Whether or not this Unit has performed its action this turn (attack or build).
    /// </summary>
    const bool& acted;

    /// <summary>
    /// The remaining health of a unit.
    /// </summary>
    const int& health;

    /// <summary>
    /// The type of unit this is.
    /// </summary>
    const Unit_job& job;

    /// <summary>
    /// The number of moves this unit has left this turn.
    /// </summary>
    const int& moves;

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
    /// attacks an enemy tower on an adjacent tile.
    /// </summary>
    /// <param name="tile"> The Tile to attack. </param>
    bool attack(const Tile& tile);

    /// <summary>
    /// unit, if it is a worker, builds a tower on the tile it is on, only workers can do this.
    /// </summary>
    /// <param name="title"> The tower type to build, as a string. </param>
    bool build(const std::string& title);

    /// <summary>
    /// stops adjacent to a river tile and begins fishing for mana.
    /// </summary>
    /// <param name="tile"> The tile the unit will stand on as it fishes. </param>
    bool fish(const Tile& tile);

    /// <summary>
    /// enters a mine and is put to work gathering resources.
    /// </summary>
    /// <param name="tile"> The tile the mine is located on. </param>
    bool mine(const Tile& tile);

    /// <summary>
    /// moves this _unit from its current _tile to an adjacent _tile.
    /// </summary>
    /// <param name="tile"> The Tile this Unit should move to. </param>
    bool move(const Tile& tile);


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

} // necrowar

} // cpp_client

#endif // GAMES_NECROWAR_UNIT_H

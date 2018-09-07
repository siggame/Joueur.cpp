#ifndef GAMES_NEWTONIAN_UNIT_H
#define GAMES_NEWTONIAN_UNIT_H

// Unit
// A unit in the game. May be a manager, intern, or physicist.

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

#include "impl/newtonian_fwd.hpp"

// <<-- Creer-Merge: includes -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
// you can add additional #includes here
// <<-- /Creer-Merge: includes -->>

namespace cpp_client
{

namespace newtonian
{

/// <summary>
/// A unit in the game. May be a manager, intern, or physicist.
/// </summary>
class Unit_ : public Game_object_
{
public:

    /// <summary>
    /// Whether this Unit has performed its action this turn.
    /// </summary>
    const bool& acted;

    /// <summary>
    /// The amount of blueium carried by this unit.
    /// </summary>
    const int& blueium;

    /// <summary>
    /// The amount of blueium ore carried by this unit.
    /// </summary>
    const int& blueium_ore;

    /// <summary>
    /// If a ship is on this Tile, how much health it has remaining.
    /// </summary>
    const int& health;

    /// <summary>
    /// The Job this Unit does.
    /// </summary>
    const Job& job;

    /// <summary>
    /// How many more times this Unit may move this turn.
    /// </summary>
    const int& moves;

    /// <summary>
    /// The Player that owns and can control this Unit.
    /// </summary>
    const Player& owner;

    /// <summary>
    /// The amount of redium carried by this unit.
    /// </summary>
    const int& redium;

    /// <summary>
    /// The amount of redium ore carried by this unit.
    /// </summary>
    const int& redium_ore;

    /// <summary>
    /// Duration of stun immunity.
    /// </summary>
    const int& stun_immune;

    /// <summary>
    /// Duration the unit is stunned.
    /// </summary>
    const int& stun_time;

    /// <summary>
    /// The Tile this Unit is on.
    /// </summary>
    const Tile& tile;

    // <<-- Creer-Merge: member variables -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
    // You can add additional member variables here. None of them will be tracked or updated by the server.
    // <<-- /Creer-Merge: member variables -->>


    /// <summary>
    /// makes the unit do something to a machine on its tile. _interns sabotage, physicists run, and managers protect.
    /// </summary>
    /// <param name="tile"> The tile the unit acts on. </param>
    bool act(const Tile& tile);

    /// <summary>
    /// attacks a unit on a ajacent tile.
    /// </summary>
    /// <param name="tile"> The Tile to attack. </param>
    bool attack(const Tile& tile);

    /// <summary>
    /// drops material at the units feat
    /// </summary>
    /// <param name="amount"> The amount of materials to dropped. Amounts <= 0 will drop all the materials on the Unit. </param>
    /// <param name="material"> The material the unit will drop. </param>
    bool drop(int amount, const std::string& material);

    /// <summary>
    /// moves this _unit from its current _tile to an adjacent _tile.
    /// </summary>
    /// <param name="tile"> The Tile this Unit should move to. </param>
    bool move(const Tile& tile);

    /// <summary>
    /// picks up material at the units feat
    /// </summary>
    /// <param name="amount"> The amount of materials to pick up. Amounts <= 0 will pick up all the materials on the Unit. </param>
    /// <param name="material"> The material the unit will pick up. </param>
    bool pickup(int amount, const std::string& material);


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

} // newtonian

} // cpp_client

#endif // GAMES_NEWTONIAN_UNIT_H

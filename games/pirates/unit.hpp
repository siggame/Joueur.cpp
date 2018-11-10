#ifndef GAMES_PIRATES_UNIT_H
#define GAMES_PIRATES_UNIT_H

// Unit
// A unit group in the game. This may consist of a ship and any number of crew.

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

#include "impl/pirates_fwd.hpp"

// <<-- Creer-Merge: includes -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
// you can add additional #includes here
// <<-- /Creer-Merge: includes -->>

namespace cpp_client
{

namespace pirates
{

/// <summary>
/// A unit group in the game. This may consist of a ship and any number of crew.
/// </summary>
class Unit_ : public Game_object_
{
public:

    /// <summary>
    /// Whether this Unit has performed its action this turn.
    /// </summary>
    const bool& acted;

    /// <summary>
    /// How many crew are on this Tile. This number will always be <= crewHealth.
    /// </summary>
    const int& crew;

    /// <summary>
    /// How much total health the crew on this Tile have.
    /// </summary>
    const int& crew_health;

    /// <summary>
    /// How much gold this Unit is carrying.
    /// </summary>
    const int& gold;

    /// <summary>
    /// How many more times this Unit may move this turn.
    /// </summary>
    const int& moves;

    /// <summary>
    /// The Player that owns and can control this Unit, or null if the Unit is neutral.
    /// </summary>
    const Player& owner;

    /// <summary>
    /// (Merchants only) The path this Unit will follow. The first element is the Tile this Unit will move to next.
    /// </summary>
    const std::vector<Tile>& path;

    /// <summary>
    /// If a ship is on this Tile, how much health it has remaining. 0 for no ship.
    /// </summary>
    const int& ship_health;

    /// <summary>
    /// (Merchants only) The number of turns this merchant ship won't be able to move. They will still attack. Merchant ships are stunned when they're attacked.
    /// </summary>
    const int& stun_turns;

    /// <summary>
    /// (Merchants only) The Port this Unit is moving to.
    /// </summary>
    const Port& target_port;

    /// <summary>
    /// The Tile this Unit is on.
    /// </summary>
    const Tile& tile;

    // <<-- Creer-Merge: member variables -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
    // You can add additional member variables here. None of them will be tracked or updated by the server.
    // <<-- /Creer-Merge: member variables -->>


    /// <summary>
    /// attacks either the 'crew' or 'ship' on a _tile in range.
    /// </summary>
    /// <param name="tile"> The Tile to attack. </param>
    /// <param name="target"> Whether to attack 'crew' or 'ship'. Crew deal damage to crew and ships deal damage to ships. Consumes any remaining moves. </param>
    bool attack(const Tile& tile, const std::string& target);

    /// <summary>
    /// buries gold on this _unit's _tile. _gold must be a certain distance away for it to get interest (_game.min_interest_distance).
    /// </summary>
    /// <param name="amount"> How much gold this Unit should bury. Amounts <= 0 will bury as much as possible. </param>
    bool bury(int amount);

    /// <summary>
    /// puts gold into an adjacent _port. _if that _port is the _player's port, the gold is added to that _player. _if that _port is owned by merchants, it adds to that _port's investment.
    /// </summary>
    /// <param name="amount"> The amount of gold to deposit. Amounts <= 0 will deposit all the gold on this Unit. </param>
    bool deposit(int amount = 0);

    /// <summary>
    /// digs up gold on this _unit's _tile.
    /// </summary>
    /// <param name="amount"> How much gold this Unit should take. Amounts <= 0 will dig up as much as possible. </param>
    bool dig(int amount = 0);

    /// <summary>
    /// moves this _unit from its current _tile to an adjacent _tile. _if this _unit merges with another one, the other _unit will be destroyed and its tile will be set to null. _make sure to check that your _unit's tile is not null before doing things with it.
    /// </summary>
    /// <param name="tile"> The Tile this Unit should move to. </param>
    bool move(const Tile& tile);

    /// <summary>
    /// regenerates this _unit's health. _must be used in range of a port.
    /// </summary>
    bool rest();

    /// <summary>
    /// moves a number of crew from this _unit to the given _tile. _this will consume a move from those crew.
    /// </summary>
    /// <param name="tile"> The Tile to move the crew to. </param>
    /// <param name="amount"> The number of crew to move onto that Tile. Amount <= 0 will move all the crew to that Tile. </param>
    /// <param name="gold"> The amount of gold the crew should take with them. Gold < 0 will move all the gold to that Tile. </param>
    bool split(const Tile& tile, int amount = 1, int gold = 0);

    /// <summary>
    /// takes gold from the _player. _you can only withdraw from your own _port.
    /// </summary>
    /// <param name="amount"> The amount of gold to withdraw. Amounts <= 0 will withdraw everything. </param>
    bool withdraw(int amount = 0);


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

} // pirates

} // cpp_client

#endif // GAMES_PIRATES_UNIT_H

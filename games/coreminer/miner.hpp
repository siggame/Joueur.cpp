#ifndef GAMES_COREMINER_MINER_H
#define GAMES_COREMINER_MINER_H

// Miner
// A Miner in the game.

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
/// A Miner in the game.
/// </summary>
class Miner_ : public Game_object_
{
public:

    /// <summary>
    /// The number of bombs being carried by this Miner.
    /// </summary>
    const int& bombs;

    /// <summary>
    /// The number of building materials carried by this Miner.
    /// </summary>
    const int& building_materials;

    /// <summary>
    /// The Upgrade this Miner is on.
    /// </summary>
    const Upgrade& current_upgrade;

    /// <summary>
    /// The amount of dirt carried by this Miner.
    /// </summary>
    const int& dirt;

    /// <summary>
    /// The remaining health of this Miner.
    /// </summary>
    const int& health;

    /// <summary>
    /// The remaining mining power this Miner has this turn.
    /// </summary>
    const int& mining_power;

    /// <summary>
    /// The number of moves this Miner has left this turn.
    /// </summary>
    const int& moves;

    /// <summary>
    /// The amount of ore carried by this Miner.
    /// </summary>
    const int& ore;

    /// <summary>
    /// The Player that owns and can control this Miner.
    /// </summary>
    const Player& owner;

    /// <summary>
    /// The Tile this Miner is on.
    /// </summary>
    const Tile& tile;

    /// <summary>
    /// The upgrade level of this Miner. Starts at 0.
    /// </summary>
    const int& upgrade_level;

    // <<-- Creer-Merge: member variables -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
    // You can add additional member variables here. None of them will be tracked or updated by the server.
    // <<-- /Creer-Merge: member variables -->>


    /// <summary>
    /// builds a support, shield, or ladder on _miner's _tile, or an adjacent _tile.
    /// </summary>
    /// <param name="tile"> The Tile to build on. </param>
    /// <param name="type"> The structure to build (support, ladder, or shield). </param>
    bool build(const Tile& tile, const std::string& type);

    /// <summary>
    /// purchase a resource from the _player's base or hopper.
    /// </summary>
    /// <param name="resource"> The type of resource to buy. </param>
    /// <param name="amount"> The amount of resource to buy. Amounts <= 0 will buy all of that material Player can. </param>
    bool buy(const std::string& resource, int amount);

    /// <summary>
    /// dumps materials from cargo to an adjacent _tile. _if the _tile is a base or a hopper _tile, materials are sold instead of placed.
    /// </summary>
    /// <param name="tile"> The Tile the materials will be dumped on. </param>
    /// <param name="material"> The material the Miner will drop. 'dirt', 'ore', or 'bomb'. </param>
    /// <param name="amount"> The number of materials to drop. Amounts <= 0 will drop all of the material. </param>
    bool dump(const Tile& tile, const std::string& material, int amount);

    /// <summary>
    /// mines the _tile the _miner is on or an adjacent _tile.
    /// </summary>
    /// <param name="tile"> The Tile the materials will be mined from. </param>
    /// <param name="amount"> The amount of material to mine up. Amounts <= 0 will mine all the materials that the Miner can. </param>
    bool mine(const Tile& tile, int amount);

    /// <summary>
    /// moves this _miner from its current _tile to an adjacent _tile.
    /// </summary>
    /// <param name="tile"> The Tile this Miner should move to. </param>
    bool move(const Tile& tile);

    /// <summary>
    /// transfers a resource from the one _miner to another.
    /// </summary>
    /// <param name="miner"> The Miner to transfer materials to. </param>
    /// <param name="resource"> The type of resource to transfer. </param>
    /// <param name="amount"> The amount of resource to transfer. Amounts <= 0 will transfer all the of the material. </param>
    bool transfer(const Miner& miner, const std::string& resource, int amount);

    /// <summary>
    /// upgrade this _miner by installing an upgrade module.
    /// </summary>
    bool upgrade();


   // <<-- Creer-Merge: methods -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
   // You can add additional methods here.
   // <<-- /Creer-Merge: methods -->>

   ~Miner_();

   // ####################
   // Don't edit these!
   // ####################
   /// \cond FALSE
   Miner_(std::initializer_list<std::pair<std::string, Any&&>> init);
   Miner_() : Miner_({}){}
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

#endif // GAMES_COREMINER_MINER_H

#ifndef GAMES_STUMPED_BEAVER_H
#define GAMES_STUMPED_BEAVER_H

// Beaver
// A beaver in the game.

// DO NOT MODIFY THIS FILE
// Never try to directly create an instance of this class, or modify its member variables.
// Instead, you should only be reading its variables and calling its functions.

#include <vector>
#include <unordered_map>
#include <string>
#include <initializer_list>

#include "../../joueur/src/any.hpp"

#include "game_object.hpp"

#include "impl/stumped_fwd.hpp"

// <<-- Creer-Merge: includes -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
// you can add additional #includes here
// <<-- /Creer-Merge: includes -->>

namespace cpp_client
{

namespace stumped
{

/// <summary>
/// A beaver in the game.
/// </summary>
class Beaver_ : public Game_object_
{
public:

    /// <summary>
    /// The number of actions remaining for the beaver this turn.
    /// </summary>
    const int& actions;

    /// <summary>
    /// The number of branches this beaver is holding.
    /// </summary>
    const int& branches;

    /// <summary>
    /// Number of turns this beaver is distracted for (0 means not distracted).
    /// </summary>
    const int& distracted;

    /// <summary>
    /// The number of fish this beaver is holding.
    /// </summary>
    const int& fish;

    /// <summary>
    /// How much health this beaver has left.
    /// </summary>
    const int& health;

    /// <summary>
    /// The Job this beaver was recruited to do.
    /// </summary>
    const Job& job;

    /// <summary>
    /// How many moves this beaver has left this turn.
    /// </summary>
    const int& moves;

    /// <summary>
    /// The Player that owns and can control this beaver.
    /// </summary>
    const Player& owner;

    /// <summary>
    /// The tile this beaver is on.
    /// </summary>
    const Tile& tile;

    // <<-- Creer-Merge: member variables -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
    // You can add additional member variables here. None of them will be tracked or updated by the server.
    // <<-- /Creer-Merge: member variables -->>


    /// <summary>
    /// attacks another adjacent beaver.
    /// </summary>
    /// <param name="tile"> The tile of the beaver you want to attack. </param>
    bool attack(const Tile& tile);

    /// <summary>
    /// builds a lodge on the _beavers current tile.
    /// </summary>
    bool build_lodge();

    /// <summary>
    /// drops some of the given resource on the beaver's tile. _fish dropped in water disappear instantly, and fish dropped on land die one per tile per turn.
    /// </summary>
    /// <param name="resource"> The type of resource to drop ('branch' or 'fish'). </param>
    /// <param name="amount"> The amount of the resource to drop, numbers <= 0 will drop all of that type. </param>
    bool drop(const std::string& resource, int amount = false);

    /// <summary>
    /// harvests the branches or fish from a _spawner on an adjacent tile.
    /// </summary>
    /// <param name="tile"> The tile you want to harvest. </param>
    bool harvest(const Tile& tile);

    /// <summary>
    /// moves this beaver from its current tile to an adjacent tile.
    /// </summary>
    /// <param name="tile"> The tile this beaver should move to. Costs 2 moves normally, 3 if moving upstream, and 1 if moving downstream. </param>
    bool move(const Tile& tile);

    /// <summary>
    /// picks up some branches or fish on the beaver's tile.
    /// </summary>
    /// <param name="resource"> The type of resource to pickup ('branch' or 'fish'). </param>
    /// <param name="amount"> The amount of the resource to drop, numbers <= 0 will pickup all of that type. </param>
    bool pickup(const std::string& resource, int amount = false);

   // <<-- Creer-Merge: methods -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
   // You can add additional methods here.
   // <<-- /Creer-Merge: methods -->>

   ~Beaver_();

   // ####################
   // Don't edit these!
   // ####################
   /// \cond FALSE
   Beaver_(std::initializer_list<std::pair<std::string, Any&&>> init);
   Beaver_() : Beaver_({}){}
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

} // stumped

} // cpp_client

#endif // GAMES_STUMPED_BEAVER_H

#ifndef GAMES_STUMPED_BEAVER_H
#define GAMES_STUMPED_BEAVER_H

// Beaver
// A beaver in the game.

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

#include "impl/stumped_fwd.hpp"

// you can add additional #includes here

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
    /// The number of actions remaining for the Beaver this turn.
    /// </summary>
    const int& actions;

    /// <summary>
    /// The amount of branches this Beaver is holding.
    /// </summary>
    const int& branches;

    /// <summary>
    /// The amount of food this Beaver is holding.
    /// </summary>
    const int& food;

    /// <summary>
    /// How much health this Beaver has left.
    /// </summary>
    const int& health;

    /// <summary>
    /// The Job this Beaver was recruited to do.
    /// </summary>
    const Job& job;

    /// <summary>
    /// How many moves this Beaver has left this turn.
    /// </summary>
    const int& moves;

    /// <summary>
    /// The Player that owns and can control this Beaver.
    /// </summary>
    const Player& owner;

    /// <summary>
    /// True if the Beaver has finished being recruited and can do things, False otherwise.
    /// </summary>
    const bool& recruited;

    /// <summary>
    /// The Tile this Beaver is on.
    /// </summary>
    const Tile& tile;

    /// <summary>
    /// Number of turns this Beaver is distracted for (0 means not distracted).
    /// </summary>
    const int& turns_distracted;

    // You can add additional member variables here. None of them will be tracked or updated by the server.


    /// <summary>
    /// attacks another adjacent beaver.
    /// </summary>
    /// <param name="beaver"> The Beaver to attack. Must be on an adjacent Tile. </param>
    bool attack(const Beaver& beaver);

    /// <summary>
    /// builds a lodge on the _beavers current _tile.
    /// </summary>
    bool build_lodge();

    /// <summary>
    /// drops some of the given resource on the beaver's _tile.
    /// </summary>
    /// <param name="tile"> The Tile to drop branches/food on. Must be the same Tile that the Beaver is on, or an adjacent one. </param>
    /// <param name="resource"> The type of resource to drop ('branch' or 'food'). </param>
    /// <param name="amount"> The amount of the resource to drop, numbers <= 0 will drop all the resource type. </param>
    bool drop(const Tile& tile, const std::string& resource, int amount = 0);

    /// <summary>
    /// harvests the branches or food from a _spawner on an adjacent _tile.
    /// </summary>
    /// <param name="spawner"> The Spawner you want to harvest. Must be on an adjacent Tile. </param>
    bool harvest(const Spawner& spawner);

    /// <summary>
    /// moves this _beaver from its current _tile to an adjacent _tile.
    /// </summary>
    /// <param name="tile"> The Tile this Beaver should move to. </param>
    bool move(const Tile& tile);

    /// <summary>
    /// picks up some branches or food on the beaver's tile.
    /// </summary>
    /// <param name="tile"> The Tile to pickup branches/food from. Must be the same Tile that the Beaver is on, or an adjacent one. </param>
    /// <param name="resource"> The type of resource to pickup ('branch' or 'food'). </param>
    /// <param name="amount"> The amount of the resource to drop, numbers <= 0 will pickup all of the resource type. </param>
    bool pickup(const Tile& tile, const std::string& resource, int amount = 0);


   // You can add additional methods here.

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

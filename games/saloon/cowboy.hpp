#ifndef GAMES_SALOON_COWBOY_H
#define GAMES_SALOON_COWBOY_H

// Cowboy
// A person on the map that can move around and interact within the saloon.

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

#include "impl/saloon_fwd.hpp"

// <<-- Creer-Merge: includes -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
// you can add additional #includes here
// <<-- /Creer-Merge: includes -->>

namespace cpp_client
{

namespace saloon
{

/// <summary>
/// A person on the map that can move around and interact within the saloon.
/// </summary>
class Cowboy_ : public Game_object_
{
public:

    /// <summary>
    /// If the Cowboy can be moved this turn via its owner.
    /// </summary>
    const bool& can_move;

    /// <summary>
    /// The direction this Cowboy is moving while drunk. Will be 'North', 'East', 'South', or 'West' when drunk; or '' (empty string) when not drunk.
    /// </summary>
    const std::string& drunk_direction;

    /// <summary>
    /// How much focus this Cowboy has. Different Jobs do different things with their Cowboy's focus.
    /// </summary>
    const int& focus;

    /// <summary>
    /// How much health this Cowboy currently has.
    /// </summary>
    const int& health;

    /// <summary>
    /// If this Cowboy is dead and has been removed from the game.
    /// </summary>
    const bool& is_dead;

    /// <summary>
    /// If this Cowboy is drunk, and will automatically walk.
    /// </summary>
    const bool& is_drunk;

    /// <summary>
    /// The job that this Cowboy does, and dictates how they fight and interact within the Saloon.
    /// </summary>
    const std::string& job;

    /// <summary>
    /// The Player that owns and can control this Cowboy.
    /// </summary>
    const Player& owner;

    /// <summary>
    /// The Tile that this Cowboy is located on.
    /// </summary>
    const Tile& tile;

    /// <summary>
    /// How many times this unit has been drunk before taking their siesta and resetting this to 0.
    /// </summary>
    const int& tolerance;

    /// <summary>
    /// How many turns this unit has remaining before it is no longer busy and can `act()` or `play()` again.
    /// </summary>
    const int& turns_busy;

    // <<-- Creer-Merge: member variables -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
    // You can add additional member variables here. None of them will be tracked or updated by the server.
    // <<-- /Creer-Merge: member variables -->>


    /// <summary>
    /// does their job's action on a _tile.
    /// </summary>
    /// <param name="tile"> The Tile you want this Cowboy to act on. </param>
    /// <param name="drunk_direction"> The direction the bottle will cause drunk cowboys to be in, can be 'North', 'East', 'South', or 'West'. </param>
    bool act(const Tile& tile, const std::string& drunk_direction = "");

    /// <summary>
    /// moves this _cowboy from its current _tile to an adjacent _tile.
    /// </summary>
    /// <param name="tile"> The Tile you want to move this Cowboy to. </param>
    bool move(const Tile& tile);

    /// <summary>
    /// sits down and plays a piano.
    /// </summary>
    /// <param name="piano"> The Furnishing that is a piano you want to play. </param>
    bool play(const Furnishing& piano);


   // <<-- Creer-Merge: methods -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
   // You can add additional methods here.
   // <<-- /Creer-Merge: methods -->>

   ~Cowboy_();

   // ####################
   // Don't edit these!
   // ####################
   /// \cond FALSE
   Cowboy_(std::initializer_list<std::pair<std::string, Any&&>> init);
   Cowboy_() : Cowboy_({}){}
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

} // saloon

} // cpp_client

#endif // GAMES_SALOON_COWBOY_H

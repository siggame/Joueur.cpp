#ifndef GAMES_PIRATES_PORT_H
#define GAMES_PIRATES_PORT_H

// Port
// A port on a Tile.

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
/// A port on a Tile.
/// </summary>
class Port_ : public Game_object_
{
public:

    /// <summary>
    /// For players, how much more gold this Port can spend this turn. For merchants, how much gold this Port has accumulated (it will spawn a ship when the Port can afford one).
    /// </summary>
    const int& gold;

    /// <summary>
    /// (Merchants only) How much gold was invested into this Port. Investment determines the strength and value of the next ship.
    /// </summary>
    const int& investment;

    /// <summary>
    /// The owner of this Port, or null if owned by merchants.
    /// </summary>
    const Player& owner;

    /// <summary>
    /// The Tile this Port is on.
    /// </summary>
    const Tile& tile;

    // <<-- Creer-Merge: member variables -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
    // You can add additional member variables here. None of them will be tracked or updated by the server.
    // <<-- /Creer-Merge: member variables -->>


    /// <summary>
    /// spawn a _unit on this port.
    /// </summary>
    /// <param name="type"> What type of Unit to create ('crew' or 'ship'). </param>
    bool spawn(const std::string& type);


   // <<-- Creer-Merge: methods -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
   // You can add additional methods here.
   // <<-- /Creer-Merge: methods -->>

   ~Port_();

   // ####################
   // Don't edit these!
   // ####################
   /// \cond FALSE
   Port_(std::initializer_list<std::pair<std::string, Any&&>> init);
   Port_() : Port_({}){}
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

#endif // GAMES_PIRATES_PORT_H

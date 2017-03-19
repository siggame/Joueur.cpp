#ifndef GAMES_SPIDERS_WEB_H
#define GAMES_SPIDERS_WEB_H

// Web
// A connection (edge) to a Nest (node) in the game that Spiders can converge on (regardless of owner). Spiders can travel in either direction on Webs.

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

#include "impl/spiders_fwd.hpp"

// <<-- Creer-Merge: includes -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
// you can add additional #includes here
// <<-- /Creer-Merge: includes -->>

namespace cpp_client
{

namespace spiders
{

/// <summary>
/// A connection (edge) to a Nest (node) in the game that Spiders can converge on (regardless of owner). Spiders can travel in either direction on Webs.
/// </summary>
class Web_ : public Game_object_
{
public:

    /// <summary>
    /// How long this Web is, i.e., the distance between its nestA and nestB.
    /// </summary>
    const double& length;

    /// <summary>
    /// How much weight this Web currently has on it, which is the sum of all its Spiderlings weight.
    /// </summary>
    const int& load;

    /// <summary>
    /// The first Nest this Web is connected to.
    /// </summary>
    const Nest& nest_a;

    /// <summary>
    /// The second Nest this Web is connected to.
    /// </summary>
    const Nest& nest_b;

    /// <summary>
    /// All the Spiderlings currently moving along this Web.
    /// </summary>
    const std::vector<Spiderling>& spiderlings;

    /// <summary>
    /// How much weight this Web can take before snapping and destroying itself and all the Spiders on it.
    /// </summary>
    const int& strength;

    // <<-- Creer-Merge: member variables -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
    // You can add additional member variables here. None of them will be tracked or updated by the server.
    // <<-- /Creer-Merge: member variables -->>



   // <<-- Creer-Merge: methods -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
   // You can add additional methods here.
   // <<-- /Creer-Merge: methods -->>

   ~Web_();

   // ####################
   // Don't edit these!
   // ####################
   /// \cond FALSE
   Web_(std::initializer_list<std::pair<std::string, Any&&>> init);
   Web_() : Web_({}){}
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

} // spiders

} // cpp_client

#endif // GAMES_SPIDERS_WEB_H

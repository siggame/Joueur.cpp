#ifndef GAMES_SPIDERS_CUTTER_H
#define GAMES_SPIDERS_CUTTER_H

// Cutter
// A Spiderling that can cut existing Webs.

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

#include "spiderling.hpp"

#include "impl/spiders_fwd.hpp"

// <<-- Creer-Merge: includes -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
// you can add additional #includes here
// <<-- /Creer-Merge: includes -->>

namespace cpp_client
{

namespace spiders
{

/// <summary>
/// A Spiderling that can cut existing Webs.
/// </summary>
class Cutter_ : public Spiderling_
{
public:

    /// <summary>
    /// The Web that this Cutter is trying to cut. Null if not cutting.
    /// </summary>
    const Web& cutting_web;

    // <<-- Creer-Merge: member variables -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
    // You can add additional member variables here. None of them will be tracked or updated by the server.
    // <<-- /Creer-Merge: member variables -->>


    /// <summary>
    /// cuts a web, destroying it, and any _spiderlings on it.
    /// </summary>
    /// <param name="web"> The web you want to Cut. Must be connected to the Nest this Cutter is currently on. </param>
    bool cut(const Web& web);


   // <<-- Creer-Merge: methods -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
   // You can add additional methods here.
   // <<-- /Creer-Merge: methods -->>

   ~Cutter_();

   // ####################
   // Don't edit these!
   // ####################
   /// \cond FALSE
   Cutter_(std::initializer_list<std::pair<std::string, Any&&>> init);
   Cutter_() : Cutter_({}){}
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

#endif // GAMES_SPIDERS_CUTTER_H

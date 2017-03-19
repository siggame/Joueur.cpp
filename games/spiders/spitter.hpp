#ifndef GAMES_SPIDERS_SPITTER_H
#define GAMES_SPIDERS_SPITTER_H

// Spitter
// A Spiderling that creates and spits new Webs from the Nest it is on to another Nest, connecting them.

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
/// A Spiderling that creates and spits new Webs from the Nest it is on to another Nest, connecting them.
/// </summary>
class Spitter_ : public Spiderling_
{
public:

    /// <summary>
    /// The Nest that this Spitter is creating a Web to spit at, thus connecting them. Null if not spitting.
    /// </summary>
    const Nest& spitting_web_to_nest;

    // <<-- Creer-Merge: member variables -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
    // You can add additional member variables here. None of them will be tracked or updated by the server.
    // <<-- /Creer-Merge: member variables -->>


    /// <summary>
    /// creates and spits a new _web from the _nest the _spitter is on to another _nest, connecting them.
    /// </summary>
    /// <param name="nest"> The Nest you want to spit a Web to, thus connecting that Nest and the one the Spitter is on. </param>
    bool spit(const Nest& nest);


   // <<-- Creer-Merge: methods -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
   // You can add additional methods here.
   // <<-- /Creer-Merge: methods -->>

   ~Spitter_();

   // ####################
   // Don't edit these!
   // ####################
   /// \cond FALSE
   Spitter_(std::initializer_list<std::pair<std::string, Any&&>> init);
   Spitter_() : Spitter_({}){}
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

#endif // GAMES_SPIDERS_SPITTER_H

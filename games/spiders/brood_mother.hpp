#ifndef GAMES_SPIDERS_BROOD_MOTHER_H
#define GAMES_SPIDERS_BROOD_MOTHER_H

// BroodMother
// The Spider Queen. She alone can spawn Spiderlings for each Player, and if she dies the owner loses.

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

#include "spider.hpp"

#include "impl/spiders_fwd.hpp"

// <<-- Creer-Merge: includes -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
// you can add additional #includes here
// <<-- /Creer-Merge: includes -->>

namespace cpp_client
{

namespace spiders
{

/// <summary>
/// The Spider Queen. She alone can spawn Spiderlings for each Player, and if she dies the owner loses.
/// </summary>
class Brood_mother_ : public Spider_
{
public:

    /// <summary>
    /// How many eggs the BroodMother has to spawn Spiderlings this turn.
    /// </summary>
    const int& eggs;

    /// <summary>
    /// How much health this BroodMother has left. When it reaches 0, she dies and her owner loses.
    /// </summary>
    const int& health;

    // <<-- Creer-Merge: member variables -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
    // You can add additional member variables here. None of them will be tracked or updated by the server.
    // <<-- /Creer-Merge: member variables -->>


    /// <summary>
    /// consumes a _spiderling of the same owner to regain some eggs to spawn more _spiderlings.
    /// </summary>
    /// <param name="spiderling"> The Spiderling to consume. It must be on the same Nest as this BroodMother. </param>
    bool consume(const Spiderling& spiderling);

    /// <summary>
    /// spawns a new _spiderling on the same _nest as this _brood_mother, consuming an egg.
    /// </summary>
    /// <param name="spiderling_type"> The string name of the Spiderling class you want to Spawn. Must be 'Spitter', 'Weaver', or 'Cutter'. </param>
    Spiderling spawn(const std::string& spiderling_type);


   // <<-- Creer-Merge: methods -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
   // You can add additional methods here.
   // <<-- /Creer-Merge: methods -->>

   ~Brood_mother_();

   // ####################
   // Don't edit these!
   // ####################
   /// \cond FALSE
   Brood_mother_(std::initializer_list<std::pair<std::string, Any&&>> init);
   Brood_mother_() : Brood_mother_({}){}
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

#endif // GAMES_SPIDERS_BROOD_MOTHER_H

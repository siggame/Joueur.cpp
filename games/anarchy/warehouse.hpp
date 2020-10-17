#ifndef GAMES_ANARCHY_WAREHOUSE_H
#define GAMES_ANARCHY_WAREHOUSE_H

// Warehouse
// A typical abandoned warehouse that anarchists hang out in and can be bribed to burn down Buildings.

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

#include "building.hpp"

#include "impl/anarchy_fwd.hpp"

// <<-- Creer-Merge: includes -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
// you can add additional #includes here
// <<-- /Creer-Merge: includes -->>

namespace cpp_client
{

namespace anarchy
{

/// <summary>
/// A typical abandoned warehouse that anarchists hang out in and can be bribed to burn down Buildings.
/// </summary>
class Warehouse_ : public Building_
{
public:

    /// <summary>
    /// How exposed the anarchists in this warehouse are to PoliceDepartments. Raises when bribed to ignite buildings, and drops each turn if not bribed.
    /// </summary>
    const int& exposure;

    /// <summary>
    /// The amount of fire added to buildings when bribed to ignite a building. Headquarters add more fire than normal Warehouses.
    /// </summary>
    const int& fire_added;

    // <<-- Creer-Merge: member variables -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
    // You can add additional member variables here. None of them will be tracked or updated by the server.
    // <<-- /Creer-Merge: member variables -->>


    /// <summary>
    /// bribes the _warehouse to light a _building on fire. _this adds this building's fire_added to their fire, and then this building's exposure is increased based on the _manhattan distance between the two buildings.
    /// </summary>
    /// <param name="building"> The Building you want to light on fire. </param>
    int ignite(const Building& building);


   // <<-- Creer-Merge: methods -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
   // You can add additional methods here.
   // <<-- /Creer-Merge: methods -->>

   ~Warehouse_();

   // ####################
   // Don't edit these!
   // ####################
   /// \cond FALSE
   Warehouse_(std::initializer_list<std::pair<std::string, Any&&>> init);
   Warehouse_() : Warehouse_({}){}
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

} // anarchy

} // cpp_client

#endif // GAMES_ANARCHY_WAREHOUSE_H

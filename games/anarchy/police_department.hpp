#ifndef GAMES_ANARCHY_POLICE_DEPARTMENT_H
#define GAMES_ANARCHY_POLICE_DEPARTMENT_H

// PoliceDepartment
// Used to keep cities under control and raid Warehouses.

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
/// Used to keep cities under control and raid Warehouses.
/// </summary>
class Police_department_ : public Building_
{
public:

    // <<-- Creer-Merge: member variables -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
    // You can add additional member variables here. None of them will be tracked or updated by the server.
    // <<-- /Creer-Merge: member variables -->>


    /// <summary>
    /// bribe the police to raid a _warehouse, dealing damage equal based on the _warehouse's current exposure, and then resetting it to 0.
    /// </summary>
    /// <param name="warehouse"> The warehouse you want to raid. </param>
    int raid(const Warehouse& warehouse);


   // <<-- Creer-Merge: methods -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
   // You can add additional methods here.
   // <<-- /Creer-Merge: methods -->>

   ~Police_department_();

   // ####################
   // Don't edit these!
   // ####################
   /// \cond FALSE
   Police_department_(std::initializer_list<std::pair<std::string, Any&&>> init);
   Police_department_() : Police_department_({}){}
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

#endif // GAMES_ANARCHY_POLICE_DEPARTMENT_H

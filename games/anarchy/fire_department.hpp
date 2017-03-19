#ifndef GAMES_ANARCHY_FIRE_DEPARTMENT_H
#define GAMES_ANARCHY_FIRE_DEPARTMENT_H

// FireDepartment
// Can put out fires completely.

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
/// Can put out fires completely.
/// </summary>
class Fire_department_ : public Building_
{
public:

    /// <summary>
    /// The amount of fire removed from a building when bribed to extinguish a building.
    /// </summary>
    const int& fire_extinguished;

    // <<-- Creer-Merge: member variables -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
    // You can add additional member variables here. None of them will be tracked or updated by the server.
    // <<-- /Creer-Merge: member variables -->>


    /// <summary>
    /// bribes this _fire_department to extinguish the some of the fire in a building.
    /// </summary>
    /// <param name="building"> The Building you want to extinguish. </param>
    bool extinguish(const Building& building);


   // <<-- Creer-Merge: methods -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
   // You can add additional methods here.
   // <<-- /Creer-Merge: methods -->>

   ~Fire_department_();

   // ####################
   // Don't edit these!
   // ####################
   /// \cond FALSE
   Fire_department_(std::initializer_list<std::pair<std::string, Any&&>> init);
   Fire_department_() : Fire_department_({}){}
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

#endif // GAMES_ANARCHY_FIRE_DEPARTMENT_H

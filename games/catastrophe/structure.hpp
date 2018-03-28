#ifndef GAMES_CATASTROPHE_STRUCTURE_H
#define GAMES_CATASTROPHE_STRUCTURE_H

// Structure
// A structure on a Tile.

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

#include "impl/catastrophe_fwd.hpp"

// <<-- Creer-Merge: includes -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
// you can add additional #includes here
// <<-- /Creer-Merge: includes -->>

namespace cpp_client
{

namespace catastrophe
{

/// <summary>
/// A structure on a Tile.
/// </summary>
class Structure_ : public Game_object_
{
public:

    /// <summary>
    /// The range of this Structure's effect. For example, a radius of 1 means this Structure affects a 3x3 square centered on this Structure.
    /// </summary>
    const int& effect_radius;

    /// <summary>
    /// The number of materials in this Structure. Once this number reaches 0, this Structure is destroyed.
    /// </summary>
    const int& materials;

    /// <summary>
    /// The owner of this Structure if any, otherwise null.
    /// </summary>
    const Player& owner;

    /// <summary>
    /// The Tile this Structure is on.
    /// </summary>
    const Tile& tile;

    /// <summary>
    /// The type of Structure this is ('shelter', 'monument', 'wall', 'road', 'neutral').
    /// </summary>
    const std::string& type;

    // <<-- Creer-Merge: member variables -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
    // You can add additional member variables here. None of them will be tracked or updated by the server.
    // <<-- /Creer-Merge: member variables -->>



   // <<-- Creer-Merge: methods -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
   // You can add additional methods here.
   // <<-- /Creer-Merge: methods -->>

   ~Structure_();

   // ####################
   // Don't edit these!
   // ####################
   /// \cond FALSE
   Structure_(std::initializer_list<std::pair<std::string, Any&&>> init);
   Structure_() : Structure_({}){}
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

} // catastrophe

} // cpp_client

#endif // GAMES_CATASTROPHE_STRUCTURE_H

#ifndef GAMES_CHECKERS_CHECKER_H
#define GAMES_CHECKERS_CHECKER_H

// Checker
// A checker on the game board.

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

#include "impl/checkers_fwd.hpp"

// <<-- Creer-Merge: includes -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
// you can add additional #includes here
// <<-- /Creer-Merge: includes -->>

namespace cpp_client
{

namespace checkers
{

/// <summary>
/// A checker on the game board.
/// </summary>
class Checker_ : public Game_object_
{
public:

    /// <summary>
    /// If the checker has been kinged and can move backwards.
    /// </summary>
    const bool& kinged;

    /// <summary>
    /// The player that controls this Checker.
    /// </summary>
    const Player& owner;

    /// <summary>
    /// The x coordinate of the checker.
    /// </summary>
    const int& x;

    /// <summary>
    /// The y coordinate of the checker.
    /// </summary>
    const int& y;

    // <<-- Creer-Merge: member variables -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
    // You can add additional member variables here. None of them will be tracked or updated by the server.
    // <<-- /Creer-Merge: member variables -->>


    /// <summary>
    /// returns if the checker is owned by your player or not.
    /// </summary>
    bool is_mine();

    /// <summary>
    /// moves the checker from its current location to the given (x, y).
    /// </summary>
    /// <param name="x"> The x coordinate to move to. </param>
    /// <param name="y"> The y coordinate to move to. </param>
    Checker move(int x, int y);


   // <<-- Creer-Merge: methods -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
   // You can add additional methods here.
   // <<-- /Creer-Merge: methods -->>

   ~Checker_();

   // ####################
   // Don't edit these!
   // ####################
   /// \cond FALSE
   Checker_(std::initializer_list<std::pair<std::string, Any&&>> init);
   Checker_() : Checker_({}){}
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

} // checkers

} // cpp_client

#endif // GAMES_CHECKERS_CHECKER_H

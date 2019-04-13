#ifndef GAMES_STARDASH_BODY_H
#define GAMES_STARDASH_BODY_H

// Body
// A celestial body located within the game.

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

#include "impl/stardash_fwd.hpp"

// <<-- Creer-Merge: includes -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
// you can add additional #includes here
// <<-- /Creer-Merge: includes -->>

namespace cpp_client
{

namespace stardash
{

/// <summary>
/// A celestial body located within the game.
/// </summary>
class Body_ : public Game_object_
{
public:

    /// <summary>
    /// The amount of material the object has, or energy if it is a planet.
    /// </summary>
    const int& amount;

    /// <summary>
    /// The type of celestial body it is. Either 'planet', 'asteroid', or 'sun'.
    /// </summary>
    const std::string& body_type;

    /// <summary>
    /// The type of material the celestial body has. Either 'none', 'genarium', 'rarium', 'legendarium', or 'mythicite'.
    /// </summary>
    const std::string& material_type;

    /// <summary>
    /// The Player that owns and can control this Body.
    /// </summary>
    const Player& owner;

    /// <summary>
    /// The radius of the circle that this body takes up.
    /// </summary>
    const double& radius;

    /// <summary>
    /// The x value this celestial body is on.
    /// </summary>
    const double& x;

    /// <summary>
    /// The y value this celestial body is on.
    /// </summary>
    const double& y;

    // <<-- Creer-Merge: member variables -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
    // You can add additional member variables here. None of them will be tracked or updated by the server.
    // <<-- /Creer-Merge: member variables -->>


    /// <summary>
    /// the x value of this body a number of turns from now. (0-how many you want).
    /// </summary>
    /// <param name="num"> The number of turns in the future you wish to check. </param>
    int next_x(int num);

    /// <summary>
    /// the x value of this body a number of turns from now. (0-how many you want).
    /// </summary>
    /// <param name="num"> The number of turns in the future you wish to check. </param>
    int next_y(int num);

    /// <summary>
    /// spawn a unit on some value of this celestial body.
    /// </summary>
    /// <param name="x"> The x value of the spawned unit. </param>
    /// <param name="y"> The y value of the spawned unit. </param>
    /// <param name="title"> The job title of the unit being spawned. </param>
    bool spawn(const double& x, const double& y, const std::string& title);


   // <<-- Creer-Merge: methods -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
   // You can add additional methods here.
   // <<-- /Creer-Merge: methods -->>

   ~Body_();

   // ####################
   // Don't edit these!
   // ####################
   /// \cond FALSE
   Body_(std::initializer_list<std::pair<std::string, Any&&>> init);
   Body_() : Body_({}){}
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

} // stardash

} // cpp_client

#endif // GAMES_STARDASH_BODY_H

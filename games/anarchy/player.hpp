#ifndef GAMES_ANARCHY_PLAYER_H
#define GAMES_ANARCHY_PLAYER_H

// Player
// A player in this game. Every AI controls one player.

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

#include "impl/anarchy_fwd.hpp"

// <<-- Creer-Merge: includes -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
// you can add additional #includes here
// <<-- /Creer-Merge: includes -->>

namespace cpp_client
{

namespace anarchy
{

/// <summary>
/// A player in this game. Every AI controls one player.
/// </summary>
class Player_ : public Game_object_
{
public:

    /// <summary>
    /// How many bribes this player has remaining to use during their turn. Each action a Building does costs 1 bribe. Any unused bribes are lost at the end of the player's turn.
    /// </summary>
    const int& bribes_remaining;

    /// <summary>
    /// All the buildings owned by this player.
    /// </summary>
    const std::vector<Building>& buildings;

    /// <summary>
    /// What type of client this is, e.g. 'Python', 'JavaScript', or some other language. For potential data mining purposes.
    /// </summary>
    const std::string& client_type;

    /// <summary>
    /// All the FireDepartments owned by this player.
    /// </summary>
    const std::vector<Fire_department>& fire_departments;

    /// <summary>
    /// The Warehouse that serves as this player's headquarters and has extra health. If this gets destroyed they lose.
    /// </summary>
    const Warehouse& headquarters;

    /// <summary>
    /// If the player lost the game or not.
    /// </summary>
    const bool& lost;

    /// <summary>
    /// The name of the player.
    /// </summary>
    const std::string& name;

    /// <summary>
    /// This player's opponent in the game.
    /// </summary>
    const Player& opponent;

    /// <summary>
    /// All the PoliceDepartments owned by this player.
    /// </summary>
    const std::vector<Police_department>& police_departments;

    /// <summary>
    /// The reason why the player lost the game.
    /// </summary>
    const std::string& reason_lost;

    /// <summary>
    /// The reason why the player won the game.
    /// </summary>
    const std::string& reason_won;

    /// <summary>
    /// The amount of time (in ns) remaining for this AI to send commands.
    /// </summary>
    const double& time_remaining;

    /// <summary>
    /// All the warehouses owned by this player. Includes the Headquarters.
    /// </summary>
    const std::vector<Warehouse>& warehouses;

    /// <summary>
    /// All the WeatherStations owned by this player.
    /// </summary>
    const std::vector<Weather_station>& weather_stations;

    /// <summary>
    /// If the player won the game or not.
    /// </summary>
    const bool& won;

    // <<-- Creer-Merge: member variables -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
    // You can add additional member variables here. None of them will be tracked or updated by the server.
    // <<-- /Creer-Merge: member variables -->>



   // <<-- Creer-Merge: methods -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
   // You can add additional methods here.
   // <<-- /Creer-Merge: methods -->>

   ~Player_();

   // ####################
   // Don't edit these!
   // ####################
   /// \cond FALSE
   Player_(std::initializer_list<std::pair<std::string, Any&&>> init);
   Player_() : Player_({}){}
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

#endif // GAMES_ANARCHY_PLAYER_H

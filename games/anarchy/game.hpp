#ifndef GAMES_ANARCHY_GAME_H
#define GAMES_ANARCHY_GAME_H

// Game
// Two player grid based game where each player tries to burn down the other player's buildings. Let it burn.

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


#include "../../joueur/src/base_game.hpp"
#include "impl/anarchy_fwd.hpp"

// <<-- Creer-Merge: includes -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
// you can add additional #includes here
// <<-- /Creer-Merge: includes -->>

namespace cpp_client
{

/// <summary>
/// Two player grid based game where each player tries to burn down the other player's buildings. Let it burn.
/// </summary>
namespace anarchy
{

/// <summary>
/// Two player grid based game where each player tries to burn down the other player's buildings. Let it burn.
/// </summary>
class Game_ : public Base_game
{
public:

    /// <summary>
    /// How many bribes players get at the beginning of their turn, not counting their burned down Buildings.
    /// </summary>
    const int& base_bribes_per_turn;

    /// <summary>
    /// All the buildings in the game.
    /// </summary>
    const std::vector<Building>& buildings;

    /// <summary>
    /// The current Forecast, which will be applied at the end of the turn.
    /// </summary>
    const Forecast& current_forecast;

    /// <summary>
    /// The player whose turn it is currently. That player can send commands. Other players cannot.
    /// </summary>
    const Player& current_player;

    /// <summary>
    /// The current turn number, starting at 0 for the first player's turn.
    /// </summary>
    const int& current_turn;

    /// <summary>
    /// All the forecasts in the game, indexed by turn number.
    /// </summary>
    const std::vector<Forecast>& forecasts;

    /// <summary>
    /// A mapping of every game object's ID to the actual game object. Primarily used by the server and client to easily refer to the game objects via ID.
    /// </summary>
    const std::unordered_map<std::string, Game_object>& game_objects;

    /// <summary>
    /// The width of the entire map along the vertical (y) axis.
    /// </summary>
    const int& map_height;

    /// <summary>
    /// The width of the entire map along the horizontal (x) axis.
    /// </summary>
    const int& map_width;

    /// <summary>
    /// The maximum amount of fire value for any Building.
    /// </summary>
    const int& max_fire;

    /// <summary>
    /// The maximum amount of intensity value for any Forecast.
    /// </summary>
    const int& max_forecast_intensity;

    /// <summary>
    /// The maximum number of turns before the game will automatically end.
    /// </summary>
    const int& max_turns;

    /// <summary>
    /// The next Forecast, which will be applied at the end of your opponent's turn. This is also the Forecast WeatherStations can control this turn.
    /// </summary>
    const Forecast& next_forecast;

    /// <summary>
    /// List of all the players in the game.
    /// </summary>
    const std::vector<Player>& players;

    /// <summary>
    /// A unique identifier for the game instance that is being played.
    /// </summary>
    const std::string& session;

    /// <summary>
    /// The amount of time (in nano-seconds) added after each player performs a turn.
    /// </summary>
    const int& time_added_per_turn;

    // <<-- Creer-Merge: member variables -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
    // You can add additional member variables here. None of them will be tracked or updated by the server.
    // <<-- /Creer-Merge: member variables -->>



   // <<-- Creer-Merge: methods -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
   // You can add additional methods here.
   // <<-- /Creer-Merge: methods -->>

   ~Game_();

   // ####################
   // Don't edit these!
   // ####################
   /// \cond FALSE
   Game_(std::initializer_list<std::pair<std::string, Any&&>> init);
   Game_() : Game_({}){}
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

#endif // GAMES_ANARCHY_GAME_H

#ifndef GAMES_ANARCHY_FORECAST_H
#define GAMES_ANARCHY_FORECAST_H

// Forecast
// The weather effect that will be applied at the end of a turn, which causes fires to spread.

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
/// The weather effect that will be applied at the end of a turn, which causes fires to spread.
/// </summary>
class Forecast_ : public Game_object_
{
public:

    /// <summary>
    /// The Player that can use WeatherStations to control this Forecast when its the nextForecast.
    /// </summary>
    const Player& controlling_player;

    /// <summary>
    /// The direction the wind will blow fires in. Can be 'north', 'east', 'south', or 'west'.
    /// </summary>
    const std::string& direction;

    /// <summary>
    /// How much of a Building's fire that can be blown in the direction of this Forecast. Fire is duplicated (copied), not moved (transferred).
    /// </summary>
    const int& intensity;

    // <<-- Creer-Merge: member variables -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
    // You can add additional member variables here. None of them will be tracked or updated by the server.
    // <<-- /Creer-Merge: member variables -->>



   // <<-- Creer-Merge: methods -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
   // You can add additional methods here.
   // <<-- /Creer-Merge: methods -->>

   ~Forecast_();

   // ####################
   // Don't edit these!
   // ####################
   /// \cond FALSE
   Forecast_(std::initializer_list<std::pair<std::string, Any&&>> init);
   Forecast_() : Forecast_({}){}
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

#endif // GAMES_ANARCHY_FORECAST_H

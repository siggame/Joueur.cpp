#ifndef GAMES_ANARCHY_WEATHER_STATION_H
#define GAMES_ANARCHY_WEATHER_STATION_H

// WeatherStation
// Can be bribed to change the next Forecast in some way.

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
/// Can be bribed to change the next Forecast in some way.
/// </summary>
class Weather_station_ : public Building_
{
public:

    // <<-- Creer-Merge: member variables -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
    // You can add additional member variables here. None of them will be tracked or updated by the server.
    // <<-- /Creer-Merge: member variables -->>


    /// <summary>
    /// bribe the weathermen to intensity the next _forecast by 1 or -1.
    /// </summary>
    /// <param name="negative"> By default the intensity will be increased by 1, setting this to true decreases the intensity by 1. </param>
    bool intensify(bool negative = false);

    /// <summary>
    /// bribe the weathermen to change the direction of the next _forecast by rotating it clockwise or counterclockwise.
    /// </summary>
    /// <param name="counterclockwise"> By default the direction will be rotated clockwise. If you set this to true we will rotate the forecast counterclockwise instead. </param>
    bool rotate(bool counterclockwise = false);


   // <<-- Creer-Merge: methods -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
   // You can add additional methods here.
   // <<-- /Creer-Merge: methods -->>

   ~Weather_station_();

   // ####################
   // Don't edit these!
   // ####################
   /// \cond FALSE
   Weather_station_(std::initializer_list<std::pair<std::string, Any&&>> init);
   Weather_station_() : Weather_station_({}){}
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

#endif // GAMES_ANARCHY_WEATHER_STATION_H

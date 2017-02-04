// Can be bribed to change the next Forecast in some way.

// DO NOT MODIFY THIS FILE
// Never try to directly create an instance of this class, or modify its member variables.
// Instead, you should only be reading its variables and calling its functions.

#ifndef JOUEUR_ANARCHY_WEATHERSTATION_H
#define JOUEUR_ANARCHY_WEATHERSTATION_H

#include "anarchy.h"
#include "building.h"

// <<-- Creer-Merge: includes -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
// you can add additional #includes(s) here.
// <<-- /Creer-Merge: includes -->>

/// <summary>
/// Can be bribed to change the next Forecast in some way.
/// </summary>
class Anarchy::WeatherStation : public Anarchy::Building
{
    friend Anarchy::GameManager;

    protected:
        virtual void deltaUpdateField(const std::string& fieldName, boost::property_tree::ptree& delta);
        WeatherStation() {};
        ~WeatherStation() {};

    public:

        // <<-- Creer-Merge: fields -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
        // you can add additional fields(s) here. None of them will be tracked or updated by the server.
        // <<-- /Creer-Merge: fields -->>

        /// <summary>
        /// Bribe the weathermen to intensity the next Forecast by 1 or -1
        /// </summary>
        /// <param name="negative">By default the intensity will be increased by 1, setting this to true decreases the intensity by 1.</param>
        /// <returns>True if the intensity was changed, false otherwise.</returns>
        bool intensify(bool negative = false);

        /// <summary>
        /// Bribe the weathermen to change the direction of the next Forecast by rotating it clockwise or counterclockwise.
        /// </summary>
        /// <param name="counterclockwise">By default the direction will be rotated clockwise. If you set this to true we will rotate the forecast counterclockwise instead.</param>
        /// <returns>True if the rotation worked, false otherwise.</returns>
        bool rotate(bool counterclockwise = false);


        // <<-- Creer-Merge: methods -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
        // you can add additional method(s) here.
        // <<-- /Creer-Merge: methods -->>
};

#endif

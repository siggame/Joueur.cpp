// DO NOT MODIFY THIS FILE
// Never try to directly create an instance of this class, or modify its member variables.
// This contains implementation details, written by code, and only useful to code

#include "anarchy.hpp"
#include "../../../joueur/src/register.hpp"

#include "../../../joueur/src/exceptions.hpp"

namespace cpp_client
{

namespace anarchy
{

//register the game
Game_registry registration("Anarchy",
                           "2bc66f9a5d7babd553079e149c7466feb6f553935b608ff722872e195fbadab8",
                           std::unique_ptr<Anarchy>(new Anarchy));

std::unique_ptr<Base_ai> Anarchy::generate_ai()
{
    return std::unique_ptr<Base_ai>(new AI);
}

std::shared_ptr<Base_object> Anarchy::generate_object(const std::string& type)
{
    if(type == "Building")
    {
        return std::make_shared<Building_>();
    }
    else if(type == "FireDepartment")
    {
        return std::make_shared<Fire_department_>();
    }
    else if(type == "Forecast")
    {
        return std::make_shared<Forecast_>();
    }
    else if(type == "GameObject")
    {
        return std::make_shared<Game_object_>();
    }
    else if(type == "Player")
    {
        return std::make_shared<Player_>();
    }
    else if(type == "PoliceDepartment")
    {
        return std::make_shared<Police_department_>();
    }
    else if(type == "Warehouse")
    {
        return std::make_shared<Warehouse_>();
    }
    else if(type == "WeatherStation")
    {
        return std::make_shared<Weather_station_>();
    }
    throw Unknown_type("Unknown type " + type + " encountered.");
}

} // anarchy

} // cpp_client

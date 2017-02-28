// DO NOT MODIFY THIS FILE
// Never try to directly create an instance of this class, or modify its member variables.
// This contains implementation details, written by code, and only useful to code

#include "stumped.hpp"
#include "../../../joueur/src/register.hpp"

#include "../../../joueur/src/exceptions.hpp"

namespace cpp_client
{

namespace stumped
{

//register the game
Game_registry registration("Stumped",
                           std::unique_ptr<Stumped>(new Stumped));

std::unique_ptr<Base_ai> Stumped::generate_ai()
{
    return std::unique_ptr<Base_ai>(new AI);
}

std::shared_ptr<Base_object> Stumped::generate_object(const std::string& type)
{
    if(type == "Beaver")
    {
        return std::make_shared<Beaver_>();
    }
    else if(type == "GameObject")
    {
        return std::make_shared<Game_object_>();
    }
    else if(type == "Job")
    {
        return std::make_shared<Job_>();
    }
    else if(type == "Player")
    {
        return std::make_shared<Player_>();
    }
    else if(type == "Spawner")
    {
        return std::make_shared<Spawner_>();
    }
    else if(type == "Tile")
    {
        return std::make_shared<Tile_>();
    }
    throw Unknown_type("Unknown type " + type + " encountered.");
}

} // stumped

} // cpp_client

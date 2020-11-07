// DO NOT MODIFY THIS FILE
// Never try to directly create an instance of this class, or modify its member variables.
// This contains implementation details, written by code, and only useful to code

#include "necrowar.hpp"
#include "../../../joueur/src/register.hpp"

#include "../../../joueur/src/exceptions.hpp"

namespace cpp_client
{

namespace necrowar
{

//register the game
Game_registry registration("Necrowar",
                           "935f0e64ba290cdce31688a40bd90d1eb5375f36aeebd67482238fc0da25ef86",
                           std::unique_ptr<Necrowar>(new Necrowar));

std::unique_ptr<Base_ai> Necrowar::generate_ai()
{
    return std::unique_ptr<Base_ai>(new AI);
}

std::shared_ptr<Base_object> Necrowar::generate_object(const std::string& type)
{
    if(type == "GameObject")
    {
        return std::make_shared<Game_object_>();
    }
    else if(type == "Player")
    {
        return std::make_shared<Player_>();
    }
    else if(type == "Tile")
    {
        return std::make_shared<Tile_>();
    }
    else if(type == "Tower")
    {
        return std::make_shared<Tower_>();
    }
    else if(type == "TowerJob")
    {
        return std::make_shared<Tower_job_>();
    }
    else if(type == "Unit")
    {
        return std::make_shared<Unit_>();
    }
    else if(type == "UnitJob")
    {
        return std::make_shared<Unit_job_>();
    }
    throw Unknown_type("Unknown type " + type + " encountered.");
}

} // necrowar

} // cpp_client

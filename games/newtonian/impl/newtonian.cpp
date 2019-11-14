// DO NOT MODIFY THIS FILE
// Never try to directly create an instance of this class, or modify its member variables.
// This contains implementation details, written by code, and only useful to code

#include "newtonian.hpp"
#include "../../../joueur/src/register.hpp"

#include "../../../joueur/src/exceptions.hpp"

namespace cpp_client
{

namespace newtonian
{

//register the game
Game_registry registration("Newtonian",
                           "7c19f909ee5faa0ac3faf4e989032b5a37ba94aeb5d6ae7654a15a2bb1401bbe",
                           std::unique_ptr<Newtonian>(new Newtonian));

std::unique_ptr<Base_ai> Newtonian::generate_ai()
{
    return std::unique_ptr<Base_ai>(new AI);
}

std::shared_ptr<Base_object> Newtonian::generate_object(const std::string& type)
{
    if(type == "GameObject")
    {
        return std::make_shared<Game_object_>();
    }
    else if(type == "Job")
    {
        return std::make_shared<Job_>();
    }
    else if(type == "Machine")
    {
        return std::make_shared<Machine_>();
    }
    else if(type == "Player")
    {
        return std::make_shared<Player_>();
    }
    else if(type == "Tile")
    {
        return std::make_shared<Tile_>();
    }
    else if(type == "Unit")
    {
        return std::make_shared<Unit_>();
    }
    throw Unknown_type("Unknown type " + type + " encountered.");
}

} // newtonian

} // cpp_client

// DO NOT MODIFY THIS FILE
// Never try to directly create an instance of this class, or modify its member variables.
// This contains implementation details, written by code, and only useful to code

#include "catastrophe.hpp"
#include "../../../joueur/src/register.hpp"

#include "../../../joueur/src/exceptions.hpp"

namespace cpp_client
{

namespace catastrophe
{

//register the game
Game_registry registration("Catastrophe",
                           "ede84ab86376b00287c09558f05e8f2a61b92109d93aad9ebd3379ff4215fb53",
                           std::unique_ptr<Catastrophe>(new Catastrophe));

std::unique_ptr<Base_ai> Catastrophe::generate_ai()
{
    return std::unique_ptr<Base_ai>(new AI);
}

std::shared_ptr<Base_object> Catastrophe::generate_object(const std::string& type)
{
    if(type == "GameObject")
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
    else if(type == "Structure")
    {
        return std::make_shared<Structure_>();
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

} // catastrophe

} // cpp_client

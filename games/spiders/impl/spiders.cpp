// DO NOT MODIFY THIS FILE
// Never try to directly create an instance of this class, or modify its member variables.
// This contains implementation details, written by code, and only useful to code

#include "spiders.hpp"
#include "../../../joueur/src/register.hpp"

#include "../../../joueur/src/exceptions.hpp"

namespace cpp_client
{

namespace spiders
{

//register the game
Game_registry registration("Spiders",
                           "a8df6038306b6855bb35959d7698f8dcbf98f48e7e148de59fef940ccb241bdf",
                           std::unique_ptr<Spiders>(new Spiders));

std::unique_ptr<Base_ai> Spiders::generate_ai()
{
    return std::unique_ptr<Base_ai>(new AI);
}

std::shared_ptr<Base_object> Spiders::generate_object(const std::string& type)
{
    if(type == "BroodMother")
    {
        return std::make_shared<Brood_mother_>();
    }
    else if(type == "Cutter")
    {
        return std::make_shared<Cutter_>();
    }
    else if(type == "GameObject")
    {
        return std::make_shared<Game_object_>();
    }
    else if(type == "Nest")
    {
        return std::make_shared<Nest_>();
    }
    else if(type == "Player")
    {
        return std::make_shared<Player_>();
    }
    else if(type == "Spider")
    {
        return std::make_shared<Spider_>();
    }
    else if(type == "Spiderling")
    {
        return std::make_shared<Spiderling_>();
    }
    else if(type == "Spitter")
    {
        return std::make_shared<Spitter_>();
    }
    else if(type == "Weaver")
    {
        return std::make_shared<Weaver_>();
    }
    else if(type == "Web")
    {
        return std::make_shared<Web_>();
    }
    throw Unknown_type("Unknown type " + type + " encountered.");
}

} // spiders

} // cpp_client

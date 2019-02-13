// DO NOT MODIFY THIS FILE
// Never try to directly create an instance of this class, or modify its member variables.
// This contains implementation details, written by code, and only useful to code

#include "star_dash.hpp"
#include "../../../joueur/src/register.hpp"

#include "../../../joueur/src/exceptions.hpp"

namespace cpp_client
{

namespace star_dash
{

//register the game
Game_registry registration("Star_dash",
                           std::unique_ptr<Star_dash>(new Star_dash));

std::unique_ptr<Base_ai> Star_dash::generate_ai()
{
    return std::unique_ptr<Base_ai>(new AI);
}

std::shared_ptr<Base_object> Star_dash::generate_object(const std::string& type)
{
    if(type == "Body")
    {
        return std::make_shared<Body_>();
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
    else if(type == "Unit")
    {
        return std::make_shared<Unit_>();
    }
    throw Unknown_type("Unknown type " + type + " encountered.");
}

} // star_dash

} // cpp_client

// DO NOT MODIFY THIS FILE
// Never try to directly create an instance of this class, or modify its member variables.
// This contains implementation details, written by code, and only useful to code

#include "jungle.hpp"
#include "../../../joueur/src/register.hpp"

#include "../../../joueur/src/exceptions.hpp"

namespace cpp_client
{

namespace jungle
{

//register the game
Game_registry registration("Jungle",
                           "f6cf5e4564b454201f45038752c7cbd6e7a6c2823a39b1b325c450262f871c79",
                           std::unique_ptr<Jungle>(new Jungle));

std::unique_ptr<Base_ai> Jungle::generate_ai()
{
    return std::unique_ptr<Base_ai>(new AI);
}

std::shared_ptr<Base_object> Jungle::generate_object(const std::string& type)
{
    if(type == "GameObject")
    {
        return std::make_shared<Game_object_>();
    }
    else if(type == "Player")
    {
        return std::make_shared<Player_>();
    }
    throw Unknown_type("Unknown type " + type + " encountered.");
}

} // jungle

} // cpp_client

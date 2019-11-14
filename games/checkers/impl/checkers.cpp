// DO NOT MODIFY THIS FILE
// Never try to directly create an instance of this class, or modify its member variables.
// This contains implementation details, written by code, and only useful to code

#include "checkers.hpp"
#include "../../../joueur/src/register.hpp"

#include "../../../joueur/src/exceptions.hpp"

namespace cpp_client
{

namespace checkers
{

//register the game
Game_registry registration("Checkers",
                           "49f1e5586cc4c62b6f74081e803d8edf9f54e8315f221c62c638f963cea8ab31",
                           std::unique_ptr<Checkers>(new Checkers));

std::unique_ptr<Base_ai> Checkers::generate_ai()
{
    return std::unique_ptr<Base_ai>(new AI);
}

std::shared_ptr<Base_object> Checkers::generate_object(const std::string& type)
{
    if(type == "Checker")
    {
        return std::make_shared<Checker_>();
    }
    else if(type == "GameObject")
    {
        return std::make_shared<Game_object_>();
    }
    else if(type == "Player")
    {
        return std::make_shared<Player_>();
    }
    throw Unknown_type("Unknown type " + type + " encountered.");
}

} // checkers

} // cpp_client

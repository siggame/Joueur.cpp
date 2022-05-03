// DO NOT MODIFY THIS FILE
// Never try to directly create an instance of this class, or modify its member variables.
// This contains implementation details, written by code, and only useful to code

#include "jungle_chess.hpp"
#include "../../../joueur/src/register.hpp"

#include "../../../joueur/src/exceptions.hpp"

namespace cpp_client
{

namespace jungle_chess
{

//register the game
Game_registry registration("Jungle_chess",
                           "0f0b85b33f03a669a391b36c90daa195d028dd1f21f8d4b601adfcf39b23eee2",
                           std::unique_ptr<Jungle_chess>(new Jungle_chess));

std::unique_ptr<Base_ai> Jungle_chess::generate_ai()
{
    return std::unique_ptr<Base_ai>(new AI);
}

std::shared_ptr<Base_object> Jungle_chess::generate_object(const std::string& type)
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

} // jungle_chess

} // cpp_client

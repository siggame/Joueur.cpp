// DO NOT MODIFY THIS FILE
// Never try to directly create an instance of this class, or modify its member variables.
// This contains implementation details, written by code, and only useful to code

#include "saloon.hpp"
#include "../../../joueur/src/register.hpp"

#include "../../../joueur/src/exceptions.hpp"

namespace cpp_client
{

namespace saloon
{

//register the game
Game_registry registration("Saloon",
                           "fbaeac2bae9020bdd5a8816cb9ae38215c277e4bf7874a2f70c3995cd8eee8d3",
                           std::unique_ptr<Saloon>(new Saloon));

std::unique_ptr<Base_ai> Saloon::generate_ai()
{
    return std::unique_ptr<Base_ai>(new AI);
}

std::shared_ptr<Base_object> Saloon::generate_object(const std::string& type)
{
    if(type == "Bottle")
    {
        return std::make_shared<Bottle_>();
    }
    else if(type == "Cowboy")
    {
        return std::make_shared<Cowboy_>();
    }
    else if(type == "Furnishing")
    {
        return std::make_shared<Furnishing_>();
    }
    else if(type == "GameObject")
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
    else if(type == "YoungGun")
    {
        return std::make_shared<Young_gun_>();
    }
    throw Unknown_type("Unknown type " + type + " encountered.");
}

} // saloon

} // cpp_client

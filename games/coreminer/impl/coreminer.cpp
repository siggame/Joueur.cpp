// DO NOT MODIFY THIS FILE
// Never try to directly create an instance of this class, or modify its member variables.
// This contains implementation details, written by code, and only useful to code

#include "coreminer.hpp"
#include "../../../joueur/src/register.hpp"

#include "../../../joueur/src/exceptions.hpp"

namespace cpp_client
{

namespace coreminer
{

//register the game
Game_registry registration("Coreminer",
                           "3418447660e65ea28b97e2a74d8d95ebd694f36bbb0b6f4bd8d43fc97a3ecd9e",
                           std::unique_ptr<Coreminer>(new Coreminer));

std::unique_ptr<Base_ai> Coreminer::generate_ai()
{
    return std::unique_ptr<Base_ai>(new AI);
}

std::shared_ptr<Base_object> Coreminer::generate_object(const std::string& type)
{
    if(type == "Bomb")
    {
        return std::make_shared<Bomb_>();
    }
    else if(type == "GameObject")
    {
        return std::make_shared<Game_object_>();
    }
    else if(type == "Miner")
    {
        return std::make_shared<Miner_>();
    }
    else if(type == "Player")
    {
        return std::make_shared<Player_>();
    }
    else if(type == "Tile")
    {
        return std::make_shared<Tile_>();
    }
    else if(type == "Upgrade")
    {
        return std::make_shared<Upgrade_>();
    }
    throw Unknown_type("Unknown type " + type + " encountered.");
}

} // coreminer

} // cpp_client

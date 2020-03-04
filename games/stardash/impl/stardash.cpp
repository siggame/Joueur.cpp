// DO NOT MODIFY THIS FILE
// Never try to directly create an instance of this class, or modify its member variables.
// This contains implementation details, written by code, and only useful to code

#include "stardash.hpp"
#include "../../../joueur/src/register.hpp"

#include "../../../joueur/src/exceptions.hpp"

namespace cpp_client
{

namespace stardash
{

//register the game
Game_registry registration("Stardash",
                           "0fa378e83ac567ebdf3e9805d3f130023f936e2740acda173d238b37f2b5d541",
                           std::unique_ptr<Stardash>(new Stardash));

std::unique_ptr<Base_ai> Stardash::generate_ai()
{
    return std::unique_ptr<Base_ai>(new AI);
}

std::shared_ptr<Base_object> Stardash::generate_object(const std::string& type)
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
    else if(type == "Projectile")
    {
        return std::make_shared<Projectile_>();
    }
    else if(type == "Unit")
    {
        return std::make_shared<Unit_>();
    }
    throw Unknown_type("Unknown type " + type + " encountered.");
}

} // stardash

} // cpp_client

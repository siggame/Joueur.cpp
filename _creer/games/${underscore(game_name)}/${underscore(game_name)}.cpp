#include "${underscore(game_name)}.hpp"
#include "../../joueur/src/register.hpp"

#include "ai.hpp"

namespace cpp_client
{

namespace ${underscore(game_name)}
{

//register the game
Game_registry registration("${underscore(game_name).capitalize()}",
                           std::unique_ptr<${underscore(game_name).capitalize()}>(new ${underscore(game_name).capitalize()}));

std::unique_ptr<Base_ai> ${underscore(game_name).capitalize()}::generate_ai()
{
   return std::unique_ptr<Base_ai>(new AI);
}

} // ${underscore(game_name)}

} // cpp_client

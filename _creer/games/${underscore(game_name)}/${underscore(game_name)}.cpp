#include "${underscore(game_name)}.hpp"
#include "../../src/register.hpp"

namespace cpp_client
{

namespace ${underscore(game_name)}
{

//register the game
Game_registry registration("${underscore(game_name).capitalize()}",
                           std::unique_ptr<${underscore(game_name).capitalize()}>());

} // ${underscore(game_name)}

} // cpp_client

#ifndef GAMES_${underscore(game_name).upper()}_HPP
#define GAMES_${underscore(game_name).upper()}_HPP

// ${header}

#include "../../src/base_game.hpp"
#include "ai.hpp"

namespace cpp_client
{

namespace ${underscore(game_name)}
{

class ${underscore(game_name).capitalize()} : public Base_game
{

};

} // ${underscore(game_name)}

} // cpp_client

#endif // GAMES_${underscore(game_name).upper()}_HPP

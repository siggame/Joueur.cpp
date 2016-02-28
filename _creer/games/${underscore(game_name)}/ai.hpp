#ifndef GAMES_${underscore(game_name).upper()}_AI_HPP
#define GAMES_${underscore(game_name).upper()}_AI_HPP

#include "${underscore(game_name)}.hpp"
#include "game.hpp"
% for game_obj_key in sort_dict_keys(game_objs):
#include "${underscore(game_obj_key).capitalize()}.hpp"
% endfor

#include "../../src/base_ai.hpp"

${merge("// ", "includes", "// You can add additional #includes here")}

namespace cpp_client
{

namespace ${underscore(game_name).upper()}
{

/// <summary>
/// This is the header file for builing your ${game_name} AI
/// </summary>
class AI : public Base_ai
{
   ;
};

} // ${underscore(game_name).upper()}

} // cpp_client

#endif // GAMES_${underscore(game_name).upper()}_AI_HPP

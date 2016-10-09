// ${game_name} Header

// DO NOT MODIFY THIS FILE
// Never try to directly create an instance of this class, or modify its member variables.
// Instead, you should only be reading its variables and calling its functions.

#ifndef JOUEUR_${game_name.upper()}_H
#define JOUEUR_${game_name.upper()}_H

#include "../../gamesRegistry.h"

namespace ${game_name}
{
% for game_obj_key in sort_dict_keys(game_objs):
    class ${game_obj_key};
% endfor

    class Game;
    class GameManager;
    class AI;
}

#endif

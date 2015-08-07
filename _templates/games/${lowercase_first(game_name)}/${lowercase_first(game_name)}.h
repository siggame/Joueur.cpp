#ifndef JOUEUR_${game_name.upper()}_H
#define JOUEUR_${game_name.upper()}_H

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

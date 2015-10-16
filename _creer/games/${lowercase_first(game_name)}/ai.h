// ${header}
// This is where you build your AI for the Checkers game.
<%include file="functions.noCreer" />
#ifndef JOUEUR_${game_name.upper()}_AI_H
#define JOUEUR_${game_name.upper()}_AI_H

#include "${lowercase_first(game_name)}.h"
#include "game.h"
% for game_obj_key in sort_dict_keys(game_objs):
#include "${lowercase_first(game_obj_key)}.h"
% endfor

#include "../../joueur/baseAI.h"

${merge("// ", "includes", '// you can add additional #includes here for your AI.')}

/// <summary>
/// This the header file for where you build your AI for the ${game_name} game.
/// </summary>
class ${game_name}::AI : public Joueur::BaseAI
{
    public:
        /// <summary>
        /// This is a pointer to the Game object itself, it contains all the information about the current game
        /// </summary>
        ${game_name}::Game* game;

        /// <summary>
        /// This is a pointer to your AI's player. This AI class is not a player, but it should command this Player.
        /// </summary>
        ${game_name}::Player* player;

${merge("        // ", "fields", '        // you can add additional fields here for your AI to use')}


        /// <summary>
        /// This returns your AI's name to the game server. Just replace the string.
        /// </summary>
        /// <returns>string of you AI's name.</returns>
        std::string getName();

        /// <summary>
        /// This is automatically called when the game first starts, once the Game object and all GameObjects have been initialized, but before any players do anything.
        /// </summary>
        void start();

        /// <summary>
        /// This is automatically called every time the game (or anything in it) updates.
        /// </summary>
        void gameUpdated();

        /// <summary>
        /// This is automatically called when the game ends.
        /// </summary>
        /// <param name="won">true if your player won, false otherwise</param>
        /// <param name="reason">a string explaining why you won or lost</param>
        void ended(bool won, std::string reason);


% for function_name in ai['function_names']:
<%
function_parms = ai['functions'][function_name]
return_type = function_parms['returns'] and shared['c++']['type'](function_parms['returns']['type'])
%>        /// <summary>
        /// ${function_parms['description']}
        /// </summary>
% for arg_parms in function_parms['arguments']:
        /// <param name="${arg_parms['name']}">${arg_parms['description']}</param>
% endfor
% if function_parms['returns'] != None:
        /// <returns>${function_parms['returns']['description']}</returns>
% endif
        ${return_type or 'void'} ${function_name}(${shared['c++']['inline_args'](function_parms)});
% endfor

${merge("        // ", "methods", '        // you can add additional methods here for your AI to call')}
};

#endif

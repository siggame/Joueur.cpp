// ${header}
// This is where you build your AI for the Checkers game.
<%include file="functions.noCreer" />
#include "ai.h"

${merge("// ", "includes", '// you can add additional #includes here for your AI.')}



/// <summary>
/// This returns your AI's name to the game server. Just replace the string.
/// </summary>
/// <returns>string of you AI's name.</returns>
std::string ${game_name}::AI::getName()
{
${merge("    // ", "get-name", '    return "' + game_name + ' C++ Player"; // REPLACE THIS WITH YOUR TEAM NAME!')}
}

/// <summary>
/// This is automatically called when the game first starts, once the Game object and all GameObjects have been initialized, but before any players do anything.
/// </summary>
void ${game_name}::AI::start()
{
${merge("    // ", "start", '    // This is a good place to initialize any variables you add to your AI, or start tracking game objects.')}
}

/// <summary>
/// This is automatically called every time the game (or anything in it) updates.
/// </summary>
void ${game_name}::AI::gameUpdated()
{
${merge("    // ", "game-updated", '    // If a function you call triggers an update this will be called before that function returns.')}
}

/// <summary>
/// This is automatically called when the game ends.
/// </summary>
/// <param name="won">true if your player won, false otherwise</param>
/// <param name="reason">a string explaining why you won or lost</param>
void ${game_name}::AI::ended(bool won, std::string reason)
{
${merge("    // ", "ended", '    // You can do any cleanup of you AI here, or do custom logging. After this function returns the application will close.')}
}


% for function_name in ai['function_names']:
<%
function_parms = ai['functions'][function_name]
return_type = function_parms['returns'] and shared['c++']['type'](function_parms['returns']['type'])
%>/// <summary>
/// ${function_parms['description']}
/// </summary>
% for arg_parms in function_parms['arguments']:
/// <param name="${arg_parms['name']}">${arg_parms['description']}</param>
% endfor
% if function_parms['returns'] != None:
/// <returns>${function_parms['returns']['description']}</returns>
% endif
${return_type or 'void'} ${game_name}::AI::${function_name}(${shared['c++']['inline_args'](function_parms)})
{
${merge("    // ", function_name,
"""    // Put your game logic here for {0}
    return {1};
""".format(function_name, shared['c++']['default'](function_parms['returns']['type'], function_parms['returns']['default']) if function_parms['returns'] else "")
)}
}
% endfor

${merge("// ", "methods", '// you can add additional methods here for your AI to call')}

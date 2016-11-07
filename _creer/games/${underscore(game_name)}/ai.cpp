// AI
// This is where you build your AI

#include "ai.hpp"

${merge("// ", "includes", "// You can add #includes here for your AI.")}<%include file="functions.noCreer" />
namespace cpp_client
{

namespace ${underscore(game_name)}
{

/// <summary>
/// This returns your AI's name to the game server.
/// Replace the string name.
/// </summary>
/// <returns>The name of your AI.</returns>
std::string AI::get_name() const
{
${merge("    // ", "get-name", '    // REPLACE WITH YOUR TEAM NAME!\n    return "' + game_name + ' C++ Player";')}
}

/// <summary>
/// This is automatically called when the game first starts, once the game objects are created
/// </summary>
void AI::start()
{
${merge("    // ", "start", "    // This is a good place to initialize any variables")}
}

/// <summary>
/// This is automatically called the game (or anything in it) updates
/// </summary>
void AI::game_updated()
{
${merge("    // ", "game-updated", "    // If a function you call triggers an update this will be called before it returns.")}
}

/// <summary>
/// This is automatically called when the game ends.
/// </summary>
/// <param name="won">true if you won, false otherwise</param>
/// <param name="reason">An explanation for why you either won or lost</param>
void AI::ended(bool won, const std::string& reason)
{
${merge("    //", "ended", "    // You can do any cleanup of your AI here.  The program ends when this function returns.")}
}

% for function_name in ai['function_names']:
<%
function_params = ai['functions'][function_name]
if function_params['returns'] and 'type' in function_params['returns']:
    return_type = shared['gen_base_type'](function_params['returns']['type'])
else:
    return_type = 'void'
args = shared['make_args'](function_params, True)
%>/// <summary>
/// ${function_params['description']}
/// </summary>
% for arg_params in function_params['arguments']:
/// <param name="${underscore(arg_params['name'])}">${arg_params['description']}</param>
% endfor
% if function_params['returns']:
/// <returns>${function_params['returns']['description']}</returns>
% endif
${return_type} AI::${underscore(function_name)}(${args})
{
${merge("    // ", function_name, "    // Put your game logic here for {} here".format(underscore(function_name)))}
% if return_type in shared['defaults']:
    return${shared['defaults'][return_type]};
% else:
    return ${return_type}{};
% endif
}
% endfor

${merge("//", "methods", "// You can add additional methods here for your AI to call")}

} // ${underscore(game_name)}

} // cpp_client

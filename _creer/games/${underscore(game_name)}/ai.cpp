// ${header}
// This is where you build your AI

#include "ai.hpp"

${merge("// ", "includes", "// You can add #includes here for your AI.")}

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
${merge("   // ", "get-name", '   // REPLACE WITH YOUR TEAM NAME!\n   return "' + game_name + ' C++ Player";')}
}

/// <summary>
/// This is automatically called when the game first starts, once the game objects are created
/// </summary>
void AI::start()
{
${merge("   // ", "start", "   // This is a good place to initialize any variables")}
}

/// <summary>
/// This is automatically called the game (or anything in it) updates
/// </summary>
void AI::game_updated()
{
${merge("   // ", "game-updated", "   // If a function you call triggers an update this will be called before it returns.")}
}

/// <summary>
/// This is automatically called when the game ends.
/// </summary>
/// <param name="won">true if you won, false otherwise</param>
/// <param name="reason">An explanation for why you either won or lost</param>
void AI::end(bool won, const std::string& reason)
{
${merge("   //", "ended", "   // You can do any cleanup of your AI here.  The program is finished once this closes")}
}

} // ${underscore(game_name)}

} // cpp_client

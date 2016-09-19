// This is where you build your AI for the Chess game.

#include "ai.h"

// <<-- Creer-Merge: includes -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
// you can add additional #includes here for your AI.
// <<-- /Creer-Merge: includes -->>



/// <summary>
/// This returns your AI's name to the game server. Just replace the string.
/// </summary>
/// <returns>string of you AI's name.</returns>
std::string Chess::AI::getName()
{
    // <<-- Creer-Merge: get-name -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
    return "Chess C++ Player"; // REPLACE THIS WITH YOUR TEAM NAME!
    // <<-- /Creer-Merge: get-name -->>
}

/// <summary>
/// This is automatically called when the game first starts, once the Game object and all GameObjects have been initialized, but before any players do anything.
/// </summary>
void Chess::AI::start()
{
    // <<-- Creer-Merge: start -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
    // This is a good place to initialize any variables you add to your AI, or start tracking game objects.
    // <<-- /Creer-Merge: start -->>
}

/// <summary>
/// This is automatically called every time the game (or anything in it) updates.
/// </summary>
void Chess::AI::gameUpdated()
{
    // <<-- Creer-Merge: game-updated -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
    // If a function you call triggers an update this will be called before that function returns.
    // <<-- /Creer-Merge: game-updated -->>
}

/// <summary>
/// This is automatically called when the game ends.
/// </summary>
/// <param name="won">true if your player won, false otherwise</param>
/// <param name="reason">a string explaining why you won or lost</param>
void Chess::AI::ended(bool won, std::string reason)
{
    // <<-- Creer-Merge: ended -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
    // You can do any cleanup of you AI here, or do custom logging. After this function returns the application will close.
    // <<-- /Creer-Merge: ended -->>
}


/// <summary>
/// This is called every time it is this AI.player's turn.
/// </summary>
/// <returns>Represents if you want to end your turn. True means end your turn, False means to keep your turn going and re-call this function.</returns>
bool Chess::AI::runTurn()
{
    // <<-- Creer-Merge: runTurn -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
    // Put your game logic here for runTurn
    return true;
    // <<-- /Creer-Merge: runTurn -->>
}

// <<-- Creer-Merge: methods -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
// you can add additional methods here for your AI to call
// <<-- /Creer-Merge: methods -->>

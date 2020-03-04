// Game
// Send hordes of the undead at your opponent while defending yourself against theirs to win.

// DO NOT MODIFY THIS FILE
// Never try to directly create an instance of this class, or modify its member variables.
// Instead, you should only be reading its variables and calling its functions.

#include "game.hpp"
#include "../../joueur/src/base_ai.hpp"
#include "../../joueur/src/any.hpp"
#include "../../joueur/src/exceptions.hpp"
#include "../../joueur/src/delta.hpp"
#include "game_object.hpp"
#include "player.hpp"
#include "tile.hpp"
#include "tower.hpp"
#include "tower_job.hpp"
#include "unit.hpp"
#include "unit_job.hpp"
#include "impl/necrowar.hpp"

#include <type_traits>

namespace cpp_client
{

namespace necrowar
{

/// <summary>
/// Gets the Tile at a specified (x, y) position
/// </summary>
/// <param name="x">integer between 0 and the mapWidth</param>
/// <param name="y">integer between 0 and the mapHeight</param>
/// <returns>the Tile at (x, y) or null if out of bounds
Tile Game_::get_tile_at(const int x, const int y)
{
    if(x < 0 || y < 0 || x >= map_width || y >= map_height) {
        // out of bounds
        return nullptr;
    }

    return tiles[x + y * map_width];
}

} // necrowar

} // cpp_client

// Game
// Convert as many humans to as you can to survive in this post-apocalyptic wasteland.

// DO NOT MODIFY THIS FILE
// Never try to directly create an instance of this class, or modify its member variables.
// Instead, you should only be reading its variables and calling its functions.

#include "game.hpp"
#include "../../joueur/src/base_ai.hpp"
#include "../../joueur/src/any.hpp"
#include "../../joueur/src/exceptions.hpp"
#include "../../joueur/src/delta.hpp"
#include "game_object.hpp"
#include "job.hpp"
#include "player.hpp"
#include "structure.hpp"
#include "tile.hpp"
#include "unit.hpp"
#include "impl/catastrophe.hpp"

#include <type_traits>

namespace cpp_client
{

namespace catastrophe
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

} // catastrophe

} // cpp_client

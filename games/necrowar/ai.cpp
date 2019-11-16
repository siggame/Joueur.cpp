// AI
// This is where you build your AI

#include "ai.hpp"
// <<-- Creer-Merge: includes -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
// You can add #includes here for your AI.
// <<-- /Creer-Merge: includes -->>

namespace cpp_client
{

namespace necrowar
{

/// <summary>
/// This returns your AI's name to the game server.
/// Replace the string name.
/// </summary>
/// <returns>The name of your AI.</returns>
std::string AI::get_name() const
{
   // <<-- Creer-Merge: get-name -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
   // REPLACE WITH YOUR TEAM NAME!
   return "Necrowar C++ Player";
   // <<-- /Creer-Merge: get-name -->>
}

/// <summary>
/// This is automatically called when the game first starts, once the game objects are created
/// </summary>
void AI::start()
{
   // <<-- Creer-Merge: start -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
   // This is a good place to initialize any variables
   // <<-- /Creer-Merge: start -->>
}

/// <summary>
/// This is automatically called the game (or anything in it) updates
/// </summary>
void AI::game_updated()
{
   // <<-- Creer-Merge: game-updated -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
   // If a function you call triggers an update this will be called before it returns.
   // <<-- /Creer-Merge: game-updated -->>
}

/// <summary>
/// This is automatically called when the game ends.
/// </summary>
/// <param name="won">true if you won, false otherwise</param>
/// <param name="reason">An explanation for why you either won or lost</param>
void AI::ended(bool won, const std::string &reason)
{
   //<<-- Creer-Merge: ended -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
   // You can do any cleanup of your AI here.  The program ends when this function returns.
   //<<-- /Creer-Merge: ended -->>
}

/// <summary>
/// This is called every time it is this AI.player's turn.
/// </summary>
/// <returns>Represents if you want to end your turn. True means end your turn, False means to keep your turn going and re-call this function.</returns>
bool AI::run_turn()
{
   std::vector<Tile> spawnWorkerTiles;
   std::vector<Tile> spawnUnitTiles;
   for (Tile tile : this->player->side)
   {
      if (tile->owner == this->player)
      {
         if (tile->is_worker_spawn)
         {
            spawnWorkerTiles.push_back(tile);
         }
         else if (tile->is_unit_spawn)
         {
            spawnUnitTiles.push_back(tile);
         }
      }
   }
   int gold = this->player->gold;
   int mana = this->player->mana;
   int numWorkers = 0;
   int numUnits = 0;
   for (int i = 0; i < this->player->units.size(); ++i)
   { 
	   if (this->player->units[i]->job->title==("worker"))
      {
         numWorkers++;
      }
      else 
	  {
		  numUnits++;
      }
   }
   if (numWorkers < 5)
   {
      spawnWorkerTiles[0]->spawn_worker();
   }
   if (numUnits < 3)
   {
      spawnUnitTiles[0]->spawn_unit("ghoul");
   }

   Player enemy = NULL;
   if (this->player == this->game->players[0])
   {
      enemy = this->game->players[1];
   }
   else
   {
      enemy = this->game->players[0];
   }

   Tile target = NULL;
   for (int i = 0; i < this->player->units.size(); ++i)
   {
      // Only tries to do something if the unit actually exists.
      // if a unit does not have a tile, then they are dead.

      if (this->player->units[i] != NULL && this->player->units[i]->tile != NULL)
      {
         if (this->player->units[i]->job->title==("worker"))
         {
            target = NULL;

            for (Tile tile : this->game->tiles)
            {
               if (tile->is_gold_mine && std::count(this->player->side.begin, this->player->side.end, tile) > 0 && tile->unit == NULL)
               {
                  target = tile;
               }

               else if (tile->is_tower && std::count(this->player->side.begin, this->player->side.end, tile) > 0 && tile->unit == NULL)
               {
                  target = tile;
               }
            }
            if (target == NULL)
            {
               std::vector<Tile> riverSpots;
               for (Tile tile : game->tiles)
               {
                  if (tile->is_river && std::count(this->player->side.begin, this->player->side.end, tile) > 0)
                  {
                     riverSpots.push_back(tile);
                  }
               }
               for (Tile tile : game->tiles)
               {
                  bool foundRiverSpot = false;
                  for (Tile spot : riverSpots)
                  {
                     foundRiverSpot = std::count(tile->get_neighbors().begin, tile->get_neighbors().end, spot) > 0;
                  }

                  if (foundRiverSpot && std::count(this->player->side.begin, this->player->side.end, tile) > 0)
                  {
                     while (unit->moves > 0 && !find_path(unit->tile, tile).empty())
                     {
                        if (!unit->move(find_path(unit->tile, tile)[0]))
                        {
                           unit->move(target);
                        }
                     }

                     if (!unit->acted)
                     {
                        unit->fish(tile);
                     }

                     break;
                  }
               }
            }
            else
            {
               while (unit->moves > 0 && !find_path(unit->tile, target).empty())
               {
                  if (!unit->move(find_path(unit->tile, target)[0]))
                  {
                     unit->move(target);
                  }
               }

               if (!unit->acted)
               {
                  if (target->is_gold_mine)
                  {
                     unit->acted = true;
                     unit->mine(unit->tile);
                  }
                  else if (target->is_tower)
                  {
                     unit->acted = true;
                     unit->build("arrow");
                  }
               }
            }
         }
         else if (unit->job.title.equals("ghoul"))
         {
            target = NULL;

            for (int i =0; i < this->game->tiles.size(); i++)
            {
               if (tile->is_tower && enemy->side.contains(tile) && tile->unit != NULL)
               {
                  target = tile;

                  while (unit->moves > 0 && find_path(unit->tile, target).size() > 1)
                  {
                     if (!unit->move(find_path(unit->tile, target)[0]))
                     {
                        unit->move(target);
                     }
                     if (!unit->acted)
                     {
                        unit->attack(target);
                        unit->acted = true;
                     }
                  }
               }
               else if (target != NULL)
               {
                  target = NULL;
                  for (Tile tileTarget : game->tiles)
                  {
                     if (tileTarget->is_castle && enemy->side->contains(tileTarget) && tileTarget->unit != NULL)
                     {
                        target = tileTarget;

                        while (unit->moves > 0 && find_path(unit->tile, target).size() > 1)
                        {
                           if (!unit->move(find_path(unit->tile, target)[0]))
                           {
                              unit->move(target);
                           }
                           if (!unit->acted)
                           {
                              unit->attack(target);
                              unit->acted = true;
                           }
                        }
                     }
                  }
               }
            }
         }
      }

      // <<-- Creer-Merge: runTurn -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
      // Put your game logic here for run_turn here
      // <<-- /Creer-Merge: runTurn -->>
      return true;
   }

   /// A very basic path finding algorithm (Breadth First Search) that when given a starting Tile, will return a valid path to the goal Tile.
   /// <param name="start">the starting Tile</param>
   /// <param name="goal">the goal Tile</param>
   /// <return>A List of Tiles representing the path, the the first element being a valid adjacent Tile to the start, and the last element being the goal. Or an empty list if no path found.</return>
   std::vector<Tile> AI::find_path(const Tile &start, const Tile &goal)
   {
      // no need to make a path to here...
      if (start == goal)
      {
         return {};
      }

      // the tiles that will have their neighbors searched for 'goal'
      std::queue<Tile> fringe;

      // How we got to each tile that went into the fringe.
      std::unordered_map<Tile, Tile> came_from;

      // Enqueue start as the first tile to have its neighbors searched.
      fringe.push(start);

      // keep exploring neighbors of neighbors... until there are no more.
      while (fringe.size() > 0)
      {
         // the tile we are currently exploring.
         Tile inspect = fringe.front();
         fringe.pop();

         // Note, we are using the `auto` keyword here
         //   The compiler can discern that this is a `std::vector<Tile>` based on the return type of `getNeighbors()`
         auto neighbors = inspect->get_neighbors();

         // cycle through the tile's neighbors.
         for (unsigned i = 0; i < neighbors.size(); i++)
         {
            Tile neighbor = neighbors[i];

            // If we found the goal we've found the path!
            if (neighbor == goal)
            {
               // Follow the path backward starting at the goal and return it.
               std::deque<Tile> path;
               path.push_front(goal);

               // Starting at the tile we are currently at, insert them retracing our steps till we get to the starting tile
               for (Tile step = inspect; step != start; step = came_from[step])
               {
                  path.push_front(step);
               }

               // we want to return a vector as that's what we use for all containers in C++
               // (and they don't have push_front like we need)
               // So construct the vector-ized path here
               std::vector<Tile> vector_path;
               for (auto &tile : path)
               {
                  vector_path.push_back(tile);
               }
               return vector_path;
            }

            // if the tile exists, has not been explored or added to the fringe yet, and it is pathable
            if (neighbor && came_from.count(neighbor) == 0 && neighbor->is_pathable())
            {
               // add it to the tiles to be explored and add where it came from.
               fringe.push(neighbor);
               came_from[neighbor] = inspect;
            }

         } // for each neighbor

      } // while fringe not empty

      // if you're here, that means that there was not a path to get to where you want to go.
      //   in that case, we'll just return an empty path.
      return {};
   }

   //<<-- Creer-Merge: methods -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
   // You can add additional methods here for your AI to call
   //<<-- /Creer-Merge: methods -->>

} // namespace necrowar

} // namespace necrowar
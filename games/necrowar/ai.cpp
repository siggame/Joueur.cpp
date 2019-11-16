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

   // Print starting stats
   std::cout << "GOLD: " << this->player->gold << std::endl;
   std::cout << "MANA: " << this->player->mana << std::endl;
   std::cout << "UNITS: ";
   for (Unit u : this->player->units)
        std::cout << u->job->title << ", ";
   std::cout << "\nTOWERS:";
   for (Tower t : this->player->towers)
        std::cout << t->job->title << ", ";
    std::cout << "\nCastle Health: " << this->player->towers[0]->health << std::endl;

    // Set up variables to track relevant info
    this->enemyCastle = this->player->opponent->towers[0];
    this->myCastle = this->player->towers[0];

    for (Tile tile : this->player->side)
    {
        if (tile->is_unit_spawn)
            this->spawnUnitTile = tile;
        else if (tile->is_worker_spawn)
            this->spawnWorkerTile = tile;
        else if (tile->is_gold_mine)
            this->goldMines.push_back(tile);
        else if (tile->is_grass)
            for (Tile neighbor : tile->get_neighbors())
                this->grassByPath.push_back(tile);
    }
    // Now we should have our spawn tiles, mines, and tower building locations!

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

   // Print final stats
   std::cout << "GOLD: " << this->player->gold << std::endl;
   std::cout << "MANA: " << this->player->mana << std::endl;
   std::cout << "UNITS: ";
   for (Unit u : this->player->units)
        std::cout << u->job->title << ", ";
   std::cout << "\nTOWERS:";
   for (Tower t : this->player->towers)
        std::cout << t->job->title << ", ";

    if (this->player->towers[0]->job->title == "castle")
        std::cout << "\nCastle Health: " << this->player->towers[0]->health << std::endl;
    else
        std::cout << "No castle left :(" << std::endl;
   //<<-- /Creer-Merge: ended -->>
}

/// <summary>
/// This is called every time it is this AI.player's turn.
/// </summary>
/// <returns>Represents if you want to end your turn. True means end your turn, False means to keep your turn going and re-call this function.</returns>
bool AI::run_turn()
{


      // <<-- Creer-Merge: runTurn -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
      // Put your game logic here for run_turn here

        // Remove dead units from our personal tracking lists
        std::vector<int> killdex;

        for (int i = this->miners.size()-1; i >= 0; i--)
        {
        if (this->miners[i]->health <= 0)
            killdex.push_back(i);
        }
        for (auto i : killdex)
            this->miners.erase(this->miners.begin() + i);

        killdex.clear();
        for (int i = this->builders.size()-1; i >= 0; i--)
        {
        if (this->builders[i]->health <= 0)
            killdex.push_back(i);
        }
        for (auto i : killdex)
            this->builders.erase(this->builders.begin() + i);

        killdex.clear();
        for (int i = this->units.size()-1; i >= 0; i--)
        {
        if (this->units[i]->health <= 0)
            killdex.push_back(i);
        }
        for (auto i : killdex)
            this->units.erase(this->units.begin() + i);

        // Spawn all three of our chosen unit types if necessary
        if (this->miners.size() == 0)
            if (this->spawnWorkerTile->spawn_worker())
                this->miners.push_back(this->player->units[this->player->units.size() - 1]);

        if (this->builders.size() == 0)
            if (this->spawnWorkerTile->spawn_worker())
                this->builders.push_back(this->player->units[this->player->units.size() - 1]);

        if (this->units.size() == 0)
            if (this->spawnUnitTile->spawn_unit("ghoul"))
                this->units.push_back(this->player->units[this->player->units.size() - 1]);


        // Activate the units in our list
        std::vector<Tile> path;
        for (auto miner : this->miners)
        {
            if (miner->tile->is_gold_mine)
                miner->mine(miner->tile);
            else
            {
                path = this->find_path_worker(miner->tile, this->goldMines[0]);
                for (auto tile : path)
                {
                    if (miner->moves <= 0)
                        break;
                    miner->move(tile);
                }
            }
        }

        for (auto builder : this->builders)
        {
            path = this->find_path_worker(builder->tile, this->grassByPath[0]);
            for (auto tile : path)
            {
                if (builder->moves <= 0)
                    break;
                builder->move(tile);
            }
            if (path.size() == 0 && builder->moves > 0)
                builder->build("arrow");
        }

        for (auto unit : this->units)
        {
            path = this->find_path(unit->tile, this->enemyCastle->tile->tile_south);
            for (auto tile : path)
            {
                if (unit->moves <= 0)
                    break;
                unit->move(tile);
            }
            if (path.size() == 0 && unit->moves > 0)
                unit->attack(this->enemyCastle->tile);
        }

        // Make towers attack anything adjacent to them
        // Note that they are not using full range
        std::vector<Tile> adjacent;
        for (Tower tower : this->player->towers)
        {
            adjacent = tower->tile->get_neighbors();
            for (Tile tile : adjacent)
            {
                if (tile->unit != nullptr && tile->unit->owner == this->player->opponent)
                    tower->attack(tile);
            }
        }
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

   std::vector<Tile> AI::find_path_worker(const Tile &start, const Tile &goal)
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
            if (neighbor && came_from.count(neighbor) == 0 && neighbor->is_pathable_worker())
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

   bool AI::isDead(Unit u) { return u->health <= 0; }


   //<<-- /Creer-Merge: methods -->>

} // namespace necrowar

} // namespace necrowar

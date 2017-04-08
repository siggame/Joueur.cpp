// AI
// This is where you build your AI

#include "ai.hpp"

// You can add #includes here for your AI.

namespace cpp_client
{

namespace stumped
{

/// <summary>
/// This returns your AI's name to the game server.
/// Replace the string name.
/// </summary>
/// <returns>The name of your AI.</returns>
std::string AI::get_name() const
{
    // REPLACE WITH YOUR TEAM NAME!
    return "Stumped C++ Player";
}

/// <summary>
/// This is automatically called when the game first starts, once the game objects are created
/// </summary>
void AI::start()
{
    // This is a good place to initialize any variables
    std::random_device rd;
    gen = std::mt19937(rd());
}

/// <summary>
/// This is automatically called the game (or anything in it) updates
/// </summary>
void AI::game_updated()
{
    // If a function you call triggers an update this will be called before it returns.
}

/// <summary>
/// This is automatically called when the game ends.
/// </summary>
/// <param name="won">true if you won, false otherwise</param>
/// <param name="reason">An explanation for why you either won or lost</param>
void AI::ended(bool won, const std::string& reason)
{
    // You can do any cleanup of your AI here.  The program ends when this function returns.
}

/// <summary>
/// This is called every time it is this AI.player's turn.
/// </summary>
/// <returns>Represents if you want to end your turn. True means end your turn, False means to keep your turn going and re-call this function.</returns>
bool AI::run_turn()
{
    // This is your Stumped ShellAI
    // ShellAI is intended to be a simple AI that does everything possible in the game, but plays the game very poorly
    // This example code does the following:
    // 1. Grabs a single beaver
    // 2. tries to move the beaver
    // 3. tries to do one of the 5 actions on it
    // 4. Grabs a lodge and tries to recruit a new beaver

    // First let's do a simple print statement telling us what turn we are on
    std::cout << "My turn " << game->current_turn << std::endl;

    // 1. get the first beaver to try to do things with
    // NOTE: this is the `auto` keyword. If you are not familiar with it, think of it this way:
    //       it basically asks the compiler to figure out what the type is. Because the beavers vector
    //       contains `Beaver` instances, the compiler can figure out `auto` -> `Beaver` (at a basic level)
    const auto beaver = random_element(player->beavers);

    // if we have a beaver, and it's not distracted, and it is alive (health greater than 0)
    if(beaver && beaver->turns_distracted == 0 && beaver->health > 0)
    {
        // then let's try to do stuff with it

        // 2. Try to move the beaver
        if(beaver->moves > 2)
        {
            // then it has enough moves to move in any direction, so let's move it

            // find a spawner to move to
            Tile target = nullptr;
            for(const auto& tile : game->tiles)
            {
                if(tile->spawner && tile->spawner->health > 1)
                {
                    // then we found a healthy spawner, let's target that tile to move to
                    target = tile;
                    break;
                }
            }

            // If we found a target tile to path to, then do so
            if(target)
            {
                // use the pathfinding algorithm below to make a path to the spawner's target tile
                const auto path = find_path(beaver->tile, target);

                // if there is a path, move to it
                //      length 0 means no path could be found to the tile
                //      length 1 means the target is adjacent, and we can't move onto the same tile as the spawner
                //      length 2+ means we have to move towards it
                if(path.size() > 1)
                {
                    std::cout << "Moving beaver #" << beaver->id << " towards tile #" << target->id << std::endl;
                    beaver->move(path.front());
                }
            }
        }

        // 3. Try to do an action on the beaver
        if(beaver->actions > 0)
        {
            // then let's try to do an action!

            // Do a random action!
            std::shuffle(actions.begin(), actions.end(), gen);
            const auto action = actions.front();

            // how much this beaver is carrying, used for calculations
            const auto load = beaver->branches + beaver->food;

            switch(action.front()) // just look at the first character
            {
            case 'b': // action == "buildLodge"
            {
                // if the beaver has enough branches to build a lodge
                //   and the tile does not already have a lodge, then do so
                if((beaver->branches + beaver->tile->branches) >= player->branches_to_build_lodge && beaver->tile->lodge_owner)
                {
                    std::cout << "Beaver #" << beaver->id << " building lodge" << std::endl;
                    beaver->build_lodge();
                }
                break;
            }
            case 'a': // action == "attack"
            {
                // look at all our neighbor tiles and if they have a beaver attack it!
                auto neighbors = beaver->tile->get_neighbors();
                std::shuffle(neighbors.begin(), neighbors.end(), gen);
                for(const auto& neighbor : neighbors)
                {
                    if(neighbor->beaver)
                    {
                        std::cout << "Beaver #" << beaver->id << " attacking beaver #" 
                                  << neighbor->beaver->id << std::endl;
                        beaver->attack(neighbor->beaver);
                        break;
                    }
                }
                break;
            }
            case 'p': // action == "pickup"
            {
                // make an array of our neighboring tiles + our tile as all can be picked up from
                auto pickup_tiles = beaver->tile->get_neighbors();
                pickup_tiles.push_back(beaver->tile);
                std::shuffle(pickup_tiles.begin(), pickup_tiles.end(), gen);

                // if the beaver can carry more resources, try to pick something up
                if(load < beaver->job->carry_limit)
                {
                    for(const auto& tile : pickup_tiles)
                    {
                        // try to pickup branches
                        if (tile->branches > 0)
                        {
                            std::cout << "Beaver #" << beaver->id << " picking up branches" << std::endl;
                            beaver->pickup(tile, "branches", 1);
                            break;
                        }
                        // try to pickup food
                        else if (tile->food > 0)
                        {
                            std::cout << "Beaver #" << beaver->id << " picking up food" << std::endl;
                            beaver->pickup(tile, "food", 1);
                            break;
                        }
                    }
                }
                break;
            }
            case 'd': // action == "drop"
            {
                // choose a random tile from our neighbors + out tile to drop stuff on
                auto drop_tiles = beaver->tile->get_neighbors();
                drop_tiles.push_back(beaver->tile);
                std::shuffle(drop_tiles.begin(), drop_tiles.end(), gen);

                // find a valid tile to drop resources onto
                Tile tile_to_drop_on = nullptr;
                for(const auto& tile : drop_tiles)
                {
                    if(!tile->spawner)
                    {
                        tile_to_drop_on = tile;
                        break;
                    }
                }

                // if there is a tile that resources can be dropped on
                if(tile_to_drop_on)
                {
                    // if we have branches to drop
                    if(beaver->branches > 0)
                    {
                        std::cout << "Beaver #"  << beaver->id << " dropping 1 branch" << std::endl;
                        beaver->drop(tile_to_drop_on, "branches", 1);
                    }
                    // or if we have food to drop
                    else if(beaver->food > 0)
                    {
                        std::cout << "Beaver #"  << beaver->id << " dropping 1 food" << std::endl;
                        beaver->drop(tile_to_drop_on, "food", 1);
                    }
                }
                break;
            }
            case 'h': // action == "harvest"
            {
                // if we can carry more, try to harvest something
                if(load < beaver->job->carry_limit)
                {
                    // try to find a neighboring tile with a spawner on it to harvest from
                    auto neighbors = beaver->tile->get_neighbors();
                    std::shuffle(neighbors.begin(), neighbors.end(), gen);
                    for(const auto& neighbor : neighbors)
                    {
                        // if it has a spawner on that tile, harvest from it
                        if(neighbor->spawner)
                        {
                            std::cout << "Beaver #"  << beaver->id << " harvesting spawner #"
                                      << neighbor->spawner->id << std::endl;
                            beaver->harvest(neighbor->spawner);
                            break;
                        }
                    }
                }
                break;
            }
            }
        }
    }

    // now try to spawn a beaver if we have lodges

    // 4. Get a lodge to try to spawn something at
    const auto lodge = random_element(player->lodges);

    if(lodge && !lodge->beaver)
    {
        // then this lodge can have a new beaver appear here

        // We need to know how many beavers we have to see if they are free to spawn
        // this will count the number of alive beavers we have using what's called a lambda expression (function)
        auto alive_beavers = std::accumulate(player->beavers.begin(), player->beavers.end(), 0,
                                             [](int acc, Beaver b)
                                             {
                                                 return b->health > 0 ? acc + 1 : acc;
                                             });

        // and we need a Job to spawn
        const auto job = random_element(game->jobs);

        // if we have less beavers than the freeBeavers count, it is free to spawn
        //    otherwise if that lodge has enough food on it to cover the job's cost
        if(alive_beavers < game->free_beavers_count || lodge->food >= job->cost)
        {
            // then spawn a new beaver of that job!
            std::cout << "Recruiting " << job->title << " to lodge #" << lodge->id << std::endl;
            job->recruit(lodge);
            //alive_beavers++;
        }
    }

    std::cout << "Done with our turn" << std::endl;
    return true;
}

/// A very basic path finding algorithm (Breadth First Search) that when given a starting Tile, will return a valid path to the goal Tile.
/// <param name="start">the starting Tile</param>
/// <param name="goal">the goal Tile</param>
/// <return>A List of Tiles representing the path, the the first element being a valid adjacent Tile to the start, and the last element being the goal. Or an empty list if no path found.</return>
std::vector<Tile> AI::find_path(const Tile& start, const Tile& goal)
{
    // no need to make a path to here...
    if(start == goal || start == nullptr || goal == nullptr)
    {
        return {};
    }

    // the tiles that will have their neighbors searched for 'goal'
    std::queue<Tile> fringe;

    // How we got to each tile that went into the fringe.
    std::unordered_map<Tile,Tile> came_from;

    // Enqueue start as the first tile to have its neighbors searched.
    fringe.push(start);

    // keep exploring neighbors of neighbors... until there are no more.
    while(fringe.size() > 0)
    {
        // the tile we are currently exploring.
        Tile inspect = fringe.front();
        fringe.pop();

        // Note, we are using the `auto` keyword here
        //   The compiler can discern that this is a `std::vector<Tile>` based on the return type of `getNeighbors()`
        auto neighbors = inspect->get_neighbors();

        // cycle through the tile's neighbors.
        for(int i = 0; i < neighbors.size(); i++)
        {
            Tile neighbor = neighbors[i];

            // If we found the goal we've found the path!
            if(neighbor == goal)
            {
                // Follow the path backward starting at the goal and return it.
                std::deque<Tile> path;
                path.push_front(goal);

                // Starting at the tile we are currently at, insert them retracing our steps till we get to the starting tile
                for(Tile step = inspect; step != start; step = came_from[step])
                {
                    path.push_front(step);
                }

                // we want to return a vector as that's what we use for all containers in C++
                // (and they don't have push_front like we need)
                // So construct the vector-ized path here
                std::vector<Tile> vector_path;
                for(auto& tile : path)
                {
                    vector_path.push_back(tile);
                }
                return vector_path;
            }

            // if the tile exists, has not been explored or added to the fringe yet, and it is pathable
            if(neighbor && came_from.count(neighbor) == 0 && neighbor->is_pathable())
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

template<class Item>
Item AI::random_element(std::vector<Item> container)
{
    if(container.size() == 0) return nullptr;
    return container.at(gen() % container.size());
}

// You can add additional methods here for your AI to call

} // stumped

} // cpp_client

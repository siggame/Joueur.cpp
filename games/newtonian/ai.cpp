// AI
// This is where you build your AI

#include "ai.hpp"

// <<-- Creer-Merge: includes -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
// You can add #includes here for your AI.
// <<-- /Creer-Merge: includes -->>

namespace cpp_client
{

namespace newtonian
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
    return "Newtonian C++ Player";
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
void AI::ended(bool won, const std::string& reason)
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
    // <<-- Creer-Merge: runTurn -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
    // Put your game logic here for run_turn here

	/*
	 * Please Note: this code is intentionally bad. you should try to optimize everything here.
	 * The code here is only to show ou how to use the game's mechanics with the MegaMinerAI server framework.
	 */
	
	// Go through all the units that you own.
	for (auto unit : player->units)
	{
		// Only tries to do something if the unit actually exists. 
		// if a unit does not have a tile, then they are dead. 
		if (unit != nullptr && unit->tile != nullptr)
		{
			if (unit->job->title == "physicist")
			{
				// If the unit is a physicist, tries to work on machines that are ready, but if there are none,
				// it finds and attacks enemy managers.
				
				// Tries to find a workable machine for blueium ore.
				// Note: you need to get redium ore as well.
				Tile target = nullptr;

				// Goes through all the machines in the game and picks one that is ready to process the ore as its target.
				for (auto machine : game->machines)
				{
					if (machine->tile->blueium_ore >= machine->refine_input)
					{
						target = machine->tile;
					}
				}

				if (target == nullptr)
				{
					// Chases down enemy managers if there are no machines that are ready to be worked.
					for (auto enemy : player->opponent->units)
					{
						// Only does anything if the unit that we found is a manager.
						if (enemy->tile != nullptr && enemy->job->title == "manager")
						{
							// Moves towards the manager.
							while (unit->moves > 0 && !find_path(unit->tile, enemy->tile).empty())
							{
								// Moves unit there are no moves left for the physicist.
								if (!unit->move(find_path(unit->tile, enemy->tile)[0]))
								{
									break;
								}
							}

							if (enemy->tile->has_neighbor(unit->tile))
							{
								if (enemy->stun_time == 0 && enemy->stun_immune == 0)
								{
									// Stuns the enemy manager if they are not stunned and not immune.
								}
								else
								{
									// Attacks the manager otherwise.
									unit->attack(enemy->tile);
								}
							}

							break;
						}
					}
				}
				else
				{
					// Gets the tile of the targeted machine if adjacent to it.
					bool adjacent = false;

					for (auto tile : target->get_neighbors())
					{
						if (tile == unit->tile)
						{
							adjacent = true;
						}
					}

					// If there is a machine that is waiting to be worked on, go to it.
					while ( unit->moves > 0 && !find_path(unit->tile, target).empty() && !adjacent)
					{
						if (!unit->move(find_path(unit->tile, target)[0]))
						{
							break;
						}
					}

					// Acts on the target machine to run it if the physicist is adjacent.
					if (adjacent && !unit->acted)
					{
						unit->act(target);
					}
				}
			}
			else if (unit->job->title == "intern")
			{
                // If the unit is an intern, collects blueium ore.
                // Note: You also need to collect redium ore.

                // Goes to gather resources if currently carrying less than the carry limit.
                if (unit->blueium_ore < unit->job->carry_limit)
                {
                    // Your intern's current target.
                    Tile target = nullptr;

                    // Goes to collect blueium ore that isn't on a machine.
                    for (auto tile : game->tiles)
                    {
                        if (tile->blueium_ore > 0 && tile->machine == nullptr)
                        {
                            target = tile;
                            break;
                        }
                    }

                    // Moves towards our target until at the target or out of moves.
                    if (!find_path(unit->tile, target).empty())
                    {
                        while (unit->moves > 0 && !find_path(unit->tile, target).empty())
                        {
                            if (!unit->move(find_path(unit->tile, target)[0]))
                                break;
                        }
                    }

                    // Picks up the appropriate resource once we reach our target's tile.
                    if (unit->tile == target && target->blueium_ore > 0)
                    {
                        unit->pickup(target, 0, "blueium ore");
                    }

	                
                }
                else
				{
                    // Deposits blueium ore in a machine for it if we have any.

                    // Finds a machine in the game's tiles that takes blueium ore.
                    for (auto tile : game->tiles)
                    {
                        if (tile->machine != nullptr && tile->machine->ore_type == "blueium")
                        {
                            // Moves towards the found machine until we reach it or are out of moves.
                            while (unit->moves > 0 && !find_path(unit->tile, tile).empty())
                            {
                                if (!unit->move(find_path(unit->tile, tile)[0]))
                                {
                                    break;
                                }
                            }

                            // Deposits blueium ore on the machine if we have reached it.
                            if (find_path(unit->tile, tile).size() <= 1)
                            {
                                unit->drop(tile, 0, "blueium ore");
                            }
                        }
                    }
				}
			}
            else if (unit->job->title == "manager")
            {
                // Finds enemy interns, stuns, && attacks them if there is no blueium to take to the generator.
                Tile target = nullptr;

                for (auto tile : game->tiles)
                {
                    if (tile->blueium > 1 && unit->blueium < unit->job->carry_limit)
                        target = tile;
                }

                if (target  == nullptr && unit->blueium == 0)
                {
                    for (auto enemy : game->units)
                    {
                        // Only does anything for an intern that is owned by your opponent.
                        if (enemy->tile != nullptr && enemy->owner == player->opponent && enemy->job->title == "intern")
                        {
                            // Moves towards the intern until reached or out of moves.
                            while (unit->moves > 0 && !find_path(unit->tile, enemy->tile).empty())
                                if (!unit->move(find_path(unit->tile, enemy->tile)[0]))
                                    break;

                            // Either stuns or attacks the intern if we are within range.
                            if (enemy->tile->has_neighbor(unit->tile))
                            {
                                if (enemy->stun_time == 0 && enemy->stun_immune == 0)
                                {
                                    // Stuns the enemy intern if they are !stunned && !immune.
                                    unit->act(enemy->tile);
                                }
                                else
								{
                                    // Attacks the intern otherwise.
                                    unit->attack(enemy->tile);
								}

                            break;
                            }
                        }
                    }
                }
                else if (target != nullptr)
                {
                    // Moves towards our target until at the target or out of moves.
                    while (unit->moves > 0 && find_path(unit->tile, target).size() > 1)
					{
                    	if (!unit->move(find_path(unit->tile, target)[0]))
						{
                    		break;
						}
					}

                    // Picks up blueium once we reach our target's tile.
                    if (find_path(unit->tile, target).size() <= 1 && target->blueium > 0)
                    {
                        unit->pickup(target, 0, "blueium");
                    }
                }
				else if (target == nullptr && unit->blueium > 0)
                {
                    // Stores a tile that is part of your generator.
                    Tile gen_tile = player->generator_tiles[0];

                    // Goes to your generator && drops blueium in.
                    while (unit->moves > 0 && !find_path(unit->tile, gen_tile).empty())
					{
                        if (!unit->move(find_path(unit->tile, gen_tile)[0]))
						{
                        	break;
						}
					}

                    // Deposits blueium in our generator if we have reached it.
                    if (find_path(unit->tile, gen_tile).empty())
                    {
                        unit->drop(gen_tile, 0, "blueium");
                    }
                }
            }
		}
	}

    // <<-- /Creer-Merge: runTurn -->>
    return true;
}

/// A very basic path finding algorithm (Breadth First Search) that when given a starting Tile, will return a valid path to the goal Tile.
/// <param name="start">the starting Tile</param>
/// <param name="goal">the goal Tile</param>
/// <return>A List of Tiles representing the path, the the first element being a valid adjacent Tile to the start, and the last element being the goal. Or an empty list if no path found.</return>
std::vector<Tile> AI::find_path(const Tile& start, const Tile& goal)
{
    // no need to make a path to here...
    if(start == goal)
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
        for(unsigned i = 0; i < neighbors.size(); i++)
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

//<<-- Creer-Merge: methods -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
// You can add additional methods here for your AI to call
//<<-- /Creer-Merge: methods -->>

} // newtonian

} // cpp_client

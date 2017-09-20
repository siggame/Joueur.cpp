// AI
// This is where you build your AI

#include "ai.hpp"

// <<-- Creer-Merge: includes -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
// You can add #includes here for your AI.
// <<-- /Creer-Merge: includes -->>

namespace cpp_client
{

namespace saloon
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
    return "Saloon C++ Player";
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
    // This is "ShellAI", some basic code we've provided that does
    // everything in the game for demo purposed, but poorly so you
    // can get to optimizing or overwriting it ASAP
    //
    // ShellAI does a few things:
    // 1. Tries to spawn a new Cowboy
    // 2. Tries to move to a Piano
    // 3. Tries to play a Piano
    // 4. Tries to act

    // Notice to CS 1570 students.
    // We use pointers extensively throughout the C++ client
    // If you are not familiar with pointers here's the quick and dirty on what you need to know
    // Normally you'd use the `.` (dot) operator to access member variables,
    // e.g. point.x = 0;
    // However with pointers use the `->` (arrow) operator instead
    // e.g. point->x = 0;
    // In Data Structures you will learn why
    // And for those on you in Data Structures, we manage the memory of the game objects automatically for you

    std::cout << "Start of my turn: " << this->game->current_turn << std::endl;

    // Find the active cowboy to try to do things with it
    Cowboy active_cowboy = nullptr;
    for(int i = 0; i < this->player->cowboys.size(); i++)
    {
        Cowboy cowboy = this->player->cowboys[i];

        // if this cowboy is not dead then make him our active cowboy we will try to control
        if(!cowboy->is_dead)
        {
            active_cowboy = cowboy;
            break;
        }
    }

    // 1. Try to spawn a cowboy.

    // Randomly select a job.
    std::string new_job = game->jobs.at(rand() % game->jobs.size());

    // Count cowboys with selected job
    int job_count = 0;
    for(int i = 0; i < this->player->cowboys.size(); i++)
    {
        Cowboy cowboy = this->player->cowboys[i];

        if(!cowboy->is_dead && cowboy->job == new_job)
        {
            job_count++;
        }
    }

    // Call in the new cowboy with that job if there aren't too many
    //   cowboys with that job already.
    if(this->player->young_gun->can_call_in && job_count < this->game->max_cowboys_per_job)
    {
        std::cout << "1. Calling in: " << new_job << std::endl;
        this->player->young_gun->call_in(new_job);
    }

    // Now lets use him
    if(active_cowboy)
    {
        // 2. Try to move to a piano.

        // Find a piano.
        Furnishing piano = nullptr;
        for(int i = 0; i < this->game->furnishings.size(); i++)
        {
            Furnishing furnishing = this->game->furnishings[i];

            if(furnishing->is_piano && !furnishing->is_destroyed)
            {
                piano = furnishing;
                break;
            }
        }

        // There will always be pianos or the game will end. No need to check for existence.
        // Attempt to move toward the piano by finding a path.
        if(active_cowboy->can_move && !active_cowboy->is_dead)
        {
            std::cout << "Trying to use Cowboy #" << active_cowboy->id << std::endl;

            // Find a path of tiles to the piano from our active cowboy's tile
            std::vector<Tile> path = this->find_path(active_cowboy->tile, piano->tile);

            // if there is a path, move along it
            //      length 0 means no path could be found to the tile
            //      length 1 means the piano is adjacent, and we can't move onto the same tile as the piano
            if(path.size() > 1)
            {
                std::cout << "2. Moving to Tile #" << path[0]->id << std::endl;
                active_cowboy->move(path[0]);
            }
        }

        // 3. Try to play a nearby piano.
        if(!active_cowboy->is_dead && active_cowboy->turns_busy == 0)
        {
            std::vector<Tile> neighbors = active_cowboy->tile->get_neighbors();

            for(int i = 0; i < neighbors.size(); i++) {
                Tile neighbor = neighbors[i];

                if(neighbor->furnishing && neighbor->furnishing->is_piano)
                {
                    std::cout << "3. Playing piano (Furnishing) #" << neighbor->furnishing->id << std::endl;
                    active_cowboy->play(neighbor->furnishing);
                    break;
                }
            }
        }

        // 4. Try to act with active cowboy
        if(!active_cowboy->is_dead && active_cowboy->turns_busy == 0)
        {
            // Get a random neighboring tile.
            std::vector<Tile> neighbors = active_cowboy->tile->get_neighbors();
            Tile neighbor = neighbors[rand() % neighbors.size()];

            // Based on job, act accordingly.
            if(active_cowboy->job == "Bartender")
            {
                // Bartenders dispense brews freely, but they still manage to get their due.
                std::string direction = Tile_::directions[rand() % Tile_::directions.size()];
                std::cout << "4. Bartender acting on Tile #" << neighbor->id << " with drunkDirection: " << direction << std::endl;
                active_cowboy->act(neighbor, direction);
            }
            else if(active_cowboy->job == "Brawler")
            {
                // Brawlers' brains are so pickled, they hardly know friend from foe.
                // Probably don't ask them act on your behalf.
                std::cout << "4. Brawlers cannot act" << std::endl;
            }
            else if(active_cowboy->job == "Sharpshooter")
            {
                // Sharpshooters aren't as quick as they used to be, and all that ruckus around them
                // requires them to focus when taking aim.
                if(active_cowboy->focus > 0)
                {
                    std::cout << "4. Sharpshooter acting on Tile #" << neighbor->id << std::endl;
                    active_cowboy->act(neighbor);
                }
                else
                {
                    std::cout << "4. Sharpshooter doesn't have enough focus. (focus == " << active_cowboy->focus << ")" << std::endl;
                }
            }
        }
    }

    std::cout << "Ending my turn." << std::endl;

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

//<<-- Creer-Merge: methods -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
// You can add additional methods here for your AI to call
//<<-- /Creer-Merge: methods -->>

} // saloon

} // cpp_client

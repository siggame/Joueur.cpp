// AI
// This is where you build your AI

#include "ai.hpp"

// <<-- Creer-Merge: includes -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
// You can add #includes here for your AI.
#include <math.h>
// <<-- /Creer-Merge: includes -->>

namespace cpp_client
{

namespace stardash
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
    return "Stardash C++ Player";
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
  // <<-- /Creer-Merge: runTurn -->>

  // Gets the coordinates of your home base (planet)
  double home_x = this->player->home_base->x;
  double home_y = this->player->home_base->y;
  // grabs the sun
  const Body sun = this->game->bodies[2];
  // Checks if we have any units.
  if(this->player->units.size()) {
    // If we don't have any units, spawn a miner.
    this->player->home_base->spawn(home_x, home_y, "miner");
  }

  // Gets the first unit in our list of units.
  const Unit unit = this->player->units[0];

  // If the miner is below 50% energy, goes back to its home base to heal.
  if(unit->energy < 0.5 * unit->job->energy) {
    this->find_dash(unit, home_x, home_y);
  }

  // If there is space in our inventory, go mine an asteroid for genarium (the worst mineral btw).
  else if(unit->genarium < unit->job->carry_limit) {

    Body target = nullptr;
    int best_dist = 9999;

    // Finds the closest asteroid that contains genarium to target.
    for(unsigned int i = 0; i < this->game->bodies.size(); i++) {
      // Only looks at asteroids that contain genarium.
      if(this->game->bodies[i]->material_type == "genarium") {
        // Gets the distance from the unit to the body
        double dist = this->distance(unit->x, unit->y, this->game->bodies[i]->x, this->game->bodies[i]->y);

        // Updates the target if the new asteroid is closer to our unit.
        if (dist < best_dist) {
          target = this->game->bodies[i];
          best_dist = dist;
        }
      }
    }
    if(target != nullptr) {
      // Tries to move to the asteroid.
      this->find_dash(unit, target->x, target->y);

      // Checks if the miner is within mining range of the target asteroid.
      if(distance(unit->x, unit->y, target->x, target->y) < unit->job->range) {
        unit->mine(target);
      }
    }
  }
  else {
    // Otherwise return to home base and drop off any mined genarium and restoring energy in the process.
    this->find_dash(unit, home_x, home_y);
  }

  return true;
}

//<<-- Creer-Merge: methods -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
// You can add additional methods here for your AI to call

/*
Args:
  x1 (int): The x coordinate of the first point.
  y1 (int): The y coordinate of the first point.
  x2 (int): The x coordinate of the second point.
  y2 (int): The y coordinate of the second point.
Returns:
  float: The distance between the two points.
*/
double AI::distance(double const& x1, double const& x2, double const& y1, double const& y2) {
  return (sqrt(pow(x2-x1,2)+pow(y2-y1,2)));
}
/*
This is an EXTREMELY basic pathfinding function to move your ship until it can dash to your target.
You REALLY should improve this functionality or make your own new one, since this is VERY basic and inefficient.
Args:
    unit (unit): The unit that will be moving.
    x (int): The x coordinate of the destination.
    y (int): The y coordinate of the destination.
*/
void AI::find_dash(const Unit unit, double const& x, double const& y) {
  Body sun = this->game->bodies[2];

  while(unit->moves >= 1) {
    if(unit->safe(x, y) && unit->energy >= ceil((distance(unit->x, unit->y, x, y) / this->game->dash_distance) * this->game->dash_cost)) {
      // Dashes if it is safe to dash to the point and we have enough energy to dash there.
      unit->dash(x, y);
      // Breaks out of the loop since we can't do anything else now.
      break;
    }
    // Otherwise tries moving towards the target.
    else {
      // The x and y modifiers for movement.
      double x_mod = 0;
      double y_mod = 0;

      if(unit->x < x || (((y < sun->y && unit->y > sun->y) || (y > sun->y && unit->y < sun->y)) && x > sun->x)) {
        // Move to the right if the destination is to the right or on the other side of the sun on the right side.
        x_mod = 1;
      }
      else if(unit->x > x || (((y < sun->y && unit->y > sun->y) || (y > sun->y && unit->y < sun->y)) && x < sun->x)) {
        // Move to the left if the destination is to the left or on the other side of the sun on the left side.
        x_mod = -1;
      }
      if(unit->y < y || (((x < sun->x && unit->x > sun->x) || (x > sun->x && unit->x < sun->x)) && y > sun->y)) {
        // Move down if the destination is down or on the other side of the sun on the lower side.
        y_mod = 1;
      }
      else if(unit->y > y || (((x < sun->x && unit->x > sun->x) || (x > sun->x && unit->x < sun->x)) && y < sun->y)) {
        // Move up if the destination is up or on the other side of the sun on the upper side.
        y_mod = -1;
      }
      if(x_mod != 0 && y_mod != 0 && ! unit->safe(unit->x + x_mod, unit->y + y_mod)) {
        // Special case if we cannot safely move diagonally.
        if(unit->safe(unit->x + x_mod, unit->y)) {
          // Only move horizontally if it is safe.
          y_mod = 0;
        }
        else if(unit->safe(unit->x, unit->y + y_mod)) {
          // Only move vertically if it is safe.
          x_mod = 0;
        }
      }
      if(unit->moves < sqrt(2) && x_mod != 0 && y_mod != 0) {
        // Special case if we only have 1 move left and are trying to move 2.
        if(unit->safe(unit->x + x_mod, unit->y)) {
          y_mod = 0;
        }
        else if(unit->safe(unit->x, unit->y + y_mod)) {
          x_mod = 0;
        }
        else {
          break;
        }
      }
      if((x_mod != 0 || y_mod != 0) && (sqrt(pow(x_mod, 2) + pow(y_mod, 2)) >= unit->moves)) {
        // Tries to move if either of the modifiers is ! zero (we are actually moving somewhere).
        unit->move(unit->x + x_mod, unit->y + y_mod);
      }
      else {
        // Breaks otherwise, since something probably went wrong.
        break;
      }
    }
  }

  return;
}
//<<-- /Creer-Merge: methods -->>

} // stardash

} // cpp_client

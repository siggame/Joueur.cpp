#ifndef GAMES_CATASTROPHE_GAME_H
#define GAMES_CATASTROPHE_GAME_H

// Game
// Convert as many humans to as you can to survive in this post-apocalyptic wasteland.

// DO NOT MODIFY THIS FILE
// Never try to directly create an instance of this class, or modify its member variables.
// Instead, you should only be reading its variables and calling its functions.

#include <vector>
#include <queue>
#include <deque>
#include <unordered_map>
#include <string>
#include <initializer_list>

#include "../../joueur/src/any.hpp"


#include "../../joueur/src/base_game.hpp"
#include "impl/catastrophe_fwd.hpp"

// <<-- Creer-Merge: includes -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
// you can add additional #includes here
// <<-- /Creer-Merge: includes -->>

namespace cpp_client
{

/// <summary>
/// Convert as many humans to as you can to survive in this post-apocalyptic wasteland.
/// </summary>
namespace catastrophe
{

/// <summary>
/// Convert as many humans to as you can to survive in this post-apocalyptic wasteland.
/// </summary>
class Game_ : public Base_game
{
public:

    /// <summary>
    /// The multiplier for the amount of energy regenerated when resting in a shelter with the cat overlord.
    /// </summary>
    const double& cat_energy_mult;

    /// <summary>
    /// The player whose turn it is currently. That player can send commands. Other players cannot.
    /// </summary>
    const Player& current_player;

    /// <summary>
    /// The current turn number, starting at 0 for the first player's turn.
    /// </summary>
    const int& current_turn;

    /// <summary>
    /// A mapping of every game object's ID to the actual game object. Primarily used by the server and client to easily refer to the game objects via ID.
    /// </summary>
    const std::unordered_map<std::string, Game_object>& game_objects;

    /// <summary>
    /// The amount of turns it takes for a Tile that was just harvested to grow food again.
    /// </summary>
    const int& harvest_cooldown;

    /// <summary>
    /// All the Jobs that Units can have in the game.
    /// </summary>
    const std::vector<Job>& jobs;

    /// <summary>
    /// The amount that the harvest rate is lowered each season.
    /// </summary>
    const int& lower_harvest_amount;

    /// <summary>
    /// The number of Tiles in the map along the y (vertical) axis.
    /// </summary>
    const int& map_height;

    /// <summary>
    /// The number of Tiles in the map along the x (horizontal) axis.
    /// </summary>
    const int& map_width;

    /// <summary>
    /// The maximum number of turns before the game will automatically end.
    /// </summary>
    const int& max_turns;

    /// <summary>
    /// The multiplier for the cost of actions when performing them in range of a monument. Does not effect pickup cost.
    /// </summary>
    const double& monument_cost_mult;

    /// <summary>
    /// The number of materials in a monument.
    /// </summary>
    const int& monument_materials;

    /// <summary>
    /// The number of materials in a neutral Structure.
    /// </summary>
    const int& neutral_materials;

    /// <summary>
    /// List of all the players in the game.
    /// </summary>
    const std::vector<Player>& players;

    /// <summary>
    /// A unique identifier for the game instance that is being played.
    /// </summary>
    const std::string& session;

    /// <summary>
    /// The number of materials in a shelter.
    /// </summary>
    const int& shelter_materials;

    /// <summary>
    /// The amount of food Players start with.
    /// </summary>
    const int& starting_food;

    /// <summary>
    /// The multiplier for the amount of energy regenerated when resting while starving.
    /// </summary>
    const double& starving_energy_mult;

    /// <summary>
    /// Every Structure in the game.
    /// </summary>
    const std::vector<Structure>& structures;

    /// <summary>
    /// All the tiles in the map, stored in Row-major order. Use `x + y * mapWidth` to access the correct index.
    /// </summary>
    const std::vector<Tile>& tiles;

    /// <summary>
    /// The amount of time (in nano-seconds) added after each player performs a turn.
    /// </summary>
    const int& time_added_per_turn;

    /// <summary>
    /// After a food tile is harvested, the number of turns before it can be harvested again.
    /// </summary>
    const int& turns_between_harvests;

    /// <summary>
    /// The number of turns between fresh humans being spawned on the road.
    /// </summary>
    const int& turns_to_create_human;

    /// <summary>
    /// The number of turns before the harvest rate is lowered (length of each season basically).
    /// </summary>
    const int& turns_to_lower_harvest;

    /// <summary>
    /// Every Unit in the game.
    /// </summary>
    const std::vector<Unit>& units;

    /// <summary>
    /// The number of materials in a wall.
    /// </summary>
    const int& wall_materials;

    // <<-- Creer-Merge: member variables -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
    // You can add additional member variables here. None of them will be tracked or updated by the server.
    // <<-- /Creer-Merge: member variables -->>


    /// <summary>
    /// Gets the Tile at a specified (x, y) position
    /// </summary>
    /// <param name="x">integer between 0 and the mapWidth</param>
    /// <param name="y">integer between 0 and the mapHeight</param>
    /// <returns>the Tile at (x, y) or null if out of bounds
    Tile get_tile_at(const int x, const int y);

   // <<-- Creer-Merge: methods -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
   // You can add additional methods here.
   // <<-- /Creer-Merge: methods -->>

   ~Game_();

   // ####################
   // Don't edit these!
   // ####################
   /// \cond FALSE
   Game_(std::initializer_list<std::pair<std::string, Any&&>> init);
   Game_() : Game_({}){}
   virtual void resize(const std::string& name, std::size_t size) override;
   virtual void change_vec_values(const std::string& name, std::vector<std::pair<std::size_t, Any>>& values) override;
   virtual void remove_key(const std::string& name, Any& key) override;
   virtual std::unique_ptr<Any> add_key_value(const std::string& name, Any& key, Any& value) override;
   virtual bool is_map(const std::string& name) override;
   virtual void rebind_by_name(Any* to_change, const std::string& member, std::shared_ptr<Base_object> ref) override;
    /// \endcond
    // ####################
    // Don't edit these!
    // ####################
};

} // catastrophe

} // cpp_client

#endif // GAMES_CATASTROPHE_GAME_H

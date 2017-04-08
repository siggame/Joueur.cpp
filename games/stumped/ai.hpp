#ifndef GAMES_STUMPED_AI_HPP
#define GAMES_STUMPED_AI_HPP

#include "impl/stumped.hpp"
#include "game.hpp"
#include "beaver.hpp"
#include "game_object.hpp"
#include "job.hpp"
#include "player.hpp"
#include "spawner.hpp"
#include "tile.hpp"

#include <algorithm>
#include <random>
#include <string>

#include "../../joueur/src/base_ai.hpp"
#include "../../joueur/src/attr_wrapper.hpp"

// You can add additional #includes here

namespace cpp_client
{

namespace stumped
{

/// <summary>
/// This is the header file for building your Stumped AI
/// </summary>
class AI : public Base_ai
{
public:
    /// <summary>
    /// This is a reference to the Game object itself, it contains all the information about the current game
    /// </summary>
    Game game;

    /// <summary>
    /// This is a pointer to your AI's player. This AI class is not a player, but it should command this Player.
    /// </summary>
    Player player;

    // You can add additional class variables here.

    // This is a better random number generator than rand() you probably learned
    std::mt19937 gen;

    // used for ShellAI, feel free to remove if you gut that code
    std::vector<std::string> actions = {"buildLodge", "attack", "pickup", "drop", "harvest"};

    /// <summary>
    /// This returns your AI's name to the game server.
    /// Replace the string name.
    /// </summary>
    /// <returns>The name of your AI.</returns>
    virtual std::string get_name() const override;

    /// <summary>
    /// This is automatically called when the game first starts, once the game objects are created
    /// </summary>
    virtual void start() override;

    /// <summary>
    /// This is automatically called when the game ends.
    /// </summary>
    /// <param name="won">true if you won, false otherwise</param>
    /// <param name="reason">An explanation for why you either won or lost</param>
    virtual void ended(bool won, const std::string& reason) override;

    /// <summary>
    /// This is automatically called the game (or anything in it) updates
    /// </summary>
    virtual void game_updated() override;

    /// <summary>
    /// This is called every time it is this AI.player's turn.
    /// </summary>
    /// <returns>Represents if you want to end your turn. True means end your turn, False means to keep your turn going and re-call this function.</returns>
    bool run_turn();

    // You can add additional methods here.

/// A very basic path finding algorithm (Breadth First Search) that when given a starting Tile, will return a valid path to the goal Tile.
/// <param name="start">the starting Tile</param>
/// <param name="goal">the goal Tile</param>
/// <return>A List of Tiles representing the path, the the first element being a valid adjacent Tile to the start, and the last element being the goal. Or an empty list if no path found.</return>
std::vector<Tile> find_path(const Tile& start, const Tile& goal);

    template<class Item>
    Item random_element(std::vector<Item> container);

    // ####################
    // Don't edit these!
    // ####################
    /// \cond FALSE
    virtual std::string invoke_by_name(const std::string& name,
                                       const std::unordered_map<std::string, Any>& args) override;
    virtual void set_game(Base_game* ptr) override;
    virtual void set_player(std::shared_ptr<Base_object> obj) override;
    virtual void print_win_loss_info() override;
    /// \endcond
    // ####################
    // Don't edit these!
    // ####################

};

} // STUMPED

} // cpp_client

#endif // GAMES_STUMPED_AI_HPP

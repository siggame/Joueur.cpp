#ifndef GAMES_SPIDERS_GAME_H
#define GAMES_SPIDERS_GAME_H

// Game
// There's an infestation of enemy spiders challenging your queen BroodMother spider! Protect her and attack the other BroodMother in this turn based, node based, game.

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
#include "impl/spiders_fwd.hpp"

// <<-- Creer-Merge: includes -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
// you can add additional #includes here
// <<-- /Creer-Merge: includes -->>

namespace cpp_client
{

/// <summary>
/// There's an infestation of enemy spiders challenging your queen BroodMother spider! Protect her and attack the other BroodMother in this turn based, node based, game.
/// </summary>
namespace spiders
{

/// <summary>
/// There's an infestation of enemy spiders challenging your queen BroodMother spider! Protect her and attack the other BroodMother in this turn based, node based, game.
/// </summary>
class Game_ : public Base_game
{
public:

    /// <summary>
    /// The player whose turn it is currently. That player can send commands. Other players cannot.
    /// </summary>
    const Player& current_player;

    /// <summary>
    /// The current turn number, starting at 0 for the first player's turn.
    /// </summary>
    const int& current_turn;

    /// <summary>
    /// The speed at which Cutters work to do cut Webs.
    /// </summary>
    const int& cut_speed;

    /// <summary>
    /// Constant used to calculate how many eggs BroodMothers get on their owner's turns.
    /// </summary>
    const double& eggs_scalar;

    /// <summary>
    /// A mapping of every game object's ID to the actual game object. Primarily used by the server and client to easily refer to the game objects via ID.
    /// </summary>
    const std::unordered_map<std::string, Game_object>& game_objects;

    /// <summary>
    /// The starting strength for Webs.
    /// </summary>
    const int& initial_web_strength;

    /// <summary>
    /// The maximum number of turns before the game will automatically end.
    /// </summary>
    const int& max_turns;

    /// <summary>
    /// The maximum strength a web can be strengthened to.
    /// </summary>
    const int& max_web_strength;

    /// <summary>
    /// The speed at which Spiderlings move on Webs.
    /// </summary>
    const int& movement_speed;

    /// <summary>
    /// Every Nest in the game.
    /// </summary>
    const std::vector<Nest>& nests;

    /// <summary>
    /// List of all the players in the game.
    /// </summary>
    const std::vector<Player>& players;

    /// <summary>
    /// A unique identifier for the game instance that is being played.
    /// </summary>
    const std::string& session;

    /// <summary>
    /// The speed at which Spitters work to spit new Webs.
    /// </summary>
    const int& spit_speed;

    /// <summary>
    /// The amount of time (in nano-seconds) added after each player performs a turn.
    /// </summary>
    const int& time_added_per_turn;

    /// <summary>
    /// How much web strength is added or removed from Webs when they are weaved.
    /// </summary>
    const int& weave_power;

    /// <summary>
    /// The speed at which Weavers work to do strengthens and weakens on Webs.
    /// </summary>
    const int& weave_speed;

    /// <summary>
    /// Every Web in the game.
    /// </summary>
    const std::vector<Web>& webs;

    // <<-- Creer-Merge: member variables -->> - Code you add between this comment and the end comment will be preserved between Creer re-runs.
    // You can add additional member variables here. None of them will be tracked or updated by the server.
    // <<-- /Creer-Merge: member variables -->>



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

} // spiders

} // cpp_client

#endif // GAMES_SPIDERS_GAME_H

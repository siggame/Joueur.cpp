#ifndef GAMES_CHESS_GAME_H
#define GAMES_CHESS_GAME_H

// Game
// The traditional 8x8 chess board with pieces.

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
#include "impl/chess_fwd.hpp"

// you can add additional #includes here

namespace cpp_client
{

/// <summary>
/// The traditional 8x8 chess board with pieces.
/// </summary>
namespace chess
{

/// <summary>
/// The traditional 8x8 chess board with pieces.
/// </summary>
class Game_ : public Base_game
{
public:

    /// <summary>
    /// Forsyth-Edwards Notation (fen), a notation that describes the game board state.
    /// </summary>
    const std::string& fen;

    /// <summary>
    /// A mapping of every game object's ID to the actual game object. Primarily used by the server and client to easily refer to the game objects via ID.
    /// </summary>
    const std::unordered_map<std::string, Game_object>& game_objects;

    /// <summary>
    /// The list of [known] moves that have occured in the game, in Standard Algebriac Notation (SAN) format. The first element is the first move, with the last being the most recent.
    /// </summary>
    const std::vector<std::string>& history;

    /// <summary>
    /// List of all the players in the game.
    /// </summary>
    const std::vector<Player>& players;

    /// <summary>
    /// A unique identifier for the game instance that is being played.
    /// </summary>
    const std::string& session;

    // You can add additional member variables here. None of them will be tracked or updated by the server.



   // You can add additional methods here.

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

} // chess

} // cpp_client

#endif // GAMES_CHESS_GAME_H

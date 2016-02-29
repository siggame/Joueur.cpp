#ifndef BASE_GAME_HPP
#define BASE_GAME_HPP

#include <memory>

namespace cpp_client
{

class Base_ai;

class Base_game
{
public:
   //generate the AI to be used for the game
   virtual std::unique_ptr<Base_ai> create_ai() const = 0;
   virtual ~Base_game() = default;
};

} // cpp_client

#endif // BASE_GAME_HPP

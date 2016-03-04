#ifndef GAMES_${underscore(game_name).upper()}_HPP
#define GAMES_${underscore(game_name).upper()}_HPP

// ${header}

#include "../../joueur/src/base_game.hpp"
#include "ai.hpp"

namespace cpp_client
{

namespace ${underscore(game_name)}
{

class ${underscore(game_name).capitalize()} : public Base_game
{
public:
   virtual std::string get_game_name() const noexcept override { return "${underscore(game_name).capitalize()}"; }
   virtual std::unique_ptr<Base_ai> generate_ai() override;
};

} // ${underscore(game_name)}

} // cpp_client

#endif // GAMES_${underscore(game_name).upper()}_HPP

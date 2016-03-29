#ifndef GAMES_${underscore(game_name).upper()}_HPP
#define GAMES_${underscore(game_name).upper()}_HPP

// ${header}

#include "../../joueur/src/base_game.hpp"
#include "ai.hpp"

// This feels bad, but it should work
#include "game.hpp"

namespace cpp_client
{

namespace ${underscore(game_name)}
{

class ${underscore(game_name).capitalize()} : public Game_
{
public:
   ${underscore(game_name).capitalize()}() :
      Game_{} {}
   virtual std::string get_game_name() const noexcept override { return "${underscore(game_name).capitalize()}"; }
   virtual std::unique_ptr<Base_ai> generate_ai() override;
   virtual std::shared_ptr<Base_object> generate_object(const std::string& type) override;
   virtual std::unordered_map<std::string, std::shared_ptr<Base_object>>& get_objects() override
   {
      return game_objects;
   }
};

} // ${underscore(game_name)}

} // cpp_client

#endif // GAMES_${underscore(game_name).upper()}_HPP

#include "base_game.hpp"
#include "base_ai.hpp"

namespace cpp_client
{

Base_game::~Base_game() = default;

void Base_game::go()
{
   ai_ = generate_ai();
   //start with the same thing each time
   std::string to_send = R"({"event": "play", "data": {"clientType": "c++", "playerIndex": )";
   //now fill in the details
   if(player_index_ == -1)
   {
      to_send += "null,";
   }
   else
   {
      to_send += std::to_string(player_index_) + ",";
   }
   const auto add_standard_str = [&to_send](const std::string& name, const std::string& to_add)
      {
         to_send += "\"" + name + "\":";
         if(to_add == "")
         {
            to_send += "null,";
         }
         else
         {
            to_send += "\"" + to_add + "\",";
         }
      };
   add_standard_str("password", password_);
   add_standard_str("requestedSession", session_);
   add_standard_str("gameSettings", game_settings_);
   to_send += R"("playerName":")";
   if(name_ == "")
   {
      //just make a temporary ai to get the name
      to_send += ai_->get_name();
   }
   else
   {
      to_send += name_;
   }
   to_send += R"(","gameName":")" + get_game_name() + R"("}})";
   conn_.send(to_send);
   auto resp = conn_.recieve();
   auto resp2 = conn_.recieve();
}

} // cpp_client

#include "base_game.hpp"
#include "base_ai.hpp"

#include "delta.hpp"
#include "attr_wrapper.hpp"
#include "rapidjson/document.h"

namespace cpp_client
{

Base_game::~Base_game() = default;

void Base_game::go()
{
   ai_ = generate_ai();
   //grab the name first
   std::string alias = R"({"event": "alias", "data": ")" + get_game_name() + "\"}";
   conn_.send(alias);
   auto resp = conn_.recieve();
   rapidjson::Document doc;
   doc.Parse(resp.c_str());
   std::string game_name = attr_wrapper::get_attribute<std::string>(doc, "data");
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
      to_send += ai_->get_name();
   }
   else
   {
      to_send += name_;
   }
   to_send += R"(","gameName":")" + game_name + R"("}})";
   conn_.send(to_send);
   //Expecting the "lobbied" message
   handle_response("lobbied");
   //Next the delta message will be received
   handle_response("delta");
   //Start should be next
   handle_response("start");
   //now just do normal handling of events
   while(handle_response())
   {
      //Intentionally empty
   }
}

Any Base_game::handle_response(const std::string& expected)
{
   //static for when returning rapidjson values
   static std::string resp;
   static std::unique_ptr<rapidjson::Document> doc_raw;
   doc_raw.reset(new rapidjson::Document);
   //first get the response
   resp = conn_.recieve();
   //now parse it
   auto& doc = *doc_raw;
   doc.Parse(resp.c_str());
   const auto event = attr_wrapper::get_attribute<std::string>(doc, "event");
   //check if it matches the expected (if needed)
   if(expected != "" && event != expected)
   {
      throw Bad_response("Expected " + expected + " event; got " + event);
   }
   //now just handle the different possible events
   if(event == "lobbied")
   {
      const auto& data = attr_wrapper::get_loc(doc, "data")->value;
      const auto& constants = attr_wrapper::get_loc(data, "constants")->value;
      //extract game constants
      len_string_ = attr_wrapper::get_attribute<std::string>(constants, "DELTA_LIST_LENGTH");
      remove_string_ = attr_wrapper::get_attribute<std::string>(constants, "DELTA_REMOVED");
      //output the session information
      std::cout << sgr::text_cyan << "In lobby for game '"
                << attr_wrapper::get_attribute<std::string>(data, "gameName")
                << "' in session '"
                << attr_wrapper::get_attribute<std::string>(data, "gameSession") << "'."
                << sgr::reset << std::endl;
   }
   else if(event == "delta")
   {
      apply_delta(doc, *this);
   }
   else if(event == "start")
   {
      //set the AI's fields properly
      const auto& data = attr_wrapper::get_loc(doc, "data")->value;
      const auto id = attr_wrapper::get_attribute<std::string>(data, "playerID");
      ai_->set_game(this);
      ai_->set_player(get_objects()[id]);
      std::cout << sgr::text_green << "Game is starting." << sgr::reset << '\n';
      ai_->start();
   }
   else if(event == "over")
   {
      ai_->print_win_loss_info();
      //output URL info
      const auto& data = attr_wrapper::get_loc(doc, "data")->value;
      const auto url = attr_wrapper::get_attribute<std::string>(data, "visualizerURL");
      std::cout << sgr::text_cyan
                << "---\n"
                << "Your gamelog is viewable at:\n"
                << url
                << "\n---\n"
                << sgr::reset
                ;
      //exit!
      exit(0);
   }
   else if(event == "fatal")
   {
      const auto data = attr_wrapper::get_loc(doc, "data");
      std::cout << sgr::text_red << "Fatal: "
                << attr_wrapper::get_attribute<std::string>(data->value, "message") << '\n'
                << sgr::reset;
      return {};
   }
   else if(event == "order")
   {
      const auto& data = attr_wrapper::get_loc(doc, "data")->value;
      const auto name = attr_wrapper::get_attribute<std::string>(data, "name");
      const auto index = attr_wrapper::get_attribute<unsigned>(data, "index");
      //loop through all parameters and make a map out of them
      const auto& args = attr_wrapper::get_loc(data, "args");
      std::unordered_map<std::string, Any> params;
      //TODO: arguments for orders (apparently they are positional)
      //send finished event with data:
      //{"orderIndex":from_above, "returned":result}
      const std::string order_done =
         R"({"event":"finished","data":{"orderIndex":)" + std::to_string(index)
         + R"(,"returned":)" + ai_->invoke_by_name(name, params) + "}}";
      conn_.send(order_done);
   }
   else if(event == "ran")
   {
      return Any{static_cast<rapidjson::Document*>(&doc)};
   }
   else if(event == "invalid")
   {
      //just print out an error message
      const auto data = attr_wrapper::get_loc(doc, "data");
      std::cout << sgr::text_yellow << "Invalid: "
                << attr_wrapper::get_attribute<std::string>(data->value, "message") << '\n'
                << sgr::reset;
   }
   //just some dummy value to indicate that this isn't done yet
   return Any{true};
}

} // cpp_client

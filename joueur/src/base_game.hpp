#ifndef BASE_GAME_HPP
#define BASE_GAME_HPP

#include "connection.hpp"
#include "base_object.hpp"
#include "delta_mergable.hpp"

#include <memory>
#include <string>
#include <unordered_map>
#include <string>

namespace cpp_client
{

class Base_ai;

class Base_game : public Delta_mergable
{
public:
   Base_game() :
      Delta_mergable({})
   {
      ;
   }

   using Delta_mergable::Delta_mergable;

   //generate the AI to be used for the game
   virtual ~Base_game();

   //sets if communication should be printed
   void set_print_communication(bool should_print) noexcept
   {
      conn_.set_print_communication(should_print);
   }

   //connect to the server on the specified port
   //will throw if an error occurs
   void connect(const char* server_url, unsigned port_num)
   {
      conn_.connect(server_url, port_num);
   }

   //start playing the game once connected and initial options are set
   void go();

   //few setters here (for initial options)
   //set to -1 for no prefered index
   void set_player_index(int index) noexcept
   {
      player_index_ = index;
   }

   void set_password(std::string password) noexcept
   {
      password_ = std::move(password);
   }

   void set_session(std::string session) noexcept
   {
      session_ = std::move(session);
   }

   void set_name(std::string name) noexcept
   {
      name_ = std::move(name);
   }

   void set_settings(std::string settings) noexcept
   {
      game_settings_ = std::move(settings);
   }

   //this makes some assumptions that should always be true, so it should be fine
   virtual std::unordered_map<std::string, std::shared_ptr<Base_object>>& get_objects() = 0;

   const std::string& len_string() const noexcept { return len_string_; }
   const std::string& remove_string() const noexcept { return remove_string_; }

   //create an object through a name
   virtual std::shared_ptr<Base_object> generate_object(const std::string& type) = 0;

protected:
   //return the name of the game
   virtual std::string get_game_name() const = 0;

   //return an ai to play the game
   virtual std::unique_ptr<Base_ai> generate_ai() = 0;

   //string constants
   //TODO: Actually load these
   std::string len_string_{"&LEN"};
   std::string remove_string_{"&RM"};

private:
   Connection conn_;

   int player_index_;
   std::string password_;
   std::string session_;
   std::string name_;
   std::string game_settings_;

   //the AI object
   std::unique_ptr<Base_ai> ai_;
};

} // cpp_client

#endif // BASE_GAME_HPP

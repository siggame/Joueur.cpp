#include "netLink.h"
#include "tclap/CmdLine.h"
#include "attr_wrapper.hpp"
#include "register.hpp"
#include "sgr.hpp"

#include <exception>
#include <iostream>

int main(int argc, const char* argv[])
{
   try
   {
      //need to do this for Windows
      #ifdef WIN32
         netLink::init();
      #endif // WIN32
      TCLAP::CmdLine cmd("Runs the C++ client.  Game name must be provided.");
      TCLAP::ValueArg<std::string> string_args[] =
      {
         {
            "s",
            "server",
            "The url to the server you want to connect to (e.g., localhost)",
            false,
            "localhost",
            "server URL"
         },
         {
            "n",
            "name",
            "The name you want to use as your AI's player name. "
               "This overrides the name you set in your code.",
            false,
            "",
            "string"
         },
         {
            "w",
            "password",
            "The password required for authentication on official servers.",
            false,
            "",
            "string"
         },
         {
            "",
            "gameSettings",
            "Any settings for the game server to force. "
               "Must be url params formatted (key=value&otherKey=otherValue)",
            false,
            "",
            "string"
         },
         {
            "r",
            "session",
            "The requested game session you want to play on the server",
            false,
            "*",
            "string"
         }
      };
      //enum for accessing string options
      enum
      {
         server,
         player_name,
         password,
         settings,
         session
      };
      TCLAP::ValueArg<int> int_args[] =
      {
         {
            "p",
            "port",
            "The port to connect to on the server.",
            false,
            3000,
            "port number"
         },
         {
            "i",
            "index",
            "The player number you want to be, with 0 being the first player.",
            false,
            -1,
            "player index"
         }
      };
      enum
      {
         port,
         player_index,
      };
      //game argument
      TCLAP::UnlabeledValueArg<std::string>
         game_arg("game", "The name of the game you want to play on the server.", true, "", "Game");
      cmd.add(game_arg);
      //debug flag
      TCLAP::SwitchArg
         print_io("", "printIO", "(debugging) Print IO through the TCP socket to stdout.", false);
      cmd.add(print_io);
      //add each option
      for(auto i = 0u; i < sizeof(string_args) / sizeof(string_args[0]); ++i)
      {
         cmd.add(string_args[i]);
      }
      for(auto i = 0u; i < sizeof(int_args) / sizeof(int_args[0]); ++i)
      {
         cmd.add(int_args[i]);
      }
      cmd.parse(argc, argv);
   }
   catch(const std::exception& e)
   {
      std::cerr << sgr::text_red << "An error occured:\n" << e.what() << sgr::reset << std::endl;
      return 1;
   }
   catch(...)
   {
      std::cerr << sgr::text_red << "An unknown error occured." << sgr::reset << std::endl;
      return 2;
   }
}

#include "connection.hpp"
#include "netLink.h"
#include "exceptions.hpp"
#include "sgr.hpp"

#include <array>
#include <iostream>
#include <chrono>
#include <thread>

namespace cpp_client
{

class Connection_internal
{
public:
   Connection_internal() :
      sock_(),
      buffer_()
   {
      //need to do this for Windows
      #ifdef WIN32
         static bool need_to_init = true;
         if(need_to_init)
         {
            need_to_init = false;
            netLink::init();
         }
      #endif // WIN32
   }

   void connect(const char* host, unsigned port)
   {
      try
      {
         sock_.initAsTcpClient(host, port, true);
      }
      catch(const netLink::Exception& e)
      {
         convert_exception(e);
      }
   }

   void send(const std::string& msg)
   {
      try
      {
         sock_.send(msg.c_str(), msg.length());
      }
      catch(const netLink::Exception& e)
      {
         convert_exception(e);
      }
   }

   std::string recieve()
   {
      std::array<char, 2048> read_buffer;
      std::string to_return;
      to_return.reserve(read_buffer.size());
      //put anything left over into the message to start
      to_return += buffer_;
      try
      {
         auto split_point = to_return.find('\x04');
         while(split_point == std::string::npos)
         {
            const auto recieved = sock_.receive(read_buffer.data(), read_buffer.size());
            to_return.append(read_buffer.data(), recieved);
            split_point = to_return.find('\x04');
            // don't use 100% CPU [setting blocking mode didn't work properly]
            std::this_thread::sleep_for(std::chrono::microseconds(100));
         }
         //now split by the 0x04
         buffer_ = to_return.substr(split_point + 1);
         to_return = to_return.substr(0, split_point);
      }
      catch(const netLink::Exception& e)
      {
         convert_exception(e);
      }
      return to_return;
   }

private:
   //convert netLink's exceptions to something sane
   void convert_exception(const netLink::Exception& e)
   {
      using namespace netLink;
      switch(e.code)
      {
      case Exception::ERROR_IOCTL:
         throw Communication_error("IOCTL error.");
         break;

      case Exception::ERROR_SELECT:
         throw Communication_error("Selection error.");
         break;

      case Exception::ERROR_SET_SOCK_OPT:
         throw Communication_error("Error selection socket operation.");
         break;

      case Exception::ERROR_GET_SOCK_NAME:
         throw Communication_error("Error getting socket name.");
         break;

      case Exception::ERROR_RESOLVING_ADDRESS:
         throw Communication_error("Error resolving address.");
         break;

      case Exception::ERROR_READ:
         throw Communication_error("Error reading from socket.");
         break;

      case Exception::ERROR_SEND:
         throw Communication_error("Error sending on the socket.");
         break;

      case Exception::ERROR_INIT:
         throw Communication_error("Error during initialization - could not connect to server.");
         break;

      case Exception::BAD_PROTOCOL:
         throw Communication_error("Bad protocol error.");
         break;

      case Exception::BAD_TYPE:
         throw Communication_error("Bad type error.");
         break;

      default:
         throw Communication_error("Unknown communication error.");
         break;
      }
   }

   netLink::Socket sock_;
   std::string buffer_;
};

std::string Connection::recieve()
{
   auto msg = conn_->recieve();
   if(print_communication_)
   {
      std::cout << sgr::text_magenta << "FROM SERVER <-- " << msg << sgr::reset << '\n';
   }
   return msg;
}

void Connection::send(const std::string& msg)
{
   using namespace std::chrono;
   const auto time = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
   if(print_communication_)
   {
      std::cout << sgr::text_magenta
                << "TO SERVER --> "
                << msg.substr(0, msg.size() - 1)
                << ", \"sentTime\": "
                << time << "}"
                << sgr::reset
                << '\n';
   }
   //cut out the last } and append the time sent
   conn_->send(msg.substr(0, msg.size() - 1));
   conn_->send(R"(, "sentTime": )" + std::to_string(time) + "}\x04");
}

void Connection::connect(const char* host, unsigned port, bool print)
{
   if(print)
   {
      std::cout << sgr::text_cyan << "Connecting to: " << host << ":" << port << '\n' << sgr::reset;
   }
   conn_->connect(host, port);
}

Connection::Connection(bool print_communication) :
   conn_(new Connection_internal),
   print_communication_(print_communication) {}


Connection::Connection(Connection&&) = default;
Connection& Connection::operator=(Connection&&) = default;
Connection::~Connection() = default;

} // cpp_client

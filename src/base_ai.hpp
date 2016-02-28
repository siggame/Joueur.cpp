#ifndef BASE_AI_HPP
#define BASE_AI_HPP

#include <string>

namespace cpp_client
{

class Base_ai
{
public:
   virtual std::string get_name() const = 0;
   virtual void start() = 0;
   virtual void end(bool won, const std::string& reason) = 0;
   virtual void invalid(const std::string& message);
   virtual void game_updated() = 0;

   virtual ~Base_ai() = default;
};

} // cpp_client

#endif // BASE_AI_HPP

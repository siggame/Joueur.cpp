#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

#include <stdexcept>

namespace cpp_client
{

class Game_not_found : public std::range_error
{
   using std::range_error::range_error;
};

class Communication_error : public std::runtime_error
{
   using std::runtime_error::runtime_error;
};

} // cpp_client


#endif // EXCEPTIONS_HPP

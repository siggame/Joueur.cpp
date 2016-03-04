#ifndef BASE_OBJECT_HPP
#define BASE_OBJECT_HPP

#include <vector>
#include <string>
#include <unordered_map>
#include <initializer_list>

#include "any.hpp"

namespace cpp_client
{

class Base_object
{
public:
   virtual ~Base_object() = default;

protected:
   std::unordered_map<std::string, Any> variables_;
};

} // cpp_client

#endif // BASE_OBJECT_HPP

#ifndef BASE_OBJECT_HPP
#define BASE_OBJECT_HPP

#include <vector>
#include <string>
#include <unordered_map>
#include <initializer_list>
#include <utility>

#include "any.hpp"

namespace cpp_client
{

class Base_object
{
public:
   virtual ~Base_object() = default;
   Base_object(std::initializer_list<std::pair<std::string, Any&&>> init)
   {
      for(auto&& obj : init)
      {
         variables_.emplace(std::make_pair(std::move(obj.first), std::move(obj.second)));
      }
   }

protected:
   std::unordered_map<std::string, Any> variables_;
};

} // cpp_client

#endif // BASE_OBJECT_HPP

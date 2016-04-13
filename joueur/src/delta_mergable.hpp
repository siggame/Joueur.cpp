#ifndef DELTA_MERGABLE_HPP
#define DELTA_MERGABLE_HPP

#include "any.hpp"
#include "exceptions.hpp"

#include <string>
#include <unordered_map>
#include <vector>

namespace cpp_client
{

class Delta_mergable
{
public:
   Delta_mergable(std::initializer_list<std::pair<std::string, Any&&>> init)
   {
      for(auto&& obj : init)
      {
         variables_.emplace(std::make_pair(std::move(obj.first), std::move(obj.second)));
      }
   }

   //erase a variable name
   void erase(const std::string& to_erase)
   {
      variables_.erase(to_erase);
   }

   //so other erasures can compile (should never happen, however)
   template<typename T>
   void erase(const T&)
   {
      throw Bad_manipulation("Non-string erase called on object.");
   }

   std::unordered_map<std::string, Any> variables_;

   //some things to allow doing stuff by name
   virtual void resize(const std::string& name, std::size_t size) = 0;
   virtual void change_vec_values(const std::string& name, std::vector<std::pair<std::size_t, Any>>& values) = 0;
   virtual void remove_key(const std::string& name, Any& key) = 0;
   virtual Any add_key_value(const std::string& name, Any& key, Any& value) = 0;
   virtual bool is_map(const std::string& name) = 0;
};

}

#endif // DELTA_MERGABLE_HPP

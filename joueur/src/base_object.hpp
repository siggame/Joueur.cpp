#ifndef BASE_OBJECT_HPP
#define BASE_OBJECT_HPP

#include <vector>
#include <string>
#include <unordered_map>
#include <initializer_list>
#include <utility>
#include <iostream>
#include <typeindex>

#include "any.hpp"
#include "sgr.hpp"
#include "delta_mergable.hpp"

namespace cpp_client
{

class Base_object : public Delta_mergable
{
public:
   using Delta_mergable::Delta_mergable;
   virtual ~Base_object() = default;
   Base_object() : Delta_mergable({}){}

   //Don't really like doing this, but I can't think of a better way
   virtual void resize(const std::string& name, std::size_t size) override {}
   virtual void change_vec_values(const std::string& name,
                                  std::vector<std::pair<std::size_t, Any>>& values) override {}
   virtual void remove_key(const std::string& name, Any& key) override {}
   virtual Any add_key_value(const std::string& name, Any& key, Any& value) override {}
   virtual bool is_map(const std::string& name) override {}
};

} // cpp_client

#endif // BASE_OBJECT_HPP

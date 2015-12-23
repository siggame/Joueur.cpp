// Author: Brian W Goldman
// This file allows C++ to do a minor form of function reflection
// using the idea of "registered functions". Allows you to add functions
// to the registry in files not included by the registry itself.
// You can then list and call all functions in the registry that were
// part of the linker step of the compiler.
//
// ============== Example Usage ==============
//
// In a header file included by all functions in the registry, you must
// put a call to CREATE_FUNCTION_REGISTRY, such as either of the following:
//
// CREATE_FUNCTION_REGISTRY(greeting_message, function<string()>)
// CREATE_FUNCTION_REGISTRY(math_operation, function<double(double, double)>)
//
// The first creates a registry of "greeing_message" functions which return a string
// and take no arguments. The second creates a registry of "math_operation"s
// that take in two doubles and returns a double. All registries should be function types.
//
// In any other source file you can put the following to add a function to the registry
//
// REGISTER_FUNCTION(greeting_message, standard, standard_greeting)
// REGISTER_FUNCTION(math_operation, multiply, [](int x, int y){ return x * y; })
//
// The first puts the "standard_greeting" function, which you have already declared,
// into the "greeting_message" registry, with the string name of "standard".
// The second puts the lambda function into the "math_operation" registry with
// the string name of "multiply"
//
// In any file that includes the header file that creates the registry,
// you can now do calls like:
//
// string message = function_registry::call_greeting_message("standard");
// double result = function_registry::call_math_operation("multiply", 7, 19);
//
// See the "example' directory for a more complete description.
//
// ============== Hard Requirements ==============
// Each registry must be uniquely named (should compiler error)
// Each registry's name must be a valid identifier (will error strangely)
// Each function in a registry must be uniquely named (should compiler error)
// Each function's name must be a valid identifier (will error strangely)
// Each REGISTER_FUNCTION macro should be compiled exactly once, meaning
//      that it should appear either in a cpp file or in a header included by
//      only one cpp file. This is necessary to ensure no duplicate registration.
#ifndef FUNCTION_REGISTRY
#define FUNCTION_REGISTRY

#include <unordered_map>
using std::string;
#include <functional>
using std::function;
#include <stdexcept>

#define CREATE_FUNCTION_REGISTRY(category, function_type)\
  using category=function_type;\
  namespace function_registry {\
    inline std::unordered_map<string, function_type>& category ## _registry() {\
      static std::unordered_map<string, function_type> result;\
      return result;\
    }\
    template <class T>\
    category& add_function_to_ ## category(const string name, const T& value) {\
      auto result = category ## _registry().find(name);\
      if (result == category ## _registry().end()) {\
        category ## _registry()[name] = category(value);\
      }\
      return category ## _registry()[name];\
    }\
    template <class... Args>\
    auto call_ ## category(string name, const Args&... args)\
         -> decltype(category ## _registry()[name](args...)) {\
      auto result = category ## _registry().find(name);\
      if (result == category ## _registry().end()) {\
        throw std::invalid_argument("Tried to use call_" +  string(#category)\
                                    + " to call unregistered function: \"" + name + "\"");\
      }\
      return result->second(args...);\
    }\
  }

#define REGISTER_FUNCTION(category, name, value)\
  namespace function_registry {\
    namespace category {\
      const auto ignore ## name=add_function_to_ ## category(#name, value);\
    }\
  }

#endif

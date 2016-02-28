#include "base_ai.hpp"
#include "sgr.hpp"

#include <iostream>

namespace cpp_client
{

void Base_ai::invalid(const std::string& message)
{
   std::cerr << sgr::text_yellow << "Invalid: " << message << sgr::reset << '\n';
}

} // cpp_client

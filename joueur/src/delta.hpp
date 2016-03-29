#ifndef DELTA_HPP
#define DELTA_HPP

#include "rapidjson/document.h"

namespace cpp_client
{

class Base_game;

void apply_delta(rapidjson::Value& delta, Base_game& apply_to);

} // cpp_client

#endif // DELTA_HPP

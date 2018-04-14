// DO NOT MODIFY THIS FILE
// Never try to directly create an instance of this class, or modify its member variables.
// This contains implementation details, written by code, and only useful to code



#include "../web.hpp"
#include "../../../joueur/src/base_ai.hpp"
#include "../../../joueur/src/any.hpp"
#include "../../../joueur/src/exceptions.hpp"
#include "../../../joueur/src/delta.hpp"
#include "../brood_mother.hpp"
#include "../cutter.hpp"
#include "../game_object.hpp"
#include "../nest.hpp"
#include "../player.hpp"
#include "../spider.hpp"
#include "../spiderling.hpp"
#include "../spitter.hpp"
#include "../weaver.hpp"
#include "../web.hpp"
#include "spiders.hpp"

#include <type_traits>

namespace cpp_client
{

namespace spiders
{


Web_::Web_(std::initializer_list<std::pair<std::string, Any&&>> init) :
    Game_object_{
        {"length", Any{std::decay<decltype(length)>::type{}}},
        {"load", Any{std::decay<decltype(load)>::type{}}},
        {"nestA", Any{std::decay<decltype(nest_a)>::type{}}},
        {"nestB", Any{std::decay<decltype(nest_b)>::type{}}},
        {"spiderlings", Any{std::decay<decltype(spiderlings)>::type{}}},
        {"strength", Any{std::decay<decltype(strength)>::type{}}},
    },
    length(variables_["length"].as<std::decay<decltype(length)>::type>()),
    load(variables_["load"].as<std::decay<decltype(load)>::type>()),
    nest_a(variables_["nestA"].as<std::decay<decltype(nest_a)>::type>()),
    nest_b(variables_["nestB"].as<std::decay<decltype(nest_b)>::type>()),
    spiderlings(variables_["spiderlings"].as<std::decay<decltype(spiderlings)>::type>()),
    strength(variables_["strength"].as<std::decay<decltype(strength)>::type>())
{
    for(auto&& obj : init)
    {
      variables_.emplace(std::make_pair(std::move(obj.first), std::move(obj.second)));
    }
}

Web_::~Web_() = default;

void Web_::resize(const std::string& name, std::size_t size)
{
    if(name == "spiderlings")
    {
        auto& vec = variables_["spiderlings"].as<std::decay<decltype(spiderlings)>::type>();
        vec.resize(size);
        return;
    }
    try
    {
        Game_object_::resize(name, size);
        return;
    }
    catch(...){}
    throw Bad_manipulation(name + " in Web treated as a vector, but it is not a vector.");
}

void Web_::change_vec_values(const std::string& name, std::vector<std::pair<std::size_t, Any>>& values)
{
    if(name == "spiderlings")
    {
        using type = std::decay<decltype(spiderlings)>::type;
        auto& vec = variables_["spiderlings"].as<type>();
        for(auto&& val : values)
        { 
            vec[val.first] = std::static_pointer_cast<type::value_type::element_type>(get_game()->get_objects()[val.second.as<std::string>()]);
        }
        return;
    } 
    try
    {
        Game_object_::change_vec_values(name, values);
        return;
    }
    catch(...){}
    throw Bad_manipulation(name + " in Web treated as a vector, but it is not a vector.");
}

void Web_::remove_key(const std::string& name, Any& key)
{
    try
    {
        Game_object_::remove_key(name, key);
        return;
    }
    catch(...){}
    throw Bad_manipulation(name + " in Web treated as a map, but it is not a map.");
}

std::unique_ptr<Any> Web_::add_key_value(const std::string& name, Any& key, Any& value)
{
    try
    {
        return Game_object_::add_key_value(name, key, value);
    }
    catch(...){}
    throw Bad_manipulation(name + " in Web treated as a map, but it is not a map.");
}

bool Web_::is_map(const std::string& name)
{
    try
    {
        return Game_object_::is_map(name);
    }
    catch(...){}
    return false;
}

void Web_::rebind_by_name(Any* to_change, const std::string& member, std::shared_ptr<Base_object> ref)
{
   if(member == "nestA")
   { 
      to_change->as<Nest>() = std::static_pointer_cast<Nest_>(ref);
      return;
   }
   if(member == "nestB")
   { 
      to_change->as<Nest>() = std::static_pointer_cast<Nest_>(ref);
      return;
   }
   try
   {
      Game_object_::rebind_by_name(to_change, member, ref);
      return;
   }
   catch(...){}
   throw Bad_manipulation(member + " in Web treated as a reference, but it is not a reference.");
}


} // spiders

} // cpp_client

// DO NOT MODIFY THIS FILE
// Never try to directly create an instance of this class, or modify its member variables.
// This contains implementation details, written by code, and only useful to code



#include "../spider.hpp"
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


Spider_::Spider_(std::initializer_list<std::pair<std::string, Any&&>> init) :
    Game_object_{
        {"isDead", Any{std::decay<decltype(is_dead)>::type{}}},
        {"nest", Any{std::decay<decltype(nest)>::type{}}},
        {"owner", Any{std::decay<decltype(owner)>::type{}}},
    },
    is_dead(variables_["isDead"].as<std::decay<decltype(is_dead)>::type>()),
    nest(variables_["nest"].as<std::decay<decltype(nest)>::type>()),
    owner(variables_["owner"].as<std::decay<decltype(owner)>::type>())
{
    for(auto&& obj : init)
    {
      variables_.emplace(std::make_pair(std::move(obj.first), std::move(obj.second)));
    }
}

Spider_::~Spider_() = default;

void Spider_::resize(const std::string& name, std::size_t size)
{
    try
    {
        Game_object_::resize(name, size);
        return;
    }
    catch(...){}
    throw Bad_manipulation(name + " in Spider treated as a vector, but it is not a vector.");
}

void Spider_::change_vec_values(const std::string& name, std::vector<std::pair<std::size_t, Any>>& values)
{
    try
    {
        Game_object_::change_vec_values(name, values);
        return;
    }
    catch(...){}
    throw Bad_manipulation(name + " in Spider treated as a vector, but it is not a vector.");
}

void Spider_::remove_key(const std::string& name, Any& key)
{
    try
    {
        Game_object_::remove_key(name, key);
        return;
    }
    catch(...){}
    throw Bad_manipulation(name + " in Spider treated as a map, but it is not a map.");
}

std::unique_ptr<Any> Spider_::add_key_value(const std::string& name, Any& key, Any& value)
{
    try
    {
        return Game_object_::add_key_value(name, key, value);
    }
    catch(...){}
    throw Bad_manipulation(name + " in Spider treated as a map, but it is not a map.");
}

bool Spider_::is_map(const std::string& name)
{
    try
    {
        return Game_object_::is_map(name);
    }
    catch(...){}
    return false;
}

void Spider_::rebind_by_name(Any* to_change, const std::string& member, std::shared_ptr<Base_object> ref)
{
   if(member == "nest")
   { 
      to_change->as<Nest>() = std::static_pointer_cast<Nest_>(ref);
      return;
   }
   if(member == "owner")
   { 
      to_change->as<Player>() = std::static_pointer_cast<Player_>(ref);
      return;
   }
   try
   {
      Game_object_::rebind_by_name(to_change, member, ref);
      return;
   }
   catch(...){}
   throw Bad_manipulation(member + " in Spider treated as a reference, but it is not a reference.");
}


} // spiders

} // cpp_client

// DO NOT MODIFY THIS FILE
// Never try to directly create an instance of this class, or modify its member variables.
// This contains implementation details, written by code, and only useful to code



#include "../nest.hpp"
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


Nest_::Nest_(std::initializer_list<std::pair<std::string, Any&&>> init) :
    Game_object_{
        {"controllingPlayer", Any{std::decay<decltype(controlling_player)>::type{}}},
        {"spiders", Any{std::decay<decltype(spiders)>::type{}}},
        {"webs", Any{std::decay<decltype(webs)>::type{}}},
        {"x", Any{std::decay<decltype(x)>::type{}}},
        {"y", Any{std::decay<decltype(y)>::type{}}},
    },
    controlling_player(variables_["controllingPlayer"].as<std::decay<decltype(controlling_player)>::type>()),
    spiders(variables_["spiders"].as<std::decay<decltype(spiders)>::type>()),
    webs(variables_["webs"].as<std::decay<decltype(webs)>::type>()),
    x(variables_["x"].as<std::decay<decltype(x)>::type>()),
    y(variables_["y"].as<std::decay<decltype(y)>::type>())
{
    for(auto&& obj : init)
    {
      variables_.emplace(std::make_pair(std::move(obj.first), std::move(obj.second)));
    }
}

Nest_::~Nest_() = default;

void Nest_::resize(const std::string& name, std::size_t size)
{
    if(name == "spiders")
    {
        auto& vec = variables_["spiders"].as<std::decay<decltype(spiders)>::type>();
        vec.resize(size);
        return;
    }
    else if(name == "webs")
    {
        auto& vec = variables_["webs"].as<std::decay<decltype(webs)>::type>();
        vec.resize(size);
        return;
    }
    try
    {
        Game_object_::resize(name, size);
        return;
    }
    catch(...){}
    throw Bad_manipulation(name + " in Nest treated as a vector, but it is not a vector.");
}

void Nest_::change_vec_values(const std::string& name, std::vector<std::pair<std::size_t, Any>>& values)
{
    if(name == "spiders")
    {
        using type = std::decay<decltype(spiders)>::type;
        auto& vec = variables_["spiders"].as<type>();
        for(auto&& val : values)
        { 
            vec[val.first] = std::static_pointer_cast<type::value_type::element_type>(get_game()->get_objects()[val.second.as<std::string>()]);
        }
        return;
    } 
    else if(name == "webs")
    {
        using type = std::decay<decltype(webs)>::type;
        auto& vec = variables_["webs"].as<type>();
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
    throw Bad_manipulation(name + " in Nest treated as a vector, but it is not a vector.");
}

void Nest_::remove_key(const std::string& name, Any& key)
{
    try
    {
        Game_object_::remove_key(name, key);
        return;
    }
    catch(...){}
    throw Bad_manipulation(name + " in Nest treated as a map, but it is not a map.");
}

std::unique_ptr<Any> Nest_::add_key_value(const std::string& name, Any& key, Any& value)
{
    try
    {
        return Game_object_::add_key_value(name, key, value);
    }
    catch(...){}
    throw Bad_manipulation(name + " in Nest treated as a map, but it is not a map.");
}

bool Nest_::is_map(const std::string& name)
{
    try
    {
        return Game_object_::is_map(name);
    }
    catch(...){}
    return false;
}

void Nest_::rebind_by_name(Any* to_change, const std::string& member, std::shared_ptr<Base_object> ref)
{
   if(member == "controllingPlayer")
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
   throw Bad_manipulation(member + " in Nest treated as a reference, but it is not a reference.");
}


} // spiders

} // cpp_client

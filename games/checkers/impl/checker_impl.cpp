// DO NOT MODIFY THIS FILE
// Never try to directly create an instance of this class, or modify its member variables.
// This contains implementation details, written by code, and only useful to code



#include "../checker.hpp"
#include "../../../joueur/src/base_ai.hpp"
#include "../../../joueur/src/any.hpp"
#include "../../../joueur/src/exceptions.hpp"
#include "../../../joueur/src/delta.hpp"
#include "../checker.hpp"
#include "../game_object.hpp"
#include "../player.hpp"
#include "checkers.hpp"

#include <type_traits>

namespace cpp_client
{

namespace checkers
{

bool Checker_::is_mine()
{
    std::string order = R"({"event": "run", "data": {"functionName": "isMine", "caller": {"id": ")";
    order += this->id + R"("}, "args": {)";

    order += "}}}";
    Checkers::instance()->send(order);
    //Go until not a delta
    std::unique_ptr<Any> info;
    //until a not bool is seen (i.e., the delta has been processed)
    do
    {
        info = Checkers::instance()->handle_response();
    } while(info->type() == typeid(bool));
    auto doc = info->as<rapidjson::Document*>();
    auto loc = doc->FindMember("data");
    if(loc == doc->MemberEnd())
    {
       return {};
    }
    auto& val = loc->value;
    Any to_return;
    morph_any(to_return, val);
    return to_return.as<bool>();
}

Checker Checker_::move(int x, int y)
{
    std::string order = R"({"event": "run", "data": {"functionName": "move", "caller": {"id": ")";
    order += this->id + R"("}, "args": {)";

    order += std::string("\"x\":") + std::to_string(x);

    order += std::string(",\"y\":") + std::to_string(y);

    order += "}}}";
    Checkers::instance()->send(order);
    //Go until not a delta
    std::unique_ptr<Any> info;
    //until a not bool is seen (i.e., the delta has been processed)
    do
    {
        info = Checkers::instance()->handle_response();
    } while(info->type() == typeid(bool));
    //reference - just pull the id
    auto doc = info->as<rapidjson::Document*>();
    auto loc = doc->FindMember("data");
    if(loc == doc->MemberEnd())
    {
        return nullptr;
    }
    auto& val = loc->value;
    if(val.IsNull())
    {
        return nullptr;
    }
    else
    {
        auto target = attr_wrapper::get_attribute<std::string>(val, "id");
        return std::dynamic_pointer_cast<Checker_>(Checkers::instance()->get_objects()[target]);
    }
}


Checker_::Checker_(std::initializer_list<std::pair<std::string, Any&&>> init) :
    Game_object_{
        {"kinged", Any{std::decay<decltype(kinged)>::type{}}},
        {"owner", Any{std::decay<decltype(owner)>::type{}}},
        {"x", Any{std::decay<decltype(x)>::type{}}},
        {"y", Any{std::decay<decltype(y)>::type{}}},
    },
    kinged(variables_["kinged"].as<std::decay<decltype(kinged)>::type>()),
    owner(variables_["owner"].as<std::decay<decltype(owner)>::type>()),
    x(variables_["x"].as<std::decay<decltype(x)>::type>()),
    y(variables_["y"].as<std::decay<decltype(y)>::type>())
{
    for(auto&& obj : init)
    {
      variables_.emplace(std::make_pair(std::move(obj.first), std::move(obj.second)));
    }
}

Checker_::~Checker_() = default;

void Checker_::resize(const std::string& name, std::size_t size)
{
    try
    {
        Game_object_::resize(name, size);
        return;
    }
    catch(...){}
    throw Bad_manipulation(name + " in Checker treated as a vector, but it is not a vector.");
}

void Checker_::change_vec_values(const std::string& name, std::vector<std::pair<std::size_t, Any>>& values)
{
    try
    {
        Game_object_::change_vec_values(name, values);
        return;
    }
    catch(...){}
    throw Bad_manipulation(name + " in Checker treated as a vector, but it is not a vector.");
}

void Checker_::remove_key(const std::string& name, Any& key)
{
    try
    {
        Game_object_::remove_key(name, key);
        return;
    }
    catch(...){}
    throw Bad_manipulation(name + " in Checker treated as a map, but it is not a map.");
}

std::unique_ptr<Any> Checker_::add_key_value(const std::string& name, Any& key, Any& value)
{
    try
    {
        return Game_object_::add_key_value(name, key, value);
    }
    catch(...){}
    throw Bad_manipulation(name + " in Checker treated as a map, but it is not a map.");
}

bool Checker_::is_map(const std::string& name)
{
    try
    {
        return Game_object_::is_map(name);
    }
    catch(...){}
    return false;
}

void Checker_::rebind_by_name(Any* to_change, const std::string& member, std::shared_ptr<Base_object> ref)
{
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
   throw Bad_manipulation(member + " in Checker treated as a reference, but it is not a reference.");
}


} // checkers

} // cpp_client

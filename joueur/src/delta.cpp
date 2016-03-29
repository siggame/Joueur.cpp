#include "delta.hpp"
#include "attr_wrapper.hpp"
#include "exceptions.hpp"
#include "any.hpp"
#include "base_game.hpp"
#include "base_ai.hpp"
#include "base_object.hpp"
#include "delta_mergable.hpp"
#include "sgr.hpp"

#include <cstring>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>

namespace cpp_client
{

namespace
{

//returns a map of created object references
template<typename T>
inline std::vector<std::pair<Delta_mergable*, std::string>>
   handle_itr(Base_game& context,
              Delta_mergable& apply_to,
              const rapidjson::Value::ConstMemberIterator& itr,
              T* owner);

}

void apply_delta(rapidjson::Value& delta, Base_game& apply_to)
{
   //can assume that the type is a delta
   const auto& data = attr_wrapper::get_loc(delta, "data")->value;
   if(!data.IsObject())
   {
      throw Bad_response("Delta's data field is not an object.");
   }
   std::vector<std::pair<Delta_mergable*, std::string>> refs;
   for(auto data_iter = data.MemberBegin(); data_iter != data.MemberEnd(); ++data_iter)
   {
      auto to_add = handle_itr(apply_to, apply_to, data_iter, &apply_to);
      //move to the back of the refs
      refs.reserve(to_add.size() + refs.size());
      std::move(std::make_move_iterator(to_add.begin()),
                std::make_move_iterator(to_add.end()),
                std::back_inserter(refs));
   }
   //now do the references
   for(auto&& ref : refs)
   {
      ref.first->variables_[ref.second] = apply_to.get_objects()[ref.second];
   }
}

namespace
{

inline Any make_any(const rapidjson::Value& val)
{
   Any to_add;
   //otherwise just create the Any from it via this stupid if-else block
   if(val.IsBool())
   {
      to_add = Any{val.GetBool()};
   }
   else if(val.IsInt())
   {
      to_add = Any{val.GetInt()};
   }
   else if(val.IsString())
   {
      to_add = Any{std::string{val.GetString()}};
   }
   else if(val.IsNumber())
   {
      to_add = Any{static_cast<double>(val.GetDouble())};
   }
   else
   {
      //some kind of weird gross type that's icky
      throw Bad_response("Unknown JSON type received in a delta.");
   }
   return to_add;
}

template<typename T>
inline std::vector<std::pair<Delta_mergable*, std::string>>
   handle_itr(Base_game& context,
              Delta_mergable& apply_to,
              const rapidjson::Value::ConstMemberIterator& itr,
              T* owner)
{
   std::vector<std::pair<Delta_mergable*, std::string>> to_return;
   //why isn't this part of the standard library?
   const auto append_vec = [&to_return](decltype(to_return)& to_append)
      {
         to_return.reserve(to_return.size() + to_append.size());
         std::move(std::make_move_iterator(to_append.begin()),
                   std::make_move_iterator(to_append.end()),
                   std::back_inserter(to_return));
      };
   const auto& val = itr->value;
   const auto name = std::string(itr->name.GetString());
   auto& objects = context.get_objects();
   //check if it's an object
   if(val.IsObject())
   {
      //check if it's an "array"
      auto len_itr = val.FindMember(context.len_string().c_str());
      auto type_itr = val.FindMember("gameObjectName");
      auto id_itr = val.FindMember("id");
      if(len_itr != val.MemberEnd())
      {
         //array...
         //grab the length
         auto size = attr_wrapper::as<int>(len_itr->value);
         //resize the vector
         apply_to.resize(name, size);
         std::vector<std::pair<std::size_t, Any>> to_edit;
         for(auto data_iter = val.MemberBegin(); data_iter != val.MemberEnd(); ++data_iter)
         {
            //skip the length iterator
            if(data_iter == len_itr)
            {
               continue;
            }
            //either a game object or a primitive - if it's an object it's a game object
            if(data_iter->value.IsObject())
            {
               //make a base object and then edit it
               auto ptr = std::make_shared<Base_object>();
               auto vec = handle_itr(context,
                                     *ptr,
                                     data_iter,
                                     &apply_to);
               to_edit.emplace_back(atoi(data_iter->name.GetString()),
                                    std::move(ptr));
               append_vec(vec);
            }
            else
            {
               to_edit.emplace_back(atoi(data_iter->name.GetString()),
                                    make_any(data_iter->value));
            }
         }
         apply_to.change_vec_values(name, to_edit);
      }
      else if(type_itr != val.MemberEnd())
      {
         //new object...
         //give it a place in the objects
         objects[name] = context.generate_object(attr_wrapper::as<std::string>(type_itr->value));
         for(auto data_iter = val.MemberBegin(); data_iter != val.MemberEnd(); ++data_iter)
         {
            auto vec = handle_itr(context,
                                  *objects[name],
                                  data_iter,
                                  &apply_to);
         }
      }
      else if(id_itr != val.MemberEnd())
      {
         //object reference...
         to_return.push_back(std::make_pair(&apply_to,
                                            attr_wrapper::as<std::string>(id_itr->value)));
      }
      else
      {
         //map...
         for(auto data_iter = val.MemberBegin(); data_iter != val.MemberEnd(); ++data_iter)
         {
            auto vec = handle_itr(context,
                                  *apply_to.variables_[name].as<std::shared_ptr<Base_object>>(),
                                  data_iter,
                                  &apply_to);
            append_vec(vec);
         }
      }
   }
   else if(!val.IsArray())
   {
      if(val.IsNull())
      {
         //need to do this a little differently so that it doesn't change type
         auto& change = apply_to.variables_[name].as<std::shared_ptr<Base_object>>();
         change.reset();
         return to_return;
      }
      else if(val.IsString() && val.GetString() == context.remove_string())
      {
         //remove this thing
         owner->erase(name);
         return to_return;
      }
      Any to_add = make_any(val);
      //do some checking (ignore name because of game weirdness)
      if(!apply_to.variables_.count(name) && name != "name")
      {
         std::cout << sgr::text_yellow
                   << "Warning: Unknown variable " << name << " added." << sgr::reset
                   << "\n"
                   ;
      }
      else if(apply_to.variables_[name].type() != to_add.type() && name != "name")
      {
         std::cout << sgr::text_yellow
                   << "Warning: Variable " << name << " has changed types." << sgr::reset
                   << "\n"
                   ;
      }
      apply_to.variables_[name] = std::move(to_add);
   }
   else
   {
      //array - some kind of error
      throw Bad_response("Received a JSON vector in a delta.");
   }
   return to_return;
}

}

} // cpp-client

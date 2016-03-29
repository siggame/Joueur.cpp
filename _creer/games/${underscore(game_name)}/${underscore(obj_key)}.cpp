// ${header}
// ${obj['description']}
<% obj_key_name = underscore(obj_key).capitalize() %>
<%include file="functions.noCreer" />
#include "${underscore(obj_key)}.hpp"
#include "../../joueur/src/base_ai.hpp"
#include "../../joueur/src/any.hpp"
#include "../../joueur/src/exceptions.hpp"
% for game_obj_key in sort_dict_keys(game_objs):
#include "${underscore(game_obj_key)}.hpp"
% endfor

#include <type_traits>

namespace cpp_client
{

namespace ${underscore(game_name)}
{
//Do not edit anything below here!
<%
parent_classes = []
for par in obj['parentClasses']:
   parent_classes.append(underscore(par).capitalize() + '_')
call_parents = True
if obj_key == "Game":
   parent_classes = [ 'Base_game' ]
   call_parents = False
elif obj_key == "GameObject":
   parent_classes = [ 'Base_object' ]
   call_parents = False
i = len(obj['attribute_names']) - 1
comma = ','
initcomma = ','
if i == -1:
   initcomma = ''
if i == 0:
   comma = ''%>
//Constructor - Do not edit this!
${obj_key_name}_::${obj_key_name}_(std::initializer_list<std::pair<std::string, Any&&>> init) :
% for par in parent_classes:
   ${underscore(par).capitalize()}{
% for attr_name in obj['attribute_names']:
      {"${attr_name}", Any{std::decay<decltype(${underscore(attr_name)})>::type{}}},
% endfor
   }${initcomma}
% endfor
% for attr_name in obj['attribute_names']:
   ${underscore(attr_name)}(variables_["${attr_name}"].as<std::decay<decltype(${underscore(attr_name)})>::type>())${comma} <% i -=1
 if i == 0:
    comma = ''%>
% endfor
{
   for(auto&& obj : init)
   {
     variables_.emplace(std::make_pair(std::move(obj.first), std::move(obj.second)));
   }
}

${obj_key_name}_::~${obj_key_name}_() = default;

void ${obj_key_name}_::resize(const std::string& name, std::size_t size)
{ <% if_str = 'if' %>
% for attr_name in obj['attribute_names']:
% if obj['attributes'][attr_name]['type'] and obj['attributes'][attr_name]['type']['name'] == 'list':
   ${if_str}(name == "${attr_name}")
   {
      auto& vec = variables_["${attr_name}"].as<std::decay<decltype(${underscore(attr_name)})>::type>();
      vec.resize(size);
      return;
   } <% if_str = 'else if' %>
% endif
% endfor
% if call_parents:
% for parent in parent_classes:
   try
   {
      ${underscore(par).capitalize()}::resize(name, size);
      return;
   }
   catch(...){}
% endfor
% endif
   throw Bad_manipulation(name + " in ${obj_key_name} treated as a vector, but it is not a vector.");
}

void ${obj_key_name}_::change_vec_values(const std::string& name, std::vector<std::pair<std::size_t, Any>>& values)
{ <% if_str = 'if' %>
% for attr_name in obj['attribute_names']:
% if obj['attributes'][attr_name]['type'] and obj['attributes'][attr_name]['type']['name'] == 'list':
   ${if_str}(name == "${attr_name}")
   {
      using type = std::decay<decltype(${underscore(attr_name)})>::type;
      auto& vec = variables_["${attr_name}"].as<type>();
      for(auto&& val : values)
      {
         vec[val.first] = std::move(val.second.as<type::value_type>());
      }
      return;
   } <% if_str = 'else if' %>
% endif
% endfor
% if call_parents:
% for parent in parent_classes:
   try
   {
      ${underscore(par).capitalize()}::change_vec_values(name, values);
      return;
   }
   catch(...){}
% endfor
% endif
   throw Bad_manipulation(name + " in ${obj_key_name} treated as a vector, but it is not a vector.");
}

void ${obj_key_name}_::remove_key(const std::string& name, Any& key)
{ <% if_str = 'if' %>
% for attr_name in obj['attribute_names']:
% if obj['attributes'][attr_name]['type'] and obj['attributes'][attr_name]['type']['name'] == 'dictionary':
   ${if_str}(name == "${attr_name}")
   {
      auto& map = variables_["${attr_name}"].as<std::decay<decltype(${underscore(attr_name)})>::type>();
      using type = std::decay<decltype(map)>::type;
      map.erase(key.as<type::key_type>());
      return;
   } <% if_str = 'else if' %>
% endif
% endfor
% if call_parents:
% for parent in parent_classes:
   try
   {
      ${underscore(par).capitalize()}::remove_key(name, key);
      return;
   }
   catch(...){}
% endfor
% endif
   throw Bad_manipulation(name + " in ${obj_key_name} treated as a map, but it is not a map.");
}

void ${obj_key_name}_::add_key_value(const std::string& name, Any& key, Any& value)
{ <% if_str = 'if' %>
% for attr_name in obj['attribute_names']:
% if obj['attributes'][attr_name]['type'] and obj['attributes'][attr_name]['type']['name'] == 'dictionary':
   ${if_str}(name == "${attr_name}")
   {
      auto& map = variables_["${attr_name}"].as<std::decay<decltype(${underscore(attr_name)})>::type>();
      using type = std::decay<decltype(map)>::type;
      map.emplace(std::make_pair(std::move(key.as<type::key_type>()), std::move(value.as<type::mapped_type>())));
      return;
   } <% if_str = 'else if' %>
% endif
% endfor
% if call_parents:
% for parent in parent_classes:
   try
   {
      ${underscore(par).capitalize()}::add_key_value(name, key, value);
      return;
   }
   catch(...){}
% endfor
% endif
   throw Bad_manipulation(name + " in ${obj_key_name} treated as a map, but it is not a map.");
}

} // ${underscore(game_name)}

} // cpp_client

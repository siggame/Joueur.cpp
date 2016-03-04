// ${header}
// ${obj['description']}
<% obj_key_name = underscore(obj_key).capitalize() %>
<%include file="functions.noCreer" />
#include "${underscore(obj_key)}.hpp"
#include "../../joueur/src/base_ai.hpp"
#include "../../joueur/src/any.hpp"

namespace cpp_client
{

namespace ${underscore(game_name)}
{
//Do not edit anything below here!
<%
   parent_classes = []
   for par in obj['parentClasses']:
      parent_classes.append(underscore(par).capitalize() + '_')
%>

<%
if obj_key == "Game":
   # no Base_game because it does not take parameters like this
   parent_classes = [ 'Base_object' ]
elif obj_key == "GameObject":
   parent_classes = [ 'Base_object' ]
%>
<% i = len(obj['attribute_names']) - 1
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
      {"${underscore(attr_name)}", Any{${shared['gen_base_type'](obj['attributes'][attr_name]['type'])}{}}},
% endfor
   }${initcomma}
% endfor
% for attr_name in obj['attribute_names']:
   ${underscore(attr_name)}(variables_["${underscore(attr_name)}"].as<${shared['gen_base_type'](obj['attributes'][attr_name]['type'])}>())${comma} <% i -=1
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

} // ${underscore(game_name)}

} // cpp_client

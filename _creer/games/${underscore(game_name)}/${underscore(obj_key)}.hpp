#ifndef GAMES_${game_name.upper()}_${underscore(obj_key).upper()}_H
#define GAMES_${game_name.upper()}_${underscore(obj_key).upper()}_H

// ${header}
// ${obj['description']}

#include <vector>
#include <unordered_map>
#include <string>

<% obj_key_name = underscore(obj_key).capitalize() %>
<%include file="functions.noCreer" />
<%
   parent_classes = []
   for par in obj['parentClasses']:
      parent_classes.append(underscore(par).capitalize())
%>
% if len(parent_classes) > 0:
%    for parent_class in parent_classes:
#include "${underscore(parent_class)}.hpp"
%    endfor
% endif
<%
mod = false
if obj_key == "Game":
   mod = true
   parent_classes = [ 'Base_game' ]
%>
% if mod:
#include "../../src/${underscore(parent_classes[0])}.hpp"
% endif
#include "${underscore(game_name)}_fwd.hpp"

${merge("// ", "includes", "// you can add additional #includes here")}

namespace cpp_client
{

namespace ${underscore(game_name)}
{

/// <summary>
/// ${obj['description']}
/// </summary>
class ${obj_key_name}_
% if len(parent_classes) > 0:
   : public ${(", public").join(parent_classes)}
% endif
{
public:
% for attr_name in obj['attribute_names']:
   <% attr_params = obj['attributes'][attr_name] %>
   /// <summary>
   /// ${attr_params['description']}
   /// </summary>
   ${shared['gen_base_type'](attr_params['type'])} ${underscore(attr_name)};
% endfor

${merge("   // ", "member variables", "   // You can add additional member variables here. None of them will be tracked or updated by the server.")}

% for function_name in obj['function_names']:
<% function_params = obj['functions'][function_name] %>
   /// <summary>
   /// ${function_params['description']}
   /// </summary>
% if 'arguments' in function_params:
% for arg_params in function_params['arguments']:
   /// <param name="${arg_params['name']}"> ${arg_params['description']} </param>
% endfor
<%
if function_params['returns']:
  return_type = shared['gen_base_type'](function_params['returns']['type'])
else:
  return_type = 'void'
name = underscore(function_name)
args = shared['make_args'](function_params, True)
%>   ${return_type} ${name}(${args});
% endif
% endfor

${merge("   // ", "methods", "   // You can add additional methods here.")}
};

} // ${lowercase_first(game_name)}

} // cpp_client

#endif // GAMES_${game_name.upper()}_${underscore(obj_key).upper()}_H

<%include file="functions.noCreer" />// ${shared['c++']['format_description'](obj['description'])}
// DO NOT MODIFY THIS FILE
#include "${lowercase_first(obj_key)}.h"
#include "gameManager.h"
<%
parent_classes = []
if len(obj['parentClasses']) > 0:
    for parent_class in obj['parentClasses']:
        parent_classes.append(game_name + "::" + parent_class)
else:
    if obj_key == "Game":
        parent_classes.append("Joueur::BaseGame")
    else:
        parent_classes.append("Joueur::BaseGameObject")

arg_classes_needed = []

if obj_key != "Game":
    for function_name in obj['function_names']:
        function_parms = obj['functions'][function_name]
        if 'arguments' in function_parms:
            for arg_parms in function_parms['arguments']:
                t = arg_parms['type']['name']
                if t != obj_key and arg_parms['type']['is_game_object']:
                    arg_classes_needed.append(t) %>
% if len(arg_classes_needed) > 0:
% for arg_class_needed in arg_classes_needed:
#include "${lowercase_first(arg_class_needed)}.h"
% endfor

% endif
${merge("// ", "includes", "// you can add additional #includes(s) here.")}




void ${game_name}::${obj_key}::deltaUpdateField(const std::string& fieldName, boost::property_tree::ptree& delta)
{
% for parent_class in parent_classes:
    ${parent_class}::deltaUpdateField(fieldName, delta);
% endfor
<% i = 0 %>
% for attr_name in obj['attribute_names']:
<% attr_parms = obj['attributes'][attr_name]
if shared['c++']['skippable'](obj_key, attr_name, skip_player_check=true):
    continue
i += 1
%>    ${"else " if i > 1 else ""}if (fieldName == "${attr_name}")
    {
        this->${attr_name} = ${shared['c++']['cast_type'](attr_parms)}this->gameManager->${shared['c++']['unserialize_function'](attr_parms, "delta", list_name=("&this->" + attr_name))};
    }
% endfor
}



% for function_name in obj['function_names']:
<%
function_parms = obj['functions'][function_name]
return_type = function_parms['returns'] and shared['c++']['type'](function_parms['returns']['type'])
%>${return_type or 'void'} ${game_name}::${obj_key}::${function_name}(${shared['c++']['inline_args'](function_parms)})
{
    boost::property_tree::ptree args;
% if 'arguments' in function_parms:
% for arg_parms in function_parms['arguments']:
    args.put_child("${arg_parms['name']}", *this->gameManager->serialize(${"static_cast<BaseGameObject*>" if arg_parms['type']['is_game_object'] else ""}(${arg_parms['name']})));
% endfor
% endif

    auto returned = this->gameManager->runOnServer(*this, "${function_name}", args);
% if return_type:
    return ${shared['c++']['cast_type'](function_parms['returns'])}this->gameManager->${shared['c++']['unserialize_function'](function_parms['returns'], '*returned')};
% endif
}

% endfor

${merge("// ", "methods", "// if you forward declaired additional methods to the " + obj_key + " then you can code them here.")}

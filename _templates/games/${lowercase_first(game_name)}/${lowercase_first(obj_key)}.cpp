// ${header}
// ${obj['description']}
<%include file="functions.noCreer" />
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

%>
${merge("// ", "includes", "// you can add additional #includes(s) here.")}




void ${game_name}::${obj_key}::deltaUpdateField(const std::string& fieldName, boost::property_tree::ptree& delta)
{
% for parent_class in parent_classes:
    ${parent_class}::deltaUpdateField(fieldName, delta);
% endfor
<% i = 0 %>
% for attr_name in obj['attribute_names']:
<% attr_parms = obj['attributes'][attr_name]
if shared['c++']['skippable'](obj_key, attr_name, skipPlayerCheck=true):
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
    args.put_child("${arg_parms['name']}", *this->gameManager->serialize(${arg_parms['name']}));
% endfor
% endif

    auto returned = this->gameManager->runOnServer(*this, "${function_name}", args);
% if return_type:
    return ${shared['c++']['cast_type'](function_parms['returns'])}this->gameManager->${shared['c++']['unserialize_function'](function_parms['returns'], '*returned')};
% endif
}

% endfor

${merge("// ", "methods", "// if you forward declaired additional methods to the " + obj_key + " then you can code them here.")}

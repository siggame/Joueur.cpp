<%include file="functions.noCreer" />// ${shared['c++']['format_description'](obj['description'])}
// DO NOT MODIFY THIS FILE
#ifndef JOUEUR_${game_name.upper()}_${obj_key.upper()}_H
#define JOUEUR_${game_name.upper()}_${obj_key.upper()}_H

#include "${lowercase_first(game_name)}.h"<% parent_classes = obj['parentClasses'] %>
% if len(parent_classes) > 0:
% for parent_class in parent_classes:
#include "${lowercase_first(parent_class)}.h"<%
parent_namespace = game_name
%>
% if obj_key == "Player":
#include "../../joueur/basePlayer.h"
% endif
% endfor
% else:
<%
parent_namespace = "Joueur"
if obj_key == "Game":
    parent_classes = [ 'BaseGame' ]
else:
    parent_classes = [ 'BaseGameObject' ]
%>#include "../../joueur/${lowercase_first(parent_classes[0])}.h"
% endif

${merge("// ", "includes", "// you can add addtional #includes(s) here.")}

/// <summary>
/// ${shared['c++']['format_description'](obj['description'])}
/// </summary>
class ${game_name}::${obj_key} : public ${parent_namespace}::${(", public " + parent_namespace + "::").join(parent_classes)}${", public Joueur::BasePlayer" if obj_key == "Player" else ""}
{
    friend ${game_name}::GameManager;

    protected:
        virtual void deltaUpdateField(const std::string& fieldName, boost::property_tree::ptree& delta);
        ${obj_key}() {${"" if (obj_key != "Game") else (' this->name = "' + game_name + '"; ')}};
        ~${obj_key}() {};

    public:
% for attr_name in obj['attribute_names']:
<% attr_parms = obj['attributes'][attr_name]
if shared['c++']['skippable'](obj_key, attr_name):
    continue
%>        /// <summary>
        /// ${shared['c++']['format_description'](attr_parms['description'])}
        /// </summary>
        ${shared['c++']['type'](attr_parms['type'])} ${attr_name};

% endfor

${merge("        // ", "fields", "        // you can add addtional fields(s) here. None of them will be tracked or updated by the server.")}

% for function_name in obj['function_names']:
<% function_parms = obj['functions'][function_name]
return_type = None
%>        /// <summary>
        /// ${shared['c++']['format_description'](function_parms['description'])}
        /// </summary>
% if 'arguments' in function_parms:
% for arg_parms in function_parms['arguments']:
        /// <param name="${arg_parms['name']}">${shared['c++']['format_description'](arg_parms['description'])}</param>
% endfor
% endif
% if function_parms['returns']:
<% return_type = shared['c++']['type'](function_parms['returns']['type'])
%>        /// <returns>${shared['c++']['format_description'](function_parms['returns']['description'])}</returns>
% endif
        ${return_type or 'void'} ${function_name}(${shared['c++']['inline_args'](function_parms, optional=True)});

% endfor

${merge("        // ", "methods", "        // you can add addtional method(s) here.")}
};

#endif

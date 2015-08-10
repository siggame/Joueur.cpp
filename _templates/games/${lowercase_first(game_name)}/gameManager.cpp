// ${header}
// $This is a class that manages the ${game_name} Game and it's GameObjects. Competitors should never have to care about this class's existance.
<% game_obj_keys = sort_dict_keys(game_objs) %>
#include "gameManager.h"
#include "ai.h"
// The Game Objects
% for game_obj_key in game_obj_keys:
#include "${lowercase_first(game_obj_key)}.h"
% endfor

${game_name}::GameManager::GameManager() :
    Joueur::BaseGameManager()
{
    this->${lowercase_first(game_name)}Game = new ${game_name}::Game();
    this->${lowercase_first(game_name)}AI = new ${game_name}::AI();

    this->setup(this->${lowercase_first(game_name)}Game, this->${lowercase_first(game_name)}AI);
}

// @overrides
Joueur::BaseGameObject* ${game_name}::GameManager::createGameObject(const std::string& gameObjectName)
{<% i = 0 %>
% for game_obj_key in game_obj_keys:
<% i += 1 %>    ${"else " if i > 1 else ""}if (gameObjectName == "${game_obj_key}")
    {
        return new ${game_name}::${game_obj_key}();
    }
% endfor

    throw new std::exception(("Game object '" + gameObjectName + "' not found to create new instance of").c_str());
}

// @overrides
void ${game_name}::GameManager::setupAI(const std::string& playerID)
{
    Joueur::BaseGameManager::setupAI(playerID);

    this->${lowercase_first(game_name)}AI->player = (${game_name}::Player*)(this->getGameObject(playerID));
    this->${lowercase_first(game_name)}AI->game = this->${lowercase_first(game_name)}Game;
}

// @overrides
boost::property_tree::ptree* ${game_name}::GameManager::orderAI(const std::string& order, boost::property_tree::ptree* args)
{
    auto ptrees = this->getOrderArgsPtrees(args);
<% i = 0 %>
% for function_name in ai['function_names']:
<%
function_parms = ai['functions'][function_name]
returns = bool(function_parms['returns'])
i + 1
arg_i = -1
%>    ${"else " if i > 1 else ""}if (order == "${function_name}")
    {
        ${"auto returned = " if returns else ""}this->${lowercase_first(game_name)}AI->runTurn(
% if len(function_parms['arguments']) > 0:
% for arg_parms in function_parms['arguments']:
<% arg_i += 1 %>            ${shared["c++"]["unserialize_function"](arg_parms, "ptree[" + arg_i + "]")}${"" if arg_i+1 == len(function_parms['arguments']) else ","}
% endfor
% endif
        );
% if returns:

        return this->serialize(returned);
% endif
    }
% endfor

    delete ptrees;
    return nullptr;
}

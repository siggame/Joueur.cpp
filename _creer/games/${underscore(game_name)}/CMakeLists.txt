set(FILES
    ${"${CMAKE_CURRENT_SOURCE_DIR}"}/ai.cpp
    ${"${CMAKE_CURRENT_SOURCE_DIR}"}/ai.hpp
    ${"${CMAKE_CURRENT_SOURCE_DIR}"}/${underscore(game_name)}.cpp
    ${"${CMAKE_CURRENT_SOURCE_DIR}"}/${underscore(game_name)}.hpp
    ${"${CMAKE_CURRENT_SOURCE_DIR}"}/${underscore(game_name)}_fwd.hpp
% for game_obj_key in sort_dict_keys(game_objs):
    ${"${CMAKE_CURRENT_SOURCE_DIR}"}/${underscore(game_obj_key)}.cpp
    ${"${CMAKE_CURRENT_SOURCE_DIR}"}/${underscore(game_obj_key)}.hpp
% endfor
    ${"${CMAKE_CURRENT_SOURCE_DIR}"}/game.cpp
    ${"${CMAKE_CURRENT_SOURCE_DIR}"}/game.hpp
    PARENT_SCOPE)

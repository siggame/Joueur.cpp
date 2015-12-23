// Author: Brian W Goldman
// This header creates a function registry:
// All games want to add their creation functions to those registries
// or, code that wants to call functions in those registries, must include this file.
#ifndef HEADER_H
#define HEADER_H

#include "function_registry.h"
#include "joueur/baseGameManager.h"

CREATE_FUNCTION_REGISTRY(gamesRegistry, std::function<Joueur::BaseGameManager*()>)

#endif

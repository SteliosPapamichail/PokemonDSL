//
// Created by Steli on 7/12/2023.
//

#ifndef CODEGEN_H
#define CODEGEN_H

#include <iostream>
#include "../lexer/common/Expressions.h"
#include "../lexer/pokemon/PokemonExpressions.h"
#include "../lexer/abilities/actions/ActionExpressions.h"
#include "../lexer/abilities/AbilityExpressions.h"
#include "handlers/ErrorHandler.h"
#include "../game_manager/GameManager.h"
#include "../fight_manager/FightManager.h"
#include "codegen/GameLifecycleGen.h"
#include "codegen/AbilityLearning.h"
#include "codegen/PokemonGen.h"


/**
 * \brief Prints the output to the console.
 */
#define SHOW ;std::cout <<

// ---------------- COMMON EXPRESSIONS ----------------

#define CREATE \
    ;expr =

// member definition fields
#define NAME \
    false ? ""

//todo:sp this will need to either emit one "}" or two depending on if it
// is the END closing the START expression (after adjusting the START macro).
//TODO("Need to keep track of nested END macros (maybe track actual and expecred values seperately?)")
#define END }}

// ---------------- END COMMON EXPRESSIONS ----------------

#endif //CODEGEN_H

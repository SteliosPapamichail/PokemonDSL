//
// Created by Steli on 7/12/2023.
//

#ifndef CODEGEN_H
#define CODEGEN_H

//todo:sp break codegen down into files (i.e. pokemon code gen)

#include "../lexer/common/Expressions.h"
#include "../lexer/abilities/AbilityExpressions.h"
#include "../lexer/pokemon/PokemonExpressions.h"
#include "handlers/ErrorHandler.h"


bool hasSeenError = false;

// GAME COMMANDS
#define BEGIN_GAME int \
    main() \
    { \
    std::cout << "------------------------------ POKEMON THE GAME ------------------------------" << std::endl; \

#define END_GAME ;return \
    ErrorHandler::getInstance().getErrors().empty() ? 0 : -1; \
    }

// CREATE COMMANDS
#define CREATE Expr* expr;

// ABILITY CREATION
#define ABILITY \
    expr = new SingleAbilityExpr

// member definition fields
#define NAME \
    false ? ""
    // switch(expr->getExprType) { \
    //     case CREATE_SINGLE_ABILITY_EXPR: \
    //         std::cout << "Found name for ability" << std::endl; \
    //         break; \
    // }

#endif //CODEGEN_H

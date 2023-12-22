//
// Created by Steli on 7/12/2023.
//

#ifndef CODEGEN_H
#define CODEGEN_H

//todo:sp break codegen down into files (i.e. pokemon code gen)

#include "../lexer/common/Expressions.h"
#include "../lexer/pokemon/PokemonExpressions.h"
#include "handlers/ErrorHandler.h"

std::vector<Pokemon> declaredPokemons;

inline void printDeclaredPokemons() {
    for (const auto&pokemon: declaredPokemons) {
        std::cout << pokemon << std::endl;
    }
}

// GAME COMMANDS
#define BEGIN_GAME int \
    main() \
    { \
    std::cout << "------------------------------ POKEMON THE GAME ------------------------------" << std::endl; \
    Expr* expr

#define END_GAME ; \
    printDeclaredPokemons(); \
    ErrorHandler& errorHandler =  ErrorHandler::getInstance();\
    errorHandler.printErrors();\
    return errorHandler.getErrors().empty() ? 0 : -1; \
    }

// CREATE COMMANDS
#define CREATE \
    ;expr =

// POKEMON CREATION
#define POKEMON \
    new SinglePokemonDefExpr

#define POKEMONS \
    MultiPokemonDefExpr()

// pokemon types
#define TYPE \
    false ? ""

// pokemon hp
#define HP \
    false ? 0

// member definition fields
#define NAME \
    false ? ""

#endif //CODEGEN_H

//
// Created by Steli on 7/12/2023.
//

#ifndef CODEGEN_H
#define CODEGEN_H

//todo:sp break codegen down into files (i.e. pokemon code gen)

#include "../lexer/common/Expressions.h"
#include "../lexer/pokemon/PokemonExpressions.h"
#include "../lexer/abilities/AbilityExpressions.h"
#include "handlers/ErrorHandler.h"
#include "../game_manager/GameManager.h"
#include "../fight_manager/FightManager.h"

std::vector<Pokemon> declaredPokemons = {};

void printDeclaredPokemons() {
    for (const auto&pokemon: declaredPokemons) {
        std::cout << pokemon << std::endl;
    }
}

/**
 * \brief Configures and begins the game.
 */
#define BEGIN_GAME int \
    main() \
    { \
    std::cout << "------------------------------ POKEMON THE GAME ------------------------------" << std::endl; \
    Expr* expr

/**
 * \brief Prints any errors to the std::cerr stream and ends the game.
 */
#define END_GAME ; \
    ErrorHandler& errorHandler =  ErrorHandler::getInstance();\
    errorHandler.printErrors();\
    return errorHandler.getErrors().empty() ? 0 : -1; \
    }

/**
 * \brief Begins the pokemon duel.
 */
#define DUEL ;GameManager::getInstance().promptUsersForPokemonSelection();

/**
 * \brief Prints the output to the console.
 */
#define SHOW ;std::cout <<

//TODO:SP these should create a new expr probably in order to evaluate them
//todo:sp at runtime once the game manager has valid values.

/**
 * \brief Returns the attacking pokemon in the current round.
 */
#define ATTACKER FightManager::getInstance().getAttacker()


/**
 * \brief Returns the defending pokemon in the current round.
 */
#define DEFENDER FightManager::getInstance().getDefender()

/**
 * \brief Returns the name of the given pokemon.
 * \param pokemon The pokemon whose name to return.
 */
#define GET_NAME(pokemon) (pokemon->getName())

/**
 * \brief Returns the type of the given pokemon.
 * \param pokemon The pokemon whose type to return
 */
#define GET_TYPE(pokemon) (PokemonTypeToString(pokemon->getType()))

/**
 * \brief Returns the current HP of the given pokemon.
 * \param pokemon The pokemon whose HP to return.
 */
#define GET_HP(pokemon) (pokemon->getHP())

// CREATE COMMANDS
#define CREATE \
    ;expr =

// POKEMON CREATION
#define POKEMON \
    new SinglePokemonDefExpr

#define POKEMONS \
    MultiPokemonDefExpr()

#define ABILITY new SingleAbilityExpr

#define ABILITIES MultiAbilityDefExpr()

/**
 * \brief Specifies the pokemon's type.
 */
#define TYPE \
    false ? ""

/**
 * \brief Specifies the pokemon's maximum HP.
 */
#define HP \
    false ? 0

// member definition fields
#define NAME \
    false ? ""

#define ACTION

#define START

#define END

#endif //CODEGEN_H

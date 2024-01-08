//
// Created by Steli on 12/26/2023.
//

#ifndef GAMELIFECYCLEGEN_H
#define GAMELIFECYCLEGEN_H
#include <vector>
#include "../../pokemon_models/Pokemon.h"
#include "../../lexer/common/Expressions.h"
#include "../handlers/ErrorHandler.h"
#include "../../lexer/abilities/AbilityExpressions.h"

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
 FightManager::cleanUp();\
 ErrorHandler& errorHandler =  ErrorHandler::getInstance();\
 errorHandler.printErrors();\
 return errorHandler.getErrors().empty() ? 0 : -1; \
 }

/**
 * \brief Begins the pokemon duel.
 */
#define DUEL ;GameManager::getInstance().promptUsersForPokemonSelection();


#endif //GAMELIFECYCLEGEN_H

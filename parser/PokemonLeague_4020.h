//
// Created by Steli on 7/12/2023.
//

#ifndef CODEGEN_H
#define CODEGEN_H

#include "../lexer/common/Expressions.h"
#include "../lexer/pokemon/PokemonExpressions.h"
#include "../lexer/abilities/actions/ActionExpressions.h"
#include "../lexer/abilities/AbilityExpressions.h"
#include "handlers/ErrorHandler.h"
#include "../game_manager/GameManager.h"
#include "../fight_manager/FightManager.h"
#include "codegen/GameLifecycleGen.h"
#include "codegen/PokemonGen.h"

std::vector<Pokemon> declaredPokemons = {};
std::vector<SingleAbilityExpr> declaredAbilities = {};

void printDeclaredPokemons() {
    for (const auto&pokemon: declaredPokemons) {
        std::cout << pokemon << std::endl;
    }
}

void printDeclaredAbilities() {
    for (const auto&ability: declaredAbilities) {
        std::cout << ability.getAbilityName() << std::endl;
    }
}


/**
 * \brief Prints the output to the console.
 */
#define SHOW ;std::cout <<

/**
 * \brief Returns the attacking pokemon in the current round.
 */
#define ATTACKER FightManager::getInstance().getAttacker()


/**
 * \brief Returns the defending pokemon in the current round.
 */
#define DEFENDER FightManager::getInstance().getDefender()

// ---------------- COMMON EXPRESSIONS ----------------

#define CREATE \
    ;expr =

// member definition fields
#define NAME \
    false ? ""

#define END }

// ---------------- END COMMON EXPRESSIONS ----------------

#endif //CODEGEN_H

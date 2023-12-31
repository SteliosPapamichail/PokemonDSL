//
// Created by Steli on 12/26/2023.
//

#ifndef ABILITYGEN_H
#define ABILITYGEN_H

#include "ActionsGen.h"
#include "LogicalOpExprGen.h"

/**
 * \brief Declares a new Pokemon ability
 */
#define ABILITY new SingleAbilityExpr

/**
 * \brief Declares multiple Pokemon abilities
 */
#define ABILITIES MultiAbilityDefExpr()

/**
 * \brief Declares the action to be performed when a Pokemon
 * executes its respective ability.
 */
#define ACTION false ? nullptr

/**
 * \brief Defines the starting point of the action(s) to be
 * performed when the respective ability is performed.
 */
#define START new AbilityActionExpr {[]() { \
        std::cout << "attacker is : " << FightManager::getInstance().getAttacker()->getName() << std::endl; \
    }
#endif //ABILITYGEN_H

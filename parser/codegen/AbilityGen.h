//
// Created by Steli on 12/26/2023.
//

#ifndef ABILITYGEN_H
#define ABILITYGEN_H

#include "LogicalOpExprGen.h"

/**
 * \brief
 */
#define ABILITY new SingleAbilityExpr

/**
 * \brief
 */
#define ABILITIES MultiAbilityDefExpr()

#define ACTION false ? nullptr

#define START new AbilityActionExpr {[]() { \
        std::cout << "attacker is : " << FightManager::getInstance().getAttacker()->getName() << std::endl; \
    }
#endif //ABILITYGEN_H

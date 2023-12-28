//
// Created by Steli on 22/12/2023.
//

#ifndef UTILS_H
#define UTILS_H

#include <string>
#include "../lexer/abilities/AbilityExpressions.h"
#include "../game_manager/GameManager.h"

inline bool doesPokemonNameExist(const std::string&nameToCheck) {
    for (const Pokemon& pokemon: GameManager::getInstance().getDeclaredPokemons()) {
        if (pokemon.getName() == nameToCheck) {
            return true;
        }
    }
    return false;
}

inline bool doesAbilityNameExist(const std::string&nameToCheck) {
    for (const SingleAbilityExpr&ability: GameManager::getInstance().getDeclaredAbilities()) {
        if (ability.getName() == nameToCheck) {
            return true;
        }
    }
    return false;
}

inline Pokemon* getPokemonByName(const std::string&nameToCheck) {
    for (Pokemon&pokemon: GameManager::getInstance().getDeclaredPokemons()) {
        if (pokemon.getName() == nameToCheck) {
            return &pokemon;
        }
    }
    return nullptr;
}

inline SingleAbilityExpr* getAbilityByName(const std::string&nameToCheck) {
    for (SingleAbilityExpr&ability: GameManager::getInstance().getDeclaredAbilities()) {
        if (ability.getName() == nameToCheck) {
            return &ability;
        }
    }
    return nullptr;
}

inline bool containsSpace(const std::string&strToCheck) {
    for (const auto ch: strToCheck) {
        if (std::isspace(ch)) {
            return true;
        }
    }
    return false;
}
#endif //UTILS_H

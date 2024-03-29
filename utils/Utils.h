//
// Created by Steli on 22/12/2023.
//

#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <ostream>
#include <string>
#include "../lexer/abilities/AbilityExpressions.h"
#include "../game_manager/GameManager.h"

// ANSI escape codes for text colors
#define RED_TEXT "\033[1;31m"
#define GREEN_TEXT "\033[1;32m"
#define YELLOW_TEXT "\033[1;33m"
#define BLUE_TEXT "\033[1;34m"
#define RESET_TEXT "\033[0m"

inline bool doesPokemonNameExist(const std::string&nameToCheck) {
    for (const auto&pokemon: GameManager::getInstance().getDeclaredPokemons()) {
        if (pokemon->getName() == nameToCheck) {
            return true;
        }
    }
    return false;
}

inline bool doesAbilityNameExist(const std::string&nameToCheck) {
    for (const auto&ability: GameManager::getInstance().getDeclaredAbilities()) {
        if (ability->getName() == nameToCheck) {
            return true;
        }
    }
    return false;
}

inline std::shared_ptr<Pokemon> getPokemonByName(const std::string&nameToCheck) {
    for (const auto&pokemon: GameManager::getInstance().getDeclaredPokemons()) {
        if (pokemon->getName() == nameToCheck) {
            return pokemon;
        }
    }
    std::cerr << "No pokemon found matching \"" << nameToCheck << "\"" << std::endl;
    exit(-1);
}

inline std::shared_ptr<SingleAbilityExpr> getAbilityByName(const std::string&nameToCheck) {
    for (const auto&ability: GameManager::getInstance().getDeclaredAbilities()) {
        if (ability->getAbilityName() == nameToCheck) {
            return ability;
        }
    }
    std::cerr << "No ability found matching \"" << nameToCheck << "\"" << std::endl;
    exit(-1);
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

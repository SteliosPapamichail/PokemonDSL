//
// Created by Steli on 22/12/2023.
//

#ifndef UTILS_H
#define UTILS_H

#include "../pokemon_models/Pokemon.h"
#include <string>
#include <vector>

extern std::vector<Pokemon> declaredPokemons;

inline bool doesPokemonNameExist(const std::string&nameToCheck) {
    for (const Pokemon&pokemon: declaredPokemons) {
        if (pokemon.getName() == nameToCheck) {
            return true;
        }
    }
    return false;
}
#endif //UTILS_H

//
// Created by Steli on 21/12/2023.
//

#ifndef POKEMONUTILS_H
#define POKEMONUTILS_H

#include <string>
#include <unordered_map>

enum POKEMON_TYPE {
    Electric,
    Fire,
    Water,
    Grass
};

std::string PokemonTypeToString(POKEMON_TYPE type);
POKEMON_TYPE StringToPokemonType(const std::string&str);

#endif //POKEMONUTILS_H

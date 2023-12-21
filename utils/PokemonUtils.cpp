//
// Created by Steli on 21/12/2023.
//

#include "PokemonUtils.h"

std::string PokemonTypeToString(const POKEMON_TYPE type) {
    static const std::unordered_map<POKEMON_TYPE, std::string> typeToString = {
        {Electric, "Electric"},
        {Fire, "Fire"},
        {Water, "Water"},
        {Grass, "Grass"}
    };

    const auto typeStr = typeToString.find(type);
    return (typeStr != typeToString.end()) ? typeStr->second : "Unknown";
}

POKEMON_TYPE StringToPokemonType(const std::string&str) {
    static const std::unordered_map<std::string, POKEMON_TYPE> stringToType = {
        {"Electric", Electric},
        {"Fire", Fire},
        {"Water", Water},
        {"Grass", Grass}
    };

    const auto typeEnumEntry = stringToType.find(str);
    return (typeEnumEntry != stringToType.end()) ? typeEnumEntry->second : Electric; // Default to Electric if not found
}

//
// Created by Steli on 12/26/2023.
//

#ifndef POKEMONGEN_H
#define POKEMONGEN_H

#include "../../lexer/pokemon/PokemonExpressions.h"
#include "AbilityGen.h"
#include "IfExprGen.h"

// POKEMON CREATION
#define POKEMON \
new SinglePokemonDefExpr

#define POKEMONS \
MultiPokemonDefExpr()


/**
 * \brief Specifies the pokemon's type.
 */
#define TYPE false ? ""

/**
 * \brief Specifies the pokemon's maximum HP.
 */
#define HP false ? 0

#endif //POKEMONGEN_H

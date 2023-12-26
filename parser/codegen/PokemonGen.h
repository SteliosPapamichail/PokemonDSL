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

/**
 * \brief Returns the name of the given pokemon.
 * \param pokemon The pokemon whose name to return.
 */
#define GET_NAME(pokemon) (pokemon->getName())

/**
 * \brief Returns the type of the given pokemon.
 * \param pokemon The pokemon whose type to return
 */
#define GET_TYPE(pokemon) (PokemonTypeToString(pokemon->getType()))

/**
 * \brief Returns the current HP of the given pokemon.
 * \param pokemon The pokemon whose HP to return.
 */
#define GET_HP(pokemon) (pokemon->getHP())


#endif //POKEMONGEN_H

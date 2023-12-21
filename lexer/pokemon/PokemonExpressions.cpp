//
// Created by Steli on 21/12/2023.
//

#include "PokemonExpressions.h"

const Pokemon* SinglePokemonDefExpr::getPokemon() const {
    return _pokemon;
}

SinglePokemonDefExpr::~SinglePokemonDefExpr() {
    delete _pokemon;
}

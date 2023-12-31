//
// Created by Steli on 21/12/2023.
//

#include "PokemonExpressions.h"

#include <iostream>

Pokemon SinglePokemonDefExpr::getPokemon() const {
    return _pokemon;
}

SinglePokemonDefExpr* SinglePokemonDefExpr::operator,(const SinglePokemonDefExpr* other) {
    GameManager::getInstance().declarePokemon(other->getPokemon());
    return this;
}

MultiPokemonDefExpr* MultiPokemonDefExpr::operator[](const SinglePokemonDefExpr* pokemonDefExpr) {
    //cout << "called [] on multi" << endl;
    // declaredPokemons.insert(declaredPokemons.end() - pokemonDefExpr->getNumOfChainedPokemonDefs(),
    //                         pokemonDefExpr->getPokemon());
    return this;
}

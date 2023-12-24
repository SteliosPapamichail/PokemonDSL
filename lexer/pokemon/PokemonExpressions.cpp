//
// Created by Steli on 21/12/2023.
//

#include "PokemonExpressions.h"

#include <iostream>

Pokemon SinglePokemonDefExpr::getPokemon() const {
    return _pokemon;
}

unsigned int SinglePokemonDefExpr::getNumOfChainedPokemonDefs() const {
    return _numOfChainedPokemonDefs;
}

SinglePokemonDefExpr* SinglePokemonDefExpr::operator,(const SinglePokemonDefExpr* other) {
    cout << "called comma from " << this->getPokemon().getName() << endl;
    declaredPokemons.push_back(other->getPokemon());
    this->_numOfChainedPokemonDefs++;
    return this;
}

MultiPokemonDefExpr* MultiPokemonDefExpr::operator[](const SinglePokemonDefExpr* pokemonDefExpr) {
    //cout << "called [] on multi" << endl;
    // declaredPokemons.insert(declaredPokemons.end() - pokemonDefExpr->getNumOfChainedPokemonDefs(),
    //                         pokemonDefExpr->getPokemon());
    return this;
}

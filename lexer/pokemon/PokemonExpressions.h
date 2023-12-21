//
// Created by Steli on 21/12/2023.
//

#ifndef POKEMONEXPRESSIONS_H
#define POKEMONEXPRESSIONS_H
#include "../common/Expressions.h"
#include "../../parser/handlers/ErrorHandler.h"

class SinglePokemonDefExpr final : public Expr {
    Pokemon* _pokemon;

public:
    ~SinglePokemonDefExpr();

    ExprType getExprType() override {
        return CREATE_SINGLE_POKEMON_EXPR;
    }

    const Pokemon* getPokemon() const;

    SinglePokemonDefExpr(std::string name,
                         std::string type, const int hp) : Expr("Single Pokemon Definition Expression") {
        auto pokemonType = StringToPokemonType(type);
        ErrorHandler&errorHandler = ErrorHandler::getInstance();
        if (pokemonType == INVALID) {
            errorHandler.addError(
                Error("Invalid pokemon type specified for " + name, __LINE__));
        }
        else if (hp <= 0) {
            errorHandler.addError(
                Error("Invalid HP value specified for " + name, __LINE__));
        }
        else {
            _pokemon = new Pokemon{
                name, StringToPokemonType(type), hp
            };
        }
    }
};

#endif //POKEMONEXPRESSIONS_H

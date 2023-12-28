//
// Created by Steli on 21/12/2023.
//

#ifndef POKEMONEXPRESSIONS_H
#define POKEMONEXPRESSIONS_H

#include "../common/Expressions.h"
#include "../../parser/handlers/ErrorHandler.h"
#include "../../utils/Utils.h"

class SinglePokemonDefExpr final : public Expr {
    Pokemon _pokemon;
    unsigned int _numOfChainedPokemonDefs = 0;

public:
    ~SinglePokemonDefExpr() = default;

    ExprType getExprType() override {
        return CREATE_SINGLE_POKEMON_EXPR;
    }

    Pokemon getPokemon() const;

    unsigned int getNumOfChainedPokemonDefs() const;

    SinglePokemonDefExpr* operator,(const SinglePokemonDefExpr* other);

    SinglePokemonDefExpr(
        const std::string&name,
        const std::string&type,
        const int hp
    ) : Expr("Single Pokemon Definition Expression"),
        _pokemon(Pokemon(name, StringToPokemonType(type), static_cast<unsigned>(hp))) {

        const auto pokemonType = StringToPokemonType(type);
        ErrorHandler&errorHandler = ErrorHandler::getInstance();
        if (pokemonType == INVALID) {
            errorHandler.addError(
                Error("Invalid pokemon type specified for " + name, __LINE__));
        }
        else if (hp <= 0) {
            errorHandler.addError(
                Error("Invalid HP value specified for " + name, __LINE__));
        }
        else if (doesPokemonNameExist(name)) {
            errorHandler.addError(
                Error("Pokemon \"" + name + "\" has already been declared!", __LINE__));
        }
        else {
            GameManager::getInstance().declarePokemon(_pokemon);
        }
    }
};

class MultiPokemonDefExpr final : public Expr {
public:
    ExprType getExprType() override {
        return CREATE_MULTIPLE_POKEMON_EXPR;
    };

    MultiPokemonDefExpr* operator[](const SinglePokemonDefExpr* pokemonDefExpr);

    ~MultiPokemonDefExpr() = default;

    MultiPokemonDefExpr(): Expr("Multi Pokemon Definition Expression") {
    };
};

#endif //POKEMONEXPRESSIONS_H

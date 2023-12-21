//
// Created by Steli on 7/12/2023.
//

#ifndef EXPRESSIONS_H
#define EXPRESSIONS_H

#include <string>
#include <utility>

#include "../../pokemon_models/Pokemon.h"

using namespace std;

enum ExprType {
    CREATE_SINGLE_ABILITY_EXPR,
    CREATE_SINGLE_POKEMON_EXPR,
    CREATE_MULTIPLE_ABILITIES_EXPR,
    CREATE_MULTIPLE_POKEMON_EXPR,
    ABILITY_ACTION_EXPR
};

class Expr {
    string _name;

public:
    virtual string getName() const { return _name; }

    virtual ExprType getExprType() =0;

    explicit Expr(string name) : _name(std::move(name)) {
    }

protected:
    ~Expr() = default;
};

class AbilityActionExpr final : public Expr {
    //TODO:sp need to construct AST in this case
public:
    AbilityActionExpr() : Expr("Ability Action Expression") {
    }

    ExprType getExprType() override {
        return ABILITY_ACTION_EXPR;
    }
};

#endif //EXPRESSIONS_H

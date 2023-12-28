//
// Created by Steli on 7/12/2023.
//

#ifndef EXPRESSIONS_H
#define EXPRESSIONS_H

#include <string>
#include <utility>

enum ExprType {
    CREATE_SINGLE_ABILITY_EXPR,
    CREATE_SINGLE_POKEMON_EXPR,
    CREATE_MULTIPLE_ABILITIES_EXPR,
    CREATE_MULTIPLE_POKEMON_EXPR,
    ABILITY_ACTION_EXPR
};

class Expr {
    std::string _name;

public:
    virtual std::string getName() const { return _name; }

    virtual ExprType getExprType() =0;

    explicit Expr(std::string name) : _name(std::move(name)) {
    }

protected:
    ~Expr() = default;
};
#endif //EXPRESSIONS_H

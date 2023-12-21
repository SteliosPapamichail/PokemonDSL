//
// Created by Steli on 21/12/2023.
//

#ifndef ABILITYEXPRESSIONS_H
#define ABILITYEXPRESSIONS_H

#include "../common/Expressions.h"

class SingleAbilityExpr final : public Expr {
    string _abilityName;
    AbilityActionExpr* _action = nullptr;

public:
    ExprType getExprType() override {
        return CREATE_SINGLE_ABILITY_EXPR;
    }

    void setAbilityName(const string&name);

    string getAbilityName() const;

    explicit SingleAbilityExpr(string abilityName) : Expr(
                                                         "Single Ability Expression"
                                                     )
                                                     ,
                                                     _abilityName(std::move(abilityName)) {
    };
};

#endif //ABILITYEXPRESSIONS_H

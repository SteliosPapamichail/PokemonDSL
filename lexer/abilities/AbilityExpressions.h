//
// Created by Steli on 21/12/2023.
//

#ifndef ABILITYEXPRESSIONS_H
#define ABILITYEXPRESSIONS_H

#include "../../parser/handlers/ErrorHandler.h"
#include "../../utils/Utils.h"
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

    explicit SingleAbilityExpr(const string& abilityName) : Expr(
                                                         "Single Ability Expression"
                                                     )
                                                     ,
                                                     _abilityName(abilityName) {
        if (containsSpace(abilityName)) {
            ErrorHandler::getInstance().addError(
                Error(
                    "Ability names are not allowed to contain spaces!", __LINE__));
        }
    };
};

class MultiAbilityDefExpr final : public Expr {
public:
    ExprType getExprType() override {
        return CREATE_MULTIPLE_ABILITIES_EXPR;
    };

    MultiAbilityDefExpr* operator[](const SingleAbilityExpr* abilityExpr);

    ~MultiAbilityDefExpr() = default;

    MultiAbilityDefExpr(): Expr("Multi Ability Definition Expression") {
    };
};

#endif //ABILITYEXPRESSIONS_H

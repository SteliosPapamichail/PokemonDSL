//
// Created by Steli on 21/12/2023.
//

#ifndef ABILITYEXPRESSIONS_H
#define ABILITYEXPRESSIONS_H

#include "../../parser/handlers/ErrorHandler.h"
#include "../abilities/actions/ActionExpressions.h"

class SingleAbilityExpr final : public Expr {
    std::string _abilityName;
    AbilityActionExpr* _action = nullptr;
    std::vector<SingleAbilityExpr> _abilitiesCollector = {};

public:
    ExprType getExprType() override {
        return CREATE_SINGLE_ABILITY_EXPR;
    }

    void setAbilityName(const std::string&name);

    std::function<void()> getAbilityAction() const {
        return _action->getAction();
    }

    std::string getAbilityName() const;

    std::vector<SingleAbilityExpr> getAbilities() const;

    SingleAbilityExpr(const std::string&abilityName, AbilityActionExpr* action);

    SingleAbilityExpr operator()(const SingleAbilityExpr&other);

    SingleAbilityExpr* operator,(const SingleAbilityExpr* other);

    ~SingleAbilityExpr() = default;
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

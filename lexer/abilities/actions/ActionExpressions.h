//
// Created by Steli on 12/26/2023.
//

#ifndef ACTIONEXPRESSIONS_H
#define ACTIONEXPRESSIONS_H

#include <functional>
#include <utility>

#include "../../common/Expressions.h"

class AbilityActionExpr final : Expr {
    std::function<void()> _actionLamda;

public:
    virtual ~AbilityActionExpr() = default;

    ExprType getExprType() override;

    explicit AbilityActionExpr(std::function<void()> action) : Expr("Action Expression"), _actionLamda(std::move(action)) {
    }

    AbilityActionExpr() : Expr("Action Expression"), _actionLamda({}) {
    }

    std::function<void()> getAction() {
        return _actionLamda;
    }
};

#endif //ACTIONEXPRESSIONS_H

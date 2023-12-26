//
// Created by Steli on 12/26/2023.
//

#ifndef ACTIONEXPRESSIONS_H
#define ACTIONEXPRESSIONS_H

#include "../../common/Expressions.h"

class AbilityActionExpr final : Expr {
public:
    virtual ~AbilityActionExpr() = default;

    ExprType getExprType() override;

    AbilityActionExpr() : Expr("Action Expression") {
    }
};

#endif //ACTIONEXPRESSIONS_H

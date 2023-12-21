//
// Created by Steli on 21/12/2023.
//

#include "AbilityExpressions.h"

void SingleAbilityExpr::setAbilityName(const string&name) {
    _abilityName = name;
}

string SingleAbilityExpr::getAbilityName() const {
    return _abilityName;
}

//
// Created by Steli on 21/12/2023.
//

#include "AbilityExpressions.h"
#include "../../utils/Utils.h"
#include "../../game_manager/GameManager.h"

SingleAbilityExpr::SingleAbilityExpr(const std::string&abilityName, AbilityActionExpr* action) : Expr(
        "Single Ability Expression"
    )
    ,
    _abilityName(abilityName),
    _action(action) {
    if (containsSpace(abilityName)) {
        ErrorHandler::getInstance().addError(
            Error(
                "Ability names are not allowed to contain spaces!", __LINE__));
    }
    else {
        GameManager::getInstance().declareAbility(*this);
    }
};


void SingleAbilityExpr::setAbilityName(const std::string&name) {
    _abilityName = name;
}

std::string SingleAbilityExpr::getAbilityName() const {
    return _abilityName;
}

std::vector<SingleAbilityExpr> SingleAbilityExpr::getAbilities() const {
    return _abilitiesCollector;
}

SingleAbilityExpr SingleAbilityExpr::operator()(const SingleAbilityExpr&other) {
    this->_abilitiesCollector.push_back(other);
    for (const auto&ab: other.getAbilities()) {
        this->_abilitiesCollector.push_back(ab);
    }
    return *this;
}

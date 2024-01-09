//
// Created by Steli on 1/8/2024.
//

#include "ScopeManager.h"

void ScopeManager::pushLoopScope() {
    scope_stack.push(true);
}

void ScopeManager::pushOtherScope() {
    scope_stack.push(false);
}

void ScopeManager::popScope() {
    scope_stack.pop();
}

bool ScopeManager::getCurrentScope() {
    const auto top = scope_stack.top();
    popScope();
    return top;
}

ScopeManager& ScopeManager::getInstance() {
    static ScopeManager instance;
    return instance;
}

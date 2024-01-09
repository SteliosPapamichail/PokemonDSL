//
// Created by Steli on 1/8/2024.
//

#ifndef SCOPEMANAGER_H
#define SCOPEMANAGER_H
#include <stack>

class ScopeManager final {
    std::stack<bool> scope_stack;

    ScopeManager() = default;

    ~ScopeManager() = default;

    void popScope();

public:
    void pushLoopScope();

    void pushOtherScope();

    bool getCurrentScope();

    static ScopeManager& getInstance();
};

#endif //SCOPEMANAGER_H

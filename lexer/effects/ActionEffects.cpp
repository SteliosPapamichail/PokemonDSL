//
// Created by Steli on 1/8/2024.
//

#include "ActionEffects.h"

#include <vector>

bool RepeatableEffect::isComplete() const {
    return _isComplete;
}

void RepeatableEffect::applyEffect() const {
    _action();
}

ActiveEffect::ActiveEffect(const unsigned rounds, const std::function<void()>&f) : RepeatableEffect(rounds, f) {
    tick();
}

DelayedEffect::DelayedEffect(const unsigned rounds, const std::function<void()>&f) : RepeatableEffect(rounds, f) {
    tick();
}


void ActiveEffect::tick() {
    if (_numOfRounds > 0) {
        applyEffect();
        --_numOfRounds;
    }
    else {
        _isComplete = true;
    }
}

void DelayedEffect::tick() {
    if (_numOfRounds == 0) {
        applyEffect();
        _isComplete = true;
    }
    else if (_numOfRounds > 0) --_numOfRounds;
}

std::vector<RepeatableEffect *>& operator+(std::vector<RepeatableEffect *>&effects, RepeatableEffect* newEffect) {
    effects.push_back(std::move(newEffect));
    return effects;
}

//
// Created by Steli on 1/8/2024.
//

#ifndef ACTIONEFFECTS_H
#define ACTIONEFFECTS_H
#include <functional>

class RepeatableEffect {
protected:
    unsigned int _numOfRounds;
    std::function<void()> _action;
    bool _isComplete = false;

public:
    RepeatableEffect(const unsigned int rounds, const std::function<void()>&f) : _numOfRounds(rounds), _action(f) {}

    void applyEffect() const;

    virtual ~RepeatableEffect() = default;

    virtual void tick() = 0;

    bool isComplete() const;
};

class ActiveEffect final : public RepeatableEffect {
public:
    ActiveEffect(const unsigned int rounds, const std::function<void()>&f) : RepeatableEffect(rounds,f) {}

    void tick() override;
};

class DelayedEffect final : public RepeatableEffect {
public:
    DelayedEffect(const unsigned int rounds, const std::function<void()>&f) : RepeatableEffect(rounds,f) {}

    void tick() override;
};

#endif //ACTIONEFFECTS_H
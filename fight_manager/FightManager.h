//
// Created by Steli on 23/12/2023.
//

#ifndef FIGHTMANAGER_H
#define FIGHTMANAGER_H
#include <memory>

#include "../pokemon_models/Pokemon.h"

class Pokemon;
class SingleAbilityExpr;

class FightManager final {
    std::shared_ptr<Pokemon> _attacker = nullptr;
    std::shared_ptr<Pokemon> _defender = nullptr;

    FightManager() = default;

    FightManager(Pokemon* attacker, Pokemon* defender);

    void endRound() const;

public:
    static FightManager& getInstance();

    std::shared_ptr<Pokemon> getAttacker() const;

    void setAttacker(const std::shared_ptr<Pokemon>&pokemon);

    std::shared_ptr<Pokemon> getDefender() const;

    void setDefender(const std::shared_ptr<Pokemon>&pokemon);

    void startRound(unsigned int round) const;

    void commenceAttack() const;

    FightManager(FightManager const&) = delete;

    void operator=(FightManager const&) = delete;
};

#endif //FIGHTMANAGER_H

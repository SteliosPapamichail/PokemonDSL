//
// Created by Steli on 23/12/2023.
//

#ifndef FIGHTMANAGER_H
#define FIGHTMANAGER_H
#include <memory>

#include "../pokemon_models/Pokemon.h"

class Ability;
class Pokemon;

class FightManager final {
    std::shared_ptr<Pokemon> _attacker = nullptr;
    std::shared_ptr<Pokemon> _defender = nullptr;

    std::unique_ptr<Ability> _attackerAbility = nullptr;
    std::unique_ptr<Ability> _defenderAbility = nullptr;

    FightManager() = default;

    FightManager(Pokemon* attacker, Pokemon* defender);

    void clearSelectedAbilities();

    void checkEndGameConditions() const;

public:
    static FightManager& getInstance();

    std::shared_ptr<Pokemon> getAttacker() const;

    void setAttacker(const std::shared_ptr<Pokemon>&pokemon);

    std::shared_ptr<Pokemon> getDefender() const;

    void setDefender(const std::shared_ptr<Pokemon>&pokemon);

    void setAttackerAbility(Ability* ability);

    void setDefenderAbility(Ability* ability);

    void startRound() const;

    void commenceAttack(bool isAttacker) const;

    static std::shared_ptr<Pokemon> damage(std::shared_ptr<Pokemon> receiver);

    static std::shared_ptr<Pokemon> heal(std::shared_ptr<Pokemon> receiver);

    FightManager(FightManager const&) = delete;

    void operator=(FightManager const&) = delete;
};

#endif //FIGHTMANAGER_H

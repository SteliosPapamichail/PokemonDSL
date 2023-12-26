//
// Created by Steli on 23/12/2023.
//

#ifndef FIGHTMANAGER_H
#define FIGHTMANAGER_H
#include "../pokemon_models/Pokemon.h"

class FightManager final {
    Pokemon* _attacker = nullptr;
    Pokemon* _defender = nullptr;

    FightManager() = default;

    FightManager(Pokemon* attacker, Pokemon* defender) : _attacker(attacker), _defender(defender) {}

    void endRound() const;

public:
    static FightManager& getInstance();

    Pokemon* getAttacker() const;

    void setAttacker(Pokemon* pokemon);

    Pokemon* getDefender() const;

    void setDefender(Pokemon* pokemon);

    void startRound(unsigned int round) const;

    void commenceAttack() const;

    FightManager(FightManager const&) = delete;

    void operator=(FightManager const&) = delete;
};

#endif //FIGHTMANAGER_H
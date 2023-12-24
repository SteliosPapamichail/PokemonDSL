//
// Created by Steli on 23/12/2023.
//

#include "FightManager.h"

Pokemon* FightManager::getAttacker() const {
    return _attacker;
}

Pokemon* FightManager::getDefender() const {
    return _defender;
}

void FightManager::setAttacker(Pokemon* pokemon) {
    _attacker = pokemon;
}

void FightManager::setDefender(Pokemon* pokemon) {
    _defender = pokemon;
}


FightManager& FightManager::getInstance() {
    static FightManager instance;
    return instance;
}

void FightManager::startRound(const unsigned round) const {
    // heal pokemons if conditions are met at the beginning of the round
    if (round % 2 == 0) {
        if (_attacker->getType() == Grass) {
            _attacker->heal(0.05 * _attacker->getMaxHP());
        }
        if (_defender->getType() == Grass) {
            _defender->heal(0.05 * _defender->getMaxHP());
        }
    }
}


void FightManager::commenceAttack() const {

}

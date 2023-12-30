//
// Created by Steli on 23/12/2023.
//

#include "FightManager.h"
#include "../game_manager/GameManager.h"

FightManager::FightManager(Pokemon* attacker, Pokemon* defender) : _attacker(attacker), _defender(defender) {}


std::shared_ptr<Pokemon> FightManager::getAttacker() const {
    return _attacker;
}

std::shared_ptr<Pokemon> FightManager::getDefender() const {
    return _defender;
}

void FightManager::setAttacker(const std::shared_ptr<Pokemon>&pokemon) {
    _attacker = pokemon;
}

void FightManager::setDefender(const std::shared_ptr<Pokemon>&pokemon) {
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

void FightManager::endRound() const {
    if (_attacker->getHP() == 0 || _defender->getHP() == 0) {
        GameManager::getInstance().setIsGameOver(true);
    }
}

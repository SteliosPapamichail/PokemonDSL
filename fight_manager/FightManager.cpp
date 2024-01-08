//
// Created by Steli on 23/12/2023.
//

#include "FightManager.h"

#include <iostream>

#include "../game_manager/GameManager.h"

FightManager::FightManager(Pokemon* attacker, Pokemon* defender) : _attacker(attacker), _defender(defender) {
}

void FightManager::clearSelectedAbilities() {
    _attackerAbility = nullptr;
    _defenderAbility = nullptr;
}

void FightManager::setAttackerAbility(Ability* ability) {
    _attackerAbility = std::unique_ptr<Ability>(ability);
}

void FightManager::setDefenderAbility(Ability* ability) {
    _defenderAbility = std::unique_ptr<Ability>(ability);
}


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

void FightManager::startRound() const {
    // heal pokemons if conditions are met at the beginning of the round
    if (GameManager::getInstance().getRound() % 2 == 0) {
        if (_attacker->getType() == Grass) {
            healPokemon(_attacker, 0.05 * _attacker->getMaxHP());
        }
        if (_defender->getType() == Grass) {
            healPokemon(_defender, 0.05 * _attacker->getMaxHP());
        }
    }
    executeEffects();
}

void FightManager::cleanUp() {
    for (const auto effect: effects) {
        delete effect;
    }
}


void FightManager::executeEffects() {
    for (const auto effect: effects) {
        if (effect->isComplete()) continue;
        effect->tick();
    }
}


void FightManager::healPokemon(const std::shared_ptr<Pokemon>&pokemon, const int amount) {
    pokemon->setShouldHeal(true);
    (*pokemon) += amount;
}


//todo:sp can obviously be improved by moving the code-block into a function to
//avoid duplication of code but ain't nobody got time for that
void FightManager::commenceAttack(const bool isAttacker) const {
    // execute the selected ability
    if (isAttacker) {
        _attackerAbility->getAction()();
        std::cout << "\n~ " << _attacker->getName() << " used " << _attackerAbility->getAbilityName() << " ~\n" <<
                std::endl;
        std::cout << *_attacker << "\n\n\n" << *_defender << std::endl;
    }
    else {
        _defenderAbility->getAction()();
        std::cout << "\n~ " << _defender->getName() << " used " << _defenderAbility->getAbilityName() << " ~\n" <<
                std::endl;
        std::cout << *_defender << "\n\n\n" << *_attacker << std::endl;
    }
    checkEndGameConditions();
}

void FightManager::checkEndGameConditions() const {
    if (_attacker->hasBeenDefeated() || _defender->hasBeenDefeated()) {
        GameManager::getInstance().setIsGameOver(true);
    }
}

std::shared_ptr<Pokemon> FightManager::damage(std::shared_ptr<Pokemon> receiver) {
    receiver->setShouldTakeDmg(true);
    return receiver;
}

std::shared_ptr<Pokemon> FightManager::heal(std::shared_ptr<Pokemon> receiver) {
    receiver->setShouldHeal(true);
    return receiver;
}

std::shared_ptr<Pokemon> FightManager::setPokeballStatus(std::shared_ptr<Pokemon> receiver) {
    receiver->setEditingPokeballStatus(true);
    return receiver;
}

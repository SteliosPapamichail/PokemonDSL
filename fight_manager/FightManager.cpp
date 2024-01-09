//
// Created by Steli on 23/12/2023.
//

#include "FightManager.h"

#include <algorithm>
#include <iostream>
#include "../utils/Utils.h"
#include "../game_manager/GameManager.h"

std::vector<RepeatableEffect *> FightManager::effects;

FightManager::FightManager(Pokemon* attacker, Pokemon* defender) : _attacker(attacker), _defender(defender) {
}

void FightManager::clearSelectedAbilities() {
    _attackerAbility = nullptr;
}

void FightManager::setAttackerAbility(Ability* ability) {
    _attackerAbility = std::unique_ptr<Ability>(ability);
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
    const bool hasIncompleteEffect = std::any_of(effects.begin(), effects.end(), [](const RepeatableEffect* effect) {
        return !effect->isComplete();
    });
    if (hasIncompleteEffect) std::cout << YELLOW_TEXT << "\n-=- Battle effects are active -=-\n" << RESET_TEXT << std::endl;

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
void FightManager::commenceAttack() const {
    // execute the selected ability
    _attackerAbility->getAction()();
    std::cout << BLUE_TEXT << "\n~ " << _attacker->getName() << " used " << _attackerAbility->getAbilityName() << " ~\n" << RESET_TEXT <<
            std::endl;
    std::cout << *_attacker << "\n\n" << *_defender << std::endl;
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

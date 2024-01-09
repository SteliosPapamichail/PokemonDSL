//
// Created by Steli on 22/12/2023.
//

#include "GameManager.h"
#include <random>
#include <iostream>
#include "../utils/Utils.h"
#include "../fight_manager/FightManager.h"

GameManager::GameManager() : _round(1) {
    _activePlayer = _players[0];
    _activePlayer->beginTurn();
} ;

GameManager& GameManager::getInstance() {
    static GameManager instance;
    return instance;
}

void GameManager::promptUsersForPokemonSelection() {
    for (const auto p: _players) {
        std::string pokemonName;
        std::cout << p->getName() << " select pokemon:\n" << std::endl;
        std::cout << "----------------------------------------------" << std::endl;
        printDeclaredPokemons();
        std::cout << "----------------------------------------------" << std::endl;
        std::getline(std::cin, pokemonName);

        const auto selectedPokemon = getPokemonByName(pokemonName);
        p->setSelectedPokemon(selectedPokemon);
    }
    initiateFight();
}


void GameManager::changeTurns() {
    getInactivePlayer()->beginTurn();
    _activePlayer->endTurn();
    _activePlayer = _players[0]->hasTurn() ? _players[0] : _players[1];
    FightManager::getInstance().setAttacker(_activePlayer->getPlayerPokemon());
    FightManager::getInstance().setDefender(getInactivePlayer()->getPlayerPokemon());
}

unsigned GameManager::getRound() const {
    return _round;
}

void GameManager::nextRound() {
    _round++;
}

Player* GameManager::getInactivePlayer() const {
    return _players[0]->hasTurn() ? _players[1] : _players[0];
}

bool GameManager::isGameOver() const {
    return _isGameOver;
}

void GameManager::setIsGameOver(const bool isOver) {
    _isGameOver = isOver;
}

void GameManager::initiateFight() {
    FightManager::getInstance().setAttacker(_activePlayer->getPlayerPokemon());
    FightManager::getInstance().setDefender(getInactivePlayer()->getPlayerPokemon());
    promptUsersForAbilitySelection();
}

void GameManager::printRoundHeader() const {
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
    std::cout << "Round " << getRound() << std::endl;
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
}

void GameManager::declareWinner() const {
    const auto winner = _activePlayer->getPlayerPokemon()->hasBeenDefeated() ? getInactivePlayer() : _activePlayer;
    std::cout << "\n\n==============================================" << std::endl;
    std::cout << GREEN_TEXT << winner->getName() << "(" << winner->getPlayerPokemon()->getName() << ") has won!" << RESET_TEXT <<
            std::endl;
    std::cout << "==============================================\n" << std::endl;
}

void GameManager::promptUsersForAbilitySelection() {
    while (!_isGameOver) {
        printRoundHeader();
        FightManager::getInstance().startRound();
        for (const auto p: _players) {
            if (p->getPlayerPokemon()->getIsInPokeball()) {
                std::cout << RED_TEXT << "\n\n" << p->getName() << "(" << p->getPlayerPokemon()->getName() <<
                        ") doesn\'t have a Pokemon out of a Pokeball so they cannot cast an ability.\n\n" << RESET_TEXT << std::endl;
                changeTurns();
                continue;
            }

            std::string abilityName;
            std::cout << p->getPlayerPokemon()->getName() << "(" << p->getName() << ") select an ability:\n" << std::endl;
            std::cout << "----------------------------------------------" << std::endl;
            p->getPlayerPokemon()->printLearnedAbilities();
            std::cout << "----------------------------------------------" << std::endl;
            std::getline(std::cin, abilityName);

            const auto selectedAbility = getAbilityByName(abilityName);
            const auto abilityToAssign = new Ability{
                selectedAbility->getAbilityName(),
                selectedAbility->getAbilityAction()
            };

            FightManager::getInstance().setAttackerAbility(
                abilityToAssign
            );
            FightManager::getInstance().commenceAttack();

            if (_isGameOver) break;

            changeTurns();
        }
        nextRound();
    }
    declareWinner();
}


std::vector<std::shared_ptr<SingleAbilityExpr>> GameManager::getDeclaredAbilities() const {
    return _declaredAbilities;
}

std::vector<std::shared_ptr<Pokemon>> GameManager::getDeclaredPokemons() const {
    return _declaredPokemons;
}

void GameManager::declarePokemon(const Pokemon&pokemon) {
    _declaredPokemons.push_back(std::make_shared<Pokemon>(pokemon));
}

void GameManager::declareAbility(const SingleAbilityExpr&ability) {
    _declaredAbilities.push_back(std::make_shared<SingleAbilityExpr>(ability));
}


void GameManager::printDeclaredPokemons() const {
    for (const auto&pokemon: _declaredPokemons) {
        std::cout << pokemon->getName() << std::endl;
    }
}

void GameManager::printDeclaredAbilities() const {
    for (const auto&ability: _declaredAbilities) {
        std::cout << ability->getAbilityName() << std::endl;
    }
}

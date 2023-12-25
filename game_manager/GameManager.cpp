//
// Created by Steli on 22/12/2023.
//

#include "GameManager.h"
#include <random>

#include "../fight_manager/FightManager.h"


int GameManager::generateRandomBinary() {
    // Use std::random_device to seed the generator
    std::random_device rd;

    // Use std::mt19937 as the random number generator engine
    std::mt19937 gen(rd());

    // Use std::uniform_int_distribution to generate a random number in the range [0, 1]
    std::uniform_int_distribution<> distribution(0, 1);

    // Generate a random number
    return distribution(gen);
}

GameManager& GameManager::getInstance() {
    static GameManager instance;
    return instance;
}

void GameManager::promptUsersForPokemonSelection() {
    for (const auto p: _players) {
        std::string pokemonName;
        std::cout << p->getName() << " select pokemon:" << std::endl;
        std::cout << "----------------------------------------------" << std::endl;
        printDeclaredPokemons();
        std::cout << "----------------------------------------------" << std::endl;
        std::cin >> pokemonName;

        Pokemon* selectedPokemon = getPokemonByName(pokemonName);
        if (selectedPokemon == nullptr) {
            std::cerr << "No pokemon matching " << pokemonName << std::endl;
            exit(-1); //todo:sp keep prompting while value is invalid
        }
        p->setSelectedPokemon(selectedPokemon);
    }
    initiateFight();
}


void GameManager::changeTurns() {
    _activePlayer = _players[0]->hasTurn() ? _players[1] : _players[0];
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


void GameManager::initiateFight() const {
    //todo:sp print console
    FightManager::getInstance().setAttacker(_activePlayer->getPlayerPokemon());
    FightManager::getInstance().setDefender(getInactivePlayer()->getPlayerPokemon());
}

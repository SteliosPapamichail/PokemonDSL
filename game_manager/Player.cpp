//
// Created by Steli on 22/12/2023.
//

#include "Player.h"

#include <utility>

#include "../lexer/pokemon/PokemonExpressions.h"

const std::string& Player::getName() const {
    return _name;
}

void Player::beginTurn() {
    _isPlaying = true;
}

void Player::endTurn() {
    _isPlaying = false;
}

bool Player::hasTurn() const {
    return _isPlaying;
}

std::shared_ptr<Pokemon> Player::getPlayerPokemon() const {
    return _selectedPokemon;
}

void Player::setSelectedPokemon(std::shared_ptr<Pokemon> pokemon) {
    _selectedPokemon = std::shared_ptr<Pokemon>(std::move(pokemon));
}

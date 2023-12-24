//
// Created by Steli on 22/12/2023.
//

#include "Player.h"

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

Pokemon * Player::getPlayerPokemon() const {
    return _selectedPokemon;
}

void Player::setSelectedPokemon(Pokemon* pokemon) {
    _selectedPokemon = pokemon;
}

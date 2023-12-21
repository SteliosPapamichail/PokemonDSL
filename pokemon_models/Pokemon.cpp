//
// Created by Steli on 9/12/2023.
//

#include "Pokemon.h"

std::string Pokemon::getName() const { return name; }
POKEMON_TYPE Pokemon::getType() const { return type; }
unsigned int Pokemon::getHP() const { return hp; }
bool Pokemon::getCanPerformAbility() const { return canPerformAbility; }
void Pokemon::setCanPerformAbility(const bool newValue) { canPerformAbility = newValue; }

Pokemon::Pokemon(std::string name, const POKEMON_TYPE type, const unsigned int hp) : name(std::move(name)), type(type),
    hp(hp) {
    MAX_HP = hp;
}

void Pokemon::takeDamage(const unsigned int damage) {
    if (hp - damage <= 0) {
        hp = 0;
    }
    else {
        hp -= damage;
    }
}

void Pokemon::heal(const unsigned int amount) {
    if (hp + amount > MAX_HP) {
        hp = MAX_HP;
    }
    else {
        hp += amount;
    }
}

bool Pokemon::hasBeenDefeated() const { return hp == 0; }

//
// Created by Steli on 9/12/2023.
//

#include <iostream>
#include "../lexer/abilities/AbilityExpressions.h"
#include "Pokemon.h"


Ability::Ability(std::string name, const std::function<void()>&action) : _abilityName(std::move(name)),
                                                                         _action(action) {}


std::string Pokemon::getName() const { return name; }
POKEMON_TYPE Pokemon::getType() const { return type; }
unsigned int Pokemon::getHP() const { return hp; }
bool Pokemon::getCanPerformAbility() const { return canPerformAbility; }
void Pokemon::setCanPerformAbility(const bool newValue) { canPerformAbility = newValue; }

std::ostream& operator<<(std::ostream&os, const Pokemon&pokemon) {
    os << "[" << PokemonTypeToString(pokemon.getType()) << "]" << " " << pokemon.getName() << " (" << pokemon.getHP() <<
            "HP)";
    return os;
}

std::vector<Ability> Pokemon::getAbilities() const {
    return _learnedAbilities;
}


void Pokemon::learnAbility(const Ability&ability) {
    _learnedAbilities.push_back(ability);
}

Pokemon* Pokemon::operator[](const SingleAbilityExpr&ability) {
    for (const auto&ab: ability.getAbilities()) {
        this->learnAbility(Ability(ab.getAbilityName(), ab.getAbilityAction()));
    }
    return this;
}

Pokemon::Pokemon(std::string name, const POKEMON_TYPE type, const unsigned int hp) : name(std::move(name)), type(type),
    hp(hp) {
    MAX_HP = hp;
}

void Pokemon::takeDamage(const unsigned int damage, const POKEMON_TYPE attackerType, const unsigned int round) {
    auto damageToTake = 0;

    if (this->getType() == Electric) {
        if (attackerType == Fire) {
            // 30% less damage
            damageToTake -= 0.3 * damage;
        }
        else {
            // 20% less damage
            damageToTake -= 0.2 * damage;
        }
    }
    else if (this->getType() == Fire) {
        damageToTake = damage;
    }
    else if (attackerType == Water) {
        // 7% more damage
        damageToTake += 0.07 * damage;
    }
    else if (this->getType() == Water) {
        // 7% less damage
        damageToTake -= 0.07 * damage;
    }
    else if (attackerType == Grass && (round % 2 != 0)) {
        // 7% more damage on odd rounds
        damageToTake += 0.07 * damage;
    }

    if (hp - damageToTake <= 0) {
        hp = 0;
    }
    else {
        hp -= damageToTake;
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

bool Pokemon::getIsInPokeball() const {
    return isInPokeball;
}

void Pokemon::setIsInPokeball(bool placeInPokeball) {
    isInPokeball = placeInPokeball;
}

unsigned Pokemon::getMaxHP() const {
    return MAX_HP;
}

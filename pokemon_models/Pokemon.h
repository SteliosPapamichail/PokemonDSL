//
// Created by Steli on 9/12/2023.
//

#ifndef POKEMON_H
#define POKEMON_H
#include <string>
#include <iostream>
#include "../utils/PokemonUtils.h"

class Pokemon final {
    std::string name;
    POKEMON_TYPE type;
    unsigned int hp;
    unsigned int MAX_HP;
    bool canPerformAbility = true;

public:
    friend std::ostream& operator<<(std::ostream& os, const Pokemon& pokemon);

    std::string getName() const;

    POKEMON_TYPE getType() const;

    unsigned int getHP() const;

    bool getCanPerformAbility() const;

    void setCanPerformAbility(bool newValue);

    ~Pokemon() = default;

    Pokemon(std::string name, POKEMON_TYPE type, unsigned int hp);

    void takeDamage(unsigned int damage);

    void heal(unsigned int amount);

    bool hasBeenDefeated() const;
};

#endif //POKEMON_H

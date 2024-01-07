//
// Created by Steli on 9/12/2023.
//

#ifndef POKEMON_H
#define POKEMON_H
#include <functional>
#include <string>
#include <vector>


#include "../utils/PokemonUtils.h"

class SingleAbilityExpr;

class Ability final {
    std::string _abilityName;
    std::function<void()> _action = {};

public:
    Ability(std::string name, const std::function<void()>&action);

    std::string getAbilityName() const;

    std::function<void()> getAction() const;
};

class Pokemon final {
    std::string name;
    POKEMON_TYPE type;
    unsigned int hp;
    unsigned int MAX_HP;
    bool canPerformAbility = true;
    bool isInPokeball = false;
    std::vector<Ability> _learnedAbilities = {};
    bool _shouldTakeDmg = false;
    bool _shouldHeal = false;

    void learnAbility(const Ability&ability);

    void takeDamage(unsigned int damage, POKEMON_TYPE attackerType, unsigned int round);

    void heal(unsigned int amount);

public:
    friend std::ostream& operator<<(std::ostream&os, const Pokemon&pokemon);

    void setShouldHeal(bool heal);

    void setShouldTakeDmg(bool takeDmg);

    bool getShouldTakeDmg() const;

    bool getShouldHeal() const;

    std::string getName() const;

    POKEMON_TYPE getType() const;

    unsigned int getHP() const;

    unsigned int getMaxHP() const;

    bool getCanPerformAbility() const;

    bool getIsInPokeball() const;

    void setIsInPokeball(bool placeInPokeball);

    void setCanPerformAbility(bool newValue);

    void printLearnedAbilities() const;

    ~Pokemon() = default;

    Pokemon(std::string name, POKEMON_TYPE type, unsigned int hp);

    Pokemon operator[](const SingleAbilityExpr&ability);

    Pokemon* operator,(int amount);

    Pokemon* operator+=(int amount);

    bool hasBeenDefeated() const;

    std::vector<Ability> getAbilities() const;
};

#endif //POKEMON_H

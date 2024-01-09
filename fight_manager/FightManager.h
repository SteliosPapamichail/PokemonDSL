//
// Created by Steli on 23/12/2023.
//

#ifndef FIGHTMANAGER_H
#define FIGHTMANAGER_H
#include <memory>

#include "../lexer/effects/ActionEffects.h"
#include "../pokemon_models/Pokemon.h"

class Ability;
class Pokemon;

/**
 * \brief Singleton class that is responsible for managing the fights between
 * the selected pokemons.
 */
class FightManager final {
    std::shared_ptr<Pokemon> _attacker = nullptr;
    std::shared_ptr<Pokemon> _defender = nullptr;

    std::unique_ptr<Ability> _attackerAbility = nullptr;

    FightManager() = default;

    FightManager(Pokemon* attacker, Pokemon* defender);

    void clearSelectedAbilities();

    void checkEndGameConditions() const;

    static void healPokemon(const std::shared_ptr<Pokemon>&pokemon, int amount);

    static void executeEffects();

public:
    static FightManager& getInstance();

    static std::vector<RepeatableEffect*> effects;

    static void cleanUp();

    std::shared_ptr<Pokemon> getAttacker() const;

    void setAttacker(const std::shared_ptr<Pokemon>&pokemon);

    std::shared_ptr<Pokemon> getDefender() const;

    void setDefender(const std::shared_ptr<Pokemon>&pokemon);

    void setAttackerAbility(Ability* ability);

    void startRound() const;

    void commenceAttack() const;

    static std::shared_ptr<Pokemon> damage(std::shared_ptr<Pokemon> receiver);

    static std::shared_ptr<Pokemon> heal(std::shared_ptr<Pokemon> receiver);

    static std::shared_ptr<Pokemon> setPokeballStatus(std::shared_ptr<Pokemon> receiver);

    FightManager(FightManager const&) = delete;

    void operator=(FightManager const&) = delete;
};

#endif //FIGHTMANAGER_H

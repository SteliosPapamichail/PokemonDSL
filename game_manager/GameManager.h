//
// Created by Steli on 22/12/2023.
//

#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "Player.h"
#include "../lexer/abilities/AbilityExpressions.h"
#include "../pokemon_models/Pokemon.h"

class GameManager final {
    std::vector<Pokemon> _declaredPokemons = {};
    std::vector<SingleAbilityExpr> _declaredAbilities = {};
    Player* _players[2] = {
        new Player{"Player 1"},
        new Player{"Player 2"}
    };

    Player* _activePlayer = nullptr;
    unsigned int _round;
    bool _isGameOver = false;

    static int generateRandomBinary();

    GameManager();

    Player* getInactivePlayer() const;

    void changeTurns();

    void initiateFight() const;

public:
    std::vector<Pokemon> getDeclaredPokemons() const;
    std::vector<SingleAbilityExpr> getDeclaredAbilities() const;

    void declarePokemon(const Pokemon& pokemon);
    void declareAbility(const SingleAbilityExpr& ability);

    void printDeclaredPokemons() const;

    void printDeclaredAbilities() const;

    static GameManager& getInstance();

    GameManager(GameManager const&) = delete;

    void operator=(GameManager const&) = delete;

    void promptUsersForPokemonSelection();

    unsigned int getRound() const;

    void nextRound();

    bool isGameOver() const;

    void setIsGameOver(bool isOver);
};

#endif //GAMEMANAGER_H

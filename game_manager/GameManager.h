//
// Created by Steli on 22/12/2023.
//

#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "Player.h"
#include "../utils/Utils.h"

extern void printDeclaredPokemons();

class GameManager final {
    Player* _players[2] = {
        new Player{"Player 1"},
        new Player{"Player 2"}
    };

    Player* _activePlayer = nullptr;
    unsigned int _round;

    static int generateRandomBinary();

    GameManager(): _round(0) {
        _activePlayer = _players[generateRandomBinary()];
        _activePlayer->beginTurn();
    } ;

    Player* getInactivePlayer() const;

    void changeTurns();

public:
    static GameManager& getInstance();

    GameManager(GameManager const&) = delete;

    void operator=(GameManager const&) = delete;

    void promptUsersForPokemonSelection();

    void initiateFight() const;

    unsigned int getRound() const;

    void nextRound();
};

#endif //GAMEMANAGER_H

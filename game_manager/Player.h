//
// Created by Steli on 22/12/2023.
//

#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <utility>

class Pokemon;

class Player final {
    std::string _name;
    bool _isPlaying = false;
    Pokemon* _selectedPokemon = nullptr;

public:
    bool hasTurn() const;

    void beginTurn();

    void endTurn();

    Pokemon* getPlayerPokemon() const;

    void setSelectedPokemon(Pokemon* pokemon);

    const std::string& getName() const;

    explicit Player(std::string name) : _name(std::move(name)) {
    }

    ~Player() = default;
};
#endif //PLAYER_H

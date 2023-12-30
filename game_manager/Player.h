//
// Created by Steli on 22/12/2023.
//

#ifndef PLAYER_H
#define PLAYER_H
#include <memory>
#include <string>
#include <utility>

class Pokemon;

class Player final {
    std::string _name;
    bool _isPlaying = false;
    std::shared_ptr<Pokemon> _selectedPokemon = nullptr;

public:
    bool hasTurn() const;

    void beginTurn();

    void endTurn();

    std::shared_ptr<Pokemon> getPlayerPokemon() const;

    void setSelectedPokemon(std::shared_ptr<Pokemon> pokemon);

    const std::string& getName() const;

    explicit Player(std::string name) : _name(std::move(name)) {
    }

    ~Player() = default;
};
#endif //PLAYER_H

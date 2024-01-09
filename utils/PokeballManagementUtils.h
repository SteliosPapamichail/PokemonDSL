//
// Created by Steli on 1/7/2024.
//

#ifndef POKEBALLMANAGEMENTUTILS_H
#define POKEBALLMANAGEMENTUTILS_H

/**
 * \brief Helper class that is used to represent a command
 * that releases a pokemon from its pokeball.
 */
class a final {
public:
    a operator-() const;

    a operator--() const;

    a() = default;

    ~a() = default;
};

#endif //POKEBALLMANAGEMENTUTILS_H

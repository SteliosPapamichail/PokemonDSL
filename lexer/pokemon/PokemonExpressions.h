//
// Created by Steli on 21/12/2023.
//

#ifndef POKEMONEXPRESSIONS_H
#define POKEMONEXPRESSIONS_H
#include "../common/Expressions.h"

class SinglePokemonDefExpr final : public Expr {
    unsigned int _hp;
    std::string _name;
    std::string _type;
    Pokemon* _pokemon;

public:
    ~SinglePokemonDefExpr();

    const Pokemon* getPokemon() const;

    SinglePokemonDefExpr(const unsigned int hp, std::string name,
                         std::string type) : Expr("Single Pokemon Definition Expression"), _hp(hp),
                                             _name(std::move(name)), _type(std::move(type)) {
        _pokemon = new Pokemon{
            name, StringToPokemonType(type), hp
        };
    }
};

#endif //POKEMONEXPRESSIONS_H

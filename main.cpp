//
// Created by Steli on 22/12/2023.
//

#include "parser/CodeGen.h"

BEGIN_GAME
    CREATE POKEMON {
            NAME: "Pikachu",
            TYPE: "Electric",
            HP: 120
    }
    CREATE POKEMON {
            NAME: "Squirtle",
            TYPE: "Water",
            HP: 100
    }
    CREATE POKEMONS [
        POKEMON{
            NAME: "Ho Oh",
            TYPE: "Fire",
            HP: 120
        },
        POKEMON{
            NAME: "Bulbasaur",
            TYPE: "Grass",
            HP: 85
        }
    ]
END_GAME
//
// Created by Steli on 22/12/2023.
//

#include "parser/PokemonLeague_4020.h"

BEGIN_GAME
    CREATE POKEMON{
              NAME : "Pikachu",
              TYPE : "Electric",
              HP : 120
          }
    CREATE POKEMON{
              NAME : "Squirtle",
              TYPE : "Water",
              HP : 100
          }
    CREATE POKEMONS[
              POKEMON{
                  NAME : "Ho Oh",
                  TYPE : "Fire",
                  HP : 120
              },
              POKEMON{
                  NAME : "Bulbasaur",
                  TYPE : "Grass",
                  HP : 85
              }
          ]

    CREATE ABILITY {
        NAME: "Electric_Shock",
        ACTION: START
            // IF GET_HP(ATTACKER) < 30 DO
            //     HEAL ATTACKER 25
            // ELSE
            //     HEAL ATTACKER 15
            // END
        END
    }
    CREATE ABILITY {
        NAME: "Lightning_Rod",
        ACTION: START
        END
    }
    CREATE ABILITY {
        NAME: "Flame_Wheel",
        ACTION: START
        END
    }
    DEAR "Pikachu" LEARN [
        ABILITY_NAME(Electric_Shock)
        ABILITY_NAME(Lightning_Rod)
    ]
    DEAR "Ho Oh" LEARN [
        ABILITY_NAME(Flame_Wheel)
    ]
    DUEL
END_GAME

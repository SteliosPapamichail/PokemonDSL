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

    CREATE ABILITIES [
        ABILITY {
            NAME: "Electric_Shock",
            ACTION: START
                // IF true DO
                //
                // END
            END
        },
        ABILITY {
            NAME: "Lightning_Rod",
            ACTION: START
            END
        }
    ]
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

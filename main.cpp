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
                  HP : 200
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
                FOR 5 ROUNDS DO
                    DAMAGE DEFENDER 10
                    SHOW "Calling for loop" << std::endl;
                END
            END
        },
        ABILITY {
            NAME: "Lightning_Rod",
            ACTION: START
                IF GET_NAME(ATTACKER) == "Pikachu" DO
                    SHOW "name of attacker is pikachu" << std::endl;
                END
                IF GET_HP(DEFENDER) == 200 DO
                    SHOW "Defender is Ho Oh (200 hp)" << std::endl;
                END
                IF GET_TYPE(DEFENDER) == "Fire" DO
                    SHOW "Defender is fire type" << std::endl;
                END
            END
        }
    ]
    CREATE ABILITY {
        NAME: "Flame_Wheel",
        ACTION: START
            AFTER 2 ROUNDS DO
                DAMAGE ATTACKER 60
                SHOW "Applying after effect" << std::endl;
            END
        END
    }
    CREATE ABILITY {
        NAME: "Ember",
        ACTION: START
            AFTER 3 ROUNDS DO
                SHOW "EMBER called" << std::endl;
        END
    END
    }
    DEAR "Pikachu" LEARN [
        ABILITY_NAME(Electric_Shock)
        ABILITY_NAME(Lightning_Rod)
    ]
    DEAR "Ho Oh" LEARN [
        ABILITY_NAME(Flame_Wheel)
        ABILITY_NAME(Ember)
    ]
    DUEL
END_GAME

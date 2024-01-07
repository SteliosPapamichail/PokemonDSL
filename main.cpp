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
                //todo:sp use to test if/else and logical expressions
                // IF NOT(false) DO
                //     std::cout << "called from not" << std::endl;
                // ELSE_IF AND(false, false) DO
                //
                // ELSE_IF OR(false,true) DO
                //     std::cout << "else if called fro OR" << std::endl;
                // ELSE
                //     std::cout << "else called!" << std::endl;
                // END
            END
        },
        ABILITY {
            NAME: "Lightning_Rod",
            ACTION: START
                //SHOW IS_IN_POKEBALL(DEFENDER) << std::endl;
                POKEBALL DEFENDER _
                // SHOW IS_IN_POKEBALL(DEFENDER) << std::endl;
                // POKEBALL DEFENDER ---α
                // SHOW IS_IN_POKEBALL(DEFENDER) << std::endl;
                //DAMAGE ATTACKER 200
                //todo:sp use to test getters
                // IF GET_NAME(ATTACKER) == "Pikachu" DO
                //     std::cout << "name of attacker is pikachu" << std::endl;
                // END
                // IF GET_HP(DEFENDER) == 200 DO
                //     std::cout << "Defender is Ho Oh (200 hp)" << std::endl;
                //     DAMAGE DEFENDER 100
                // END
                // IF GET_TYPE(DEFENDER) == "Fire" DO
                //     std::cout << "Defender is fire type" << std::endl;
                // END
            END
        }
    ]
    CREATE ABILITY {
        NAME: "Flame_Wheel",
        ACTION: START
            HEAL ATTACKER 20
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

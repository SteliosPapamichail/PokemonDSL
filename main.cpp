//
// Created by Steli on 22/12/2023.
//

#include "parser/PokemonLeague_4020.h"

BEGIN_GAME
 CREATE ABILITY{
           NAME : "Bite",
           ACTION
               : START
                   //Επιστρέφει το αντίπαλο pokemon στο pokeball
                   POKEBALL DEFENDER _
     // Μετά απο 2 γύρους ξαναβγάζει τον αντίπαλο(DEFENDER)
     AFTER
              2 ROUNDS DO
                  POKEBALL DEFENDER ---α
     END
     END
       }
CREATE ABILITY{
          NAME : "Solar_Power",
          ACTION
              : START
                  // Για 5 γύρους κάνει 8 damage στον αντίπαλο (DEFENDER)
                  FOR
                         5 ROUNDS DO
                             DAMAGE DEFENDER 8
    END
    END
      }
CREATE ABILITY{
          NAME : "Slash",
          ACTION
              : START
                  // Κάνει 22 damage στον αντίπαλο (DEFENDER)
                  DAMAGE DEFENDER 22
    END
      }
CREATE ABILITY{
          NAME : "Blaze",
          ACTION
              : START
                  // Κάνει heal στον εαυτό του (ATTACKER)
                  HEAL ATTACKER 30
    END
      }
CREATE POKEMON{
          NAME : "Charizard",
          TYPE : "Fire",
          HP : 100
      }
CREATE POKEMON{
          NAME : "Pikachu",
          TYPE : "Electric",
          HP : 90
      }
DEAR"Charizard" LEARN[
                ABILITY_NAME(Bite)
                ABILITY_NAME(Solar_Power)
                ABILITY_NAME(Slash)
                ABILITY_NAME(Blaze)
            ]
DEAR"Pikachu" LEARN[
                ABILITY_NAME(Bite)
                ABILITY_NAME(Slash)
            ]
DUEL
END_GAME

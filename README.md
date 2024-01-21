# C++ based Pokémon DSL
Author: Stelios Papamichail (csd4020) <br/>
Std version: 11
# Compilation & Execution

In order to compile the project and create the executable, simply perform the following commands:
1) `mkdir build`
2) `cd build`
3) `cmake ..`
4) `make`

To execute the program, simply run `./PokemonLeague_4020` executable.

# Language Elements

## Pokemon Definitions

```
CREATE POKEMON { 
  NAME: "name", 
  TYPE: "type", 
  HP: health_points 
} 
CREATE POKEMONS [  
  POKEMON { 
    NAME: "name", 
    TYPE: "type", 
    HP: health_points 
  }, 
  POKEMON { 
    NAME: "name", 
    TYPE: "type", 
    HP: health_points 
  }, 
  ... 
]
```

Example:

```
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
```


## Ability Definition 
```
CREATE ABILITY { 
 NAME: "ability_name", 
 ACTION: START  
  ... 
 END 
} 
CREATE ABILITIES [  
 ABILITY { 
  NAME: "ability_name", 
  ACTION: START  
   ... 
  END 
 }, 
 ABILITY { 
  NAME: "ability_name", 
  ACTION: START  
   ... 
  END  
 }, 
... 
]
```

Example:
 
 ```
CREATE ABILITY { 
 NAME: "Electric_Shock", 
 ACTION: START 
  IF GET_HP(ATTACKER) < 30 DO 
   HEAL ATTACKER 25 
  ELSE  
   HEAL ATTACKER 15 
  END 
 END 
}

CREATE ABILITY { 
 NAME: "Solar_Power", 
 ACTION: START 
  POKEBALL ATTACKER ---α 
  DAMAGE DEFENDER 20 
 END 
}

CREATE ABILITIES [ 
 ABILITY { 
  NAME: "Electric_Shock", 
  ACTION: START 
   IF GET_HP (ATTACKER) < 30 DO 
    HEAL ATTACKER 25 
   ELSE  
    HEAL ATTACKER 15 
   END 
  END 
 }, 
 ABILITY { 
  NAME: "Blaze", 
  ACTION: START 
   DAMAGE DEFENDER 22  
  END 
 } 
]
```

  ## Teaching abilities to Pokemon 

```
DEAR "pokemon name" LEARN [ 
ABILITY_NAME(ability_name) 
ABILITY_NAME(ability_name) 
... 
]
```

Example:

```
DEAR "Pikachu" LEARN [ 
ABILITY_NAME(Electric_Shock) 
ABILITY_NAME(Lightning_Rod) 
] 
DEAR "Ho Oh" LEARN [ 
ABILITY_NAME(Solar_Power) 
ABILITY_NAME(Blaze) 
ABILITY_NAME(Tough_Claws) 
ABILITY_NAME(Drought) 
]
```

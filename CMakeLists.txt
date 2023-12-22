cmake_minimum_required(VERSION 3.27)
project(PokemonLeague_4020)

set(CMAKE_CXX_STANDARD 11)

add_executable(PokemonLeague_4020 main.cpp
        lexer/common/Expressions.h
        parser/CodeGen.h
        parser/handlers/ErrorHandler.cpp
        parser/handlers/ErrorHandler.h
        pokemon_models/Pokemon.cpp
        pokemon_models/Pokemon.h
        utils/PokemonUtils.cpp
        utils/PokemonUtils.h
        lexer/common/Expressions.cpp
        lexer/pokemon/PokemonExpressions.cpp
        lexer/pokemon/PokemonExpressions.h
        lexer/abilities/AbilityExpressions.cpp
        lexer/abilities/AbilityExpressions.h
        utils/Utils.h)

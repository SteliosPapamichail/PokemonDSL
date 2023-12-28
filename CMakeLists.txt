cmake_minimum_required(VERSION 3.27)
project(PokemonLeague_4020)

set(CMAKE_CXX_STANDARD 11)

add_executable(PokemonLeague_4020 main.cpp
        lexer/common/Expressions.h
        parser/PokemonLeague_4020.h
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
        utils/Utils.h
        game_manager/Player.cpp
        game_manager/Player.h
        game_manager/GameManager.cpp
        game_manager/GameManager.h
        fight_manager/FightManager.cpp
        fight_manager/FightManager.h
        main.cpp
        lexer/abilities/actions/ActionExpressions.cpp
        lexer/abilities/actions/ActionExpressions.h
        parser/codegen/GameLifecycleGen.h
        parser/codegen/PokemonGen.h
        parser/codegen/AbilityGen.h
        parser/codegen/IfExprGen.h
        parser/codegen/LogicalOpExprGen.h
        parser/codegen/AbilityLearning.h)

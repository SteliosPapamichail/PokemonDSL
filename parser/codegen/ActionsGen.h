//
// Created by Steli on 12/31/2023.
//

#ifndef ACTIONSGEN_H
#define ACTIONSGEN_H

#include "../../utils/PokeballManagementUtils.h"

/**
 * \brief Returns the attacking pokemon in the current round.
 */
#define ATTACKER FightManager::getInstance().getAttacker())+=


/**
 * \brief Returns the defending pokemon in the current round.
 */
#define DEFENDER FightManager::getInstance().getDefender())+=

/**
 * \brief Returns the name of the given pokemon.
 * \param pokemon The pokemon whose name to return.
 */
#define GET_NAME(pokemon) (((*pokemon 0)->getName())

/**
 * \brief Returns the type of the given pokemon.
 * \param pokemon The pokemon whose type to return
 */
#define GET_TYPE(pokemon) (PokemonTypeToString(((*pokemon 0)->getType()))

/**
 * \brief Returns the current HP of the given pokemon.
 * \param pokemon The pokemon whose HP to return.
 */
#define GET_HP(pokemon) (((*pokemon 0)->getHP())

/**
 * \brief Returns whether or not the given pokemon is in its pokeball.
 * \param pokemon The pokemon to check.
 */
#define IS_IN_POKEBALL(pokemon) (((*pokemon 0)->getIsInPokeball())

/**
 * \brief Damages the specified pokemon by a certain amount.
 * Format: DAMAGE (ATTACKER/DEFENDER) number
 */
#define DAMAGE ;*FightManager::damage(

/**
 * \brief Heals the specified pokemon by a certain amount.
 * Format: HEAL (ATTACKER/DEFENDER) number
 */
#define HEAL ;*FightManager::heal(

/**
 * \brief Releases or encloses the specified
 * * pokemon from/in the Pokeball.
 * Format: POKEBALL ATTACKER/DEFENDER (option)
 */
#define POKEBALL ;*FightManager::setPokeballStatus(

/**
 * \brief
 */
#define α a()

/**
 * \brief
 */
#define _ true

#endif //ACTIONSGEN_H
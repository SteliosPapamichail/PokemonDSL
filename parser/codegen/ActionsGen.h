//
// Created by Steli on 12/31/2023.
//

#ifndef ACTIONSGEN_H
#define ACTIONSGEN_H

/**
 * \brief Returns the attacking pokemon in the current round.
 */
#define ATTACKER FightManager::getInstance().getAttacker()


/**
 * \brief Returns the defending pokemon in the current round.
 */
#define DEFENDER FightManager::getInstance().getDefender()

/**
 * \brief Returns the name of the given pokemon.
 * \param pokemon The pokemon whose name to return.
 */
#define GET_NAME(pokemon) (pokemon->getName())

/**
 * \brief Returns the type of the given pokemon.
 * \param pokemon The pokemon whose type to return
 */
#define GET_TYPE(pokemon) (PokemonTypeToString(pokemon->getType()))

/**
 * \brief Returns the current HP of the given pokemon.
 * \param pokemon The pokemon whose HP to return.
 */
#define GET_HP(pokemon) (pokemon->getHP())

/**
 * \brief
 * Format: DAMAGE (ATTACKER/DEFENDER) number
 */
#define DAMAGE

/**
 * \brief
 * Format: HEAL (ATTACKER/DEFENDER) number
 */
#define HEAL

#endif //ACTIONSGEN_H

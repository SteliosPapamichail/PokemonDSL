//
// Created by Steli on 12/27/2023.
//

#ifndef ABILITYLEARNING_H
#define ABILITYLEARNING_H

#include "../../utils/Utils.h"

/**
 * \brief 
 */
#define DEAR ; (*getPokemonByName(
/**
 * \brief 
 */
#define LEARN ))

/**
 * \brief Retrieves the ability with the given name, if it exists.
 * Otherwise, nullptr is returned.
 * \param name The name of the ability to look for.
 */
#define ABILITY_NAME(name) (*(getAbilityByName(#name)))


#endif //ABILITYLEARNING_H

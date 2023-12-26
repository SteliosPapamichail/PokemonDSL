//
// Created by Steli on 12/26/2023.
//

#ifndef LOGICALOPEXPRGEN_H
#define LOGICALOPEXPRGEN_H
/**
 * \brief Performs the logical AND action.
 *
 * Calls to this macro must specify at least two (2) conditions.
 *
 * Example:
 * \code{.cpp}
 * AND (GET_TYPE(ATTACKER) == "Electric", GET_HP(ATTACKER) > 20)
 * \endcode
 */
#define AND

/**
 * \brief Performs the logical OR action.
 *
 * Calls to this macro must specify at least two (2) conditions.
 *
 * Example:
 * \code{.cpp}
 * OR (GET_TYPE(DEFENDER) == "Fire",
 *     NOT (GET_TYPE(ATTACKER) == "Electric"),
 *     GET_HP(DEFENDER) <= 20)
 * \endcode
 */
#define OR

/**
 * \brief Performs the logical NOT action.
 *
 * Calls to this macro must specify exactly one (1) condition.
 *
 * Example:
 * \code{.cpp}
 * NOT (AND (GET_HP(DEFENDER) > 20, GET_HP(DEFENDER) < 70))
 * \endcode
 */
#define NOT
#endif //LOGICALOPEXPRGEN_H

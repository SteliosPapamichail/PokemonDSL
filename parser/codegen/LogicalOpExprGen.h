//
// Created by Steli on 12/26/2023.
//

#ifndef LOGICALOPEXPRGEN_H
#define LOGICALOPEXPRGEN_H

//todo:sp figure out a way to use static_assert to restrict arg size

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
#define AND(...) \
    [&]() -> bool { \
        bool result = true; \
        std::vector<bool> args = {__VA_ARGS__}; \
        for (bool arg : args) \
            result = result && arg; \
        return result; \
    }()

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
#define OR(...) \
 [&]() -> bool { \
 bool result = true; \
 std::vector<bool> args = {__VA_ARGS__}; \
 for (bool arg : args) \
 result = result || arg; \
 return result; \
 }()

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
#define NOT(expr) !expr
#endif //LOGICALOPEXPRGEN_H

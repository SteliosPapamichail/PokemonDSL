//
// Created by Steli on 12/26/2023.
//

#ifndef IFEXPRGEN_H
#define IFEXPRGEN_H

/*
 *  Valid IF statement format:
 *
 *  IF Condition DO
 *      Commands
 *  ELSE_IF Condition DO
 *      Commands
 *  ELSE
 *      Commands
 *  END
 */

/**
 * \brief Used to define a logical if branch statement.
 */
#define IF ; {if(

/**
 * \brief Used to define a logical else-if branch statement.
 */
#define ELSE_IF ;} else if (

/**
 * \brief Used to define a logical else branch statement.
 */
#define ELSE ;} else {

/**
 * \brief Used to specify the commands to be executed.
 */
#define DO ) {

#endif //IFEXPRGEN_H
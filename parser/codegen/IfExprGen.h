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
 * \brief
 */
#define IF if (

#define ELSE }} else {{

#define ELSE_IF }} else if (

#define DO ) {{

#endif //IFEXPRGEN_H

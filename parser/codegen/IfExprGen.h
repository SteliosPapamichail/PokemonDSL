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
#define IF new IfExpr

#define ELSE

#define ELSE_IF

#define DO

#endif //IFEXPRGEN_H

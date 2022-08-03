//
// Created by Maylon on 2022/7/21.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#ifndef DATA_STRUCTURES_MAIN_H
#define DATA_STRUCTURES_MAIN_H

typedef int ElemType;

/*!
 * enumerate function return status
 */
typedef enum Status {
    false,
    true,
    input_error,
    list_full,
} Status;

/*!
 * enumerate the option type
 */
typedef enum OptType {
    insert,
    update,
} OptType;

/*!
 * Visit a node and print its value
 * @param e : the data of the node visited
 */
void visit(ElemType e);

/*!
 * Get element from input
 * @param e : pointer to the element
 */
void get_input_element(ElemType *e);

/*!
 * Get the order position
 * @param i : pointer to the integer
 */
void get_order_position(int *i);

/*!
 * Prevent users from entering other characters indiscriminately, and standardize user input of integers
 * @return the legitimate integer
 */
int judge_int(void);

/*!
 * The main menu
 */
void main_menu(void);

#endif //DATA_STRUCTURES_MAIN_H

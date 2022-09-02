//
// Created by Maylon on 2022/8/12.
//

#include "Stack.h"

#ifndef DATA_STRUCTURES_LINKSTACK_H
#define DATA_STRUCTURES_LINKSTACK_H

typedef struct LinkStackNode {
    ElemType data;
    struct LinkStackNode *next;
} *LinkStack;

/* Create */
/*!
 * Initialize or reset the linked stack (without a head)
 * @param S : pointer to the linked stack
 */
void InitLinkStack(LinkStack *S);

/* Destroy */
/*!
 * Destroy the linked stack (without a head)
 * @param S : pointer to the linked stack
 * @return status (true, false)
 */
Status DestroyLinkStack(LinkStack *S);

/* Push */
/*!
 * Push an element into the linked stack (without a head)
 * @param S : pointer to the linked stack
 * @param e : the data to be pushed
 * @return status (true, false)
 */
Status LinkStack_Push(LinkStack *S, ElemType e);

/* Pop */
/*!
 * Pop an element out of the linked stack (without a head)
 * @param S : pointer to the linked stack
 * @param e : pointer to the data to be popped
 * @return status (true, false)
 */
Status LinkStack_Pop(LinkStack *S, ElemType *e);

/* Retrieve */
/*!
 * Get the top data of the linked stack (without a head)
 * @param S : the linked stack
 * @param e : pointer to the top data
 */
void LinkStack_Get_Top(LinkStack S, ElemType *e);

/*!
 * Judge if the linked stack (without a head) is empty
 * @param S : the linked stack
 * @return status (true, false)
 */
Status LinkStack_Empty(LinkStack S);

/*!
 * Get the length of the linked stack (without a head)
 * @param S : the linked stack
 * @return length of the stack
 */
int LinkStack_Len(LinkStack S);

/* Traverse */
/*!
 * Traverse the linked stack (without a head)
 * @param S : the linked stack
 * @param visit : function pointer to the function that prints the data of a node
 */
void LinkStack_Traverse(LinkStack S, void(*visit)(ElemType e));

/*!
 * The linked stack (without a head) menu
 */
void linkstack_menu(void);

/*!
 * The linked stack (without a head) menu details
 */
void linkstack_menu_show_details(void);

#endif //DATA_STRUCTURES_LINKSTACK_H

//
// Created by Maylon on 2022/8/12.
//

#include "Stack.h"

#ifndef DATA_STRUCTURES_SEQSTACK_H
#define DATA_STRUCTURES_SEQSTACK_H

#define DeltaSize 5

typedef struct {
    ElemType *data;
    int top, MaxSize;
} SeqStack;

/* Create */
/*!
 * Initialize or reset the sequential stack
 * @param S : pointer to the sequential stack
 * @return status (true, false)
 */
Status InitSeqStack(SeqStack *S);

/*!
 * Increase capacity of the sequential stack when the stack is full
 * @param S : pointer to the sequential stack
 * @return status (true, false)
 */
Status SeqStack_Increase_Capacity(SeqStack *S);

/* Destroy */
/*!
 * Destroy the sequential stack
 * @param S : pointer to the sequential stack
 */
void DestroySeqStack(SeqStack *S);

/* Push */
/*!
 * Push an element into the sequential stack
 * @param S : pointer to the sequential stack
 * @param e : the data to be pushed
 * @return status (true, false)
 */
Status SeqStack_Push(SeqStack *S, ElemType e);

/* Pop */
/*!
 * Pop an element out of the sequential stack
 * @param S : pointer to the sequential stack
 * @param e : pointer to the data to be popped
 * @return status (true, false)
 */
Status SeqStack_Pop(SeqStack *S, ElemType *e);

/* Retrieve */
/*!
 * Get the top data of the sequential stack
 * @param S : the sequential stack
 * @param e : pointer to the top data
 */
void SeqStack_Get_Top(SeqStack S, ElemType *e);

/*!
 * Judge if the sequential stack is empty
 * @param S : the sequential stack
 * @return status (true, false)
 */
Status SeqStack_Empty(SeqStack S);

/*!
 * Get the length of the sequential stack
 * @param S : the sequential stack
 * @return length of the stack
 */
int SeqStack_Len(SeqStack S);

/* Traverse */
/*!
 * Traverse the sequential stack
 * @param S : the sequential stack
 * @param visit : function pointer to the function that prints the data of a node
 */
void SeqStack_Traverse(SeqStack S, void(*visit)(ElemType e));

/*!
 * The sequential stack menu
 */
void seqstack_menu(void);

/*!
 * The sequential stack menu details
 */
void seqstack_menu_show_details(void);

#endif //DATA_STRUCTURES_SEQSTACK_H

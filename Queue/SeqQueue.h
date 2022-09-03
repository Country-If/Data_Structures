//
// Created by Maylon on 2022/9/2.
//

#include "Queue.h"

#ifndef DATA_STRUCTURES_SEQQUEUE_H
#define DATA_STRUCTURES_SEQQUEUE_H

#define DeltaSize 5

typedef struct {
    ElemType *data;
    int front, rear, MaxSize;
} SeqQueue;

/* Create */
/*!
 * Initialize or reset the sequential queue
 * @param Q : pointer to the sequential queue
 * @return status (true, false)
 */
Status InitSeqQueue(SeqQueue *Q);

/*!
 * Increase capacity of the sequential queue when the queue is full
 * @param Q : pointer to the sequential queue
 * @return status (true, false)
 */
Status SeqQueue_Increase_Capacity(SeqQueue *Q);

/* Destroy */
/*!
 * Destroy the sequential queue
 * @param Q : pointer to the sequential queue
 */
void DestroySeqQueue(SeqQueue *Q);

/* EnQueue */
/*!
 * Enter an element to the rear of the sequential queue
 * @param Q : pointer to the sequential queue
 * @param e : the data to be entered
 * @return status (true, false)
 */
Status EnSeqQueue(SeqQueue *Q, ElemType e);

/* DeQueue */
/*!
 * Delete an element from the front of the sequential queue
 * @param Q : pointer to the sequential queue
 * @param e : pointer to the data to be deleted
 * @return status (true, false)
 */
Status DeSeqQueue(SeqQueue *Q, ElemType *e);

/* Retrieve */
/*!
 * Get the head data of the sequential queue
 * @param Q : the sequential queue
 * @param e : pointer to the head data
 */
void SeqQueue_Get_Head(SeqQueue Q, ElemType *e);

/*!
 * Judge if the sequential queue is empty
 * @param Q : the sequential queue
 * @return status (true, false)
 */
Status SeqQueue_Empty(SeqQueue Q);

/*!
 * Judge if the sequential queue is full
 * @param Q : the sequential queue
 * @return status (true, false)
 */
Status SeqQueue_Full(SeqQueue Q);

/*!
 * Get the length of the sequential queue
 * @param Q : the sequential queue
 * @return the length of the queue
 */
int SeqQueue_Len(SeqQueue Q);

/* Traverse */
/*!
 * Traverse the sequential queue
 * @param Q : the sequential queue
 * @param visit : function pointer to the function that prints the data of a node
 */
void SeqQueue_Traverse(SeqQueue Q, void(*visit)(ElemType e));

/*!
 * The sequential queue menu
 */
void seqqueue_menu(void);

/*!
 * The sequential queue menu details
 */
void seqqueue_menu_show_details(void);

#endif //DATA_STRUCTURES_SEQQUEUE_H

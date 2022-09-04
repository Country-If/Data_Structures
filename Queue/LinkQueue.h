//
// Created by Maylon on 2022/9/2.
//

#include "Queue.h"

#ifndef DATA_STRUCTURES_LINKQUEUE_H
#define DATA_STRUCTURES_LINKQUEUE_H

typedef struct LinkQueueNode {
    ElemType data;
    struct LinkQueueNode *next;
} LinkQueueNode;

typedef struct {
    LinkQueueNode *front;
    LinkQueueNode *rear;
} LinkQueue;

/* Create */
/*!
 * Initialize or reset the linked queue (with a head)
 * @param Q : pointer to the linked queue
 * @return status (true, false)
 */
Status InitLinkQueue(LinkQueue *Q);

/* Destroy */
/*!
 * Destroy the linked queue (with a head)
 * @param Q : pointer to the linked queue
 * @return status (true, false)
 */
Status DestroyLinkQueue(LinkQueue *Q);

/* EnQueue */
/*!
 * Enter an element to the rear of the linked queue (with a head)
 * @param Q : pointer to the linked queue
 * @param e : the data to be entered
 * @return status (true, false)
 */
Status EnLinkQueue(LinkQueue *Q, ElemType e);

/* DeQueue */
/*!
 * Delete an element from the front of the linked queue (with a head)
 * @param Q : pointer to the linked queue
 * @param e : pointer to the data to be deleted
 * @return status (true, false)
 */
Status DeLinkQueue(LinkQueue *Q, ElemType *e);

/* Retrieve */
/*!
 * Get the head data of the linked queue (with a head)
 * @param Q : the linked queue
 * @param e : pointer to the head data
 */
void LinkQueue_Get_Head(LinkQueue Q, ElemType *e);

/*!
 * Judge if the linked queue (with a head) is empty
 * @param Q : the linked queue
 * @return status (true, false)
 */
Status LinkQueue_Empty(LinkQueue Q);

/*!
 * Get the length of the linked queue (with a head)
 * @param Q : the linked queue
 * @return the length of the queue
 */
int LinkQueue_Len(LinkQueue Q);

/* Traverse */
/*!
 * Traverse the linked queue (with a head)
 * @param Q : the linked queue
 * @param visit : function pointer to the function that prints the data of a node
 */
void LinkQueue_Traverse(LinkQueue Q, void(*visit)(ElemType e));

/*!
 * The linked queue (with a head) menu
 */
void linkqueue_menu(void);

/*!
 * The linked queue (with a head) menu details
 */
void linkqueue_menu_show_details(void);

#endif //DATA_STRUCTURES_LINKQUEUE_H

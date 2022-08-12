//
// Created by Maylon on 2022/7/21.
//

#include "LinkList.h"

#ifndef DATA_STRUCTURES_STALINKLIST_H
#define DATA_STRUCTURES_STALINKLIST_H

#define MaxSize 10

typedef struct {
    ElemType data;
    int next;
} StaLinkList[MaxSize];

/* Create */
/*!
 * Initialize or reset the static linked list (with a head node)
 * @param L : pointer to the static linked list array pointer
 * @return status (true, false)
 */
Status InitStaList(StaLinkList **L);

/* Destroy */
/*!
 * Destroy the static linked list (with a head node)
 * @param L : pointer to the static linked list array pointer
 * @return status (true, false)
 */
Status DestroyStaList(StaLinkList **L);

/* Insert */
/*!
 * Insert a node from head of the static linked list (with a head node)
 * @param L : pointer to the static linked list array
 * @param e : element to be inserted
 * @return status (true, false, list_full)
 */
Status StaList_Head_Insert(StaLinkList *L, ElemType e);

/*!
 * Insert a node from tail of the static linked list (with a head node)
 * @param L : pointer to the static linked list array
 * @param e : element to be insert
 * @return status (true, false, list_full)
 */
Status StaList_Tail_Insert(StaLinkList *L, ElemType e);

/*!
 * Insert a node before a specific node of the static linked list (with a head node) by order
 * @param L : pointer to the static linked list array
 * @param i : the order of a specific node, legitimate range: [1, n + 1]
 * @param e : element to be insert
 * @return status (true, false, input_error, list_full)
 */
Status StaList_Insert_By_Order(StaLinkList *L, int i, ElemType e);

/* Delete */
/*!
 * Delete a node of the static linked list (with a head node) by value
 * @param L : pointer to the static linked list array
 * @param e : the data of the node to be deleted
 * @return status (true, false)
 */
Status StaList_Delete_By_Value(StaLinkList *L, ElemType e);

/*!
 * Delete a node of the static linked list (with a head node) by order
 * @param L : pointer to the static linked list array
 * @param i : the order of a specific node, legitimate range: [1, n]
 * @param e : the data of the node to be deleted
 * @return status (true, false, input_error)
 */
Status StaList_Delete_By_Order(StaLinkList *L, int i, ElemType *e);

/* Retrieve */
/*!
 * Retrieve an unused position to be inserted
 * @param L : pointer to the static linked list array
 * @return position of the result node if successfully retrieved else -1
 */
int StaList_Retrieve_Position(StaLinkList *L);

/*!
 * Retrieve a node of the static linked list (with a head node) by value
 * @param L : pointer to the static linked list array
 * @param e : the data of the node to be retrieved
 * @return position of the result node if successfully retrieved else -1
 */
int StaList_Retrieve_By_Value(StaLinkList *L, ElemType e);

/*!
 * Retrieve a node of the static linked list (with a head node) by order
 * @param L : pointer to the static linked list array
 * @param i : the order of a specific node, legitimate range: [1, n]
 * @return position of the result node if successfully retrieved else -1
 */
int StaList_Retrieve_By_Order(StaLinkList *L, int i);

/* Update */
/*!
 * Update a node of the static linked list (with a head node) by value
 * @param L : pointer to the static linked list array
 * @param old : the old data of the node to be updated
 * @param new : the new data of the node to be updated
 * @return status (true, false)
 */
Status StaList_Update_By_Value(StaLinkList *L, ElemType old, ElemType new);

/*!
 * Update a node of the static linked list (with a head node) by order
 * @param L : pointer to the static linked list array
 * @param i : the order of a specific node, legitimate range: [1, n]
 * @param e : the data of the node to be updated
 * @return status (true, false, input_error)
 */
Status StaList_Update_By_Order(StaLinkList *L, int i, ElemType e);

/* Reverse */
/*!
 * Reverse the static linked list (with a head node)
 * @param L : pointer to the static linked list array
 * @return status (true, false)
 */
Status StaList_Reverse(StaLinkList *L);

/* Traverse */
/*!
 * Traverse the static linked list (with a head node)
 * @param L : pointer to the static linked list array
 * @param visit : function pointer to the function that prints the data of a node
 * @return status (true, false)
 */
Status StaList_Traverse(StaLinkList *L, void(*visit)(ElemType e));

/*!
 * The static linked list (with a head node) menu
 */
void stalinklist_menu(void);

/*!
 * The static linked list (with a head node) menu details
 */
void stalinklist_menu_show_details(void);

#endif //DATA_STRUCTURES_STALINKLIST_H

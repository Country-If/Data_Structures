//
// Created by Maylon on 2022/7/21.
//

#include "LinkList.h"

#ifndef DATA_STRUCTURES_CIRSILINKLIST_H
#define DATA_STRUCTURES_CIRSILINKLIST_H

typedef struct CirSiLNode {
    ElemType data;
    struct CirSiLNode *next;
} CirSiLNode, *CirSiList;

/* Create */
/*!
 * Initialize or reset the circular single linked list (with a head node)
 * @param L : pointer to the circular single linked list pointer
 * @return status (true, false)
 */
Status InitCirSiList(CirSiList *L);

/* Destroy */
/*!
 * Destroy the circular single linked list (with a head node)
 * @param L : pointer to the circular single linked list pointer
 * @return status (true, false)
 */
Status DestroyCirSiList(CirSiList *L);

/* Insert */
/*!
 * Insert a node from head of the circular single linked list (with a head node)
 * @param L : pointer to the circular single linked list
 * @param e : element to be inserted
 * @return status (true, false)
 */
Status CirSiList_Head_Insert(CirSiList L, ElemType e);

/*!
 * Insert a node from tail of the circular single linked list (with a head node)
 * @param L : pointer to the circular single linked list
 * @param e : element to be insert
 * @return status (true, false)
 */
Status CirSiList_Tail_Insert(CirSiList L, ElemType e);

/*!
 * Insert a node before a specific node of the circular single linked list (with a head node) by order
 * @param L : pointer to the circular single linked list
 * @param i : the order of a specific node, legitimate range: [1, n + 1]
 * @param e : element to be insert
 * @return status (true, false, input_error)
 */
Status CirSiList_Insert_By_Order(CirSiList L, int i, ElemType e);

/* Delete */
/*!
 * Delete a node of the circular single linked list (with a head node) by value
 * @param L : pointer to the circular single linked list
 * @param e : the data of the node to be deleted
 * @return status (true, false)
 */
Status CirSiList_Delete_By_Value(CirSiList L, ElemType e);

/*!
 * Delete a node of the circular single linked list (with a head node) by order
 * @param L : pointer to the circular single linked list
 * @param i : the order of a specific node, legitimate range: [1, n]
 * @param e : the data of the node to be deleted
 * @return status (true, false, input_error)
 */
Status CirSiList_Delete_By_Order(CirSiList L, int i, ElemType *e);

/* Retrieve */
/*!
 * Retrieve a node of the circular single linked list (with a head node) by value
 * @param L : pointer to the circular single linked list
 * @param e : the data of the node to be retrieve
 * @return pointer to the result node if successfully retrieved else NULL or head node
 */
CirSiLNode *CirSiList_Retrieve_By_Value(CirSiList L, ElemType e);

/*!
 * Retrieve a node of the circular single linked list (with a head node) by order (only used in update and delete function)
 * @param L : pointer to the circular single linked list
 * @param i : the order of a specific node, legitimate range: [1, n]
 * @return pointer to the result node if successfully retrieved else NULL or head node
 */
CirSiLNode *CirSiList_Retrieve_By_Order(CirSiList L, int i);

/* Update */
/*!
 * Update a node of the circular single linked list (with a head node) by value
 * @param L : pointer to the circular single linked list
 * @param old : the old data of the node to be updated
 * @param new : the new data of the node to be updated
 * @return status (true, false)
 */
Status CirSiList_Update_By_Value(CirSiList L, ElemType old, ElemType new);

/*!
 * Update a node of the circular single linked list (with a head node) by order
 * @param L : pointer to the single linked list
 * @param i : the order of a specific node, legitimate range: [1, n]
 * @param e : the data of the node to be updated
 * @return status (true, false, input_error)
 */
Status CirSiList_Update_By_Order(CirSiList L, int i, ElemType e);

/* Traverse */
/*!
 * Traverse the circular single linked list (with a head node)
 * @param L : pointer to the single linked list
 * @param visit : function pointer to the function that prints the data of a node
 * @return status (true, false)
 */
Status CirSiList_Traverse(CirSiList L, void(*visit)(ElemType e));

/*!
 * The circular single linked list (with a head node) menu
 */
void cirsilist_menu(void);

/*!
 * The circular single linked list (with a head node) menu details
 */
void cirsilist_menu_show_details(void);

#endif //DATA_STRUCTURES_CIRSILINKLIST_H

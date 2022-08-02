//
// Created by Maylon on 2022/7/21.
//

#include "LinkList.h"

#ifndef DATA_STRUCTURES_CIRDOLINKLIST_H
#define DATA_STRUCTURES_CIRDOLINKLIST_H

typedef struct CirDoLNode {
    ElemType data;
    struct CirDoLNode *prior;
    struct CirDoLNode *next;
} CirDoLNode, *CirDoList;

/* Create */
/*!
 * Initialize or reset the circular double linked list
 * @param L : pointer to the circular double linked list pointer
 */
void InitCirDoList(CirDoList *L);

/* Destroy */
/*!
 * Destroy the circular double linked list
 * @param L : pointer to the circular double linked list pointer
 * @return status (true, false)
 */
Status DestroyCirDoList(CirDoList *L);

/* Insert */
/*!
 * Insert a node from head of the circular double linked list
 * @param L : pointer to the circular double linked list pointer
 * @param e : element to be inserted
 * @return status (true, false)
 */
Status CirDoList_Head_Insert(CirDoList *L, ElemType e);

/*!
 * Insert a node from tail of the circular double linked list
 * @param L : pointer to the circular double linked list pointer
 * @param e : element to be insert
 * @return status (true, false)
 */
Status CirDoList_Tail_Insert(CirDoList *L, ElemType e);

/*!
 * Insert a node before a specific node of the circular double linked list by order
 * @param L : pointer to the circular double linked list pointer
 * @param i : the order of a specific node, legitimate range: [1, n + 1]
 * @param e : element to be insert
 * @return status (true, false, input_error)
 */
Status CirDoList_Insert_By_Order(CirDoList *L, int i, ElemType e);

/* Delete */
/*!
 * Delete a node of the circular double linked list by the specific node
 * @param L : pointer to the circular double linked list pointer
 * @param p : pointer to the node to be deleted
 */
void CirDoList_Delete_By_Node(CirDoList *L, CirDoLNode *p);

/*!
 * Delete a node of the circular double linked list by value
 * @param L : pointer to the circular double linked list pointer
 * @param e : the data of the node to be deleted
 * @return status (true, false)
 */
Status CirDoList_Delete_By_Value(CirDoList *L, ElemType e);

/*!
 * Delete a node of the circular double linked list by order
 * @param L : pointer to the circular double linked list pointer
 * @param i : the order of a specific node, legitimate range: [1, n]
 * @param e : the data of the node to be deleted
 * @return status (true, false, input_error)
 */
Status CirDoList_Delete_By_Order(CirDoList *L, int i, ElemType *e);

/* Retrieve */
/*!
 * Retrieve a node of the circular double linked list by value
 * @param L : pointer to the circular double linked list
 * @param e : the data of the node to be retrieve
 * @return pointer to the result node if successfully retrieved else NULL
 */
CirDoLNode *CirDoList_Retrieve_By_Value(CirDoList L, ElemType e);

/*!
 * Retrieve a node of the circular double linked list by order (only used in update and delete function)
 * @param L : pointer to the circular double linked list
 * @param i : the order of a specific node, legitimate range: [1, n]
 * @return pointer to the result node if successfully retrieved else NULL
 */
CirDoLNode *CirDoList_Retrieve_By_Order(CirDoList L, int i);

/* Update */
/*!
 * Update a node of the circular double linked list by value
 * @param L : pointer to the circular double linked list
 * @param old : the old data of the node to be updated
 * @param new : the new data of the node to be updated
 * @return status (true, false)
 */
Status CirDoList_Update_By_Value(CirDoList L, ElemType old, ElemType new);

/*!
 * Update a node of the circular double linked list by order
 * @param L : pointer to the circular double linked list
 * @param i : the order of a specific node, legitimate range: [1, n]
 * @param e : the data of the node to be updated
 * @return status (true, false, input_error)
 */
Status CirDoList_Update_By_Order(CirDoList L, int i, ElemType e);

/* Traverse */
/*!
 * Traverse the circular double linked list
 * @param L : pointer to the circular double linked list
 * @param visit : function pointer to the function that prints the data of a node
 */
void CirDoList_Traverse(CirDoList L, void(*visit)(ElemType e));

/*!
 * The circular double linked list menu
 */
void cirdolinklist_menu(void);

/*!
 * The circular double linked list menu details
 */
void cirdolinklist_menu_show_details(void);

#endif //DATA_STRUCTURES_CIRDOLINKLIST_H

//
// Created by Maylon on 2022/7/21.
//

#include "LinkList.h"

#ifndef DATA_STRUCTURES_DOLINKLIST_H
#define DATA_STRUCTURES_DOLINKLIST_H

typedef struct DoLNode {
    ElemType data;
    struct DoLNode *prior;
    struct DoLNode *next;
} DoLNode, *DoList;

/* Create */
/*!
 * Initialize or reset the double linked list (without a head node)
 * @param L : pointer to the double linked list pointer
 */
void InitDoList(DoList *L);

/* Destroy */
/*!
 * Destroy the double linked list (without a head node)
 * @param L : pointer to the double linked list pointer
 * @return status (true, false)
 */
Status DestroyDoList(DoList *L);

/* Insert */
/*!
 * Insert a node from head of the double linked list (without a head node)
 * @param L : pointer to the double linked list pointer
 * @param e : element to be inserted
 * @return status (true, false)
 */
Status DoList_Head_Insert(DoList *L, ElemType e);

/*!
 * Insert a node from tail of the double linked list (without a head node)
 * @param L : pointer to the double linked list pointer
 * @param e : element to be insert
 * @return status (true, false)
 */
Status DoList_Tail_Insert(DoList *L, ElemType e);

/*!
 * Insert a node before a specific node of the double linked list (without a head node) by order
 * @param L : pointer to the double linked list pointer
 * @param i : the order of a specific node, legitimate range: [1, n + 1]
 * @param e : element to be insert
 * @return status (true, false, input_error)
 */
Status DoList_Insert_By_Order(DoList *L, int i, ElemType e);

/* Delete */
/*!
 * Delete a node of the double linked list (without a head node) by the specific node
 * @param L : pointer to the double linked list pointer
 * @param p : pointer to the node to be deleted
 */
void DoList_Delete_By_Node(DoList *L, DoLNode *p);

/*!
 * Delete a node of the double linked list (without a head node) by value
 * @param L : pointer to the double linked list pointer
 * @param e : the data of the node to be deleted
 * @return status (true, false)
 */
Status DoList_Delete_By_Value(DoList *L, ElemType e);

/*!
 * Delete a node of the double linked list (without a head node) by order
 * @param L : pointer to the double linked list pointer
 * @param i : the order of a specific node, legitimate range: [1, n]
 * @param e : the data of the node to be deleted
 * @return status (true, false, input_error)
 */
Status DoList_Delete_By_Order(DoList *L, int i, ElemType *e);

/* Retrieve */
/*!
 * Retrieve a node of the double linked list (without a head node) by value
 * @param L : pointer to the double linked list
 * @param e : the data of the node to be retrieved
 * @return pointer to the result node if successfully retrieved else NULL
 */
DoLNode *DoList_Retrieve_By_Value(DoList L, ElemType e);

/*!
 * Retrieve a node of the double linked list (without a head node) by order (only used in update and delete function)
 * @param L : pointer to the double linked list
 * @param i : the order of a specific node, legitimate range: [1, n]
 * @return pointer to the result node if successfully retrieved else NULL
 */
DoLNode *DoList_Retrieve_By_Order(DoList L, int i);

/* Update */
/*!
 * Update a node of the double linked list (without a head node) by value
 * @param L : pointer to the double linked list
 * @param old : the old data of the node to be updated
 * @param new : the new data of the node to be updated
 * @return status (true, false)
 */
Status DoList_Update_By_Value(DoList L, ElemType old, ElemType new);

/*!
 * Update a node of the double linked list (without a head node) by order
 * @param L : pointer to the double linked list
 * @param i : the order of a specific node, legitimate range: [1, n]
 * @param e : the data of the node to be updated
 * @return status (true, false, input_error)
 */
Status DoList_Update_By_Order(DoList L, int i, ElemType e);

/* Reverse */
/*!
 * Reverse the double linked list (without a head node)
 * @param L : pointer to the double linked list pointer
 * @return status (true, false)
 */
Status DoList_Reverse(DoList *L);

/* Traverse */
/*!
 * Traverse the double linked list (without a head node)
 * @param L : pointer to the double linked list
 * @param visit : function pointer to the function that prints the data of a node
 */
void DoList_Traverse(DoList L, void(*visit)(ElemType e));

/*!
 * The double linked list (without a head node) menu
 */
void dolinklist_menu(void);

/*!
 * The double linked list (without a head node) menu details
 */
void dolinklist_menu_show_details(void);

#endif //DATA_STRUCTURES_DOLINKLIST_H

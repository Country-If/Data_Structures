//
// Created by Maylon on 2022/7/21.
// Name: single linked list with a head node
//

#include "LinkList.h"

#ifndef DATA_STRUCTURES_SILINKLIST_HEAD_H
#define DATA_STRUCTURES_SILINKLIST_HEAD_H

typedef struct SiLNode {
    ElemType data;
    struct SiLNode *next;
} SiLNode, *SiList;

/* Create */
/*!
 * Initialize a single linked list (with a head node)
 * @param L : pointer to single linked list pointer
 * @return status (true, false)
 */
Status InitSiList_Head(SiList *L);

/* Destroy */
/*!
 * Destroy a single linked list (with a head node)
 * @param L : pointer to a single linked list pointer
 * @return status (true, false)
 */
Status DestroySiList_Head(SiList *L);

/* Insert */
/*!
 * Insert a node from head of a single linked list (with a head node)
 * @param L : pointer to a single linked list
 * @param e : element to be inserted
 * @return status (true, false)
 */
Status SiList_Head_Head_Insert(SiList L, ElemType e);

/*!
 * Insert a node from tail of a single linked list (with a head node)
 * @param L : pointer to a single linked list
 * @param e : element to be insert
 * @return status (true, false)
 */
Status SiList_Head_Tail_Insert(SiList L, ElemType e);

/*!
 * Insert a node before a specific node of a single linked list (with a head node) by order
 * @param L : pointer to a single linked list
 * @param i : the order of a specific node, legitimate range: [1, n + 1]
 * @param e : element to be insert
 * @return status (true, false)
 */
Status SiList_Head_Insert_By_Order(SiList L, int i, ElemType e);

/* Delete */
/*!
 * Delete a node of a single linked list (with a head node) by a specific node
 * @param L : pointer to a single linked list
 * @param p : pointer to a single linked list node to be deleted
 * @return status (true, false)
 */
Status SiList_Head_Delete_By_Node(SiList L, SiLNode *p);

/*!
 * Delete a node of a single linked list (with a head node) by order
 * @param L : pointer to a single linked list
 * @param i : the order of a specific node, legitimate range: [1, n + 1]
 * @param e : the data of the node to be deleted
 * @return status (true, false)
 */
Status SiList_Head_Delete_By_Order(SiList L, int i, ElemType *e);

/* Retrieve */
/*!
 * Retrieve a node of a single linked list (with a head node) by value
 * @param L : pointer to a single linked list
 * @param e : the data of the node to be retrieve
 * @return pointer to the result node if successfully retrieved else NULL
 */
SiLNode *SiList_Head_Retrieve_By_Value(SiList L, ElemType e);

/*!
 * Retrieve a node of a single linked list (with a head node) by order
 * @param L : pointer to a single linked list
 * @param i : the order of a specific node, legitimate range: [1, n + 1]
 * @return pointer to the result node if successfully retrieved else NULL
 */
SiLNode *SiList_Head_Retrieve_By_Order(SiList L, int i);

/* Update */
/*!
 * Update a node of a single linked list (with a head node) by value
 * @param L : pointer to a single linked list
 * @param old : the old data of the node to be updated
 * @param new : the new data of the node to be updated
 * @return status (true, false)
 */
Status SiList_Head_Update_By_Value(SiList L, ElemType old, ElemType new);

/*!
 * Update a node of a single linked list (with a head node) by order
 * @param L : pointer to a single linked list
 * @param i : the order of a specific node, legitimate range: [1, n + 1]
 * @param e : the data of the node to be updated
 * @return status (true, false)
 */
Status SiList_Head_Update_By_Order(SiList L, int i, ElemType e);

/* Traverse */
/*!
 * Traverse the single linked list (with a head node)
 * @param L : pointer to a single linked list
 * @param visit : function pointer to a function that prints the data of a node
 * @return status (true, false)
 */
Status SiList_Head_Traverse(SiList L, void(*visit)(ElemType e));

/*!
 * The single linked list (with a head node) menu
 */
void silinklist_head_menu(void);

/*!
 * The single linked list (with a head node) menu details
 */
void silinklist_head_menu_show_details(void);

#endif //DATA_STRUCTURES_SILINKLIST_HEAD_H

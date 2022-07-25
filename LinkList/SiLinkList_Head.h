//
// Created by Maylon on 2022/7/21.
// Name: single linked list with a head node
//

#include "LinkList.h"

#ifndef DATA_STRUCTURES_SILINKLIST_HEAD_H
#define DATA_STRUCTURES_SILINKLIST_HEAD_H

typedef struct SiLNode_Head {
    ElemType data;
    struct SiLNode_Head *next;
} SiLNode_Head, *SiList_Head;

/* Create */
/*!
 * Initialize a single linked list (with a head node)
 * @param L : pointer to single linked list pointer
 * @return status (true, false)
 */
Status InitSiList_Head(SiList_Head *L);

/* Destroy */
/*!
 * Destroy a single linked list (with a head node)
 * @param L : pointer to a single linked list pointer
 * @return status (true, false)
 */
Status DestroySiList_Head(SiList_Head *L);

/* Insert */
/*!
 * Insert a node from head of a single linked list (with a head node)
 * @param L : pointer to a single linked list
 * @param e : element to be inserted
 * @return status (true, false)
 */
Status SiList_Head_Head_Insert(SiList_Head L, ElemType e);

/*!
 * Insert a node from tail of a single linked list (with a head node)
 * @param L : pointer to a single linked list
 * @param e : element to be insert
 * @return status (true, false)
 */
Status SiList_Head_Tail_Insert(SiList_Head L, ElemType e);

/*!
 * Insert a node before a specific node of a single linked list (with a head node) by order
 * @param L : pointer to a single linked list
 * @param i : the order of a specific node, legitimate range: [1, n + 1]
 * @param e : element to be insert
 * @return status (true, false, input_error)
 */
Status SiList_Head_Insert_By_Order(SiList_Head L, int i, ElemType e);

/* Delete */
/*!
 * Delete a node of a single linked list (with a head node) by value
 * @param L : pointer to a single linked list
 * @param e : the data of the node to be deleted
 * @return status (true, false)
 */
Status SiList_Head_Delete_By_Value(SiList_Head L, ElemType e);

/*!
 * Delete a node of a single linked list (with a head node) by order
 * @param L : pointer to a single linked list
 * @param i : the order of a specific node, legitimate range: [1, n]
 * @param e : the data of the node to be deleted
 * @return status (true, false, input_error)
 */
Status SiList_Head_Delete_By_Order(SiList_Head L, int i, ElemType *e);

/* Retrieve */
/*!
 * Retrieve a node of a single linked list (with a head node) by value
 * @param L : pointer to a single linked list
 * @param e : the data of the node to be retrieve
 * @return pointer to the result node if successfully retrieved else NULL
 */
SiLNode_Head *SiList_Head_Retrieve_By_Value(SiList_Head L, ElemType e);

/*!
 * Retrieve a node of a single linked list (with a head node) by order
 * @param L : pointer to a single linked list
 * @param i : the order of a specific node, legitimate range: [1, n]
 * @param opt : the option type: insert or update
 * @return pointer to the prior node of the query node if OptType is insert else pointer to the query node if OptType is update else NULL
 */
SiLNode_Head *SiList_Head_Retrieve_By_Order(SiList_Head L, int i, OptType opt);

/* Update */
/*!
 * Update a node of a single linked list (with a head node) by value
 * @param L : pointer to a single linked list
 * @param old : the old data of the node to be updated
 * @param new : the new data of the node to be updated
 * @return status (true, false)
 */
Status SiList_Head_Update_By_Value(SiList_Head L, ElemType old, ElemType new);

/*!
 * Update a node of a single linked list (with a head node) by order
 * @param L : pointer to a single linked list
 * @param i : the order of a specific node, legitimate range: [1, n]
 * @param e : the data of the node to be updated
 * @return status (true, false, input_error)
 */
Status SiList_Head_Update_By_Order(SiList_Head L, int i, ElemType e);

/* Traverse */
/*!
 * Traverse the single linked list (with a head node)
 * @param L : pointer to a single linked list
 * @param visit : function pointer to a function that prints the data of a node
 * @return status (true, false)
 */
Status SiList_Head_Traverse(SiList_Head L, void(*visit)(ElemType e));

/*!
 * The single linked list (with a head node) menu
 */
void silinklist_head_menu(void);

/*!
 * The single linked list (with a head node) menu details
 */
void silinklist_head_menu_show_details(void);

#endif //DATA_STRUCTURES_SILINKLIST_HEAD_H

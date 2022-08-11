//
// Created by Maylon on 2022/7/21.
// Name: single linked list without a head node
//

#include "LinkList.h"

#ifndef DATA_STRUCTURES_SILINKLIST_NOHEAD_H
#define DATA_STRUCTURES_SILINKLIST_NOHEAD_H

typedef struct SiLNode_noHead {
    ElemType data;
    struct SiLNode_noHead *next;
} SiLNode_noHead, *SiList_noHead;

/* Create */
/*!
 * Initialize or reset the single linked list (without a head node)
 * @param L : pointer to the single linked list pointer
 */
void InitSiList_noHead(SiList_noHead *L);

/* Destroy */
/*!
 * Destroy the single linked list (without a head node)
 * @param L : pointer to the single linked list pointer
 * @return status (true, false)
 */
Status DestroySiList_noHead(SiList_noHead *L);

/* Insert */
/*!
 * Insert a node from head of the single linked list (without a head node)
 * @param L : pointer to the single linked list pointer
 * @param e : element to be inserted
 * @return status (true, false)
 */
Status SiList_noHead_Head_Insert(SiList_noHead *L, ElemType e);

/*!
 * Insert a node from tail of the single linked list (without a head node)
 * @param L : pointer to the single linked list pointer
 * @param e : element to be insert
 * @return status (true, false)
 */
Status SiList_noHead_Tail_Insert(SiList_noHead *L, ElemType e);

/*!
 * Insert a node before a specific node of the single linked list (without a head node) by order
 * @param L : pointer to the single linked list pointer
 * @param i : the order of a specific node, legitimate range: [1, n + 1]
 * @param e : element to be insert
 * @return status (true, false, input_error)
 */
Status SiList_noHead_Insert_By_Order(SiList_noHead *L, int i, ElemType e);

/* Delete */
/*!
 * Delete a node of the single linked list (without a head node) by value
 * @param L : pointer to the single linked list pointer
 * @param e : the data of the node to be deleted
 * @return status (true, false)
 */
Status SiList_noHead_Delete_By_Value(SiList_noHead *L, ElemType e);

/*!
 * Delete a node of the single linked list (without a head node) by order
 * @param L : pointer to the single linked list pointer
 * @param i : the order of a specific node, legitimate range: [1, n]
 * @param e : the data of the node to be deleted
 * @return status (true, false, input_error)
 */
Status SiList_noHead_Delete_By_Order(SiList_noHead *L, int i, ElemType *e);

/* Retrieve */
/*!
 * Retrieve a node of the single linked list (without a head node) by value
 * @param L : pointer to the single linked list
 * @param e : the data of the node to be retrieved
 * @return pointer to the result node if successfully retrieved else NULL
 */
SiLNode_noHead *SiList_noHead_Retrieve_By_Value(SiList_noHead L, ElemType e);

/* Update */
/*!
 * Update a node of the single linked list (without a head node) by value
 * @param L : pointer to the single linked list
 * @param old : the old data of the node to be updated
 * @param new : the new data of the node to be updated
 * @return status (true, false)
 */
Status SiList_noHead_Update_By_Value(SiList_noHead L, ElemType old, ElemType new);

/*!
 * Update a node of the single linked list (without a head node) by order
 * @param L : pointer to the single linked list
 * @param i : the order of a specific node, legitimate range: [1, n]
 * @param e : the data of the node to be updated
 * @return status (true, false, input_error)
 */
Status SiList_noHead_Update_By_Order(SiList_noHead L, int i, ElemType e);

/* Reverse */
/*!
 * Reverse the single linked list (without a head node)
 * @param L : pointer to the single linked list pointer
 * @return status (true, false)
 */
Status SiList_noHead_Reverse(SiList_noHead *L);

/* Traverse */
/*!
 * Traverse the single linked list (without a head node)
 * @param L : pointer to a single linked list
 * @param visit : function pointer to the function that prints the data of a node
 */
void SiList_noHead_Traverse(SiList_noHead L, void(*visit)(ElemType e));

/*!
 * The single linked list (without a head node) menu
 */
void silinklist_noHead_menu(void);

/*!
 * The single linked list (without a head node) menu details
 */
void silinklist_noHead_menu_show_details(void);

#endif //DATA_STRUCTURES_SILINKLIST_NOHEAD_H

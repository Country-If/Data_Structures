//
// Created by Maylon on 2022/8/3.
//

#include "../main.h"

#ifndef DATA_STRUCTURES_ARRAY_H
#define DATA_STRUCTURES_ARRAY_H

#define DeltaSize 5

typedef struct {
    ElemType *data;
    int length, MaxSize;
} SeqList;

/* Create */
/*!
 * Initialize or reset the sequential list
 * @param L : pointer to the sequential list
 * @return status (true, false)
 */
Status InitSeqList(SeqList *L);

/*!
 * Increase capacity of sequential list when list is full
 * @param L : pointer to the sequential list
 * @return status (true, false)
 */
Status SeqList_Increase_Capacity(SeqList *L);

/* Destroy */
/*!
 * Destroy the sequential list
 * @param L : pointer to the sequential list
 */
void DestroySeqList(SeqList *L);

/* Insert */
/*!
 * Insert a data from head of the sequential list
 * @param L : pointer to the sequential list
 * @param e : element to be inserted
 * @return status (true, false)
 */
Status SeqList_Head_Insert(SeqList *L, ElemType e);

/*!
 * Insert a data from tail of the sequential list
 * @param L : pointer to the sequential list
 * @param e : element to be insert
 * @return status (true, false)
 */
Status SeqList_Tail_Insert(SeqList *L, ElemType e);

/*!
 * Insert a data before a specific position of the sequential list by order
 * @param L : pointer to the sequential list
 * @param i : the order of a specific position, legitimate range: [1, n + 1]
 * @param e : element to be insert
 * @return status (true, false, input_error)
 */
Status SeqList_Insert_By_Order(SeqList *L, int i, ElemType e);

/* Delete */
/*!
 * Delete a data of the sequential list by value
 * @param L : pointer to the sequential list
 * @param e : the data to be deleted
 * @return status (true, false)
 */
Status SeqList_Delete_By_Value(SeqList *L, ElemType e);

/*!
 * Delete a data of the sequential list by order
 * @param L : pointer to the sequential list
 * @param i : the order of a specific data, legitimate range: [1, n]
 * @param e : the data to be deleted
 * @return status (true, false, input_error)
 */
Status SeqList_Delete_By_Order(SeqList *L, int i, ElemType *e);

/* Retrieve */
/*!
 * Retrieve a data of the sequential list by value
 * @param L : pointer to the sequential list
 * @param e : the data to be retrieved
 * @return position (subscript) of the result if successfully retrieved else -1
 */
int SeqList_Retrieve_By_Value(SeqList *L, ElemType e);

/* Update */
/*!
 * Update a data of the sequential list by value
 * @param L : pointer to the sequential list
 * @param old : the old data to be updated
 * @param new : the new data to be updated
 * @return status (true, false)
 */
Status SeqList_Update_By_Value(SeqList *L, ElemType old, ElemType new);

/*!
 * Update a data of the sequential list by order
 * @param L : pointer to the sequential list
 * @param i : the order of a specific data, legitimate range: [1, n]
 * @param e : the data to be updated
 * @return status (true, false, input_error)
 */
Status SeqList_Update_By_Order(SeqList *L, int i, ElemType e);

/* Traverse */
/*!
 * Traverse the sequential list
 * @param L : the sequential list
 * @param visit : function pointer to the function that prints the data
 * @return status (true, false)
 */
Status SeqList_Traverse(SeqList L, void(*visit)(ElemType e));

/*!
 * The sequential list
 */
void seqlist_menu(void);

/*!
 * The sequential list menu details
 */
void seqlist_menu_show_details(void);

#endif //DATA_STRUCTURES_ARRAY_H

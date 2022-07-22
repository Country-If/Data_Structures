//
// Created by Maylon on 2022/7/21.
//

#include "SiLinkList_Head.h"

Status InitSiList_Head(SiList *L) {
    *L = (SiLNode *) malloc(sizeof(SiLNode));
    if (*L == NULL) {
        return false;
    }
    (*L)->next = NULL;
    return true;
}


Status DestroySiList_Head(SiList *L) {}


Status SiList_Head_Head_Insert(SiList L, ElemType e) {}


Status SiList_Head_Tail_Insert(SiList L, ElemType e) {}


Status SiList_Head_Insert_By_Order(SiList L, int i, ElemType e) {}


Status SiList_Head_Delete_By_Node(SiList L, SiLNode *p) {}


Status SiList_Head_Delete_By_Order(SiList L, int i, ElemType *e) {}


SiLNode *SiList_Head_Retrieve_By_Value(SiList L, ElemType e) {}


SiLNode *SiList_Head_Retrieve_By_Order(SiList L, int i) {}


Status SiList_Head_Update_By_Value(SiList L, ElemType old, ElemType new) {}


Status SiList_Head_Update_By_Order(SiList L, int i, ElemType e) {}


void SiList_Head_Traverse(SiList L, void(*visit)(ElemType e)) {}

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


Status SiList_Head_Head_Insert(SiList L, ElemType e) {
    if (L == NULL) {
        return false;
    }
    SiLNode *p = (SiLNode *)malloc(sizeof(SiLNode));
    if (p == NULL) {
        return false;
    }
    p->data = e;
    p->next = L->next;
    L->next = p;
    return true;
}


Status SiList_Head_Tail_Insert(SiList L, ElemType e) {}


Status SiList_Head_Insert_By_Order(SiList L, int i, ElemType e) {}


Status SiList_Head_Delete_By_Node(SiList L, SiLNode *p) {}


Status SiList_Head_Delete_By_Order(SiList L, int i, ElemType *e) {}


SiLNode *SiList_Head_Retrieve_By_Value(SiList L, ElemType e) {}


SiLNode *SiList_Head_Retrieve_By_Order(SiList L, int i) {}


Status SiList_Head_Update_By_Value(SiList L, ElemType old, ElemType new) {}


Status SiList_Head_Update_By_Order(SiList L, int i, ElemType e) {}


void SiList_Head_Traverse(SiList L, void(*visit)(ElemType e)) {
    SiList p = L->next;
    while (p != NULL) {
        visit(p->data);
        p = p->next;
    }
    printf("NULL\n");
}


void silinklist_head_menu(void) {
    int choice = 0;
    SiList L = NULL;
    ElemType e;
    do {
        silinklist_head_menu_show_details();
        choice = judge_int();
        system("cls");
        switch (choice) {
            case 0:     // exit
                break;
            case 1:     // Initialize
                if (InitSiList_Head(&L)) {
                    printf("Succeeded!\n");
                }
                else {
                    printf("Failed!\n");
                }
                break;
            case 2:     // Destroy

                break;
            case 3:     // Insert a node from head
                if (L == NULL) {
                    printf("The list is NULL!\n");
                }
                else {
                    get_input_element(&e);
                    if (SiList_Head_Head_Insert(L, e)) {
                        printf("Succeeded!\n");
                    }
                    else {
                        printf("Failed!\n");
                    }
                }
                break;
            case 4:     // Insert a node from tail

                break;
            case 5:     // Insert a node by order

                break;
            case 6:     // Delete a node by order

                break;
            case 7:     // Delete a node by value

                break;
            case 8:     // Update a node by order

                break;
            case 9:     // Update a node by value

                break;
            case 10:    // Traverse the list
                SiList_Head_Traverse(L, visit);
                break;
            default:
                printf("Wrong input, please re-enter.\n");
                break;
        }
    } while (choice != 0);
}


void silinklist_head_menu_show_details(void) {
    printf("\n");
    printf("\t**************************************************\n");
    printf("\t*      Single Linked List (with a head node)     *\n");
    printf("\t*------------------------------------------------*\n");
    printf("\t*  1  |   Initialize                             *\n");
    printf("\t*------------------------------------------------*\n");
    printf("\t*  2  |   Destroy                                *\n");
    printf("\t*------------------------------------------------*\n");
    printf("\t*  3  |   Insert a node from head                *\n");
    printf("\t*------------------------------------------------*\n");
    printf("\t*  4  |   Insert a node from tail                *\n");
    printf("\t*-------------------------- ---------------------*\n");
    printf("\t*  5  |   Insert a node by order                 *\n");
    printf("\t*------------------------------------------------*\n");
    printf("\t*  6  |   Delete a node by order                 *\n");
    printf("\t*--------------------------- --------------------*\n");
    printf("\t*  7  |   Delete a node by value                 *\n");
    printf("\t*------------------------------------------------*\n");
    printf("\t*  8  |   Update a node by order                 *\n");
    printf("\t*------------------------------------------------*\n");
    printf("\t*  9  |   Update a node by value                 *\n");
    printf("\t*------------------------------------------------*\n");
    printf("\t*  10 |   Traverse the list                      *\n");
    printf("\t*------------------------------------------------*\n");
    printf("\t*  0  |   Exit                                   *\n");
    printf("\t**************************************************\n");
    printf("\nPlease enter the corresponding number(0-10): ");
}

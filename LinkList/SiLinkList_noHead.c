//
// Created by Maylon on 2022/7/21.
//

#include "SiLinkList_noHead.h"

void InitSiList_noHead(SiList_noHead *L) {
    *L = NULL;
}


Status DestroySiList_noHead(SiList_noHead *L) {
    if (*L == NULL) {
        return false;
    }

    SiLNode_noHead *p;
    while (*L != NULL) {
        p = *L;
        *L = (*L)->next;
        free(p);
    }
    return true;
}


Status SiList_noHead_Head_Insert(SiList_noHead L, ElemType e) {}


Status SiList_noHead_Tail_Insert(SiList_noHead L, ElemType e) {}


Status SiList_noHead_Insert_By_Order(SiList_noHead L, int i, ElemType e) {}


Status SiList_noHead_Delete_By_Value(SiList_noHead L, ElemType e) {}


Status SiList_noHead_Delete_By_Order(SiList_noHead L, int i, ElemType *e) {}


SiLNode_noHead *SiList_noHead_Retrieve_By_Value(SiList_noHead L, ElemType e) {}


SiLNode_noHead *SiList_noHead_Retrieve_By_Order(SiList_noHead L, int i, OptType opt) {}


Status SiList_noHead_Update_By_Value(SiList_noHead L, ElemType old, ElemType new) {}


Status SiList_noHead_Update_By_Order(SiList_noHead L, int i, ElemType e) {}


Status SiList_noHead_Traverse(SiList_noHead L, void(*visit)(ElemType e)) {}


void silinklist_noHead_menu(void) {
    int choice = 0;
    SiList_noHead L = NULL;
    ElemType e, old, new;
    int i;
    Status result;
    do {
        silinklist_noHead_menu_show_details();
        choice = judge_int();
        system("cls");
        switch (choice) {
            case 0:     // exit
                break;
            case 1:     // Initialize
                InitSiList_noHead(&L);
                printf("Succeeded!\n");
                printf("Current list: NULL\n");
                break;
            case 2:     // Destroy
                if (L == NULL) {
                    printf("The list is already NULL!\n");
                }
                else {
                    if (DestroySiList_noHead(&L) == true) {
                        printf("Succeeded!\n");
                    }
                    else {
                        printf("Failed!\n");
                    }
                }
                break;
            case 3:     // Insert a node from head
                if (L == NULL) {
                    printf("The list is NULL!\n");
                }
                else {

                }
                break;
            case 4:     // Insert a node from tail
                if (L == NULL) {
                    printf("The list is NULL!\n");
                }
                else {

                }
                break;
            case 5:     // Insert a node by order
                if (L == NULL) {
                    printf("The list is NULL!\n");
                }
                else {

                }
                break;
            case 6:     // Delete a node by order
                if (L == NULL || L->next == NULL) {
                    printf("The list is NULL!\n");
                }
                else {

                }
                break;
            case 7:     // Delete a node by value
                if (L == NULL) {
                    printf("The list is NULL!\n");
                }
                else {

                }
                break;
            case 8:     // Update a node by order
                if (L == NULL) {
                    printf("The list is NULL!\n");
                }
                else {

                }
                break;
            case 9:     // Update a node by value
                if (L == NULL) {
                    printf("The list is NULL!\n");
                }
                else {

                }
                break;
            default:
                printf("Wrong input, please re-enter!\n");
                break;
        }
    } while (choice != 0);
    // release memory
    if (L != NULL) {
        DestroySiList_noHead(&L);
    }
}


void silinklist_noHead_menu_show_details(void) {
    printf("\n");
    printf("\t**************************************************\n");
    printf("\t*     Single Linked List (without a head node)   *\n");
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
    printf("\t*  0  |   Back                                   *\n");
    printf("\t**************************************************\n");
    printf("\nPlease enter the corresponding number(0-9): ");
}

//
// Created by Maylon on 2022/7/21.
//

#include "CirDoLinkList.h"

void InitCirDoList(CirDoList *L) {
    *L = NULL;
}


Status DestroyCirDoList(CirDoList *L) {
    if (*L == NULL) {
        return false;
    }

    CirDoLNode *p = (*L)->next;
    while (p != *L) {
        p = p->next;
        free((*L)->next);
        (*L)->next = p;
    }
    free(*L);
    *L = NULL;
    return true;
}


Status CirDoList_Head_Insert(CirDoList *L, ElemType e) {
    CirDoLNode *p = (CirDoLNode *) malloc(sizeof(CirDoLNode));
    if (p == NULL) {
        return false;
    }

    if (*L == NULL) {
        *L = p;
        (*L)->data = e;
        (*L)->prior = *L;
        (*L)->next = *L;
    }
    else {
        p->data = e;
        p->prior = (*L)->prior;
        p->next = *L;
        (*L)->prior->next = p;
        (*L)->prior = p;
        *L = p;
    }
    return true;
}


Status CirDoList_Tail_Insert(CirDoList *L, ElemType e) {}


Status CirDoList_Insert_By_Order(CirDoList *L, int i, ElemType e) {}


void CirDoList_Delete_By_Node(CirDoList *L, CirDoLNode *p) {}


Status CirDoList_Delete_By_Value(CirDoList *L, ElemType e) {}


Status CirDoList_Delete_By_Order(CirDoList *L, int i, ElemType *e) {}


CirDoLNode *CirDoList_Retrieve_By_Value(CirDoList L, ElemType e) {}


CirDoLNode *CirDoList_Retrieve_By_Order(CirDoList L, int i) {}


Status CirDoList_Update_By_Value(CirDoList L, ElemType old, ElemType new) {}


Status CirDoList_Update_By_Order(CirDoList L, int i, ElemType e) {}


void CirDoList_Traverse(CirDoList L, void(*visit)(ElemType e)) {
    CirDoLNode *p = L;
    if (L != NULL) {
        do {
            visit(p->data);
            p = p->next;
        } while (p != L);
    }
    printf("NULL\n");
}


void cirdolinklist_menu(void) {
    int choice;
    CirDoList L = NULL;
    ElemType e, old, new;
    int i;
    Status result;
    do {
        cirdolinklist_menu_show_details();
        choice = judge_int();
        system("cls");
        switch (choice) {
            case 0:     // exit
                break;
            case 1:     // Initialize
                InitCirDoList(&L);
                printf("Succeeded!\n");
                break;
            case 2:     // Destroy
                if (L == NULL) {
                    printf("The list is already NULL!\n");
                }
                else {
                    if (DestroyCirDoList(&L) == true) {
                        printf("Succeeded!\n");
                    }
                    else {
                        printf("Failed!\n");
                    }
                }
                break;
            case 3:     // Insert a node from head
                get_input_element(&e);
                system("cls");
                if (CirDoList_Head_Insert(&L, e) == true) {
                    printf("Succeeded!\n");
                }
                else {
                    printf("Failed!\n");
                }
                break;
            case 4:     // Insert a node from tail
                get_input_element(&e);
                system("cls");
                if (CirDoList_Tail_Insert(&L, e) == true) {
                    printf("Succeeded!\n");
                }
                else {
                    printf("Failed!\n");
                }
                break;
            case 5:     // Insert a node by order
                get_order_position(&i);
                get_input_element(&e);
                system("cls");
                result = CirDoList_Insert_By_Order(&L, i, e);
                if (result == true) {
                    printf("Succeeded!\n");
                }
                else {
                    if (result == input_error) {
                        printf("Out of bounds!\n");
                    }
                    printf("Failed!\n");
                }
                break;
            case 6:     // Delete a node by order
                if (L == NULL) {
                    printf("The list is NULL!\n");
                }
                else {
                    get_order_position(&i);
                    system("cls");
                    result = CirDoList_Delete_By_Order(&L, i, &e);
                    if (result == true) {
                        printf("Successfully deleted data: %d\n", e);
                    }
                    else {
                        if (result == input_error) {
                            printf("Out of bounds!\n");
                        }
                        printf("Failed!\n");
                    }
                }
                break;
            case 7:     // Delete a node by value
                if (L == NULL) {
                    printf("The list is NULL!\n");
                }
                else {
                    get_input_element(&e);
                    system("cls");
                    if (CirDoList_Delete_By_Value(&L, e) == true) {
                        printf("Succeeded!\n");
                    }
                    else {
                        printf("Cannot find the element!\n");
                    }
                }
                break;
            case 8:     // Update a node by order
                if (L == NULL) {
                    printf("The list is NULL!\n");
                }
                else {
                    get_order_position(&i);
                    get_input_element(&e);
                    system("cls");
                    result = CirDoList_Update_By_Order(L, i, e);
                    if (result == true) {
                        printf("Succeeded!\n");
                    }
                    else {
                        if (result == input_error) {
                            printf("Out of bounds!\n");
                        }
                        printf("Failed!\n");
                    }
                }
                break;
            case 9:     // Update a node by value
                if (L == NULL) {
                    printf("The list is NULL!\n");
                }
                else {
                    get_input_element(&old);
                    get_input_element(&new);
                    system("cls");
                    if (CirDoList_Update_By_Value(L, old, new) == true) {
                        printf("Succeeded!\n");
                    }
                    else {
                        printf("Cannot find the element!\n");
                    }
                }
                break;
            default:
                printf("Wrong input, please re-enter!\n");
                break;
        }
        if (choice >= 1 && choice <= 9) {
            printf("Current list: ");
            CirDoList_Traverse(L, visit);
        }
    } while (choice != 0);
    // release memory
    if (L != NULL) {
        DestroyCirDoList(&L);
    }
}


void cirdolinklist_menu_show_details(void) {
    printf("\n");
    printf("\t**************************************************\n");
    printf("\t*   Circular Double Linked List (without head)   *\n");
    printf("\t*------------------------------------------------*\n");
    printf("\t*  1  |   Initialize (Reset)                     *\n");
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
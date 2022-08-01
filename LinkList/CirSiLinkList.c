//
// Created by Maylon on 2022/7/21.
//

#include "CirSiLinkList.h"

Status InitCirSiList(CirSiList *L) {
    *L = (CirSiLNode *) malloc(sizeof(CirSiLNode));
    if (*L == NULL) {
        return false;
    }

    (*L)->next = *L;
    return true;
}


Status DestroyCirSiList(CirSiList *L) {
    if (*L == NULL) {
        return false;
    }

    CirSiLNode *p = (*L)->next;
    while (p != *L) {
        p = p->next;
        free((*L)->next);
        (*L)->next = p;
    }
    free(*L);
    *L = NULL;
    return true;
}


Status CirSiList_Head_Insert(CirSiList L, ElemType e) {
    if (L == NULL) {
        return false;
    }

    CirSiLNode *p = (CirSiLNode *) malloc(sizeof(CirSiLNode));
    if (p == NULL) {
        return false;
    }

    p->data = e;
    p->next = L->next;
    L->next = p;
    return true;
}


Status CirSiList_Tail_Insert(CirSiList L, ElemType e) {
    if (L == NULL) {
        return false;
    }

    CirSiLNode *p = (CirSiLNode *) malloc(sizeof(CirSiLNode));
    if (p == NULL) {
        return false;
    }

    CirSiLNode *t = L->next;
    while (t->next != L) {
        t = t->next;
    }

    p->data = e;
    p->next = L;
    t->next = p;
    return true;
}


Status CirSiList_Insert_By_Order(CirSiList L, int i, ElemType e) {}


Status CirSiList_Delete_By_Value(CirSiList L, ElemType e) {}


Status CirSiList_Delete_By_Order(CirSiList L, int i, ElemType *e) {}


CirSiLNode *CirSiList_Retrieve_By_Value(CirSiList L, ElemType e) {}


CirSiLNode *CirSiList_Retrieve_By_Order(CirSiList L, int i) {}


Status CirSiList_Update_By_Value(CirSiList L, ElemType old, ElemType new) {}


Status CirSiList_Update_By_Order(CirSiList L, int i, ElemType e) {}


Status CirSiList_Traverse(CirSiList L, void(*visit)(ElemType e)) {
    if (L == NULL) {
        return false;
    }

    CirSiLNode *p = L->next;
    while (p != L) {
        visit(p->data);
        p = p->next;
    }

    printf("NULL\n");
    return true;
}


void cirsilist_menu(void) {
    int choice;
    CirSiList L = NULL;
    ElemType e, old, new;
    int i;
    Status result;
    do {
        cirsilist_menu_show_details();
        choice = judge_int();
        system("cls");
        switch (choice) {
            case 0:     // exit
                break;
            case 1:     // Initialize
                if (InitCirSiList(&L) == true) {
                    printf("Succeeded!\n");
                    printf("Current list: NULL\n");
                }
                else {
                    printf("Failed!\n");
                }
                break;
            case 2:     // Destroy
                if (L == NULL) {
                    printf("The list is already NULL!\n");
                }
                else {
                    if (DestroyCirSiList(&L) == true) {
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
                    get_input_element(&e);
                    system("cls");
                    if (CirSiList_Head_Insert(L, e) == true) {
                        printf("Succeeded!\n");
                    }
                    else {
                        printf("Failed!\n");
                    }
                }
                break;
            case 4:     // Insert a node from tail
                if (L == NULL) {
                    printf("The list is NULL!\n");
                }
                else {
                    get_input_element(&e);
                    system("cls");
                    if (CirSiList_Tail_Insert(L, e) == true) {
                        printf("Succeeded!\n");
                    }
                    else {
                        printf("Failed!\n");
                    }
                }
                break;
            case 5:     // Insert a node by order
                if (L == NULL) {
                    printf("The list is NULL!\n");
                }
                else {
                    get_order_position(&i);
                    get_input_element(&e);
                    system("cls");
                    result = CirSiList_Insert_By_Order(L, i, e);
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
            case 6:     // Delete a node by order
                if (L == NULL || L->next == L) {
                    printf("The list is NULL!\n");
                }
                else {
                    get_order_position(&i);
                    system("cls");
                    result = CirSiList_Delete_By_Order(L, i, &e);
                    if (result == true) {
                        printf("Successfully deleted data: %d\n", e);
                        if (L->next == NULL) {
                            printf("Current list: NULL\n");
                        }
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
                if (L == NULL || L->next == L) {
                    printf("The list is NULL!\n");
                }
                else {
                    get_input_element(&e);
                    system("cls");
                    if (CirSiList_Delete_By_Value(L, e) == true) {
                        printf("Succeeded!\n");
                        if (L->next == NULL) {
                            printf("Current list: NULL\n");
                        }
                    }
                    else {
                        printf("Cannot find the element!\n");
                    }
                }
                break;
            case 8:     // Update a node by order
                if (L == NULL || L->next == L) {
                    printf("The list is NULL!\n");
                }
                else {
                    get_order_position(&i);
                    get_input_element(&e);
                    system("cls");
                    result = CirSiList_Update_By_Order(L, i, e);
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
                if (L == NULL || L->next == L) {
                    printf("The list is NULL!\n");
                }
                else {
                    get_input_element(&old);
                    get_input_element(&new);
                    system("cls");
                    if (CirSiList_Update_By_Value(L, old, new) == true) {
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
        if (choice >= 3 && choice <= 9 && L != NULL && L->next != L) {
            printf("Current list: ");
            CirSiList_Traverse(L, visit);
        }
    } while (choice != 0);
    // release memory
    if (L != NULL) {
        DestroyCirSiList(&L);
    }
}


void cirsilist_menu_show_details(void) {
    printf("\n");
    printf("\t**************************************************\n");
    printf("\t*      Circular Single Linked List (with head)   *\n");
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
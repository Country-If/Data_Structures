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


Status CirSiList_Insert_By_Order(CirSiList L, int i, ElemType e) {
    if (L == NULL) {
        return false;
    }

    if (i < 1) {            // out of bounds
        return input_error;
    }

    CirSiLNode *p = (CirSiLNode *) malloc(sizeof(CirSiLNode));
    if (p == NULL) {
        return false;
    }

    int j = 0;
    CirSiLNode *t = L;
    while (t->next != L && i != j + 1) {        // find the insert position (prior node)
        t = t->next;
        j++;
    }

    if (i > j + 1) {        // out of bounds
        return input_error;
    }

    p->data = e;
    p->next = t->next;
    t->next = p;
    return true;
}


Status CirSiList_Delete_By_Value(CirSiList L, ElemType e) {
    if (L == NULL || L->next == L) {
        return false;
    }

    CirSiLNode *p_prior = L, *p = L->next;
    while (p != L) {
        if (p->data == e) {
            break;
        }
        p_prior = p;
        p = p->next;
    }

    if (p == L) {
        return false;
    }
    else {
        p_prior->next = p->next;
        free(p);
        return true;
    }
}


Status CirSiList_Delete_By_Order(CirSiList L, int i, ElemType *e) {
    if (L == NULL || L->next == L) {
        return false;
    }

    if (i < 1) {        // out of bounds
        return input_error;
    }

    int j = 1;
    CirSiLNode *p_prior = L, *p = L->next;  // p points to the node to be deleted, p_prior points to the prior node of p
    while (p->next != L) {
        if (i == j) {
            break;
        }
        p_prior = p;
        p = p->next;
        j++;
    }

    if (i > j) {        // out of bounds
        return input_error;
    }

    p_prior->next = p->next;
    *e = p->data;
    free(p);
    return true;
}


CirSiLNode *CirSiList_Retrieve_By_Value(CirSiList L, ElemType e) {
    if (L == NULL) {
        return NULL;
    }

    CirSiLNode *p = L->next;
    while (p != L) {
        if (p->data == e) {
            break;
        }
        p = p->next;
    }
    return p;
}


CirSiLNode *CirSiList_Retrieve_By_Order(CirSiList L, int i) {
    if (L == NULL) {
        return NULL;
    }

    if (i < 1) {        // out of bounds
        return NULL;
    }

    int j = 1;
    CirSiLNode *p = L->next;
    while (p != L) {
        if (i == j) {
            break;
        }
        p = p->next;
        j++;
    }

    if (i > j) {        // out of bounds
        return NULL;
    }

    return p;
}


Status CirSiList_Update_By_Value(CirSiList L, ElemType old, ElemType new) {
    if (L == NULL || L->next == L) {
        return false;
    }

    CirSiLNode *p = CirSiList_Retrieve_By_Value(L, old);
    if (p == NULL) {
        return false;
    }

    p->data = new;
    return true;
}


Status CirSiList_Update_By_Order(CirSiList L, int i, ElemType e) {
    if (L == NULL || L->next == L) {
        return false;
    }

    CirSiLNode *p = CirSiList_Retrieve_By_Order(L, i);
    if (p == NULL || p == L) {
        return input_error;
    }

    p->data = e;
    return true;
}


Status CirSiList_Reverse(CirSiList L) {
    if (L == NULL || L->next == L) {
        return false;
    }

    CirSiLNode *p = L->next, *q;
    L->next = L;
    while (p != L) {
        q = p->next;
        p->next = L->next;
        L->next = p;
        p = q;
    }
    return true;
}


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
            case 10:    // reverse the list
                if (L == NULL || L->next == L) {
                    printf("The list is NULL!\n");
                }
                else {
                    if (CirSiList_Reverse(L) == true) {
                        printf("Succeeded!\n");
                    }
                    else {
                        printf("Failed!\n");
                    }
                }
                break;
            default:
                printf("Wrong input, please re-enter!\n");
                break;
        }
        if (choice >= 3 && choice <= 10 && L != NULL) {
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
    printf("\t*  10 |   Reverse the list                       *\n");
    printf("\t*------------------------------------------------*\n");
    printf("\t*  0  |   Back                                   *\n");
    printf("\t**************************************************\n");
    printf("\nPlease enter the corresponding number(0-10): ");
}
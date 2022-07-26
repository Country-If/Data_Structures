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


Status CirDoList_Tail_Insert(CirDoList *L, ElemType e) {
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
    }
    return true;
}


Status CirDoList_Insert_By_Order(CirDoList *L, int i, ElemType e) {
    if (i < 1) {        // out of bounds
        return input_error;
    }

    CirDoLNode *p = (CirDoLNode *) malloc(sizeof(CirDoLNode));
    if (p == NULL) {
        return false;
    }
    p->data = e;

    if (i == 1) {
        if (*L == NULL) {
            *L = p;
            (*L)->prior = *L;
            (*L)->next = *L;
        }
        else {
            p->prior = (*L)->prior;
            p->next = *L;
            (*L)->prior->next = p;
            (*L)->prior = p;
            *L = p;
        }
    }
    else {
        int j = 1;
        CirDoLNode *t = *L;
        while (t->next != *L && i != j + 1) {       // find the insert position (prior node)
            t = t->next;
            j++;
        }

        if (i > j + 1) {        // out of bounds
            return input_error;
        }

        p->prior = t;
        p->next = t->next;
        t->next->prior = p;
        t->next = p;
    }
    return true;
}


void CirDoList_Delete_By_Node(CirDoList *L, CirDoLNode *p) {
    if (p == p->next) {
        *L = NULL;
        free(p);
    }
    else {
        p->prior->next = p->next;
        p->next->prior = p->prior;
        if (p == *L) {
            *L = p->next;
        }
        free(p);
    }
}


Status CirDoList_Delete_By_Value(CirDoList *L, ElemType e) {
    if (*L == NULL) {
        return false;
    }

    CirDoLNode *p = CirDoList_Retrieve_By_Value(*L, e);
    if (p == NULL) {
        return false;
    }

    CirDoList_Delete_By_Node(L, p);
    return true;
}


Status CirDoList_Delete_By_Order(CirDoList *L, int i, ElemType *e) {
    if (*L == NULL) {
        return false;
    }

    CirDoLNode *p = CirDoList_Retrieve_By_Order(*L, i);
    if (p == NULL) {
        return input_error;
    }

    CirDoList_Delete_By_Node(L, p);
    return true;
}


CirDoLNode *CirDoList_Retrieve_By_Value(CirDoList L, ElemType e) {
    CirDoLNode *p = L;
    if (L != NULL) {
        do {
            if (p->data == e) {
                break;
            }
            p = p->next;
        } while (p->next != L);
        if (p->data != e) {
            p = NULL;
        }
    }
    return p;
}


CirDoLNode *CirDoList_Retrieve_By_Order(CirDoList L, int i) {
    if (i < 1) {        // out of bounds
        return NULL;
    }

    int j = 1;
    CirDoLNode *p = L;
    if (L != NULL) {
        do {
            if (i == j) {
                break;
            }
            p = p->next;
            j++;
        } while (p->next != L);

        if (i > j) {        // out of bounds
            return NULL;
        }
    }

    return p;
}


Status CirDoList_Update_By_Value(CirDoList L, ElemType old, ElemType new) {
    if (L == NULL) {
        return false;
    }

    CirDoLNode *p = CirDoList_Retrieve_By_Value(L, old);
    if (p == NULL) {
        return false;
    }

    p->data = new;
    return true;
}


Status CirDoList_Update_By_Order(CirDoList L, int i, ElemType e) {
    if (L == NULL) {
        return false;
    }

    CirDoLNode *p = CirDoList_Retrieve_By_Order(L, i);
    if (p == NULL) {
        return input_error;
    }

    p->data = e;
    return true;
}


Status CirDoList_Reverse(CirDoList *L) {
    if (*L == NULL) {
        return false;
    }

    CirDoLNode *p = (*L)->next, *q, *r = (*L)->prior, *s = *L;
    (*L)->prior = p;
    (*L)->next = r;
    while (p != s) {
        q = p->next;
        p->prior = q;
        p->next = *L;
        *L = p;
        p = q;
    }
    return true;
}


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
            case 10:    // reverse the list
                if (L == NULL) {
                    printf("The list is NULL!\n");
                }
                else {
                    if (CirDoList_Reverse(&L) == true) {
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
        if (choice >= 1 && choice <= 10) {
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
    printf("\t*  10 |   Reverse the list                       *\n");
    printf("\t*------------------------------------------------*\n");
    printf("\t*  0  |   Back                                   *\n");
    printf("\t**************************************************\n");
    printf("\nPlease enter the corresponding number(0-10): ");
}
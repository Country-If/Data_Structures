//
// Created by Maylon on 2022/7/21.
//

#include "DoLinkList.h"

void InitDoList(DoList *L) {
    *L = NULL;
}


Status DestroyDoList(DoList *L) {
    if (*L == NULL) {
        return false;
    }

    DoLNode *p;
    while (*L != NULL) {
        p = *L;
        *L = (*L)->next;
        free(p);
    }
    return true;
}


Status DoList_Head_Insert(DoList *L, ElemType e) {
    DoLNode *p = (DoLNode *) malloc(sizeof(DoLNode));
    if (p == NULL) {
        return false;
    }

    if (*L == NULL) {
        *L = p;
        (*L)->data = e;
        (*L)->prior = NULL;
        (*L)->next = NULL;
    }
    else {
        p->data = e;
        p->prior = NULL;
        p->next = *L;
        *L = p;
    }
    return true;
}


Status DoList_Tail_Insert(DoList *L, ElemType e) {
    DoLNode *p = (DoLNode *) malloc(sizeof(DoLNode));
    if (p == NULL) {
        return false;
    }

    if (*L == NULL) {
        *L = p;
        (*L)->data = e;
        (*L)->prior = NULL;
        (*L)->next = NULL;
    }
    else {
        DoLNode *t = *L;
        while (t->next != NULL) {
            t = t->next;
        }
        p->data = e;
        p->prior = t;
        p->next = NULL;
        t->next = p;
    }
    return true;
}


Status DoList_Insert_By_Order(DoList *L, int i, ElemType e) {
    if (i < 1) {        // out of bounds
        return input_error;
    }

    DoLNode *p = (DoLNode *) malloc(sizeof(DoLNode));
    if (p == NULL) {
        return false;
    }
    p->data = e;

    if (i == 1) {
        p->prior = NULL;
        p->next = *L;
        *L = p;
    }
    else {
        int j = 1;
        DoLNode *t = *L;
        while (t->next != NULL && i != j + 1) {     // find the insert position (prior node)
            t = t->next;
            j++;
        }

        if (i > j + 1) {        // out of bounds
            return input_error;
        }

        p->prior = t;
        p->next = t->next;
        if (t->next != NULL) {
            t->next->prior = p;
        }
        t->next = p;
    }
    return true;
}


void DoList_Delete_By_Node(DoList *L, DoLNode *p) {
    if (*L == p) {
        *L = p->next;
        if (p->next != NULL) {
            p->next->prior = NULL;
        }
        free(p);
    }
    else {
        p->prior->next = p->next;
        if (p->next != NULL) {
            p->next->prior = p->prior;
        }
        free(p);
    }
}


Status DoList_Delete_By_Value(DoList *L, ElemType e) {
    if (*L == NULL) {
        return false;
    }

    DoLNode *p = DoList_Retrieve_By_Value(*L, e);
    if (p == NULL) {
        return false;
    }

    DoList_Delete_By_Node(L, p);
    return true;
}


Status DoList_Delete_By_Order(DoList *L, int i, ElemType *e) {
    if (*L == NULL) {
        return false;
    }

    DoLNode *p = DoList_Retrieve_By_Order(*L, i);
    if (p == NULL) {
        return input_error;
    }

    DoList_Delete_By_Node(L, p);
    return true;
}


DoLNode *DoList_Retrieve_By_Value(DoList L, ElemType e) {
    DoLNode *p = L;
    while (p != NULL) {
        if (p->data == e) {
            break;
        }
        p = p->next;
    }
    return p;
}


DoLNode *DoList_Retrieve_By_Order(DoList L, int i) {
    if (L == NULL) {
        return NULL;
    }

    if (i < 1) {        // out of bounds
        return NULL;
    }

    int j = 1;
    DoLNode *p = L;
    while (p->next != NULL) {
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


Status DoList_Update_By_Value(DoList L, ElemType old, ElemType new) {
    if (L == NULL) {
        return false;
    }

    DoLNode *p = DoList_Retrieve_By_Value(L, old);
    if (p == NULL) {
        return false;
    }

    p->data = new;
    return true;
}


Status DoList_Update_By_Order(DoList L, int i, ElemType e) {
    if (L == NULL) {
        return false;
    }

    DoLNode *p = DoList_Retrieve_By_Order(L, i);
    if (p == NULL) {
        return input_error;
    }

    p->data = e;
    return true;
}


Status DoList_Reverse(DoList *L) {
    if (*L == NULL) {
        return false;
    }

    DoLNode *p = (*L)->next, *q;
    (*L)->prior = p;
    (*L)->next = NULL;
    while (p != NULL) {
        q = p->next;
        p->prior = q;
        p->next = *L;
        *L = p;
        p = q;
    }
    return true;
}


void DoList_Traverse(DoList L, void(*visit)(ElemType e)) {
    DoLNode *p = L;
    while (p != NULL) {
        visit(p->data);
        p = p->next;
    }
    printf("NULL\n");
}


void dolinklist_menu(void) {
    int choice;
    DoList L = NULL;
    ElemType e, old, new;
    int i;
    Status result;
    do {
        dolinklist_menu_show_details();
        choice = judge_int();
        system("cls");
        switch (choice) {
            case 0:     // exit
                break;
            case 1:     // Initialize
                InitDoList(&L);
                printf("Succeeded!\n");
                break;
            case 2:     // Destroy
                if (L == NULL) {
                    printf("The list is already NULL!\n");
                }
                else {
                    if (DestroyDoList(&L) == true) {
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
                if (DoList_Head_Insert(&L, e) == true) {
                    printf("Succeeded!\n");
                }
                else {
                    printf("Failed!\n");
                }
                break;
            case 4:     // Insert a node from tail
                get_input_element(&e);
                system("cls");
                if (DoList_Tail_Insert(&L, e) == true) {
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
                result = DoList_Insert_By_Order(&L, i, e);
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
                    result = DoList_Delete_By_Order(&L, i, &e);
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
                    if (DoList_Delete_By_Value(&L, e) == true) {
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
                    result = DoList_Update_By_Order(L, i, e);
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
                    if (DoList_Update_By_Value(L, old, new) == true) {
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
                    if (DoList_Reverse(&L) == true) {
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
            DoList_Traverse(L, visit);
        }
    } while (choice != 0);
    // release memory
    if (L != NULL) {
        DestroyDoList(&L);
    }
}


void dolinklist_menu_show_details(void) {
    printf("\n");
    printf("\t**************************************************\n");
    printf("\t*        Double Linked List (without head)       *\n");
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

//
// Created by Maylon on 2022/7/21.
//

#include "SiLinkList_Head.h"

Status InitSiList_Head(SiList_Head *L) {
    *L = (SiLNode_Head *) malloc(sizeof(SiLNode_Head));
    if (*L == NULL) {
        return false;
    }

    (*L)->next = NULL;
    return true;
}


Status DestroySiList_Head(SiList_Head *L) {
    if (*L == NULL) {
        return false;
    }

    SiLNode_Head *p;
    while (*L != NULL) {
        p = *L;
        *L = (*L)->next;
        free(p);
    }
    return true;
}


Status SiList_Head_Head_Insert(SiList_Head L, ElemType e) {
    if (L == NULL) {
        return false;
    }

    SiLNode_Head *p = (SiLNode_Head *) malloc(sizeof(SiLNode_Head));
    if (p == NULL) {
        return false;
    }

    p->data = e;
    p->next = L->next;
    L->next = p;
    return true;
}


Status SiList_Head_Tail_Insert(SiList_Head L, ElemType e) {
    if (L == NULL) {
        return false;
    }

    SiLNode_Head *p = (SiLNode_Head *) malloc(sizeof(SiLNode_Head));
    if (p == NULL) {
        return false;
    }

    SiLNode_Head *t = L;
    while (t->next != NULL) {
        t = t->next;
    }

    p->data = e;
    p->next = t->next;
    t->next = p;
    return true;
}


Status SiList_Head_Insert_By_Order(SiList_Head L, int i, ElemType e) {
    if (L == NULL) {
        return false;
    }

    SiLNode_Head *p = SiList_Head_Retrieve_By_Order(L, i, insert);
    if (p == NULL) {
        return input_error;
    }

    SiLNode_Head *t = (SiLNode_Head *) malloc(sizeof(SiLNode_Head));
    if (t == NULL) {
        return false;
    }

    t->data = e;
    t->next = p->next;
    p->next = t;
    return true;
}


Status SiList_Head_Delete_By_Value(SiList_Head L, ElemType e) {
    if (L == NULL) {
        return false;
    }

    SiLNode_Head *p_prior = L, *p = L->next;
    while (p != NULL) {         // find the position
        if (p->data == e) {
            break;
        }
        p_prior = p;
        p = p->next;
    }

    if (p == NULL) {
        return false;
    }
    else {
        p_prior->next = p->next;
        free(p);
        return true;
    }
}


Status SiList_Head_Delete_By_Order(SiList_Head L, int i, ElemType *e) {
    if (L == NULL || L->next == NULL) {
        return false;
    }

    if (i < 1) {        // out of bounds
        return input_error;
    }

    int j = 1;
    SiLNode_Head *p_prior = L, *p = L->next;
    while (p->next != NULL) {         // find the position
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


SiLNode_Head *SiList_Head_Retrieve_By_Value(SiList_Head L, ElemType e) {
    if (L == NULL) {
        return NULL;
    }

    SiLNode_Head *p = L->next;
    while (p != NULL) {
        if (p->data == e) {
            break;
        }
        p = p->next;
    }
    return p;
}


SiLNode_Head *SiList_Head_Retrieve_By_Order(SiList_Head L, int i, OptType opt) {
    if (L == NULL) {
        return NULL;
    }

    if (i < 1) {        // out of bounds
        return NULL;
    }

    int j = 0;
    SiLNode_Head *p = L;
    while (p != NULL) {         // find the position
        if (j + 1 == i) {
            break;
        }
        p = p->next;
        j++;
    }


    if (i > j + 1) {        // out of bounds
        return NULL;
    }

    if (opt == insert) {
        return p;
    }
    else if (opt == update) {
        if (p == NULL) {
            return NULL;
        }
        else {
            return p->next;
        }
    }
}


Status SiList_Head_Update_By_Value(SiList_Head L, ElemType old, ElemType new) {
    if (L == NULL) {
        return false;
    }

    SiLNode_Head *p = SiList_Head_Retrieve_By_Value(L, old);
    if (p == NULL) {
        return false;
    }

    p->data = new;
    return true;
}


Status SiList_Head_Update_By_Order(SiList_Head L, int i, ElemType e) {
    if (L == NULL) {
        return false;
    }

    SiLNode_Head *p = SiList_Head_Retrieve_By_Order(L, i, update);
    if (p == NULL) {
        return input_error;
    }

    p->data = e;
    return true;
}


Status SiList_Head_Traverse(SiList_Head L, void(*visit)(ElemType e)) {
    if (L == NULL) {
        return false;
    }

    SiList_Head p = L->next;
    while (p != NULL) {
        visit(p->data);
        p = p->next;
    }

    printf("NULL\n");
    return true;
}


void silinklist_head_menu(void) {
    int choice;
    SiList_Head L = NULL;
    ElemType e, old, new;
    int i;
    Status result;
    do {
        silinklist_head_menu_show_details();
        choice = judge_int();
        system("cls");
        switch (choice) {
            case 0:     // exit
                break;
            case 1:     // Initialize
                if (InitSiList_Head(&L) == true) {
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
                    if (DestroySiList_Head(&L) == true) {
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
                    if (SiList_Head_Head_Insert(L, e) == true) {
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
                    if (SiList_Head_Tail_Insert(L, e) == true) {
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
                    result = SiList_Head_Insert_By_Order(L, i, e);
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
                if (L == NULL || L->next == NULL) {
                    printf("The list is NULL!\n");
                }
                else {
                    get_order_position(&i);
                    system("cls");
                    result = SiList_Head_Delete_By_Order(L, i, &e);
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
                if (L == NULL || L->next == NULL) {
                    printf("The list is NULL!\n");
                }
                else {
                    get_input_element(&e);
                    system("cls");
                    if (SiList_Head_Delete_By_Value(L, e) == true) {
                        printf("Succeeded!\n");
                    }
                    else {
                        printf("Cannot find the element!\n");
                    }
                }
                break;
            case 8:     // Update a node by order
                if (L == NULL || L->next == NULL) {
                    printf("The list is NULL!\n");
                }
                else {
                    get_order_position(&i);
                    get_input_element(&e);
                    system("cls");
                    result = SiList_Head_Update_By_Order(L, i, e);
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
                if (L == NULL || L->next == NULL) {
                    printf("The list is NULL!\n");
                }
                else {
                    get_input_element(&old);
                    get_input_element(&new);
                    system("cls");
                    if (SiList_Head_Update_By_Value(L, old, new) == true) {
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
        if (choice >= 3 && choice <= 9 && L != NULL) {
            printf("Current list: ");
            SiList_Head_Traverse(L, visit);
        }
    } while (choice != 0);
    // release memory
    if (L != NULL) {
        DestroySiList_Head(&L);
    }
}


void silinklist_head_menu_show_details(void) {
    printf("\n");
    printf("\t**************************************************\n");
    printf("\t*      Single Linked List (with a head node)     *\n");
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

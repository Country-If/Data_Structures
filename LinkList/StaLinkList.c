//
// Created by Maylon on 2022/7/21.
//

#include "StaLinkList.h"

Status InitStaList(StaLinkList **L) {
    *L = (StaLinkList *) malloc(sizeof(StaLinkList) * MaxSize);     // array head pointer
    if (*L == NULL) {
        return false;
    }

    (**L)[0].next = -1;             // -1: end position of the list
    for (int i = 1; i < MaxSize; i++) {
        (**L)[i].next = -2;         // -2: unused node
    }
    return true;
}


Status DestroyStaList(StaLinkList **L) {
    if (*L == NULL) {
        return false;
    }

    free(*L);
    *L = NULL;
    return true;
}


int StaList_Retrieve_Position(StaLinkList *L) {
    int pos;
    for (int i = 1; i < MaxSize; i++) {
        pos = (*L)[i].next;
        if (pos == -2) {
            return i;
        }
    }
    return -1;
}


Status StaList_Head_Insert(StaLinkList *L, ElemType e) {
    if (*L == NULL) {
        return false;
    }

    int pos = StaList_Retrieve_Position(L);
    if (pos == -1) {
        return list_full;
    }

    (*L)[pos].data = e;
    (*L)[pos].next = (*L)[0].next;
    (*L)[0].next = pos;
    return true;
}


Status StaList_Tail_Insert(StaLinkList *L, ElemType e) {
    if (*L == NULL) {
        return false;
    }

    int pos = StaList_Retrieve_Position(L);
    if (pos == -1) {
        return list_full;
    }

    int t = 0;
    while (t < MaxSize) {       // find tail position
        if ((*L)[t].next == -1) {
            break;
        }
        t++;
    }

    (*L)[pos].data = e;
    (*L)[pos].next = -1;
    (*L)[t].next = pos;
    return true;
}


Status StaList_Insert_By_Order(StaLinkList *L, int i, ElemType e) {
    if (*L == NULL) {
        return false;
    }

    if (i < 1) {        // out of bounds
        return input_error;
    }

    int pos = StaList_Retrieve_Position(L);
    if (pos == -1) {
        return list_full;
    }

    int j = 0;
    int t = 0;
    while ((*L)[t].next != -1 && i != j + 1) {
        t = (*L)[t].next;
        j++;
    }

    if (i > j + 1) {        // out of bounds;
        return input_error;
    }

    (*L)[pos].data = e;
    (*L)[pos].next = (*L)[t].next;
    (*L)[t].next = pos;
    return true;
}


Status StaList_Delete_By_Value(StaLinkList *L, ElemType e) {
    if (*L == NULL || (*L)[0].next == -1) {
        return false;
    }

    int p_prior = 0, p = (*L)[0].next;
    while (p != -1) {       // find the position
        if ((*L)[p].data == e) {
            break;
        }
        p_prior = p;
        p = (*L)[p].next;
    }

    if (p == -1) {
        return false;
    }
    else {
        (*L)[p_prior].next = (*L)[p].next;
        (*L)[p].next = -2;
        return true;
    }
}


Status StaList_Delete_By_Order(StaLinkList *L, int i, ElemType *e) {
    if (*L == NULL || (*L)[0].next == -1) {
        return false;
    }

    if (i < 1) {        // out of bounds
        return input_error;
    }

    int j = 1;
    int p_prior = 0, p = (*L)[0].next;
    while ((*L)[p].next != -1) {
        if (i == j) {
            break;
        }
        p_prior = p;
        p = (*L)[p].next;
        j++;
    }

    if (i > j) {        // out of bounds
        return input_error;
    }

    (*L)[p_prior].next = (*L)[p].next;
    *e = (*L)[p].data;
    (*L)[p].next = -2;
    return true;
}


int StaList_Retrieve_By_Value(StaLinkList *L, ElemType e) {
    if (*L == NULL) {
        return -1;
    }

    int pos = (*L)[0].next;
    while (pos != -1) {
        if ((*L)[pos].data == e) {
            break;
        }
        pos = (*L)[pos].next;
    }
    return pos;
}


int StaList_Retrieve_By_Order(StaLinkList *L, int i) {
    if (*L == NULL) {
        return -1;
    }

    if (i < 1) {        // out of bounds
        return -1;
    }

    int j = 1;
    int pos = (*L)[0].next;
    while (pos != -1) {
        if (i == j) {
            break;
        }
        pos = (*L)[pos].next;
        j++;
    }

    if (i > j) {        // out of bounds
        return -1;
    }

    return pos;
}


Status StaList_Update_By_Value(StaLinkList *L, ElemType old, ElemType new) {
    if (*L == NULL || (*L)[0].next == -1) {
        return false;
    }

    int pos = StaList_Retrieve_By_Value(L, old);
    if (pos == -1) {
        return false;
    }

    (*L)[pos].data = new;
    return true;
}


Status StaList_Update_By_Order(StaLinkList *L, int i, ElemType e) {
    if (*L == NULL || (*L)[0].next == -1) {
        return false;
    }

    int pos = StaList_Retrieve_By_Order(L, i);
    if (pos == -1) {
        return input_error;
    }

    (*L)[pos].data = e;
    return true;
}


Status StaList_Reverse(StaLinkList *L) {
    if (*L == NULL || (*L)[0].next == -1) {
        return false;
    }

    int p = (*L)[0].next, q;
    (*L)[0].next = -1;
    while (p != -1) {
        q = (*L)[p].next;
        (*L)[p].next = (*L)[0].next;
        (*L)[0].next = p;
        p = q;
    }
    return true;
}


Status StaList_Traverse(StaLinkList *L, void(*visit)(ElemType e)) {
    if (*L == NULL) {
        return false;
    }

    int i = (*L)[0].next;
    while (i != -1) {
        visit((*L)[i].data);
        i = (*L)[i].next;
    }

    printf("NULL\n");
    return true;
}


void stalinklist_menu(void) {
    int choice;
    StaLinkList *L = NULL;
    ElemType e, old, new;
    int i;
    Status result;
    do {
        stalinklist_menu_show_details();
        choice = judge_int();
        system("cls");
        switch (choice) {
            case 0:     // exit
                break;
            case 1:     // Initialize
                if (InitStaList(&L) == true) {
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
                    if (DestroyStaList(&L) == true) {
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
                    result = StaList_Head_Insert(L, e);
                    if (result == true) {
                        printf("Succeeded!\n");
                    }
                    else {
                        if (result == list_full) {
                            printf("List is already full!\n");
                        }
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
                    result = StaList_Tail_Insert(L, e);
                    if (result == true) {
                        printf("Succeeded!\n");
                    }
                    else {
                        if (result == list_full) {
                            printf("List is already full!\n");
                        }
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
                    result = StaList_Insert_By_Order(L, i, e);
                    if (result == true) {
                        printf("Succeeded!\n");
                    }
                    else {
                        if (result == input_error) {
                            printf("Out of bounds!\n");
                        }
                        else if (result == list_full) {
                            printf("List is already full!\n");
                        }
                        printf("Failed!\n");
                    }
                }
                break;
            case 6:     // Delete a node by order
                if (L == NULL || (*L)[0].next == -1) {
                    printf("The list is NULL!\n");
                }
                else {
                    get_order_position(&i);
                    system("cls");
                    result = StaList_Delete_By_Order(L, i, &e);
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
                if (L == NULL || (*L)[0].next == -1) {
                    printf("The list is NULL!\n");
                }
                else {
                    get_input_element(&e);
                    system("cls");
                    if (StaList_Delete_By_Value(L, e) == true) {
                        printf("Succeeded!\n");
                    }
                    else {
                        printf("Cannot find the element!\n");
                    }
                }
                break;
            case 8:     // Update a node by order
                if (L == NULL || (*L)[0].next == -1) {
                    printf("The list is NULL!\n");
                }
                else {
                    get_order_position(&i);
                    get_input_element(&e);
                    system("cls");
                    result = StaList_Update_By_Order(L, i, e);
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
                if (L == NULL || (*L)[0].next == -1) {
                    printf("The list is NULL!\n");
                }
                else {
                    get_input_element(&old);
                    get_input_element(&new);
                    system("cls");
                    if (StaList_Update_By_Value(L, old, new) == true) {
                        printf("Succeeded!\n");
                    }
                    else {
                        printf("Cannot find the element!\n");
                    }
                }
                break;
            case 10:    // reverse the list
                if (L == NULL || (*L)[0].next == -1) {
                    printf("The list is NULL!\n");
                }
                else {
                    if (StaList_Reverse(L) == true) {
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
            StaList_Traverse(L, visit);
        }
    } while (choice != 0);
    // release memory
    if (L != NULL) {
        DestroyStaList(&L);
    }
}


void stalinklist_menu_show_details(void) {
    printf("\n");
    printf("\t**************************************************\n");
    printf("\t*      Static Linked List (with a head node)     *\n");
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

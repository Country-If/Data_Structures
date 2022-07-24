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


Status DestroySiList_Head(SiList *L) {
    if (*L == NULL) {
        return false;
    }

    SiLNode *p;
    while (*L != NULL) {
        p = *L;
        *L = (*L)->next;
        free(p);
    }
    return true;
}


Status SiList_Head_Head_Insert(SiList L, ElemType e) {
    if (L == NULL) {
        return false;
    }

    SiLNode *p = (SiLNode *) malloc(sizeof(SiLNode));
    if (p == NULL) {
        return false;
    }

    p->data = e;
    p->next = L->next;
    L->next = p;
    return true;
}


Status SiList_Head_Tail_Insert(SiList L, ElemType e) {
    if (L == NULL) {
        return false;
    }

    SiLNode *p = (SiLNode *) malloc(sizeof(SiLNode));
    if (p == NULL) {
        return false;
    }

    SiLNode *t = L;
    while (t->next != NULL) {
        t = t->next;
    }

    p->data = e;
    p->next = t->next;
    t->next = p;
    return true;
}


Status SiList_Head_Insert_By_Order(SiList L, int i, ElemType e) {
    if (L == NULL) {
        return false;
    }

    SiLNode *p = SiList_Head_Retrieve_By_Order(L, i);
    if (p == NULL) {
        return input_error;
    }

    SiLNode *t = (SiLNode *) malloc(sizeof(SiLNode));
    if (t == NULL) {
        return false;
    }

    t->data = e;
    t->next = p->next;
    p->next = t;
    return true;
}


Status SiList_Head_Delete_By_Node(SiList L, SiLNode *p) {}


Status SiList_Head_Delete_By_Order(SiList L, int i, ElemType *e) {}


SiLNode *SiList_Head_Retrieve_By_Value(SiList L, ElemType e) {
    SiLNode *p = L->next;
    while (p != NULL) {
        if (p->data == e) {
            break;
        }
        p = p->next;
    }
    return p;
}


SiLNode *SiList_Head_Retrieve_By_Order(SiList L, int i) {
    if (i < 1) {        // out of bounds
        return NULL;
    }

    int j = 0;
    SiLNode *p = L;
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
    return p;
}


Status SiList_Head_Update_By_Value(SiList L, ElemType old, ElemType new) {}


Status SiList_Head_Update_By_Order(SiList L, int i, ElemType e) {}


Status SiList_Head_Traverse(SiList L, void(*visit)(ElemType e)) {
    if (L == NULL) {
        return false;
    }

    SiList p = L->next;
    while (p != NULL) {
        visit(p->data);
        p = p->next;
    }

    printf("NULL\n");
    return true;
}


void silinklist_head_menu(void) {
    int choice = 0;
    SiList L = NULL;
    ElemType e;
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

                break;
            case 7:     // Delete a node by value

                break;
            case 8:     // Update a node by order

                break;
            case 9:     // Update a node by value

                break;
            case 10:    // Traverse the list
                if (L == NULL) {
                    printf("The list is NULL!\n");
                }
                else {
                    if (SiList_Head_Traverse(L, visit) != true) {
                        printf("Failed!\n");
                    }
                }
                break;
            default:
                printf("Wrong input, please re-enter!\n");
                break;
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
    printf("\t*  0  |   Back                                   *\n");
    printf("\t**************************************************\n");
    printf("\nPlease enter the corresponding number(0-10): ");
}

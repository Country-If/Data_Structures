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


Status SiList_noHead_Head_Insert(SiList_noHead *L, ElemType e) {
    SiLNode_noHead *p = (SiLNode_noHead *) malloc(sizeof(SiLNode_noHead));
    if (p == NULL) {
        return false;
    }

    if (*L == NULL) {
        *L = p;
        (*L)->data = e;
        (*L)->next = NULL;
    }
    else {
        p->data = e;
        p->next = *L;
        *L = p;
    }
    return true;
}

Status SiList_noHead_Tail_Insert(SiList_noHead *L, ElemType e) {
    SiLNode_noHead *p = (SiLNode_noHead *) malloc(sizeof(SiLNode_noHead));
    if (p == NULL) {
        return false;
    }

    if (*L == NULL) {
        *L = p;
        (*L)->data = e;
        (*L)->next = NULL;
    }
    else {
        SiLNode_noHead *t = *L;
        while (t->next != NULL) {
            t = t->next;
        }
        p->data = e;
        p->next = NULL;
        t->next = p;
    }
    return true;
}


Status SiList_noHead_Insert_By_Order(SiList_noHead *L, int i, ElemType e) {}


Status SiList_noHead_Delete_By_Value(SiList_noHead *L, ElemType e) {
    if (*L == NULL) {
        return false;
    }

    if ((*L)->data == e) {
        SiLNode_noHead *p = *L;
        *L = (*L)->next;
        free(p);
    }
    else {
        SiLNode_noHead *p_prior = *L, *p = (*L)->next;
        while (p != NULL) {
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
}


Status SiList_noHead_Delete_By_Order(SiList_noHead *L, int i, ElemType *e) {}


SiLNode_noHead *SiList_noHead_Retrieve_By_Value(SiList_noHead L, ElemType e) {
    SiLNode_noHead *p = L;
    while (p != NULL) {
        if (p->data == e) {
            break;
        }
        p = p->next;
    }
    return p;
}


SiLNode_noHead *SiList_noHead_Retrieve_By_Order(SiList_noHead L, int i, OptType opt) {}


Status SiList_noHead_Update_By_Value(SiList_noHead L, ElemType old, ElemType new) {
    if (L == NULL) {
        return false;
    }

    SiLNode_noHead *p = SiList_noHead_Retrieve_By_Value(L, old);
    if (p == NULL) {
        return false;
    }

    p->data = new;
    return true;
}


Status SiList_noHead_Update_By_Order(SiList_noHead L, int i, ElemType e) {}


void SiList_noHead_Traverse(SiList_noHead L, void(*visit)(ElemType e)) {
    SiList_noHead p = L;
    while (p != NULL) {
        visit(p->data);
        p = p->next;
    }
    printf("NULL\n");
}


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
                get_input_element(&e);
                system("cls");
                if (SiList_noHead_Head_Insert(&L, e) == true) {
                    printf("Succeeded!\n");
                }
                else {
                    printf("Failed!\n");
                }
                break;
            case 4:     // Insert a node from tail
                get_input_element(&e);
                system("cls");
                if (SiList_noHead_Tail_Insert(&L, e) == true) {
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
                result = SiList_noHead_Insert_By_Order(&L, i, e);
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
                    result = SiList_noHead_Delete_By_Order(&L, i, &e);
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
                    if (SiList_noHead_Delete_By_Value(&L, e) == true) {
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
                    result = SiList_noHead_Update_By_Order(L, i, e);
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
                    if (SiList_noHead_Update_By_Value(L, old, new) == true) {
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
            SiList_noHead_Traverse(L, visit);
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

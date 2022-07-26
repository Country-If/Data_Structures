//
// Created by Maylon on 2022/8/3.
//

#include "SeqList.h"

Status InitSeqList(SeqList *L) {
    (*L).data = (ElemType *) calloc(DeltaSize, sizeof(ElemType));
    if ((*L).data == NULL) {
        return false;
    }

    (*L).length = 0;
    (*L).MaxSize = DeltaSize;
    return true;
}


Status SeqList_Increase_Capacity(SeqList *L) {
    if ((*L).data == NULL) {
        return false;
    }

    ElemType *p = (*L).data;
    (*L).data = (ElemType *) calloc((*L).MaxSize + DeltaSize, sizeof(ElemType));
    if ((*L).data == NULL) {
        return false;
    }

    for (int i = 0; i < (*L).length; i++) {     // backup old data
        (*L).data[i] = p[i];
    }
    (*L).MaxSize += DeltaSize;
    free(p);
    return true;
}


void DestroySeqList(SeqList *L) {
    free((*L).data);
}


Status SeqList_Head_Insert(SeqList *L, ElemType e) {
    return SeqList_Insert_By_Order(L, 1, e);
}


Status SeqList_Tail_Insert(SeqList *L, ElemType e) {
    char choice;

    if ((*L).data == NULL) {
        return false;
    }

    if ((*L).length == (*L).MaxSize) {
        printf("The list if full, do you want to increase the capacity?(y/n) ");
        choice = get_choice();
        system("cls");
        if (choice == 'N' || choice == 'n') {
            return false;
        }
        else if (choice == 'Y' || choice == 'y') {
            if (SeqList_Increase_Capacity(L) == false) {
                printf("Failed to increase capacity!\n");
                return false;
            }
        }
    }
    (*L).data[(*L).length++] = e;
    return true;
}


Status SeqList_Insert_By_Order(SeqList *L, int i, ElemType e) {
    char choice;

    if ((*L).data == NULL) {
        return false;
    }

    if (i < 1 || i > (*L).length + 1) {
        return input_error;
    }

    if (i == (*L).length + 1) {
        return SeqList_Tail_Insert(L, e);
    }
    else {
        if ((*L).length == (*L).MaxSize) {
            printf("The list if full, do you want to increase the capacity?(y/n) ");
            choice = get_choice();
            system("cls");
            if (choice == 'N' || choice == 'n') {
                return false;
            }
            else if (choice == 'Y' || choice == 'y') {
                if (SeqList_Increase_Capacity(L) == false) {
                    printf("Failed to increase capacity!\n");
                    return false;
                }
            }
        }

        for (int j = (*L).length; j > i - 1; j--) {     // move backward
            (*L).data[j] = (*L).data[j - 1];
        }
        (*L).data[i - 1] = e;
        (*L).length++;
        return true;
    }
}


Status SeqList_Delete_By_Value(SeqList *L, ElemType e) {
    if ((*L).data == NULL) {
        return false;
    }

    int pos = SeqList_Retrieve_By_Value(L, e);
    if (pos == -1) {
        return false;
    }

    return SeqList_Delete_By_Order(L, pos + 1, &e);
}


Status SeqList_Delete_By_Order(SeqList *L, int i, ElemType *e) {
    if ((*L).data == NULL) {
        return false;
    }

    if (i < 1 || i > (*L).length) {
        return input_error;
    }

    *e = (*L).data[i - 1];
    for (int j = i; j < (*L).length; j++) {
        (*L).data[j - 1] = (*L).data[j];
    }
    (*L).length--;
    return true;
}


int SeqList_Retrieve_By_Value(SeqList *L, ElemType e) {
    if ((*L).data == NULL) {
        return -1;
    }

    for (int i = 0; i < (*L).length; i++) {
        if ((*L).data[i] == e) {
            return i;
        }
    }
    return -1;
}


Status SeqList_Update_By_Value(SeqList *L, ElemType old, ElemType new) {
    if ((*L).data == NULL) {
        return false;
    }

    int pos = SeqList_Retrieve_By_Value(L, old);
    if (pos == -1) {
        return false;
    }

    (*L).data[pos] = new;
    return true;
}


Status SeqList_Update_By_Order(SeqList *L, int i, ElemType e) {
    if ((*L).data == NULL) {
        return false;
    }

    if (i < 1 || i > (*L).length) {
        return input_error;
    }

    (*L).data[i - 1] = e;
    return true;
}


Status SeqList_Reverse(SeqList *L) {
    if ((*L).data == NULL) {
        return false;
    }

    ElemType t;
    for (int i = 0; i < (*L).length / 2; i++) {
        t = (*L).data[i];
        (*L).data[i] = (*L).data[(*L).length - 1 - i];
        (*L).data[(*L).length - 1 - i] = t;
    }
    return true;
}


Status SeqList_Traverse(SeqList L, void(*visit)(ElemType e)) {
    for (int i = 0; i < L.length; i++) {
        visit(L.data[i]);
    }
    printf("NULL\n");
}


void seqlist_menu(void) {
    int choice;
    SeqList L;
    int init_flag = 0;
    ElemType e, old, new;
    int i;
    Status result;
    do {
        seqlist_menu_show_details();
        choice = judge_int();
        system("cls");
        switch (choice) {
            case 0:     // exit
                break;
            case 1:     // Initialize
                if (InitSeqList(&L) == true) {
                    init_flag = 1;
                    printf("Succeeded!\n");
                    printf("Current list: NULL\n");
                }
                else {
                    printf("Failed!\n");
                }
                break;
            case 2:     // Destroy
                if (init_flag == 0) {
                    printf("The list is already NULL!\n");
                }
                else {
                    DestroySeqList(&L);
                    init_flag = 0;
                    printf("Succeeded!\n");
                }
                break;
            case 3:     // Insert a node from head
                if (init_flag == 0) {
                    printf("The list is NULL!\n");
                }
                else {
                    get_input_element(&e);
                    system("cls");
                    result = SeqList_Head_Insert(&L, e);
                    if (result == true) {
                        printf("Succeeded!\n");
                    }
                    else {
                        printf("Failed!\n");
                    }
                }
                break;
            case 4:     // Insert a node from tail
                if (init_flag == 0) {
                    printf("The list is NULL!\n");
                }
                else {
                    get_input_element(&e);
                    system("cls");
                    result = SeqList_Tail_Insert(&L, e);
                    if (result == true) {
                        printf("Succeeded!\n");
                    }
                    else {
                        printf("Failed!\n");
                    }
                }
                break;
            case 5:     // Insert a node by order
                if (init_flag == 0) {
                    printf("The list is NULL!\n");
                }
                else {
                    get_order_position(&i);
                    get_input_element(&e);
                    system("cls");
                    result = SeqList_Insert_By_Order(&L, i, e);
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
                if (init_flag == 0 || L.length == 0) {
                    printf("The list is NULL!\n");
                }
                else {
                    get_order_position(&i);
                    system("cls");
                    result = SeqList_Delete_By_Order(&L, i, &e);
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
                if (init_flag == 0 || L.length == 0) {
                    printf("The list is NULL!\n");
                }
                else {
                    get_input_element(&e);
                    system("cls");
                    if (SeqList_Delete_By_Value(&L, e) == true) {
                        printf("Succeeded!\n");
                    }
                    else {
                        printf("Cannot find the element!\n");
                    }
                }
                break;
            case 8:     // Update a node by order
                if (init_flag == 0 || L.length == 0) {
                    printf("The list is NULL!\n");
                }
                else {
                    get_order_position(&i);
                    get_input_element(&e);
                    system("cls");
                    result = SeqList_Update_By_Order(&L, i, e);
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
                if (init_flag == 0 || L.length == 0) {
                    printf("The list is NULL!\n");
                }
                else {
                    get_input_element(&old);
                    get_input_element(&new);
                    system("cls");
                    if (SeqList_Update_By_Value(&L, old, new) == true) {
                        printf("Succeeded!\n");
                    }
                    else {
                        printf("Cannot find the element!\n");
                    }
                }
                break;
            case 10:    // reverse the list
                if (init_flag == 0 || L.length == 0) {
                    printf("The list is NULL!\n");
                }
                else {
                    if (SeqList_Reverse(&L) == true) {
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
        if (choice >= 3 && choice <= 10 && init_flag != 0) {
            printf("Current list: ");
            SeqList_Traverse(L, visit);
        }
    } while (choice != 0);
    // release memory
    if (init_flag != 0) {
        DestroySeqList(&L);
    }
}


void seqlist_menu_show_details(void) {
    printf("\n");
    printf("\t********************************************\n");
    printf("\t*          Sequential List                 *\n");
    printf("\t*------------------------------------------*\n");
    printf("\t*  1  |   Initialize (Reset)               *\n");
    printf("\t*------------------------------------------*\n");
    printf("\t*  2  |   Destroy                          *\n");
    printf("\t*------------------------------------------*\n");
    printf("\t*  3  |   Insert a data from head          *\n");
    printf("\t*------------------------------------------*\n");
    printf("\t*  4  |   Insert a data from tail          *\n");
    printf("\t*-------------------------- ---------------*\n");
    printf("\t*  5  |   Insert a data by order           *\n");
    printf("\t*------------------------------------------*\n");
    printf("\t*  6  |   Delete a data by order           *\n");
    printf("\t*--------------------------- --------------*\n");
    printf("\t*  7  |   Delete a data by value           *\n");
    printf("\t*------------------------------------------*\n");
    printf("\t*  8  |   Update a data by order           *\n");
    printf("\t*------------------------------------------*\n");
    printf("\t*  9  |   Update a data by value           *\n");
    printf("\t*------------------------------------------*\n");
    printf("\t*  10 |   Reverse the list                 *\n");
    printf("\t*------------------------------------------*\n");
    printf("\t*  0  |   Back                             *\n");
    printf("\t********************************************\n");
    printf("\nPlease enter the corresponding number(0-10): ");
}

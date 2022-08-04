//
// Created by Maylon on 2022/8/3.
//

#include "SeqList.h"

Status InitSeqList(SeqList *L) {}


Status DestroySeqList(SeqList *L) {}


Status SeqList_Head_Insert(SeqList *L, ElemType e) {}


Status SeqList_Tail_Insert(SeqList *L, ElemType e) {}


Status SeqList_Insert_By_Order(SeqList *L, int i, ElemType e) {}


Status SeqList_Delete_By_Value(SeqList *L, ElemType e) {}


Status SeqList_Delete_By_Order(SeqList *L, int i, ElemType *e) {}


int SeqList_Retrieve_By_Value(SeqList *L, ElemType e) {}


Status SeqList_Update_By_Value(SeqList *L, ElemType old, ElemType new) {}


Status SeqList_Update_By_Order(SeqList *L, int i, ElemType e) {}


Status SeqList_Traverse(SeqList L, void(*visit)(ElemType e)) {}


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
                    if (DestroySeqList(&L) == true) {
                        init_flag = 0;
                        printf("Succeeded!\n");
                    }
                    else {
                        printf("Failed!\n");
                    }
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
                        if (result == list_full) {
                            printf("List is already full!\n");
                        }
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
                        if (result == list_full) {
                            printf("List is already full!\n");
                        }
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
                if (init_flag == 0) {
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
                if (init_flag == 0) {
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
                if (init_flag == 0) {
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
                if (init_flag == 0) {
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
            default:
                printf("Wrong input, please re-enter!\n");
                break;
        }
        if (choice >= 3 && choice <= 9 && init_flag != 0) {
            printf("Current list: ");
            SeqList_Traverse(L, visit);
        }
    } while (choice != 0);
    // release memory
    if (init_flag == 0) {
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
    printf("\t*  0  |   Back                             *\n");
    printf("\t********************************************\n");
    printf("\nPlease enter the corresponding number(0-9): ");
}

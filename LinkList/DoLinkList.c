//
// Created by Maylon on 2022/7/21.
//

#include "DoLinkList.h"

void InitDoList(DoList *L) {}


Status DestroyDoList(DoList *L) {}


Status DoList_Head_Insert(DoList *L, ElemType e) {}


Status DoList_Tail_Insert(DoList *L, ElemType e) {}


Status DoList_Insert_By_Order(DoList *L, int i, ElemType e) {}


Status DoList_Delete_By_Value(DoList *L, ElemType e) {}


Status DoList_Delete_By_Order(DoList *L, int i, ElemType *e) {}


DoLNode *DoList_Retrieve_By_Value(DoList L, ElemType e) {}


Status DoList_Update_By_Value(DoList L, ElemType old, ElemType new) {}


Status DoList_Update_By_Order(DoList L, int i, ElemType e) {}


void DoList_Traverse(DoList L, void(*visit)(ElemType e)) {}


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

                break;
            case 2:     // Destroy
                if (L == NULL) {
                    printf("The list is already NULL!\n");
                }
                else {

                }
                break;
            case 3:     // Insert a node from head
                get_input_element(&e);
                system("cls");

                break;
            case 4:     // Insert a node from tail
                get_input_element(&e);
                system("cls");

                break;
            case 5:     // Insert a node by order
                get_order_position(&i);
                get_input_element(&e);
                system("cls");

                break;
            case 6:     // Delete a node by order
                if (L == NULL) {
                    printf("The list is NULL!\n");
                }
                else {
                    get_order_position(&i);
                    system("cls");

                }
                break;
            case 7:     // Delete a node by value
                if (L == NULL) {
                    printf("The list is NULL!\n");
                }
                else {
                    get_input_element(&e);
                    system("cls");

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

                }
                break;
            default:
                printf("Wrong input, please re-enter!\n");
                break;
        }
        if (choice >= 1 && choice <= 9) {
            printf("Current list: ");

        }
    } while (choice != 0);
    // release memory
    if (L != NULL) {

    }
}


void dolinklist_menu_show_details(void) {
    printf("\n");
    printf("\t**************************************************\n");
    printf("\t*              Double Linked List                *\n");
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
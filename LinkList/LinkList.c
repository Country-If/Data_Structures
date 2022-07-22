//
// Created by Maylon on 2022/7/22.
//

#include "LinkList.h"

void linklist_menu(void) {
    int choice = 0;
    do {
        linklist_menu_show_details();
        choice = judge_int();
        system("cls");
        switch (choice) {
            case 0:     // exit
                break;
            case 1:     // single linked list (with a head node)
                break;
            case 2:     // single linked list (without a head node)
                break;
            case 3:     // double linked list
                break;
            case 4:     // circular single linked list
                break;
            case 5:     // circular double linked list
                break;
            case 6:     // static linked list
                break;
            default:
                printf("Wrong input, please re-enter.\n");
                break;
        }
    } while (choice != 0);
}


void linklist_menu_show_details(void) {
    printf("\n");
    printf("\t******************************************************\n");
    printf("\t*                 Linked List                        *\n");
    printf("\t*----------------------------------------------------*\n");
    printf("\t*  1  |   Single linked list (with a head node)      *\n");
    printf("\t*----------------------------------------------------*\n");
    printf("\t*  2  |   Single Linked List (without a head node)   *\n");
    printf("\t*----------------------------------------------------*\n");
    printf("\t*  3  |   Double linked list                         *\n");
    printf("\t*----------------------------------------------------*\n");
    printf("\t*  4  |   Circular single linked list                *\n");
    printf("\t*----------------------------------------------------*\n");
    printf("\t*  5  |   Circular double linked list                *\n");
    printf("\t*----------------------------------------------------*\n");
    printf("\t*  6  |   Static linked list                         *\n");
    printf("\t*----------------------------------------------------*\n");
    printf("\t*  0  |   Exit                                       *\n");
    printf("\t******************************************************\n");
    printf("\nPlease enter the corresponding number(0-6): ");
}

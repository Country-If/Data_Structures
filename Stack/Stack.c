//
// Created by Maylon on 2022/8/4.
//

#include "Stack.h"
#include "SeqStack.h"       // sequential stack
#include "LinkStack.h"      // linked stack (with a head node)

void stack_menu(void) {
    int choice;
    do {
        stack_menu_show_details();
        choice = judge_int();
        system("cls");
        switch (choice) {
            case 0:     // exit
                break;
            case 1:     // sequential stack
//                seqstack_menu();
                break;
            case 2:     // linked stack (with a head node)
//                linkstack_menu();
                break;
            default:
                printf("Wrong input, please re-enter!\n");
                break;
        }
    } while (choice != 0);
}


void stack_menu_show_details(void) {
    printf("\n");
    printf("\t********************************************\n");
    printf("\t*            Stack                         *\n");
    printf("\t*------------------------------------------*\n");
    printf("\t*  1  |   Sequential stack                 *\n");
    printf("\t*------------------------------------------*\n");
    printf("\t*  2  |   Linked stack                     *\n");
    printf("\t*------------------------------------------*\n");
    printf("\t*  0  |   Back                             *\n");
    printf("\t********************************************\n");
    printf("\nPlease enter the corresponding number(0-2): ");
}

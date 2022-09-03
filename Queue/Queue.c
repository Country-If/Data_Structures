//
// Created by Maylon on 2022/9/2.
//

#include "Queue.h"
#include "SeqQueue.h"       // sequential queue
#include "LinkQueue.h"      // linked queue (with a head node)

void queue_menu(void) {
    int choice;
    do {
        queue_menu_show_details();
        choice = judge_int();
        system("cls");
        switch (choice) {
            case 0:     // exit
                break;
            case 1:     // sequential queue
                seqqueue_menu();
                break;
            case 2:     // linked queue (with a head node)
                linkqueue_menu();
                break;
            default:
                printf("Wrong input, please re-enter!\n");
                break;
        }
    } while (choice != 0);
}


void queue_menu_show_details(void) {
    printf("\n");
    printf("\t********************************************\n");
    printf("\t*            Queue                         *\n");
    printf("\t*------------------------------------------*\n");
    printf("\t*  1  |   Sequential queue                 *\n");
    printf("\t*------------------------------------------*\n");
    printf("\t*  2  |   Linked queue                     *\n");
    printf("\t*------------------------------------------*\n");
    printf("\t*  0  |   Back                             *\n");
    printf("\t********************************************\n");
    printf("\nPlease enter the corresponding number(0-2): ");
}

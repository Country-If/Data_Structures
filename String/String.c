//
// Created by Maylon on 2022/9/15.
//

#include "String.h"
#include "SeqString.h"      // sequential string
//#include "LinkString.h"     // linked string

void string_menu(void) {
    int choice;
    do {
        string_menu_show_details();
        choice = judge_int();
        system("cls");
        switch (choice) {
            case 0:     // exit
                break;
            case 1:     // sequential string
                seqstring_menu();
                break;
//            case 2:     // linked string
//                linkstring_menu();
//                break;
            default:
                printf("Wrong input, please re-enter!\n");
                break;
        }
    } while (choice != 0);
}


void string_menu_show_details(void) {
    printf("\n");
    printf("\t********************************************\n");
    printf("\t*            String                        *\n");
    printf("\t*------------------------------------------*\n");
    printf("\t*  1  |   Sequential string                *\n");
    printf("\t*------------------------------------------*\n");
    printf("\t*  2  |   Linked string (Nothing)          *\n");
    printf("\t*------------------------------------------*\n");
    printf("\t*  0  |   Back                             *\n");
    printf("\t********************************************\n");
    printf("\nPlease enter the corresponding number(0-1): ");
}

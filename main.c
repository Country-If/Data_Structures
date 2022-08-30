#include "main.h"

#include "SeqList/SeqList.h"            // SeqList
#include "LinkList/LinkList.h"          // Linked List
#include "Stack/Stack.h"                // Stack

int main() {
    int choice;
    do {
        main_menu();
        choice = judge_int();
        system("cls");
        switch (choice) {
            case 0:     // exit
                break;
            case 1:     // array
                seqlist_menu();
                break;
            case 2:     // linked list
                linklist_menu();
                break;
            case 3:     // stack
                stack_menu();
                break;
            case 4:     // queue

                break;
            case 5:     // tree

                break;
            case 6:     // map

                break;
            default:
                printf("Wrong input, please re-enter!\n");
                break;
        }
    } while (choice != 0);

    return 0;
}


void visit(ElemType e) {
    if (sizeof(e) == sizeof(char)) {
        printf("%c -> ", e);
    }
    else if (sizeof(e) == sizeof(int)) {
        printf("%d -> ", e);
    }
}


void get_input_element(ElemType *e) {
    printf("Please input the data: ");
    if (sizeof((*e)) == sizeof(char)) {
        scanf("%c", e);
    }
    else if (sizeof((*e)) == sizeof(int)) {
        *e = judge_int();
    }
}


void get_order_position(int *i) {
    printf("Please input the position: ");
    *i = judge_int();
}


int judge_int(void) {
    int len, num = 0, arg = 1;
    char word[10] = {0};
    int m, j = 1, k;
    while (j) {
        scanf("%s", word);
        len = strlen(word);
        for (m = 0; m < len; m++) {
            if (word[m] < '0' || word[m] > '9')  // Checks for garbled input of other characters
            {
                printf("Please enter an integer: ");
                break;
            }
            else {
                if (m == len - 1)
                    j = 0;
            }
        }
    }
    j = len - 1;
    for (m = 0; m < len; m++)  // Converts characters back to numbers
    {
        for (k = 0; k < j; k++)
            arg *= 10;
        num += (word[m] - '0') * arg;
        arg = 1;
        j--;
    }
    return num;
}


char get_choice(void) {
    int len;
    char word[10] = {0};
    while (1) {
        scanf("%s", word);
        len = strlen(word);
        if ((len == 1) && (word[0] == 'Y' || word[0] == 'y' || word[0] == 'N' || word[0] == 'n')) {
            break;
        }
        else {
            printf("Please enter Y/y or N/n: ");
        }
    }
    return word[0];
}


void main_menu(void) {
    printf("\n");
    printf("\t**********************************\n");
    printf("\t*         Data Structure         *\n");
    printf("\t*--------------------------------*\n");
    printf("\t*  1  |   Sequential List        *\n");
    printf("\t*--------------------------------*\n");
    printf("\t*  2  |   Linked List            *\n");
    printf("\t*--------------------------------*\n");
    printf("\t*  3  |   Stack                  *\n");
    printf("\t*--------------------------------*\n");
    printf("\t*  4  |   Queue                  *\n");
    printf("\t*--------------------------------*\n");
    printf("\t*  5  |   Tree                   *\n");
    printf("\t*--------------------------------*\n");
    printf("\t*  6  |   Map                    *\n");
    printf("\t*--------------------------------*\n");
    printf("\t*  0  |   Exit                   *\n");
    printf("\t**********************************\n");
    printf("\nPlease enter the corresponding number(0-6): ");
}
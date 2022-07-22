#include "main.h"

#include "LinkList/LinkList.h"      // Linked List

int main() {
    int choice = 0;
    do {
        main_menu();
        choice = judge_int();
        system("cls");
        switch (choice) {
            case 0:     // exit

                break;
            case 1:     // array

                break;
            case 2:     // linked list
                linklist_menu();
                break;
            case 3:     // stack

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

//    system("pause");
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
    printf("Please input: ");
    if (sizeof((*e)) == sizeof(char)) {
        scanf("%c", e);
    }
    else if (sizeof((*e)) == sizeof(int)) {
        scanf("%d", e);
    }
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


void main_menu(void) {
    printf("\n");
    printf("\t**********************************\n");
    printf("\t*         Data Structure         *\n");
    printf("\t*--------------------------------*\n");
    printf("\t*  1  |     Array                *\n");
    printf("\t*--------------------------------*\n");
    printf("\t*  2  |     Linked List          *\n");
    printf("\t*--------------------------------*\n");
    printf("\t*  3  |     Stack                *\n");
    printf("\t*--------------------------------*\n");
    printf("\t*  4  |     Queue                *\n");
    printf("\t*--------------------------------*\n");
    printf("\t*  5  |     Tree                 *\n");
    printf("\t*--------------------------------*\n");
    printf("\t*  6  |     Map                  *\n");
    printf("\t*--------------------------------*\n");
    printf("\t*  0  |     Exit                 *\n");
    printf("\t**********************************\n");
    printf("\nPlease enter the corresponding number(0-6): ");
}
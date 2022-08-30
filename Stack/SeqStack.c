//
// Created by Maylon on 2022/8/12.
//

#include "SeqStack.h"

Status InitSeqStack(SeqStack *S) {
    (*S).data = (ElemType *) calloc(DeltaSize, sizeof(ElemType));
    if ((*S).data == NULL) {
        return false;
    }

    (*S).top = -1;
    (*S).MaxSize = DeltaSize;
    return true;
}


Status SeqStack_Increase_Capacity(SeqStack *S) {}


void DestroySeqStack(SeqStack *S) {
    free((*S).data);
}


Status SeqStack_Push(SeqStack *S, ElemType e) {}


Status SeqStack_Pop(SeqStack *S, ElemType *e) {}


Status SeqStack_Empty(SeqStack S) {
    return S.top == -1;
}


int SeqStack_Len(SeqStack S) {
    return S.top;
}


void SeqStack_Traverse(SeqStack *S, void(*visit)(ElemType e)) {}


void seqstack_menu(void) {
    int choice;
    SeqStack S;
    int init_flag = 0;
    ElemType e;
    Status result;
    do {
        seqstack_menu_show_details();
        choice = judge_int();
        system("cls");
        switch (choice) {
            case 0:     // exit
                break;
            case 1:     // Initialize
                if (InitSeqStack(&S) == true) {
                    init_flag = 1;
                    printf("Succeeded!\n");
                    printf("Current stack: NULL\n");
                }
                else {
                    printf("Failed!\n");
                }
                break;
            case 2:     // Destroy
                if (init_flag == 0) {
                    printf("The stack is already NULL!\n");
                }
                else {
                    DestroySeqStack(&S);
                    init_flag = 0;
                    printf("Succeeded!\n");
                }
                break;
            case 3:     // Push stack
                if (init_flag == 0) {
                    printf("The stack is NULL!\n");
                }
                else {
                    get_input_element(&e);
                    system("cls");
                    result = SeqStack_Push(&S, e);
                    if (result == true) {
                        printf("Succeeded!\n");
                    }
                    else {
                        printf("Failed!\n");
                    }
                }
                break;
            case 4:     // Pop stack
                if (init_flag == 0 || SeqStack_Empty(S) == true) {
                    printf("The stack is NULL!\n");
                }
                else {
                    get_input_element(&e);
                    system("cls");
                    result = SeqStack_Pop(&S, &e);
                    if (result == true) {
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
        if (choice >= 3 && choice <= 4 && init_flag != 0) {
            printf("Current stack: ");
            SeqStack_Traverse(&S, visit);
        }
    } while (choice != 0);
    // release memory
    if (init_flag != 0) {
        DestroySeqStack(&S);
    }
}


void seqstack_menu_show_details(void) {
    printf("\n");
    printf("\t********************************************\n");
    printf("\t*          Sequential Stack                *\n");
    printf("\t*------------------------------------------*\n");
    printf("\t*  1  |   Initialize (Reset)               *\n");
    printf("\t*------------------------------------------*\n");
    printf("\t*  2  |   Destroy                          *\n");
    printf("\t*------------------------------------------*\n");
    printf("\t*  3  |   Push stack                       *\n");
    printf("\t*------------------------------------------*\n");
    printf("\t*  4  |   Pop stack                        *\n");
    printf("\t*-------------------------- ---------------*\n");
    printf("\t*  0  |   Back                             *\n");
    printf("\t********************************************\n");
    printf("\nPlease enter the corresponding number(0-4): ");
}

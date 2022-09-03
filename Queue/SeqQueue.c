//
// Created by Maylon on 2022/9/2.
//

#include "SeqQueue.h"

Status InitSeqQueue(SeqQueue *Q) {
    (*Q).data = (ElemType *) calloc(DeltaSize, sizeof(ElemType));
    if ((*Q).data == NULL) {
        return false;
    }

    (*Q).front = (*Q).rear = 0;
    (*Q).MaxSize = DeltaSize;
    return true;
}


Status SeqQueue_Increase_Capacity(SeqQueue *Q) {
    if ((*Q).data == NULL) {
        return false;
    }

    ElemType *p = (*Q).data;
    (*Q).data = (ElemType *) calloc((*Q).MaxSize + DeltaSize, sizeof(ElemType));
    if ((*Q).data == NULL) {
        return false;
    }

    for (int i = (*Q).front; i != (*Q).rear; i = (i + 1) % (*Q).MaxSize) {
        (*Q).data[i] = p[i];
    }
    (*Q).MaxSize += DeltaSize;
    free(p);
    return true;
}


void DestroySeqQueue(SeqQueue *Q) {
    free((*Q).data);
}


Status EnSeqQueue(SeqQueue *Q, ElemType e) {
    char choice;

    if ((*Q).data == NULL) {
        return false;
    }

    if (SeqQueue_Full(*Q) == true) {
        printf("The queue is full, do you want to increase the capacity?(y/n) ");
        choice = get_choice();
        system("cls");
        if (choice == 'N' || choice == 'n') {
            return false;
        }
        else if (choice == 'Y' || choice == 'y') {
            if (SeqQueue_Increase_Capacity(Q) == false) {
                printf("Failed to increase capacity!\n");
                return false;
            }
        }
    }
    (*Q).data[(*Q).rear] = e;
    (*Q).rear = ((*Q).rear + 1) % (*Q).MaxSize;
    return true;
}


Status DeSeqQueue(SeqQueue *Q, ElemType *e) {}


void SeqQueue_Get_Head(SeqQueue Q, ElemType *e) {}


Status SeqQueue_Empty(SeqQueue Q) {
    return Q.rear == Q.front;
}


Status SeqQueue_Full(SeqQueue Q) {
    return (Q.rear + 1) % Q.MaxSize == Q.front;
}


int SeqQueue_Len(SeqQueue Q) {}


void SeqQueue_Traverse(SeqQueue Q, void(*visit)(ElemType e)) {
    int i = Q.front;
    while (i != Q.rear) {
        visit(Q.data[i]);
        i = (i + 1) % Q.MaxSize;
    }
    printf("NULL\n");
}


void seqqueue_menu(void) {
    int choice;
    SeqQueue Q;
    int init_flag = 0;
    ElemType e;
    Status result;
    do {
        seqqueue_menu_show_details();
        choice = judge_int();
        system("cls");
        switch (choice) {
            case 0:     // exit
                break;
            case 1:     // Initialize
                if (InitSeqQueue(&Q) == true) {
                    init_flag = 1;
                    printf("Succeeded!\n");
                    printf("Current queue (from front to rear): NULL\n");
                }
                else {
                    printf("Failed!\n");
                }
                break;
            case 2:     // Destroy
                if (init_flag == 0) {
                    printf("The stack isn't initialized!\n");
                }
                else {
                    DestroySeqQueue(&Q);
                    init_flag = 0;
                    printf("Succeeded!\n");
                }
                break;
            case 3:     // EnQueue
                if (init_flag == 0) {
                    printf("The stack isn't initialized!\n");
                }
                else {
                    get_input_element(&e);
                    system("cls");
                    result = EnSeqQueue(&Q, e);
                    if (result == true) {
                        printf("Succeeded!\n");
                    }
                    else {
                        printf("Failed!\n");
                    }
                }
                break;
            case 4:     // DeQueue
                if (init_flag == 0) {
                    printf("The stack isn't initialized!\n");
                }
                else if (SeqQueue_Empty(Q) == true) {
                    printf("The stack is NULL!\n");
                }
                else {
                    result = DeSeqQueue(&Q, &e);
                    if (result == true) {
                        printf("Successfully deleted data: %d\n", e);
                    }
                    else {
                        printf("Failed!\n");
                    }
                }
                break;
            case 5:     // Get head
                if (init_flag == 0) {
                    printf("The stack isn't initialized!\n");
                }
                else if (SeqQueue_Empty(Q) == true) {
                    printf("The stack is NULL!\n");
                }
                else {
                    SeqQueue_Get_Head(Q, &e);
                    printf("Stack Top data: %d\n", e);
                }
                break;
            case 6:     // Get length
                if (init_flag == 0) {
                    printf("The stack isn't initialized!\n");
                }
                else {
                    printf("Stack length: %d\n", SeqQueue_Len(Q));
                }
                break;
            default:
                printf("Wrong input, please re-enter!\n");
                break;
        }
        if (choice >= 3 && choice <= 6 && init_flag != 0) {
            printf("Current queue (from front to rear): ");
            SeqQueue_Traverse(Q, visit);
        }
    } while (choice != 0);
    // release memory
    if (init_flag != 0) {
        DestroySeqQueue(&Q);
    }
}


void seqqueue_menu_show_details(void) {
    printf("\n");
    printf("\t********************************************\n");
    printf("\t*          Sequential Queue                *\n");
    printf("\t*------------------------------------------*\n");
    printf("\t*  1  |   Initialize (Reset)               *\n");
    printf("\t*------------------------------------------*\n");
    printf("\t*  2  |   Destroy                          *\n");
    printf("\t*------------------------------------------*\n");
    printf("\t*  3  |   EnQueue                          *\n");
    printf("\t*------------------------------------------*\n");
    printf("\t*  4  |   DeQueue                          *\n");
    printf("\t*------------------------------------------*\n");
    printf("\t*  5  |   Get head                         *\n");
    printf("\t*------------------------------------------*\n");
    printf("\t*  6  |   Get length                       *\n");
    printf("\t*------------------------------------------*\n");
    printf("\t*  0  |   Back                             *\n");
    printf("\t********************************************\n");
    printf("\nPlease enter the corresponding number(0-6): ");
}

//
// Created by Maylon on 2022/9/2.
//

#include "LinkQueue.h"

Status InitLinkQueue(LinkQueue *Q) {
    LinkQueueNode *q = (LinkQueueNode *) malloc(sizeof(LinkQueueNode));
    if (q == NULL) {
        return false;
    }

    q->next = NULL;
    Q->front = Q->rear = q;
    return true;
}


Status DestroyLinkQueue(LinkQueue *Q) {
    if (Q == NULL) {
        return false;
    }

    LinkQueueNode *p;
    while (Q->front != NULL) {
        p = Q->front;
        Q->front = Q->front->next;
        free(p);
    }
    Q->rear = NULL;
    return true;
}


Status EnLinkQueue(LinkQueue *Q, ElemType e) {
    if (Q->front == NULL) {
        return false;
    }

    LinkQueueNode *p = (LinkQueueNode *) malloc(sizeof(LinkQueueNode));
    if (p == NULL) {
        return false;
    }

    p->data = e;
    p->next = NULL;
    Q->rear->next = p;
    Q->rear = p;
    return true;
}


Status DeLinkQueue(LinkQueue *Q, ElemType *e) {
    if (Q->front == NULL || LinkQueue_Empty(Q)) {
        return false;
    }

    *e = Q->front->next->data;
    LinkQueueNode *p = Q->front->next;
    Q->front->next = p->next;
    if (p->next == NULL) {
        Q->rear = Q->front;
    }
    free(p);
    return true;
}


void LinkQueue_Get_Head(LinkQueue *Q, ElemType *e) {
    if (Q->front == NULL || LinkQueue_Empty(Q) == true) {
        return;
    }

    *e = Q->front->next->data;
}


Status LinkQueue_Empty(LinkQueue *Q) {
    return Q->front == NULL || Q->front == Q->rear;
}


int LinkQueue_Len(LinkQueue *Q) {
    if (Q->front == NULL || LinkQueue_Empty(Q) == true) {
        return 0;
    }

    int count = 0;
    LinkQueueNode *p = Q->front->next;
    while (p != NULL) {
        count++;
        p = p->next;
    }
    return count;
}


void LinkQueue_Traverse(LinkQueue *Q, void(*visit)(ElemType e)) {
    if (Q->front == NULL) {
        return;
    }

    LinkQueueNode *p = Q->front->next;
    while (p != NULL) {
        visit(p->data);
        p = p->next;
    }
    printf("NULL\n");
}


void linkqueue_menu(void) {
    int choice;
    LinkQueue Q;
    Q.front = Q.rear = NULL;
    ElemType e;
    Status result;
    do {
        linkqueue_menu_show_details();
        choice = judge_int();
        system("cls");
        switch (choice) {
            case 0:     // exit
                break;
            case 1:     // Initialize
                if (InitLinkQueue(&Q) == true) {
                    printf("Succeeded!\n");
                    printf("Current queue (from front to rear): NULL\n");
                }
                else {
                    printf("Failed!\n");
                }
                break;
            case 2:     // Destroy
                if (Q.front == NULL) {
                    printf("The stack isn't initialized!\n");
                }
                else {
                    DestroyLinkQueue(&Q);
                    printf("Succeeded!\n");
                }
                break;
            case 3:     // EnQueue
                if (Q.front == NULL) {
                    printf("The stack isn't initialized!\n");
                }
                else {
                    get_input_element(&e);
                    system("cls");
                    result = EnLinkQueue(&Q, e);
                    if (result == true) {
                        printf("Succeeded!\n");
                    }
                    else {
                        printf("Failed!\n");
                    }
                }
                break;
            case 4:     // DeQueue
                if (Q.front == NULL) {
                    printf("The stack isn't initialized!\n");
                }
                else if (LinkQueue_Empty(&Q) == true) {
                    printf("The stack is NULL!\n");
                }
                else {
                    result = DeLinkQueue(&Q, &e);
                    if (result == true) {
                        printf("Successfully deleted data: %d\n", e);
                    }
                    else {
                        printf("Failed!\n");
                    }
                }
                break;
            case 5:     // Get head
                if (Q.front == NULL) {
                    printf("The stack isn't initialized!\n");
                }
                else if (LinkQueue_Empty(&Q) == true) {
                    printf("The stack is NULL!\n");
                }
                else {
                    LinkQueue_Get_Head(&Q, &e);
                    printf("Stack Top data: %d\n", e);
                }
                break;
            case 6:     // Get length
                if (Q.front == NULL) {
                    printf("The stack isn't initialized!\n");
                }
                else {
                    printf("Stack length: %d\n", LinkQueue_Len(&Q));
                }
                break;
            default:
                printf("Wrong input, please re-enter!\n");
                break;
        }
        if (choice >= 3 && choice <= 6 && Q.front != NULL) {
            printf("Current queue (from front to rear): ");
            LinkQueue_Traverse(&Q, visit);
        }
    } while (choice != 0);
    // release memory
    if (Q.front != NULL) {
        DestroyLinkQueue(&Q);
    }
}


void linkqueue_menu_show_details(void) {
    printf("\n");
    printf("\t********************************************\n");
    printf("\t*       Linked Queue (with head)           *\n");
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

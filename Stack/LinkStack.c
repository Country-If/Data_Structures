//
// Created by Maylon on 2022/8/12.
//

#include "LinkStack.h"

void InitLinkStack(LinkStack *S) {
    *L = NULL;
}


Status DestroyLinkStack(LinkStack *S) {
    if (*S == NULL) {
        return false;
    }

    LinkStackNode *p;
    while (*S != NULL) {
        p = *S;
        *S = (*S)->next;
        free(p);
    }
    return true;
}


Status LinkStack_Push(LinkStack *S, ElemType e) {}


Status LinkStack_Pop(LinkStack *S, ElemType *e) {}


void LinkStack_Get_Top(LinkStack S, ElemType *e) {
    *e = S->data;
}


Status LinkStack_Empty(LinkStack S) {
    return S == NULL;
}


int LinkStack_Len(LinkStack S) {
    int count = 0;
    LinkStack p = S;
    while (p != NULL) {
        count++;
        p = p->next;
    }
    return count;
}


void LinkStack_Traverse(LinkStack S, void(*visit)(ElemType e)) {
    LinkStack p = S;
    while (p != NULL) {
        visit(p->data);
        p = p->next;
    }
    printf("NULL!\n");
}


void linkstack_menu(void) {
    int choice;
    LinkStack S = NULL;
    ElemType e;
    Status result;
    do {
        linkstack_menu_show_details();
        choice = judge_int();
        system("cls");
        switch (choice) {
            case 0:     // exit
                break;
            case 1:     // Initialize
                InitLinkStack(&S);
                printf("Succeeded!\n");
                break;
            case 2:     // Destroy
                if (S == 0) {
                    printf("The stack is already NULL!\n");
                }
                else {
                    if (DestroyLinkStack(&S) == true) {
                        printf("Succeeded!\n");
                    }
                    else {
                        printf("Failed!\n");
                    }
                }
                break;
            case 3:     // Push stack
                get_input_element(&e);
                system("cls");
                result = LinkStack_Push(&S, e);
                if (result == true) {
                    printf("Succeeded!\n");
                }
                else {
                    printf("Failed!\n");
                }
                break;
            case 4:     // Pop stack
                if (LinkStack_Empty(S) == true) {
                    printf("The stack is NULL!\n");
                }
                else {
                    result = LinkStack_Pop(&S, &e);
                    if (result == true) {
                        printf("Successfully deleted data: %d\n", e);
                    }
                    else {
                        printf("Failed!\n");
                    }
                }
                break;
            case 5:     // Get top
                if (LinkStack_Empty(S) == true) {
                    printf("The stack is NULL!\n");
                }
                else {
                    LinkStack_Get_Top(S, &e);
                    printf("Stack Top data: %d\n", e);
                }
                break;
            case 6:     // Get length
                printf("Stack length: %d\n", LinkStack_Len(S));
                break;
            default:
                printf("Wrong input, please re-enter!\n");
                break;
        }
        if (choice >= 3 && choice <= 6) {
            printf("Current stack (from bottom to top): ");
            LinkStack_Traverse(S, visit);
        }
    } while (choice != 0);
    // release memory
    if (S != 0) {
        DestroyLinkStack(&S);
    }
}


void linkstack_menu_show_details(void) {
    printf("\n");
    printf("\t********************************************\n");
    printf("\t*       Linked Stack (without head)        *\n");
    printf("\t*------------------------------------------*\n");
    printf("\t*  1  |   Initialize (Reset)               *\n");
    printf("\t*------------------------------------------*\n");
    printf("\t*  2  |   Destroy                          *\n");
    printf("\t*------------------------------------------*\n");
    printf("\t*  3  |   Push stack                       *\n");
    printf("\t*------------------------------------------*\n");
    printf("\t*  4  |   Pop stack                        *\n");
    printf("\t*------------------------------------------*\n");
    printf("\t*  5  |   Get top                          *\n");
    printf("\t*------------------------------------------*\n");
    printf("\t*  6  |   Get length                       *\n");
    printf("\t*------------------------------------------*\n");
    printf("\t*  0  |   Back                             *\n");
    printf("\t********************************************\n");
    printf("\nPlease enter the corresponding number(0-6): ");
}

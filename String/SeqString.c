//
// Created by Maylon on 2022/9/15.
//

#include "SeqString.h"

Status InitSeqString(SString *S) {}


Status SeqString_Increase_Capacity(SString *S) {}


void DestroySeqString(SString *S) {}


void ClearSeqString(SString *S) {}


Status SeqStringAssign(SString *S, char *ch) {}


Status SeqStringCopy(SString *S, SString T) {}


Status SeqStringEmpty(SString S) {}


int SeqStringLength(SString S) {}


Status SeqStringConcat(SString *T, SString S1, SString S2) {}


Status GetSeqSubString(SString *Sub, SString S, int pos, int len) {}


int SeqStringIndex(SString S, SString T) {}


int SeqStringCompare(SString S, SString T) {}


void SeqString_Traverse(SString S, void(*print_string)(char *ch, int len)) {}


void seqstring_menu(void) {
    int choice;
    SString S, T, R;
    int init_flag = 0;
    char ch1[10], ch2[10];
    Status result;
    do {
        seqstring_menu_show_details();
        choice = judge_int();
        system("cls");
        switch (choice) {
            case 0:     // exit
                break;
            case 1:     // Initialize
                if (InitSeqString(&S) == true) {
                    init_flag = 1;
                    printf("Succeeded!\n");
                    printf("Current string: \"\"\n");
                }
                else {
                    printf("Failed!\n");
                }
                break;
            case 2:     // Destroy
                if (init_flag == 0) {
                    printf("The string isn't initialized!\n");
                }
                else {
                    DestroySeqString(&S);
                    init_flag = 0;
                    printf("Succeeded!\n");
                }
                break;
            case 3:     // Clear
                if (init_flag == 0) {
                    printf("The string isn't initialized!\n");
                }
                else {
                    ClearSeqString(&S);
                    printf("Succeed!\n");
                    printf("Current string: ");
                    SeqString_Traverse(S, print_string);
                }
                break;
            case 4:     // Assignment
                if (init_flag == 0) {
                    printf("The string isn't initialized!\n");
                }
                else {
                    printf("Please input the string: ");
                    int res = scanf_s("%s", ch1, sizeof(ch1));
                    if (res == 1) {
                        result = SeqStringAssign(&S, ch1);
                        if (result == true) {
                            printf("Succeeded!\n");
                            SeqString_Traverse(S, print_string);
                        }
                        else {
                            printf("Failed!\n");
                        }
                    }
                    else {
                        printf("Input string out of bound!\n");
                    }
                }
                break;
            case 5:     // Get length
                if (init_flag == 0) {
                    printf("The string isn't initialized!\n");
                }
                else {
                    printf("String length: %d\n", SeqStringLength(S));
                }
                break;
            case 6:     // Get sub string
                if (init_flag == 0) {
                    printf("The string isn't initialized!\n");
                }
                else {
                    int pos, len;
                    printf("Please input the position: ");
                    pos = judge_int();
                    printf("Please input the length: ");
                    len = judge_int();
                    if (InitSeqString(&T) == true) {
                        result = GetSeqSubString(&T, S, pos, len);
                        printf("Current string: ");
                        SeqString_Traverse(S, print_string);
                        if (result == true) {
                            printf("Sub string: ");
                            SeqString_Traverse(T, print_string);
                        } else {
                            printf("Failed to get the sub string, please check the input position and the length!");
                        }
                        DestroySeqString(&T);
                    }
                    else {
                        printf("Failed to initialize a new string!\n");
                    }
                }
                break;
            case 7:     // Get string index
                if (init_flag == 0) {
                    printf("The string isn't initialized!\n");
                }
                else {

                }
                break;
            case 8:     // Concat strings
                if (init_flag == 0) {
                    printf("The string isn't initialized!\n");
                }
                else {
                    printf("Please input the string to concat with current string: ");
                    int res = scanf_s("%s", ch1, sizeof(ch1));
                    printf("Current string: ");
                    SeqString_Traverse(S, print_string);
                    if (res == 1) {
                        if (InitSeqString(&T) == true && InitSeqString(&R) == true) {
                            result = SeqStringAssign(&T, ch1);
                            if (result == true) {
                                result = SeqStringConcat(&R, S, T);
                                if (result == true) {
                                    printf("Succeeded!\n");
                                    printf("The new string: ");
                                    SeqString_Traverse(R, print_string);
                                }
                                else {
                                    printf("Failed!\n");
                                }
                            } else {
                                printf("Failed!\n");
                            }
                            DestroySeqString(&T);
                            DestroySeqString(&R);
                        }
                        else {
                            printf("Failed to initialize a new string!\n");
                        }
                    }
                    else {
                        printf("Input string out of bound!\n");
                    }
                }
                break;
            case 9:     // Compare strings
                if (init_flag == 0) {
                    printf("The string isn't initialized!\n");
                }
                else {
                    if (InitSeqString(&T) == true && InitSeqString(&R) == true) {
                        printf("Please input string1: ");
                        int res1 = scanf_s("%s", ch1, sizeof(ch1));
                        printf("Please input string2: ");
                        int res2 = scanf_s("%s", ch2, sizeof(ch2));
                        if (res1 == 1 && res2 == 1) {
                            if (SeqStringAssign(&T, ch1) == true && SeqStringAssign(&R, ch2) == true) {
                                int res = SeqStringCompare(T, R);
                                if (res > 0) {
                                    printf("%s > %s", T.ch, R.ch);
                                }
                                else if (res == 0) {
                                    printf("%s == %s", T.ch, R.ch);
                                }
                                else {
                                    printf("%s < %s", T.ch, R.ch);
                                }
                            }
                            else {
                                printf("Failed!\n");
                            }
                        }
                        else {
                            printf("Input string out of bound!\n");
                        }
                        DestroySeqString(&T);
                        DestroySeqString(&R);
                    }
                    else {
                        printf("Failed to initialize a new string!\n");
                    }
                }
                break;
            default:
                printf("Wrong input, please re-enter!\n");
                break;
        }
    } while (choice != 0);
    // release memory
    if (init_flag != 0) {
        DestroySeqString(&S);
    }
}


void seqstring_menu_show_details(void) {
    printf("\n");
    printf("\t********************************************\n");
    printf("\t*         Sequential String                *\n");
    printf("\t*------------------------------------------*\n");
    printf("\t*  1  |   Initialize (Reset)               *\n");
    printf("\t*------------------------------------------*\n");
    printf("\t*  2  |   Destroy                          *\n");
    printf("\t*------------------------------------------*\n");
    printf("\t*  3  |   Clear                            *\n");
    printf("\t*------------------------------------------*\n");
    printf("\t*  4  |   Assignment                       *\n");
    printf("\t*------------------------------------------*\n");
    printf("\t*  5  |   Get length                       *\n");
    printf("\t*------------------------------------------*\n");
    printf("\t*  6  |   Get sub string                   *\n");
    printf("\t*------------------------------------------*\n");
    printf("\t*  7  |   Get string index                 *\n");
    printf("\t*------------------------------------------*\n");
    printf("\t*  8  |   Concat strings                   *\n");
    printf("\t*------------------------------------------*\n");
    printf("\t*  9  |   Compare strings                  *\n");
    printf("\t*------------------------------------------*\n");
    printf("\t*  0  |   Back                             *\n");
    printf("\t********************************************\n");
    printf("\nPlease enter the corresponding number(0-9): ");
}

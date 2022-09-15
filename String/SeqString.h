//
// Created by Maylon on 2022/9/15.
//

#include "String.h"

#ifndef DATA_STRUCTURES_SEQSTRING_H
#define DATA_STRUCTURES_SEQSTRING_H

#define MaxSize 5

typedef struct {
    char *ch;
    int length, MaxLen;
} SString;

/* Create */
/*!
 * Initialize or reset the sequential string
 * @param S : pointer to the sequential string
 * @return status (true, false)
 */
Status InitSeqString(SString *S);

/*!
 * Increase capacity of the sequential string when the string is full
 * @param S : pointer to the sequential string
 * @return status (true, false)
 */
Status SeqString_Increase_Capacity(SString *S);

/* Destroy */
/*!
 * Destroy the sequential string
 * @param S : pointer to the sequential string
 */
void DestroySeqString(SString *S);

/*!
 * Clear the sequential string
 * @param S : pointer to the sequential string
 */
void ClearSeqString(SString *S);

/*!
 * Sequential string assignment
 * @param S : pointer to the sequential string to be assigned
 * @param ch : pointer to the char sequence
 * @return status (true, false)
 */
Status SeqStringAssign(SString *S, char *ch);

/*!
 * Copy sequential string T to get sequential string S
 * @param S : pointer to the sequential string to be revised
 * @param T : the sequential string to be copied
 * @return status (true, false)
 */
Status SeqStringCopy(SString *S, SString T);

/*!
 * Judge if the sequential string is empty or not
 * @param S : the sequential string
 * @return status (true, false)
 */
Status SeqStringEmpty(SString S);

/*!
 * Get the length of the sequential string
 * @param S : the sequential string
 * @return the length
 */
int SeqStringLength(SString S);

/*!
 * Concat two sequential strings to get a new sequential string
 * @param T : pointer to the new sequential string
 * @param S1 : one of the sequential string
 * @param S2 : one of the sequential string
 * @return status (true, false)
 */
Status SeqStringConcat(SString *T, SString S1, SString S2);

/*!
 * Get the substring of the sequential string
 * @param Sub : pointer to the sequential substring
 * @param S : the sequential string
 * @param pos : the start position
 * @param len : the length of the sequential substring
 * @return status (true, false)
 */
Status GetSeqSubString(SString *Sub, SString S, int pos, int len);

/*!
 * Get the index position when seq string T first occur in seq string S
 * @param S : the main sequential string
 * @param T : the query sequential string
 * @return index num if S occurs in T else 0
 */
int SeqStringIndex(SString S, SString T);

/*!
 * Compare two sequential strings
 * @param S : one of the sequential string
 * @param T : one of the sequential string
 * @return : if S > T, result > 0; if S == T, result == 0; if S < T, result < 0
 */
int SeqStringCompare(SString S, SString T);

/*!
 * The sequential string menu
 */
void seqstring_menu(void);

/*!
 * The sequential string menu details
 */
void seqstring_menu_show_details(void);

#endif //DATA_STRUCTURES_SEQSTRING_H

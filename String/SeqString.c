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


void seqstring_menu(void) {}


void seqstring_menu_show_details(void) {}

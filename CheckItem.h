#ifndef HEADER_CheckItem
#define HEADER_CheckItem
/*
htop - CheckItem.h
(C) 2004-2011 Hisham H. Muhammad
Released under the GNU GPL, see the COPYING file
in the source distribution for its full text.
*/

#include "Object.h"

typedef struct CheckItem_ {
   Object super;
   char* text;
   bool* ref;
   bool value;
} CheckItem;


extern ObjectClass CheckItem_class;

extern CheckItem* CheckItem_newByRef(char* text, bool* ref);

extern CheckItem* CheckItem_newByVal(char* text, bool value);

extern void CheckItem_set(CheckItem* this, bool value);

extern bool CheckItem_get(CheckItem* this);

#endif

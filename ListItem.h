#ifndef HEADER_ListItem
#define HEADER_ListItem
/*
htop - ListItem.h
(C) 2004-2011 Hisham H. Muhammad
Released under the GNU GPL, see the COPYING file
in the source distribution for its full text.
*/

#include "Object.h"

typedef struct ListItem_ {
   Object super;
   char* value;
   int key;
   bool moving;
} ListItem;


extern ObjectClass ListItem_class;

extern ListItem* ListItem_new(const char* value, int key);

extern void ListItem_append(ListItem* this, const char* text);

extern const char* ListItem_getRef(ListItem* this);

extern long ListItem_compare(const void* cast1, const void* cast2);

#endif

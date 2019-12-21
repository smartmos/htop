#ifndef HEADER_FunctionBar
#define HEADER_FunctionBar
/*
htop - FunctionBar.h
(C) 2004-2011 Hisham H. Muhammad
Released under the GNU GPL, see the COPYING file
in the source distribution for its full text.
*/


#include <stdbool.h>

typedef struct FunctionBar_ {
   int size;
   char** functions;
   char** keys;
   int* events;
   bool staticData;
} FunctionBar;



extern FunctionBar* FunctionBar_newEnterEsc(const char* enter, const char* esc);

extern FunctionBar* FunctionBar_new(const char* const* functions, const char* const* keys, const int* events);

extern void FunctionBar_delete(FunctionBar* this);

extern void FunctionBar_setLabel(FunctionBar* this, int event, const char* text);

extern void FunctionBar_draw(const FunctionBar* this, char* buffer);

extern void FunctionBar_drawAttr(const FunctionBar* this, char* buffer, int attr);

extern int FunctionBar_synthesizeEvent(const FunctionBar* this, int pos);

#endif

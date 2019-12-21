#ifndef HEADER_TraceScreen
#define HEADER_TraceScreen
/*
htop - TraceScreen.h
(C) 2005-2006 Hisham H. Muhammad
Released under the GNU GPL, see the COPYING file
in the source distribution for its full text.
*/

#include "InfoScreen.h"

typedef struct TraceScreen_ {
   InfoScreen super;
   bool tracing;
   int fdpair[2];
   int child;
   FILE* strace;
   int fd_strace;
   bool contLine;
   bool follow;
} TraceScreen;


extern InfoScreenClass TraceScreen_class;

extern TraceScreen* TraceScreen_new(Process* process);

extern void TraceScreen_delete(Object* cast);

extern void TraceScreen_draw(InfoScreen* this);

extern bool TraceScreen_forkTracer(TraceScreen* this);

extern void TraceScreen_updateTrace(InfoScreen* super);

extern bool TraceScreen_onKey(InfoScreen* super, int ch);

#endif

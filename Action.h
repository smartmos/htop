#ifndef HEADER_Action
#define HEADER_Action
/*
htop - Action.h
(C) 2015 Hisham H. Muhammad
Released under the GNU GPL, see the COPYING file
in the source distribution for its full text.
*/


#include "IncSet.h"
#include "Settings.h"
#include "Header.h"
#include "UsersTable.h"
#include "ProcessList.h"
#include "Panel.h"

typedef enum {
   HTOP_OK = 0x00,
   HTOP_REFRESH = 0x01,
   HTOP_RECALCULATE = 0x03, // implies HTOP_REFRESH
   HTOP_SAVE_SETTINGS = 0x04,
   HTOP_KEEP_FOLLOWING = 0x08,
   HTOP_QUIT = 0x10,
   HTOP_REDRAW_BAR = 0x20,
   HTOP_UPDATE_PANELHDR = 0x41, // implies HTOP_REFRESH
} Htop_Reaction;

typedef Htop_Reaction (*Htop_Action)();

typedef struct State_ {
   Settings* settings;
   UsersTable* ut;
   ProcessList* pl;
   Panel* panel;
   Header* header;
} State;


extern Object* Action_pickFromVector(State* st, Panel* list, int x, bool followProcess);

// ----------------------------------------

extern bool Action_setUserOnly(const char* userName, uid_t* userId);

extern Htop_Reaction Action_setSortKey(Settings* settings, ProcessField sortKey);

// ----------------------------------------

extern Htop_Reaction Action_follow(State* st);


extern void Action_setBindings(Htop_Action* keys);

#endif

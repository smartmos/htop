#ifndef HEADER_Header
#define HEADER_Header
/*
htop - Header.h
(C) 2004-2011 Hisham H. Muhammad
Released under the GNU GPL, see the COPYING file
in the source distribution for its full text.
*/

#include "Meter.h"
#include "Settings.h"
#include "Vector.h"

typedef struct Header_ {
   Vector** columns;
   Settings* settings;
   struct ProcessList_* pl;
   int nrColumns;
   int pad;
   int height;
} Header;


#ifndef MAX
#define MAX(a,b) ((a)>(b)?(a):(b))
#endif

#ifndef Header_forEachColumn
#define Header_forEachColumn(this_, i_) for (int (i_)=0; (i_) < (this_)->nrColumns; ++(i_))
#endif

extern Header* Header_new(struct ProcessList_* pl, Settings* settings, int nrColumns);

extern void Header_delete(Header* this);

extern void Header_populateFromSettings(Header* this);

extern void Header_writeBackToSettings(const Header* this);

extern MeterModeId Header_addMeterByName(Header* this, char* name, int column);

extern void Header_setMode(Header* this, int i, MeterModeId mode, int column);

extern Meter* Header_addMeterByClass(Header* this, MeterClass* type, int param, int column);

extern int Header_size(Header* this, int column);

extern char* Header_readMeterName(Header* this, int i, int column);

extern MeterModeId Header_readMeterMode(Header* this, int i, int column);

extern void Header_reinit(Header* this);

extern void Header_draw(const Header* this);

extern int Header_calculateHeight(Header* this);

#endif

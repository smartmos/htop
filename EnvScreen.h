#ifndef HEADER_EnvScreen
#define HEADER_EnvScreen

#include "InfoScreen.h"

typedef struct EnvScreen_ {
   InfoScreen super;
} EnvScreen;

extern InfoScreenClass EnvScreen_class;

extern EnvScreen* EnvScreen_new(Process* process);

extern void EnvScreen_delete(Object* this);

extern void EnvScreen_draw(InfoScreen* this);

extern void EnvScreen_scan(InfoScreen* this);

#endif

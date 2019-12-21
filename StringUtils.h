#ifndef HEADER_StringUtils
#define HEADER_StringUtils
/*
htop - StringUtils.h
(C) 2004-2011 Hisham H. Muhammad
Released under the GNU GPL, see the COPYING file
in the source distribution for its full text.
*/

#include <stdio.h>

#define String_startsWith(s, match) (strncmp((s),(match),strlen(match)) == 0)
#define String_contains_i(s1, s2) (strcasestr(s1, s2) != NULL)

/*
 * String_startsWith gives better performance if strlen(match) can be computed
 * at compile time (e.g. when they are immutable string literals). :)
 */

extern char* String_cat(const char* s1, const char* s2);

extern char* String_trim(const char* in);

extern int String_eq(const char* s1, const char* s2);

extern char** String_split(const char* s, char sep, int* n);

extern void String_freeArray(char** s);

extern char* String_getToken(const char* line, const unsigned short int numMatch);

extern char* String_readLine(FILE* fd);

#endif

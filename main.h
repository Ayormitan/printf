#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

#define BUFFER_SIZE 1024

void _printbuffer(char buffer, int *buffindex);
int _printf(const char *format, ...);

/** prototype handling specifiers **/
int _printschar(va_list args, char buffer[]);
int _printstring(va_list args, char buffer[]);
int _printspercent(va_list arg, char buffer[]);

/**
 *
 *
 */
/** Handle write and parsing functions prototypes**/
struct formt
{
	char formt;
	int (*fn)(va_list, char[]);
};
typedef struct formt formt_t;
/**
 *
 *
 *
 */
int _handleprints(const char *formt, int *indx, va_list lists, char buffer[]);

#endif

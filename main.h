#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

#define BUFFER_SIZE 1024

/** flags */
#define F_ZERO 4
#define F_MINUS 1
#define UNUSED(x) (void)(x)

void _printbuffer(char buffer[], int *buffindex);
int _printf(const char *format, ...);

/** prototype handling specifiers **/
int _printschar(va_list args, char buffer[], int flags, int width);
int _printstring(va_list args, char buffer[], int flags, int width);
int _printspercent(va_list args, char buffer[], int flags, int width);

/**
 *
 *
 */
/** Handle write and parsing functions prototypes**/
struct formt
{
	char formt;
	int (*fn)(va_list, char[], int, int);
};
typedef struct formt formt_t;
/**
 *
 */
int _handleprints(const char *formt, int *indx, va_list lists, char buffer[], int flags, int width);

/** Write char and string to buffer */
int write_character_to_buffer(char c, char buffer[], int width, int flags);
#endif

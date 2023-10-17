#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

#define BUFFER_SIZE 1024
#define UNUSED(x) (void)(x)

/** flags */
#define F_ZERO 4
#define F_MINUS 1
#define SHORT_H 1
#define LONG_H 2

void _printbuffer(char buffer[], int *buffindex);
int _printf(const char *format, ...);

/** prototype handling specifiers **/
int _printschar(va_list args, char buffer[], int flags, int width, int size);
int _printstring(va_list args, char buffer[], int flags, int width, int size);
int _printspercent(va_list args, char buffer[], int flags, int width, int size);
int _print_unsignedint(va_list args, char buffer[], int flags, int width, int size);

/**
 *
 *
 */
/** Handle write and parsing functions prototypes**/
struct formt
{
	char formt;
	int (*fn)(va_list, char[], int, int, int);
};
typedef struct formt formt_t;
/**
 *
 */
int _handleprints(const char *formt, int *indx, va_list lists, char buffer[], int flags, int width, int size);

/** Write char, string and others to buffer */
int write_character_to_buffer(char c, char buffer[], int width, int flags, int size);
int write_unsignedint_to_buffer(int negative, int indx, char buffer[], int flags, int width, int size);

/** UTILITIES FILE **/
long int convert_unsignedint_to_bin(long int number, int size);
#endif

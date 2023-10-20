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
#define F_HASH 8
#define F_PLUS 2
#define F_SPACE 16

void _printbuffer(char buffer[], int *buffindex);
int _printf(const char *format, ...);

/** prototype handling specifiers **/
int _printschar(va_list args, char buffer[], int flags, int width, int size);
int _printstring(va_list args, char buffer[], int flags, int width, int size);
int _printspercent(va_list args, char buffer[], int flags, int width, int size);
int _print_unsignedint(va_list args, char buffer[], int flags, int width, int size);
int _printoctal(va_list args, char buffer[], int flags, int width, int pre, int size);
int _printhex(va_list args, char rd_to[], char buffer[], int flags,
                char flag_c, int width, int pre, int size);
int _printhexdec(va_list args, char buffer[], int flags,
                int width, int pre, int size);
int _printhex_inupper(va_list args, char buffer[], int flags,
                int width, int pre, int size);
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
int write_unsignedint_to_buffer(int negative, int indx, char buffer[], int flags, int width, int pre, int size);

/** UTILITIES FILE **/
long int convert_unsignedint_to_bin(long int number, int size);
int _writenumber(int is_neg, int indx, char buffer[],
                int flags, int width, int pre, int size);
int _writenum(int indx, char buffer[], int flags, int width, int pre,
                int len, char paddlin, char extra_char);
long int convsize_num(long int num, int size);
#endif

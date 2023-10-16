#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
/**
 *
 *
 *
 *
 */
void _printbuffer(char buffer, int *buffindex)
{
	if (*buffindex > 0)
	{
		write(1, &buffer[0], *buffindex);/** Output the content of buffer if it exits*/
		*buffindex = 0; /** Will return when there is nothing in the buffer to print*/
	}
}
/**
 *
 *
 *
 *
 */
int _printf(const char *format, ...)
{
	int printchar = 0;
	int i;
	int buffindex = 0;
	char buffer[BUFFER_SIZE];
	va_list lists;

	if (format == NULL)
	{
		return (-1);/** the function exits if theirs is nothing in the format string*/
	}
	va_start(lists, format);
	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buffindex++] = format[i];
			if (buffindex == BUFFER_SIZE)
				_printbuffer(buffer, &buffindex);/** During string parsing if BUFFER_SIZE ia full*/
				/** we use rite already implemented as _printbuffer to print to stdout*/
				printchar++;
		}
	}
	_printbuffer(buffer, &buffindex);
	va_end(lists);
	return (printchar);
}

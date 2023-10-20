#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
/**
 * _printbuffer - outputs the content of a char buffer
 * @buffer: contains content to be printed
 * @buffindex: pointer to int
 */
void _printbuffer(char buffer[], int *buffindex)
{
	if (*buffindex > 0)
	{
		write(1, &buffer[0], *buffindex);
		/** Output the content of buffer if it exits*/

		*buffindex = 0;
	}
}
/**
 * _printf - prints formatted data to the standard output
 * @format: specifies format of output
 * @...: variable arguments that corresponds to format
 * Return: total number of char printed or -1 if error
 */
int _printf(const char *format, ...)
{
	int i, printchar = 0, printed = 0;
	int flags = 0;
	int width = 0;
	int pre = 0;
	int size = 0;
	int buffindex = 0;
	char buffer[BUFFER_SIZE];
	va_list lists;

	if (format == NULL)
	{
		return (-1);
	}
	va_start(lists, format);
	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buffindex++] = format[i];
			if (buffindex == BUFFER_SIZE)
			{
				_printbuffer(buffer, &buffindex);
				printchar++;
			}
		}
			else
		{
			_printbuffer(buffer, &buffindex);
			++i;
			printed = _handleprints(format, &i, lists, buffer, flags, width, pre, size);
			{
			if (printed == -1)
				return (-1);
			}
				printchar += printed;
		}
	}
	_printbuffer(buffer, &buffindex);
	va_end(lists);
	return (printchar);
}

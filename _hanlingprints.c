#include <stdio.h>
#include <stdarg.h>
#include "main.h"
/**
 * _handleprints - handles all printing of types based on struct defination
 * @formt: pointer to a char string
 * @indx: represents acurrent indx
 * @lists: contains variable arguement
 * @buffer: stores formatted data
 * @flags: used fro formattine
 * @width: field width for output
 * @size: size modifier for output
 * Return: char written to output or 1 if error
 */
int _handleprints(const char *formt, int *indx, va_list lists,
		char buffer[], int flags, int width, int pre, int size)
{
	int i;
	int lenght_not_known = 0;
	int print_char = -1;

	formt_t formt_lists[] = {
	{'c', _printschar}, {'s', _printstring}, {'%', _printspercent},
	{'u', _print_unsignedint}, {'d', _printint}, {'o', _printoctal},
	{'b', _printbinary},
	{'\0', NULL}
	};
	for (i = 0; formt_lists[i].formt != '\0'; i++)
	{
		if (formt[*indx] == formt_lists[i].formt)
		{
			return (formt_lists[i].fn(lists, buffer, flags, width, pre, size));
		}
	}
	if (formt_lists[i].formt == '\0')
	{
		if (formt[*indx] == '\0')
			return (-1);
		lenght_not_known += write(1, "%%", 1);
		if (formt[*indx - 1] == ' ')
		lenght_not_known += write(1, " ", 1);
		else if (width)
		{
			--(*indx);
			while (formt[*indx] != ' ' && formt[*indx] != '%')
			--(*indx);
			if (formt[*indx] == ' ')
			--(*indx);
			return (1);
		}
			lenght_not_known += write(1, &formt[*indx], 1);
			return (lenght_not_known);
	}
	return (print_char);
}

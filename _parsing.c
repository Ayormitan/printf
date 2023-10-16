#include <stdio.h>
#include <stdarg.h>
#include "main.h"
/**
 *
 *
 */
int _handleprints(const char *formt, int *indx, va_list lists, char buffer[], int width)
{
	int i;
	int lenght_not_known = 0;
	int print_char = -1;

	formt_t formt_lists[] = {
	{'c', _printschar}, {'s', _printstring}, {'%', _printspercent},
	{'\0', NULL}
	};
	for (i = 0; formt_lists[i].formt != '\0'; i++)
	{
		if (formt[*indx] == formt_lists[i].formt)
		{
			return (formt_lists[i].fn(lists, buffer));
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

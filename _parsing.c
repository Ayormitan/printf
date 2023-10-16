#include <stdio.h>
#include <stdarg.h>
#include "main.h"
/**
 *
 *
 */
int _handleprints(const char *formt, int *indx, va_list lists, char buffer[])
{
	int parser = 0;
	int i;
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
	return (print_char);
}

#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include "main.h"
/**
 *
 *
 *
 *
 */
int _printschar(va_list args, char buffer[], int flags, int width)
{
	char ch = va_arg(args, int);
	{
		return(write_character_to_buffer(ch, buffer, flags, width));
	}
}
/**
 *
 *
 *
 *
 *
 */
int _printstring(va_list args, char buffer[], int flags, int width)
{
	int length = 0;

	char *string = va_arg(args, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	if (string == NULL)
	{
		string = "(null)";/** checks for no empty string and make in null*/
	}
	else
	{
		length = strlen(string);
	}
	return (write(1, string, length));/** call write function */
}
/**
 *
 *
 *
 *
 *
 */
int _printspercent(va_list args, char buffer[], int flags, int width)
{
	UNUSED(flags);
	UNUSED(width);
	UNUSED(args);
	UNUSED(buffer);
	return (write(1, "%%", 1));
}

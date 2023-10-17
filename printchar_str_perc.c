#include <stdarg.h>
#include <unistd.h>
#include "main.h"
#include <string.h>
/**
 * _printschar - prints a single character to a char buffer
 * @args: arguments passed to a function
 * @buffer: stores formatted characters
 * @flags: rep various flags used for formatting
 * @width: minimum width field output
 * @size: rep size modifier for output
 * Return: number of byte or -1 at error
 */
int _printschar(va_list args, char buffer[], int flags, int width, int size)
{
	char ch = va_arg(args, int);

	return (write_character_to_buffer(ch, buffer, flags, width, size));
}

/**
 * _printstring - prints a string to standard output
 * @args: variable argument passed to funtion
 * @buffer: stores format character
 * @flags: rep several flags
 * @width: unused
 * @size: unused
 * Return: byte written or -1 at failure
 */
int _printstring(va_list args, char buffer[], int flags, int width, int size)
{
	int length = 0;

	char *string = va_arg(args, char *);

	UNUSED(size);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);

	if (string == NULL)
	{
		string = "(null)"; /*checkes for empty string*/
	}
	else
	{
		length = strlen(string);
	}

	return (write(1, string, length));
}

/**
 * _printspercent - prints % to the standard output
 * @args: unused
 * @width: unused
 * @size: unused
 * @flags: unused
 * @buffer: unused
 *
 * Return: bytes written or -1 on failure
 */
int _printspercent(va_list args, char buffer[], int flags, int width, int size)
{
	UNUSED(size);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(args);
	UNUSED(buffer);

	return (write(1, "%%", 1));
}

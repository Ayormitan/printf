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

/**
 * _printint - converts and prints a long int to a char buffer
 * @args: the va_list containing the long int arg
 * @buffer: character buffer to store the converted int
 * @flags: unused
 * @width: unused
 * Return: number of char within the buffer
 */
int _printint(va_list args, char buffer[], int flags, int width)
{
	int i = BUFFER_SIZE - 1;
	unsigned int num1;
	int num = va_arg(args, long int);
	int is_neg = 0;

	UNUSED(flags);
	UNUSED(width);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFFER_SIZE - 1] = '0';

	if (num < 0)
	{
		num1 = (unsigned long int)(-num);
		is_neg = 1;
	}
	else
	{
		num1 = (unsigned long int)(num);
	}

	while (num1 > 0)
	{
		buffer[i--] = (num1 % 10) + '0';
		num1 /= 10;
	}

	i++;

	if (is_neg)
		buffer[i--] = '-';

	return (_writenumber(is_neg, i, buffer));
}

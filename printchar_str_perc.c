#include <stdarg.h>
#include <unistd.h>
#include "main.h"
#include <string.h>
/**
<<<<<<< HEAD
 * _printchar - handles printing of char
 *
 *
 *
=======
 * _printschar - prints a single character to a char buffer
 * @args: arguments passed to a function
 * @buffer: stores formatted characters
 * @flags: rep various flags used for formatting
 * @width: minimum width field output
 * @size: rep size modifier for output
 * Return: number of byte or -1 at error
>>>>>>> 7989be7dd16d865b8eba780599070000f31b5f2a
 */
int _printschar(va_list args, char buffer[], int flags, int width, int pre, int size)
{
	char ch = va_arg(args, int);

	return (write_character_to_buffer(ch, buffer, flags, width, pre, size));
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
int _printstring(va_list args, char buffer[], int flags, int width, int pre, int size)
{
	int length = 0;

	char *string = va_arg(args, char *);

	UNUSED(size);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(pre);

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
int _printspercent(va_list args, char buffer[], int flags, int width, int pre, int size)
{
	UNUSED(size);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(args);
	UNUSED(buffer);
	UNUSED(pre);
	return (write(1, "%%", 1));
}

/**
 * _printint - prints an int to the standard poutput
 * @args: argument lists
 * @buffer: stores format chars
 * @flags: flags for various formating
 * @width: unused
 * @precision: unused
 * @size: unused
 * Return: bytes writed
 */
int _printint(va_list args, char buffer[], int flags,
		int width, int pre, int size)
{
	int is_neg = 0;
	int j = BUFFER_SIZE - 2;

	long int p = va_arg(args, int);
	unsigned long int n;

	p = convsize_num(p, size);

	if (p == 0)
		buffer[j--] = '0';

	buffer[BUFFER_SIZE - 1] = '\0';
	n = (unsigned long int)p;

	if (p < 0)
	{
		n = (unsigned long int)((-1) * p);
		is_neg = 1;
	}
	while (n > 0)
	{
		buffer[j--] = (n % 10) + '0';
		n /= 10;
	}
	return (_writenumber(is_neg, j, buffer, flags, width, pre, size));
}

/**
 * _printoctal - converts unsigned long int ot its octal represntation
 * @args: variable argument list
 * @flags: indicates formating option
 * @width: unused
 * @buffer: stores octal representation
 * @pre: precison value
 * @size: size of number
 * Return: number of char written
 */
int _printoctal(va_list args, char buffer[], int flags,
		int width, int pre, int size)
{
	int j = BUFFER_SIZE - 2;
	unsigned long int count = va_arg(args, unsigned long int);
	unsigned long int num_assign = count;

	UNUSED(width);
	count = convert_unsignedint_to_bin(count, size);

	if (count == 0)
		buffer[j--] = '0';

	buffer[BUFFER_SIZE - 1] = '\0';

	while (count > 0)
	{
		buffer[j--] = (count % 8) + '0';
		count /= 8;
	}

	if (flags & F_HASH && num_assign == 0)
	{
		buffer[j--] = '0';
	}
	j++;
	return (write_unsignedint_to_buffer(0, j, buffer, flags, width, pre, size));
}

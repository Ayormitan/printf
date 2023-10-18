#include "main.h"
/**
 * _printhex_inupper - prints hexadecimal in upper case
 * @args: argument list
 * @buffer: stores hexadecimal representation
 * @flags: indicates formating option
 * @width: output width
 * @pre: precision value
 * @size: size of number
 * Return: number of value written
 */
int _printhex_inupper(va_list args, char buffer[], int flags,
		int width, int pre, int size)
{
	return (_printhex(args, "0123456789ABCDEF", buffer,
				flags, 'X', width, pre, size));
}

/**
 * _printhexdec - prints hexadecimal unsigned number
 * @args: argument list
 * @buffer: stores hexadecimal representatio
 * @flags: indicates formating option
 * @pre: precision value
 * @size: size of number
 * @Return: number of value written
 */
int _printhexdec(va_list args, char buffer[], int flags, int width, int prec, int size)
{
	return (_printhex(args, "0123456789abcdef", buffer,
				flags, 'x', width, pre, size));
}

/**
 * _printhex - converts unsigned long int to hexadecimal
 * @rd_to: represents the set char used
 * @args: argument variable list
 * @buffer: stores hexadecimal representation
 * @flags: indicatea formating option
 * @flag_c: char used for hexadecimal representation
 * @width: output width
 * @size: size of number
 * Return: number written to char
 */
int _printhex(va_list args, char rd_to[], char buffer[], int flags, char flag_c,
		int width, int pre, int size)
{
	int j = BUFFER_SIZE - 2;
	unsigned long int count = va_arg(args, unsigned long int);
	unsigned long int assign_num = count;

	UNUSED(width);

	count = convert_unsignedint_to_bin(count, size);

	if (count == 0)
		buffer[j--] = '0';

	buffer[BUFFER_SIZE - 1] = '\0';

	while (count > 0)
	{
		buffer[j--] = rd_to[count % 16];
		num /= 16;
	}

	if (flags & F_HASH && assign_num != 0)
	{
		buffer[j--] = flag_c;
		buffer[j--] = '0';
	}
	j++;

	return (write_unsignedint_to_buffer(0, j, buffer, flags, width, precision, size));
}

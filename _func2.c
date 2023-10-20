#include "main.h"
#
/**
 * _print_unsignedint - prints an unsigned int value to bufer
 * @args: va-list containg argument passed to function
 * @buffer: stores formatted unsigned int
 * @flags: represents various flags used for formatting
 * @width: minimum width field for formattings
 * @pre: unused
 * @size: unused
 * Return: number of written bytes or -1 if eror
 */
int _print_unsignedint(va_list args, char buffer[],
		int flags, int width, int pre, int size)
{
	int i = BUFFER_SIZE - 2;
	unsigned long int number = va_arg(args, unsigned long int);

	UNUSED(size);
	UNUSED(pre);

	number = convert_unsignedint_to_bin(number, size);

	if (number == 0)
	{
		buffer[i--] = '0';
		buffer[BUFFER_SIZE - 1] = '\0';
	}
	while (number > 0)
	{
		buffer[i--] = (number % 10) + '0';
		number /= 10;
	}
	i++;
	return (write_unsignedint_to_buffer(0, i, buffer, flags, width, pre, size));
}

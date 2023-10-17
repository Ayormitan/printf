#include "main.h"
#
/**
 *
 *
 * 
 */
int _print_unsignedint(va_list args, char buffer[], int flags, int width, int size)
{
	int i = BUFFER_SIZE - 2;
	unsigned long int number = va_arg(args, unsigned long int);

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
	return (write_unsignedint_to_buffer(0, i, buffer, flags, width, size));
}

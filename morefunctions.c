#include "main.h"
/**
 */
int _printpointer(va_list args, char buffer[], int flags,
		int width, int pre, int size)
{
	char extra_char = 0, paddlin = ' ';
	int indx = BUFFER_SIZE - 2, len = 2, padding = 1;
	char rd_to = "0123456789abcdef";
	unsigned long num_addr;
	void *addr = va_arg(args, void *);

	UNUSED(width);
	UNUSED(size);
	UNUSED(pre);

	if (addr == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFFER_SIZE - 1] = '\0';

	num_addr = (unsigned long)addr;

	while (num_addr > 0)
	{
		buffer[indx--] = rd_to[num_addr % 16];
		num_addr /= 16;
		len++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
	{
		paddlin = '0';
	}
	if (flags & F_PLUS)
		extra_char = +, len++;
	else if (flags & F_SPACE)
		extra_char = ' ', len++;
	indx++;

	return (_writepointer(char buffer[], int indx, int len, int width,
				int flags, char paddlin, char extra_char, char padding));
}

/**
 */


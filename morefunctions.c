#include "main.h"
/**
 * _printpointer - formats and prints a poinetr value in hecxadecimal
 * @args: contains variable argumenyts
 * @buffer: stores formated output
 * @flags: formattin flags
 * @width: minimum field width
 * @pre: precision value
 * @size: size modifier
 */
int _printpointer(va_list args, char buffer[], int flags,
		int width, int pre, int size)
{
	char extra_char = 0, paddlin = ' ';
	int indx = BUFFER_SIZE - 2, len = 2, padding = 1;
	char rd_to[] = "0123456789abcdef";
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

	return (_writepointer(buffer, indx, len, width, flags, paddlin, extra_char, padding));
}

/**
 * _writepointer - writes a memory address
 * @buffer: stores output string
 * @indx: shows where writing should be stored
 * @len: length of string to be written
 * @flags: bit flags that controls formatting
 * @width: output width
 * @paddlin: padding character
 * @extra_char: extra character
 * @padding: index for padding
 * Return: numbers of char written
 */
int _writepointer(char buffer[], int indx, int len, int width,
		int flags, char paddlin, char extra_char, char padding);
{
	int j;

	if (width > len)
	{
		for (j = 3; j < width - len + 3; j++)
			buffer[j] = paddlin;
		buffer[j] = '\0';

		if (flags & F_MINUS && paddlin == ' ')
		{
			buffer[--indx] = 'x';
			buffer[--indx] = '0';

			if (extra_char)
				buffer[--indx] = extra_char;
			return (write(1, &buffer[indx], len) + write(1, &buffer[3], j - 3));
		}
		else if (!(flags & F_MINUS) && paddlin == ' ')
		{
			buffer[--indx] = 'x';
			buffer[--indx] = '0';

			if (extra_char)
				buffer[--indx] = extra_char;
			return (write(1, &buffer[3], j - 3) + write(1, &buffer[indx], len));
		}
		else if (!(flags & F_MINUS) == '0')
		{
			if (extra_char)
				buffer[--padding] = extra_char;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[padding], j - padding) + write(1, buffer[indx], len - (1 - padding) - 2));
		}
	}
	buffer[--indx] = 'x';
	buffer[--indx] = '0';

	if (extra_char)
		buffer[--ind] = extar_char;
	return (write(1, &buffer[indx], BUFFER_SIZE - indx - 1));
}

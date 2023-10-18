#include "main.h"
/**
 * _writenumber - writes number to a char buffer
 * @is_neg: indicated if a number is negative
 * @indx: represents current in buffer
 * @buffer: char array to store numbers
 * @flags: indicates formating option
 * @width: output width
 * @pre: precison value
 * @size: number size
 * Return: result of write function
 */
int _writenumber(int is_neg, int indx, char buffer[],
		int flags, int width, int pre, int size)
{
	int len = BUFFER_SIZE - indx - 1;
	char extra_char = 0;
	char paddlin = ' ';

	UNUSED(size);

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		paddlin = '0';
	if (is_neg)
		extra_char = '-';
	else if (flags & F_PLUS)
		extra_char = '+';
	else if (flags & F_SPACE)
		extra_char = ' ';

	return (_writenum(indx, buffer, flags, width, pre, len, paddlin, extra_char));
}

/**
 * _writenum - writes num to char buffer
 * @indx: current index in buffer
 * @buffer: array to store number
 * @paddlin: unsed
 * @extra_char: extra character written before number
 * @pre: precison value
 * @len: length of value
 * @width: output width
 * @flags: indicates formatting option
 * Return: result of write function
 */
int _writenum(int indx, char buffer[], int flags, int width, int pre,
		int len, char paddlin, char extra_char)
{
	int j, padding = 1;

	if (pre == 0 && indx == BUFFER_SIZE - 2 && buffer[indx] == '0' && width == 0)
		return (0);
	if (pre == 0 && indx == BUFFER_SIZE - 2 && buffer[indx] == '0')
		buffer[indx] = paddlin = ' ';
	if (pre > 0 && pre < len)
		paddlin = ' ';
	while (pre > len)
		buffer[--indx] = '0', len++;
	if (extra_char != 0)
		len++;
	if (width > len)
	{
		for (j = 1; j < width - len + 1; j++)
			buffer[j] = paddlin;
		buffer[j] = '\0';
		if (flags & F_MINUS && paddlin == ' ')
		{
			if (extra_char)
				buffer[--indx] = extra_char;
			return (write(1, &buffer[indx], len) + write(1, &buffer[1], j - 1));
		}
		else if (!(flags & F_MINUS) && paddlin == ' ')
		{
			if (extar_char)
				buffer[--indx] = extra_char;
			return (write(1, &buffer[1], j - 1) + write(1, &buffer[indx], len));
		}
		else if (!(flags & F_MINUS) && paddlin == '0')
		{
			if (extra_char)
				buffer[--padding] = extra_char;
			return (write(1, &buffer[padding], j - padding) +
					write(1, buffer[indx], len - (1 - padding)));
		}
	}
	if (extra_char)
		buffer[indx] = extra_char;
	return (write(1, buffer[indx], len));
}


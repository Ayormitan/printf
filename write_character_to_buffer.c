#include <unistd.h>
#include "main.h"
/**
 * write_character_to_buffer - writes a single char c, to buffer
 * @c: char to to written to buffer
 * @buffer: stores characters and padding
 * @width: represents minimum with field for output
 * @flags: represents various flags(int)
 * @pre: unused
 * @size: unused
 * Return: number of bytes or -2 if error
 */
int write_character_to_buffer(char c, char buffer[],
		int width, int flags, int pre, int size)
{
	int i = 0;
	char paddlin = ' ';

	UNUSED(size);
	UNUSED(pre);

	if (flags & F_ZERO)
		paddlin = '0';

	buffer[0] = c;
	buffer[1] = '\0';
	if (width > 1)
	{
		buffer[BUFFER_SIZE - 1] = '\0';
		for (i = 0; i < width - 1; i++)
		{
			buffer[BUFFER_SIZE - i - 2] = paddlin;
			if (flags & F_MINUS)
			{
				return (write(1, &buffer[0], 1) + write(1,
							&buffer[BUFFER_SIZE - i - 1], width - 1));
			}
			else
			{
				return (write(1, &buffer[BUFFER_SIZE - i  - 1], width - 1)
						+ write(1, &buffer[0], 1));
			}
		}
	}
	return (write(1, &buffer[0], 1));
}
/**
 * write_unsignedint_to_buffer - writes an unsigned int values to char buffer
 * @negative: unused
 * @indx: represents current index in buffer
 * @buffer: buffer to store unsigned int
 * @flags: represents various flags used
 * @width: field width for outputr
 * @pre: Unused
 * @size: unused
 * Return: number of bytes or -1 if error
 */
int write_unsignedint_to_buffer(int negative, int indx, char buffer[],
int flags, int width, int pre, int size)
{
	int len = BUFFER_SIZE - indx - 1, i = 0;
	char paddlin = ' ';

	UNUSED(negative);
	UNUSED(size);
	UNUSED(pre);
	if (indx == BUFFER_SIZE - 2 && buffer[indx] == '0')
	{
		return (0);
	}
	if ((flags & F_ZERO) && !(flags & F_MINUS))
	{
		paddlin = '0';
	}
	if (width > len)
	{
		for (i = 0; i < width - len; i++)
		buffer[i] = paddlin;
		buffer[i] = '\0';
		if (flags & F_MINUS)
		{
			return (write(1, &buffer[indx], len) + write(1, &buffer[0], i));
		}
		else
		{
			return (write(1, &buffer[0], i) + write(1, &buffer[indx], len));
		}
	}
	return (write(1, &buffer[indx], len));
}

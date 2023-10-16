#include <unistd.h>
#include "main.h"
/**
 *
 *
 */
int write_character_to_buffer(char c, char buffer[], int width, int flags)
{
	int i =0;
	char paddlin = ' ';

	     if (flags & F_ZERO)
		     paddlin = '0';
	buffer[0] = c;
	buffer[1] = '\0';
	if (width > 1)
	{
		buffer[BUFFER_SIZE - 1] = '\0';
		for (i = 0; i < width - 1; i++)
		{
			buffer[BUFFER_SIZE -i -2] = paddlin;
			if (flags & F_MINUS)
			{
				return (write(1, &buffer[0], 1) + write(1, &buffer[BUFFER_SIZE -i - 1], width - 1));
			}
			else
			{
				return (write(1, &buffer[BUFFER_SIZE - i  - 1], width - 1) + write(1, &buffer[0], 1));
			}
		}
	}
	return (write(1, &buffer[0], 1));
}

#include "main.h"
/**
 */
int _writenumber(int is_neg, int indx, char buffer[])
{
	int len = BUFFER_SIZE - indx - 1;
	char extra_char = 0;

	if (is_neg)
		extra_char = '-'; /*determine extra char for sign*/

	return (_writenum(indx, buffer, len, extra_char));
}

/**
 */
int _writenum(int indx, char buffer[],
       	char paddlin, char extra_char)
{
	int len = BUFFER_SIZE - indx - 1;

	UNUSED(paddlin);

	if (extra_char != '0')
		len++;

	if (extra_char)
		buffer[--indx] = extra_char;

	return (write(1, &buffer[indx], len));
}

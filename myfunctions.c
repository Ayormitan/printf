#include "main.h"
/**
 * _writenumber - writes number to a char buffer
 * @is_neg: indicated if a number is negative
 * @indx: represents current in buffer
 * @buffer: char array to store numbers
 * Return: result of write function
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
 * _writenum - writes num to char buffer
 * @indx: current index in buffer
 * @buffer: array to store number
 * @paddlin: unsed
 *
 * @extra_char: extra character written before number
 * Return: result of write function
 */
int _writenum(int indx, char buffer[], char paddlin, char extra_char)
{
	int len = BUFFER_SIZE - indx - 1;

	UNUSED(paddlin);

	if (extra_char != '0')
		len++;

	if (extra_char)
		buffer[--indx] = extra_char;

	return (write(1, &buffer[indx], len));
}

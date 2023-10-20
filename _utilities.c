#include "main.h"
/**
 * convert_unsignedint_to_bin - converts an unsigned int to a number
 * @number: long int representing unsigned int
 * @size: int representing desired size
 * Return: converted unsigned int
 */
long int convert_unsignedint_to_bin(long int number, int size)
{
	if (size == LONG_H)
	{
		return (number);
	}
	else if (size == SHORT_H)
	{
		return ((unsigned short)number);
	}
	return ((unsigned int)number);
}

/**
 * convsize_num - converts an int to number
 * @num: long int representing int
 * @size: int representing size
 * Return: converted unsigned int
 */
long int convsize_num(long int num, int size)
{
	if (size == LONG_H)
	{
		return (num);
	}
	else if (size == SHORT_H)
	{
		return ((short)num);
	}

	return ((int)num);
}
/**
 * check_digit - Check if character is digit
 *
 * @ch: char to check
 * Return: 1 if true else 0;
 */
int check_digit(char ch)
{
	if (ch >= '0' && ch <= '9')
	{
		return (1);
	}
	return (0);
}

/**
 * _isprintable - checks for printability
 * @c: char to checks for printablilty
 * Return: 1 or 0 if not not printatble
 */
int _isprintable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * _appendhex - appends hexadecimal represntation of an ascii
 * @as_code: ascii code to be covenrted  and appended to buffer
 * @buffer: array character where hexadecimal rep will be appended
 * @j: increments inddex as charactr is appended
 * Return: int value
 */
int _appendhex(char as_code, char buffer, int j)
{
	char rd_to = "0123456789ABCDEF";

	if (as_code < 0)
		as_code *= -1;

	buffer[j++] = '\\';
	buffer[j++] = 'x';
	buffer[j++] = rd_to[as_code / 16];
	buffer[j] = rd_to[as_code % 16];

	return (3);
}

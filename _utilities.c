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

	return ((int)num)
}

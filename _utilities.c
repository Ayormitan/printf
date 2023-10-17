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

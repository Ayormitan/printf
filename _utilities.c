#include "main.h"
/**
 *
 *
 *
 *
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

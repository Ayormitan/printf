#include "main.h"
/**
 *size_handling - Hadling size to cast arguments
 *
 * @formt: Formated list of string
 * @i: pointr to list of arguments to be printed
 *Return: size
 */
int size_handling(const char *formt, int *i)
{
	int size = 0;
	int current_indx = *i + 1;

	if (formt[current_indx] == 'I')
	{
		size = LONG_H;
	}
	else if (formt[current_indx] == 'h')
	{
		size = SHORT_H;
	}
	if (size == 0)
	{
		*i = current_indx - 1;
	}
	else
	{
		*i = current_indx;
	}
	return (size);
}
/**
 * width_handling - Handles formating of the width
 *
 *@formt: Formated strings to stdout
 *@i: pointer to handled string
 *@type: Variadic list of arg
 *Return: Width of string
 */
int width_handling(const char *formt, int *i, va_list type)
{
	int width = 0;
	int current_indx;

	for (current_indx = *i + 1; formt[current_indx] != '\0'; current_indx++)
	{
		if (check_digit(formt[current_indx]))
		{
			width *= 10;
			width += formt[current_indx] - '0';
		}
		else if (formt[current_indx] == '*')
		{
			current_indx++;
			width = va_arg(type, int);
			break;
		}
		else
		{
			break;
		}
	}
	*i = current_indx - 1;
	return (width);
}
/**
 *prec_handling - Get precision for formated arg
 *
 *@formt: Foemated argument list
 *@i: Pointer to list of arguemnts
 *@type: Variadic list of arguements
 *Return: precision
 */
int prec_handling(const char *formt, int *i, va_list type)
{
	int prec = -1;
	int current_indx = *i + 1;

	if (formt[current_indx] != '.')
	{
		return (prec);
	}
	prec = 0;
	for (current_indx += 1; formt[current_indx] != '\0'; current_indx++)
	{
		if (check_digit(formt[current_indx]))
		{
			prec *= 10;
			prec += formt[current_indx] - '0';
		}
		else if (formt[current_indx] == '*')
		{
			current_indx++;
			prec = va_arg(type, int);
			break;
		}
		else
		{
			break;
		}
	}
	*i = current_indx - 1;
	return (prec);
}
/**
 * flags_handling - Get flags to arguements
 * @formt: Format arguments
 * @i: Pointer to arguemnts
 *
 * Return: The flags attached
 */
int flags_handling(const char *formt, int *i)
{
	int j;
	int flags = 0;
	int current_indx;
	const char FLAGS_CHAR[] = {'-', '0', '+', ' ', '#', '\0'};
	const int FLAGS_ARRAY[] = {F_MINUS, F_ZERO, F_PLUS, F_SPACE, F_HASH, 0};

	for (current_indx = *i + 1; formt[current_indx] != '\0'; current_indx++)
	{
		for (j = 0; FLAGS_CHAR[j] != '\0'; j++)
			if (formt[current_indx] == FLAGS_CHAR[j])
			{
				flags |= FLAGS_ARRAY[j];
				break;
			}
		if (FLAGS_CHAR[j] == 0)
			break;
	}
	*i = current_indx - 1;
	return (flags);
}

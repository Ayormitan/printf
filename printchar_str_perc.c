#include <stdarg.h>
#include <unistd.h>
#include "main.h"
/**
 *
 *
 *
 *
 */
int _printschar(va_list args, char buffer[])
{
	char ch = va_arg(args, int);
	{
		return(ch);
	}
}
/**
 *
 *
 *
 *
 *
 */
int _printstring(va_list args, char buffer[])
{
	int length = 0;

	char *string = va_arg(args, char *);
	if (string == NULL)
	{
		string = "(null)";/** checks for no empty string and make in null*/
	}
	return (write(1, string, length));/** call write function */
}
/**
 *
 *
 *
 *
 *
 */
int _printspercent(va_list arg, char buffer[])
{
	return (write(1, "%%", 1));
}

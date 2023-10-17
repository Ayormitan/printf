#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 * Return: Always 0
 */
int main(void)
{
	int i = 4;

	_printf("my d = %d\n", i);
	printf("d = %d\n", i);
	printf("i = %i\n", i);
	_printf("Character:[%c]\n", 'H');
	_printf("String:[%s]\n", "I am a string !");
	printf("String:[%s]\n", "I am a string !");
	_printf("Let's try to printf a simple sentence.\n");
	_printf("%b\n", 98);
	return (0);
}

#include "main.h"
/**
* print_char - function that prints a character to stdout.
* @args: variadic arguments.
*
* Return: number of characters printed.
*/

int print_char(va_list args)
{
	int value;
	char c;
	int count;

	c = (char) va_arg(args, int);
	count = 0;

	if (c)
	{
		value = write(1, &c, sizeof(char));
		count += value;
		return (count);
	}

	return (0);
}

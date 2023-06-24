#include "main.h"
/**
* print_string - function that prints
* a character string to stdout.
*
* @args: variadic arguments.
*
* Return: number of characters printed.
*/
int print_string(va_list args)
{
	int value;
	int count;
	char *s;

	s = va_arg(args, char *);
	count = 0;

	if (s)
	{
		while (*s != '\0')
		{
			value = write(1, s, strlen(s));
			count += value;
			return (count);
		}
	}

	return (0);
}

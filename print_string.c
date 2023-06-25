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
	int value, count;
	char *s;

	s = va_arg(args, char *);
	count = 0;

	if (s)
	{
		while (*s != '\0')
		{
			value = write(1, s, 1);

			if (value < 0)
				return (-1);
			count += value;
			s++;
		}
		return (count);
	}

	return (0);
}

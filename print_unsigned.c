#include "main.h"
/**
* print_unsigned - function that prints an unsigned integer to stdout.
* @args: variadic arguments.
*
* Return: number of characters printed.
*/
int print_unsigned(va_list args)
{
	unsigned int u, base = 10;
	char buffer[32], tempbuffer[32];
	int i, count = 0, index = 0, len = 0, value;

	u = va_arg(args, unsigned int);

	if (u == 0)
		buffer[len++] = '0';

	else
	{
		while (u != 0)
		{
			int digit = u % base;

			tempbuffer[index++] = digit + '0';
			u /= base;
		}


		for (i = index - 1; i >= 0; i--)
		{
			buffer[len++] = tempbuffer[i];
		}
	}

	value = write(1, buffer, len);
	if (value < 0)
		return (-1);

	count += value;
	return (count);
}

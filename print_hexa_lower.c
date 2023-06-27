#include "main.h"
/**
* print_hexa_lower - function that prints an unsigned
* integer as a sequence of hexadecimal (base 16) in lowercase,
* digits (0 to 9 and a to f).
* @args: variadic arguments.
*
* Return: number of characters printed.
*/
int print_hexa_lower(va_list args)
{
	int value, i, len = 0, count = 0, index = 0, digit;
	unsigned int hexx, temp;
	char buffer[32], tempbuffer[32];
	const char *hexChars = "0123456789abcdef";
	unsigned int base = 16;

	hexx = va_arg(args, unsigned int);
	temp = hexx;

	if (temp == 0)
		buffer[len++] = '0';

	else
	{
		while (temp != 0)
		{
			digit = temp % base;
			tempbuffer[index++] = hexChars[digit];
			temp /= base;
		}

		for (i = index - 1; i >= 0; i--)
		{
			buffer[len++] = tempbuffer[i];
		}
	}

	value = write(1, buffer, len);
	if (value == 0)
		return (-1);
	count += value;

	return (count);
}

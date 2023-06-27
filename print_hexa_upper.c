#include "main.h"
/**
* print_hexa_upper - function that prints an unsigned
* integer as a sequence of hexadecimal (base 16) in uppercase,
* digits (0 to 9 and A to F).
* @args: variadic arguments.
*
* Return: number of characters printed.
*/
int print_hexa_upper(va_list args)
{
	int value, i, len = 0, count = 0, index = 0, digit;
	unsigned int hexX, temp;
	char buffer[32], tempbuffer[32];
	const char *hexChars = "0123456789ABCDEF";
	unsigned int base = 16;


	hexX = va_arg(args, unsigned int);
	temp = hexX;
	if (temp == 0)
	{
		buffer[index++] = '0';
		count++;
	}

	else
	{
		while (temp != 0)
		{
			digit = temp % base;
			tempbuffer[index++] = hexChars[digit];
			temp /= base;
		}

	}

	for (i = index - 1; i >= 0; i--)
	{
		buffer[len++] = tempbuffer[i];
	}

	value = write(1, buffer, index);

	if (value == 0)
		return (-1);

	count += value;

	return (count);
}

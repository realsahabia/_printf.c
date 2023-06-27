#include "main.h"
/**
* print_octal - function that prints octal integers (base 8).
* @args: variadic arguments.
*
* Return: number of characters printed.
*/
int print_octal(va_list args)
{
	int value, i, len = 0, count = 0, index = 0, digit;
	unsigned int octal, temp;
	char buffer[32], tempbuffer[32];
	unsigned int base = 8;

	octal = va_arg(args, unsigned int);
	temp = octal;
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
			tempbuffer[index++] = digit + '0';
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

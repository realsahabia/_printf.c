#include "main.h"
/**
 * print_binary - Function that prints integers in binary.
 * @args: argument lists.
 *
 * Return: Number of characters printed
 */
int print_binary(va_list args)
{
	int count = 0, i, index = 0, length, value;
	unsigned int binary[32];
	char buffer[32];

	unsigned int b = va_arg(args, unsigned int);

	if (b == 0)
	{
		buffer[index++] = b + '0';
	}

	else
	{
		for (i = 0; b > 0; i++)
		{
			binary[i] = b % 2;
			b /= 2;
		}

		length = i;
		for (i = length - 1; i >= 0; i--)
		{
			buffer[index] = binary[i] + '0';
			index++;
		}
	}

	value = write(1, buffer, index);
	if (value < 0)
		return (-1);

	count += value;
	return (count);
}

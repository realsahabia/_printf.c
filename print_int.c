#include "main.h"
/**
 * print_int - Function that prints integers.
 * @args: argument lists.
 *
 * Return: Number of ints printed
 */
int print_int(va_list args)
{
	int count = 0, length = 0, index = 0;
	int i, integer, digit, result;
	char buffer[32], tempbuffer[32];

	integer = va_arg(args, int);

	if (integer == 0)
		buffer[length++] = '0';
	else
	{
		if (integer < 0)
		{
			buffer[length++] = '-';
			integer  = -integer;
		}

		while (integer != 0)
		{
			digit = integer % 10;
			tempbuffer[index++] = digit + '0';
			integer /= 10;
		}

		for (i = index - 1; i >= 0; i--)
		{
			buffer[length++] = tempbuffer[i];
		}
	}

	result = write(1, buffer, length);
	if (result < 0)
		return (-1);

	count += result;
	return (count);
}

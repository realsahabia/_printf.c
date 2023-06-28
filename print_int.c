#include "main.h"
/**
 * print_int - Function that prints integers.
 * @args: argument lists.
 *
 * Return: Number of ints printed
 */
int print_int(va_list args)
{
	int count = 0, length = 0, integer, temp, index, digit, result;
	char buffer[20];

	integer = va_arg(args, int);
	temp = integer;

	if (temp == 0)
		buffer[index++] = '0';
	else
	{
		if (temp < 0)
		{
			buffer[index++] = '-';
			integer  = -integer;
		}

		while (temp != 0)
		{
			digit = temp % 10;
			char tempbuffer[length++] = digit + '0';
			temp /= 10;
		}

		for (i = length - 1; i >= 0; i--)
		{
			buffer[index++] = tempbuffer[i];
		}
	}

	result = write(1, buffer, index);
	if (result < 0)
		return (-1);

	count += result;
	return (count);
}

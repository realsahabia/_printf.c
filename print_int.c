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

	if (integer == 0)
		buffer[length++] = '0';
	else
	{
		if (integer < 0)
		{
			buffer[length++] = '-';
			integer  = -integer;
		}

		temp = integer;
		while (temp != 0)
		{
			temp /= 10;
			length++;
		}

		index = length - 1;
		while (integer != 0)
		{
			digit = integer % 10;
			buffer[index--] = '0' + digit;
			integer /= 10;
		}
	}

	result = write(1, buffer, length);
	if (result < 0)
		return (-1);

	count += result;
	return (count);
}

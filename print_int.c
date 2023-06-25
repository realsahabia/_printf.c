#include "main.h"
/**
* print_int - function that prints an integer to stdout.
* @args: variadic arguments.
*
* Return: number of characters printed.
*/

int print_int(va_list args)
{
	char buffer[20];
	int integer, count = 0, length, result;

	length = snprintf(buffer, sizeof(buffer), "%d", integer);
	if (length < 0)
		return (-1);

	result = write(1, buffer, length);
	if (result >= 0)
	count += result;

	return (count);
}

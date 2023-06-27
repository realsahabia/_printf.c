#include "main.h"
/**
* print_percent - function that prints a % to stdout.
* @args: variadic arguments.
*
* Return: number of characters printed.
*/
int print_percent(va_list args)
{
	int value;
	int pc;
	int count;

	pc = va_arg(args, int);
	count = 0;

	if (pc)
	{
		value = write(1, "%%", 1);

		count += value;
		return (count);
	}

	return (0);
}

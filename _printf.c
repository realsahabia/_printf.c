#include "main.h"
/**
 * _printf - function that prints a string with specifiers.
 * @format: pointer to a string to be printed.
 *
 * Return: printed string.
 */
int _printf(const char *format, ...)
{
	int i = 0, c_count, count = 0;
	va_list args;
	int (*f)(va_list);

	va_start(args, format);

	if (format == NULL)
		return (-1);
	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			c_count = write(1, &format[i], 1);
			count += c_count;
			i++;
			continue;
		}
		if (format[i] == '%')
		{
			f = check_specifier(&format[i + 1]);
			if (f != NULL)
			{
				c_count = f(args);
				count += c_count;
				i += 2;
				continue;
			}
			if (format[i + 1] == '\0')
				break;
			if (format[i + 1] != '\0')
			{
				c_count = write(1, &format[i], 1);
				count += c_count;
				i++;
				continue;
			}
		}
	}
	va_end(args);
	return (count);
}

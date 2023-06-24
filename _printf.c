#include "main.h"
/**
 * _printf - function that prints a string with specifiers.
 * @format: pointer to a string to be printed.
 *
 * Return: printed string.
 */

int _printf(const char *format, ...)
{
	int i = 0;
	int c_count;
	int count = 0;
	va_list args;

	int (*f)(va_list);

	va_start(args, format);

	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			c_count = write(1, &format[i], 1);
			if (c_count < 0)
				return(-1);

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
				if (c_count < 0)
					return(-1);

				count += c_count;
				i += 2;
				continue;
			}
			if (format[i + 1] == '\0')
				break;
		}
	}

	return (count);
}


int (*check_specifier(const char *specifier))(va_list)
{
        int i;

        //declared an array for struct
        check_sp check_sp[] = {
                                {"c", print_char},
                                {"s", print_string},
                                {"%", print_percent},
                                {NULL, NULL}
        };


        for (i = 0; check_sp[i].sp != NULL; i++)
        {
                if (*(check_sp[i].sp) == *specifier)
                {
                        return (check_sp[i].f);
                }
        }

        return (NULL);
}


int print_char(va_list args)
{
        int value;
        char c;
        int count;

        c = (char) va_arg(args, int);
        count = 0;

        if (c)
        {
                value = write(1, &c, sizeof(char));
                count += value;
                return (count);
        }

        return (0);
}


int print_string(va_list args)
{
        int value;
        int count;
        char *s;

        s = va_arg(args, char *);
        count = 0;

        if (s)
        {
                while (*s != '\0')
                {
                        value = write(1, s, strlen(s));
                        count += value;
			return (count);
		}
        }

        return (0);
}

int print_percent(va_list args)
{
        int value;
        int pc;
        int count;

        pc = va_arg(args, int);
        count = 0;

        if (pc)
        {
                value = write(1, &pc, 1);
                count += value;
                return (count);
        }

        return (0);
}

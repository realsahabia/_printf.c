#include "main.h"
/**
* check_specifier - checks specifier type and assigns
* the appropriate function to print its arguments.
*
* @specifier: the conversion specifier to check for.
*
* Return: pointer to function.
*/

int (*check_specifier(const char *specifier))(va_list)
{
	int i;

	check_sp check_sp_array[] = {
	{"c", print_char},
	{"s", print_string},
	{"%", print_percent},
	{"d", print_int},
	{"i", print_int},
	{"b", print_binary},
	{"u", print_unsigned},
	{"o", print_octal},
	{"x", print_hexa_lower},
	{"X", print_hexa_upper},
	{NULL, NULL}
	};

	if (specifier == NULL)
		return (NULL);

	for (i = 0; check_sp_array[i].sp != NULL; i++)
	{
		if (*(check_sp_array[i].sp) == *specifier)
		{
			return (check_sp_array[i].f);
		}
	}

	return (0);
}

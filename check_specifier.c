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

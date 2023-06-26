#ifndef _MAIN_H_
#define _MAIN_H_

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

/**
 * struct check - a struct that encapsulates specifiers
 * and corresponding functions.
 * @sp: specifier type.
 * @f: function pointer that takes va_list arguments.
 */
	typedef struct check
	{
		char *sp;
		int (*f)(va_list);
	} check_sp;

int _printf(const char *format, ...);
int (*check_specifier(const char *specifier))(va_list);

int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);
int print_int(va_list args);
int print_binary(va_list args);

#endif

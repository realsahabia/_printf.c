#ifndef _MAIN_H_
#define _MAIN_H_

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

typedef struct check
{
	char *sp;
	int *(f)(va_list);
} check_sp;

int _printf(const char *format, ...);
int *(check_specifier(char *specifier))(va_list);

int print_char(va_list args);
int print_string(va_list args);
#endif

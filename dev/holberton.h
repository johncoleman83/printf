#ifndef _HOLBERTON_H_
#define _HOLBERTON_H_
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
/**
 * struct directive_struct - printf directives and helper print functions
 * @ch: the directive
 * @func: pointer to the helper function
 */
typedef struct directive_struct
{
	char ch;
	int (*func)(va_list arg_list);
} directive_t;
int _putchar(char c);
int _printf(const char *format, ...);
int (*get_directive(char c))(va_list);
int p_char(va_list);
int p_string(va_list);
int p_percent(va_list);
int p_int(va_list);
#endif

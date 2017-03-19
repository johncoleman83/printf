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
	int (*func)(char *buffer, va_list arg_list);
} directive_t;
int _putchar(char c);
int _printf(const char *format, ...);
int (*get_directive(char c))(char *, va_list);
void print_buffer(char *, int);
int p_char(char *, va_list);
int p_string(char *, va_list);
int p_percent(char *, va_list);
int p_int(char *, va_list);
#endif

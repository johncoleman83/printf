#ifndef _HOLBERTON_H_ /* begin include guard for header files */
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
/* begin prototypes for helper functions */
void rev_string(char *s);
int skip_spaces(const char *format);
int _putchar(char c);
/* end prototypes for helper functions */
/* begin prototypes for functions that write to the buffer */
int _printf(const char *format, ...);
int (*get_directive(char c))(char *, va_list);
void print_buffer(char *, int);
int p_char(char *, va_list);
int p_string(char *, va_list);
int p_percent(char *, va_list);
int p_int(char *, va_list);
int p_binary(char *, va_list);
/* end prototypes for functions that write to the buffer */
#endif /* end include guard for header files */

#ifndef _HOLBERTON_H_
#define _HOLBERTON_H_
/* begin include guard for header files */
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
/**
 * struct specifier_struct - printf specifiers and paired function
 * @ch: the specifier
 * @func: pointer to the conversion specifier function
 */
typedef struct specifier_struct
{
	char ch;
	int (*func)(va_list arg_list);
} specifiers_t;
/* the one and only */
int _printf(const char *format, ...);
/* begin prototypes for helper functions */
void *_calloc(unsigned int nmemb, unsigned int size);
void rev_string(char *s);
int skip_spaces(const char *format);
int _strlen(char *s);
int _putchar(char c);
int (*match_specifier(char c))(va_list arg_list);
/* end prototypes for helper functions */
/* begin prototypes for functions that write to the buffer */
int p_char(va_list arg_list);
int p_string(va_list arg_list);
int p_string_hex(va_list arg_list);
int p_pointer(va_list arg_list);
int p_rev_string(va_list arg_list);
int p_rot13(va_list arg_list);
int p_percent(va_list arg_list);
int p_int(va_list arg_list);
int p_uint(va_list arg_list);
int p_oct(va_list arg_list);
int p_lowhex(va_list arg_list);
int p_uphex(va_list arg_list);
int p_binary(va_list arg_list);
/* end prototypes for functions that write to the buffer */
#endif /* end include guard for header files */

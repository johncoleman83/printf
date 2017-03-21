#ifndef HOLBERTON_H
#define HOLBERTON_H
#include <stdlib.h>
#include <stdarg.h>
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
int _printf(const char *format, ...);
void *_calloc(unsigned int nmemb, unsigned int size);
void rev_string(char *s);
int _strlen(char *s);
int _putchar(char c);
int (*match_specifier(char c))(va_list arg_list);
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
#endif

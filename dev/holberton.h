#ifndef _HOLBERTON_H_
#define _HOLBERTON_H_
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
/**
 * struct pflag - struct for organizing printf flags and print helper functions
 * @ch: the flag
 * @func: The helper function associated with the flag
 */
typedef struct pflag
{
	char ch;
	void (*func)(va_list valist);
} pflat_t
int _putchar(char c);
int _printf(const char *format, ...);
void (*get_pflag(char c))(va_list);
void p_char(va_list);
void p_string(va_list);
void p_percent(va_list);
#endif

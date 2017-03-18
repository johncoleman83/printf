#ifndef _HOLBERTON_H_
#define _HOLBTERTON_H_
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
/**
 * struct pflag - struct for organizing printf flags and print helper functions
 * @c: the flag
 * @f: The helper function associated with the flag
 */
typedef struct pflag
{
	char ch;
	void (*f)(va_list valist);
} pflat_t
int _putchar(char c);
int _printf(const char *format, ...);
void (*get_pflag(char c))(va_list);
void p_char(va_list);
void p_string(va_list);
void p_percent(va_list);
#endif

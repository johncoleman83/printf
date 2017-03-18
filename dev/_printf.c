#include "holberton.h"
/**
 * _printf - behaves as the C function printf()
 * @format: character string of directives
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list arg_list;
	unsigned int i = 0, sum_chars = 0, skip;
	int (*temp_func)(va_list) = NULL;

	va_start(arg_list, format);
	while (format && format[i])
	{
		skip = 0;
		if (format[i] == '%')
		{
			temp_func = get_directive(format[i + 1]);
			if (temp_func)
			{
				sum_chars += temp_func(arg_list);
				i += 2, skip = 1;
			}
		}
		if (!skip)
		{
			_putchar(format[i++]);
			sum_chars++;
		}
	}
	va_end(arg_list);
	return (sum_chars);
}

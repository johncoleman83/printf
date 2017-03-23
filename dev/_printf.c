#include "holberton.h"
/**
 * _printf - replication of some of the features from C function printf()
 * @format: character string of directives, flags, modifiers, & specifiers
 * Description: This function uses the variable arguments functionality and is
 * supposed to resemble printf().  Please review the README for more
 * information on how it works.
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	unsigned int i = 0, chars_written = 0;
	int (*temp_func)(va_list);
	va_list arg_list;

	va_start(arg_list, format);
	if (!format)
		return (end_func(arg_list));
	while (format[i])
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
			chars_written++;
		}
		else
		{
			temp_func = match_specifier(format[i + 1]);
			if (temp_func)
			{
				chars_written += temp_func(arg_list);
				i++;
			}
			else
			{
				if (i == 0 && format[i + 1] == '\0')
					return (end_func(arg_list));
				_putchar('%');
				chars_written++;
			}
		}
		i++;
	}
	va_end(arg_list);
	return (chars_written);
}

#include "holberton.h"
/**
 * _printf - behaves as the C function printf()
 * @format: character string of directives
 * Description: This function is supposed to resemble printf().  Please review
 * the README for more information on how it works
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list arg_list;
	unsigned int i = 0, chars_written = 0;
	int (*temp_func)(va_list);

	if (!format)
		return (0);

	va_start(arg_list, format);
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
				_putchar('%');
				chars_written++;
			}
		}
		i++;
	}
	va_end(arg_list);
	return (chars_written);
}

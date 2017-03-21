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
	unsigned int i = 0, temp_i, chars_written = 0;
	int (*temp_func)(va_list), no_conversion;

	if (!format)
		return (0);

	va_start(arg_list, format);
	while (format[i])
	{
		no_conversion = 1;
		if (format[i] == '%')
		{
			temp_i = i;
			i += skip_spaces(format + i);
			temp_func = match_specifier(format[i]);
			if (temp_func)
			{
				chars_written += temp_func(arg_list);
				i++, no_conversion = 0;
			}
			else if (format[temp_i + 1] == ' ')
			{
				_putchar('%');
				chars_written++;
				i = temp_i + skip_spaces(format + temp_i) - 1;
			}
			else
				i = temp_i;
		}
		if (no_conversion)
		{
			_putchar(format[i++]);
			chars_written++;
		}
	}
	va_end(arg_list);
	return (chars_written);
}

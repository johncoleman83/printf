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
	char char1, char2;

	va_start(arg_list, format);
	if (!format)
		return (end_func(arg_list));
	while (format[i])
	{
		if (format[i] != '%')
			chars_written += _putchar(format[i]);
		else
		{
			char1 = format[i + 1], char2 = format[i + 2];
			temp_func = is_modifier(char1, char2);
			if (temp_func)
			{
				chars_written += temp_func(arg_list);
				i += 2;
			}
			else
			{
				temp_func = match_specifier(char1);
				if (temp_func)
				{
					chars_written += temp_func(arg_list);
					i++;
				}
				else if (i != 0 && char1 != '\0')
					chars_written += _putchar('%');
				else
					return (end_func(arg_list));
			}
		}
		i++;
	}
	va_end(arg_list);
	return (chars_written);
}

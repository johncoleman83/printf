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
	char *buffer = _calloc(LINE_MAX, sizeof(char));
	unsigned int i = 0, temp_i, chars_processed = 0;
	int (*temp_func)(char *, va_list), no_directive;

	if (!format)
		return (0);

	va_start(arg_list, format);
	while (format[i])
	{
		no_directive = 1;
		if (format[i] == '%')
		{
			temp_i = i;
			i += skip_spaces(format + i);
			temp_func = get_directive(format[i]);
			if (temp_func)
			{
				chars_processed += temp_func(buffer, arg_list);
				i++, no_directive = 0;
			}
			else if (format[temp_i + 1] == ' ')
			{
				chars_processed += add_to_buffer(buffer, '%');
				i = temp_i + skip_spaces(format + temp_i) - 1;
			}
			else
				i = temp_i;
		}
		if (no_directive)
			chars_processed += add_to_buffer(buffer, format[i++]);
	}
	print_buffer(buffer);
	va_end(arg_list);
	return (chars_processed);
}

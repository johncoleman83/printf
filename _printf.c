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
	unsigned int i = 0, temp_i, chars_written = 0;
	int (*temp_func)(char *, va_list), no_conversion;

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
				chars_written += temp_func(buffer, arg_list);
				i++, no_conversion = 0;
			}
			else if (format[temp_i + 1] == ' ')
			{
				chars_written += add_to_buffer(buffer, '%');
				i = temp_i + skip_spaces(format + temp_i) - 1;
			}
			else
				i = temp_i;
		}
		if (no_conversion)
			chars_written += add_to_buffer(buffer, format[i++]);
	}
	print_buffer(buffer);
	free(buffer);
	va_end(arg_list);
	return (chars_written);
}

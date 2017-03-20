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
	char buffer[1024];
	unsigned int i = 0, temp_i, buf_len = 0, no_directive;
	int (*temp_func)(char *, va_list);

	va_start(arg_list, format);
	while (format && format[i])
	{
		no_directive = 1;
		if (format[i] == '%')
		{
			temp_i = i++;
			while (format[i] && format[i] == ' ')
				i++;
			temp_func = get_directive(format[i]);
			if (temp_func)
			{
				buf_len += temp_func(buffer + buf_len, arg_list);
				i++, no_directive = 0;
			}
			else
				i = temp_i;
		}
		if (no_directive)
			buffer[buf_len++] = format[i++];
	}
	print_buffer(buffer, buf_len);
	va_end(arg_list);
	return (buf_len);
}

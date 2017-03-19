#include "holberton.h"
/**
 * _printf - behaves as the C function printf()
 * @format: character string of directives
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list arg_list;
	char buffer[1024];
	unsigned int i = 0, buf_len = 0, skip;
	int (*temp_func)(char *, va_list) = NULL;

	va_start(arg_list, format);
	while (format && format[i])
	{
		skip = 0;
		if (format[i] == '%')
		{
			temp_func = get_directive(format[i + 1]);
			if (temp_func)
			{
				buf_len += temp_func(buffer + buf_len, arg_list);
				i += 2, skip = 1;
			}
		}
		if (!skip)
		{
			buffer[buf_len] = format[i++];
			buf_len++;
		}
	}
	print_buffer(buffer, buf_len);
	va_end(arg_list);
	return (buf_len);
}

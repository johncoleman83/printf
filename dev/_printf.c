#include "holberton.h"
/**
 * _printf - behaves as the C function printf()
 * @format: character string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list valist;
	unsigned int i = 0, sum_chars = 0;
	int (*temp_func)(va_list) = NULL;

	va_start(valist, format);
	while (format && format[i])
	{
		if (format[i] == '%')
		{
			temp_func = get_pflag(format[i + 1]);
			if (temp_func)
			{
				sum_chars += temp_func(valist);
				i += 2;
			}
			else
			{
				_putchar(format[i++]);
				sum_chars++;
			}
		}
		else
		{
			_putchar(format[i++]);
			sum_chars++;
		}
	}
	va_end(valist);
	return (sum_chars);
}

#include "holberton.h"
/**
 * p_uint - writes unsigned integers to buffer or stdout in decimal
 * @arg_list: input list queued at appropriate unsigned int to write to buffer
 * Return: number of wrote to buffer
 */
int p_uint(va_list arg_list)
{
	unsigned long int n = va_arg(arg_list, int), copy, size;
	int nth, chars_written = 0;

	size = 1;
	n = copy;
	if (n < 10)
	{
		_putchar('0' + n);
		return (1);
	}
	while (copy / 10 != 0)
		copy /= 10, size *= 10;
	while (size > 0)
	{
		nth = n / size;
		_putchar('0' + nth);
		n -= nth * size;
		size /= 10;
		chars_written++;
	}
	return (chars_written);
}
/**
 * p_lowhex - writes unsigned integer to buffer or stdout in base hexidecimal
 * @arg_list: input list queued at appropriate int to write to buffer
 * Return: number of chars wrote to buffer
 */
int p_lowhex(va_list arg_list)
{
	unsigned long int n = va_arg(arg_list, int);
	int i, chars_written = 0;
	char *hex = _calloc(9, sizeof(char));
	char hexvalues[] = "0123456789abcdef";

	if (!n)
	{
		_putchar('0');
		return (1);
	}
	for (i = 0; n; i++, n /= 16)
		hex[i] = hexvalues[n % 16];
	for (i--; i >= 0; i--, chars_written++)
		_putchar(hex[i]);
	free(hex);
	return (chars_written);
}
/**
 * p_uphex - writes unsigned integer to buffer in base hexidecimal upcase
 * @arg_list: input list queued at appropriate int to write to buffer
 * Return: number of chars wrote to buffer
 */
int p_uphex(va_list arg_list)
{
	unsigned long int n = va_arg(arg_list, int);
	int i, chars_written = 0;
	char *hex = _calloc(9, sizeof(char));
	char hexvalues[] = "0123456789ABCDEF";

	if (!n)
	{
		_putchar('0');
		return (1);
	}
	for (i = 0; n; i++, n /= 16)
		hex[i] = hexvalues[n % 16];
	for (i--; i >= 0; i--, chars_written++)
		_putchar(hex[i]);
	free(hex);
	return (chars_written);
}
/**
 * p_oct - writes unsigned integer to buffer or stdout in base 8: octal
 * @arg_list: input list queued at appropriate int to write to buffer
 * Return: number of chars wrote to buffer
 */
int p_oct(va_list arg_list)
{
	unsigned long int n = va_arg(arg_list, int);
	int i, chars_written = 0;
	char *oct = _calloc(12, sizeof(char));

	if (!n)
	{
		_putchar('0');
		return (1);
	}
	for (i = 0; n; i++, n /= 8)
		oct[i] = (n % 8 + '0');
	for (i--; i >= 0; i--, chars_written++)
		_putchar(oct[i]);
	free(oct);
	return (chars_written);
}

#include "holberton.h"
/**
 * p_uint - writes unsigned integers to buffer in decimal
 * @buffer: buffer to store chars for printing
 * @arg_list: input list queued at appropriate unsigned int to write to buffer
 * Return: number of wrote to buffer
 */
int p_uint(char *buffer, va_list arg_list)
{
	unsigned int n = va_arg(arg_list, int), nth;
	int size = 1, ones = n % 10, copy, chars_written = 0;

	n /= 10;
	copy = n;
	if (ones < 0)
	{
		ones *= -1, copy *= -1, n *= -1;
		add_to_buffer(buffer, '-');
		chars_written++;
	}
	if (copy > 0)
	{
		while (copy / 10 != 0)
			copy /= 10, size *= 10;
		while (size > 0)
		{
			nth = n / size;
			add_to_buffer(buffer, ('0' + nth));
			n -= nth * size;
			size /= 10;
			chars_written++;
		}
	}
	add_to_buffer(buffer, ('0' + ones));
	return (++chars_written);
}
/**
 * p_hex - writes unsigned integer to buffer in base hexidecimal
 * @buffer: buffer to store chars for printing
 * @arg_list: input list queued at appropriate int to write to buffer
 * Return: number of chars wrote to buffer
 */
int p_lowhex(char *buffer, va_list arg_list)
{
	unsigned int n = va_arg(arg_list, int);
	int i, chars_written = 0;
	char *hex = _calloc(9, sizeof(char));
	char hexvalues[] = "0123456789abcdef";

	for (i = 0; n; i++, n /= 16)
		hex[i] = hexvalues[n % 16];
	if (i == 0)
	{
		add_to_buffer(buffer, '0');
		return (1);
	}
	for (i--; i >= 0; i--, chars_written++)
		add_to_buffer(buffer, hex[i]);
	free(hex);
	return (chars_written);
}
/**
 * p_hex - writes unsigned integer to buffer in base hexidecimal upcase
 * @buffer: buffer to store chars for printing
 * @arg_list: input list queued at appropriate int to write to buffer
 * Return: number of chars wrote to buffer
 */
int p_uphex(char *buffer, va_list arg_list)
{
	unsigned int n = va_arg(arg_list, int);
	int i, chars_written = 0;
	char *hex = _calloc(9, sizeof(char));
	char hexvalues[] = "0123456789ABCDEF";

	for (i = 0; n; i++, n /= 16)
		hex[i] = hexvalues[n % 16];
	if (i == 0)
	{
		add_to_buffer(buffer, '0');
		return (1);
	}
	for (i--; i >= 0; i--, chars_written++)
		add_to_buffer(buffer, hex[i]);
	free(hex);
	return (chars_written);
}
/**
 * p_oct - writes unsigned integer to buffer in base 8: octal
 * @buffer: buffer to store chars for printing
 * @arg_list: input list queued at appropriate int to write to buffer
 * Return: number of chars wrote to buffer
 */
int p_oct(char *buffer, va_list arg_list)
{
	unsigned int n = va_arg(arg_list, int);
	int i, chars_written = 0;
	char *oct = _calloc(12, sizeof(char));

	for (i = 0; n; i++, n /= 8)
		oct[i] = (n % 8 + '0');
	if (i == 0)
	{
		add_to_buffer(buffer, '0');
		return (1);
	}
	for (i--; i >= 0; i--, chars_written++)
		add_to_buffer(buffer, oct[i]);
	free(oct);
	return (chars_written);
}

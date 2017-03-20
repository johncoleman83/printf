#include "holberton.h"
/**
 * p_uint - writes unsigned integers to buffer
 * @buffer: buffer to store chars for printing
 * @arg_list: input list queued at appropriate unsigned int to write to buffer
 * Return: number of wrote to buffer
 */
int p_uint(char *buffer, va_list arg_list)
{
	int n = va_arg(arg_list, int), size = 1, ones = n % 10, copy, nth, digs = 0;

	n /= 10;
	copy = n;
	if (ones < 0)
	{
		ones *= -1, copy *= -1, n *= -1;
		add_to_buffer(buffer, '-');
		digs++;
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
			digs++;
		}
	}
	add_to_buffer(buffer, ('0' + ones));
	return (++digs);
}
/**
 * p_hex - writes unsigned integer to buffer
 * @buffer: buffer to store chars for printing
 * @arg_list: input list queued at appropriate int to write to buffer
 * Return: number of chars wrote to buffer
 */
int p_lowhex(char *buffer, va_list arg_list)
{
	unsigned int n = va_arg(arg_list, int);
	int i, digs = 0;
	char *hex = _calloc(9, sizeof(char));
	char hexvalues[] = "0123456789abcdef";

	for (i = 0; n; i++, n /= 16)
		hex[i] = hexvalues[n % 16];
	if (i == 0)
	{
		add_to_buffer(buffer, '0');
		return (1);
	}
	for (i--, digs = 0; i >= 0; i--, digs++)
		add_to_buffer(buffer, hex[i]);
	free(hex);
	return (digs);
}
/**
 * p_hex - writes unsigned integer to buffer
 * @buffer: buffer to store chars for printing
 * @arg_list: input list queued at appropriate int to write to buffer
 * Return: number of chars wrote to buffer
 */
int p_uphex(char *buffer, va_list arg_list)
{
	unsigned int n = va_arg(arg_list, int);
	int i, digs = 0;
	char *hex = _calloc(9, sizeof(char));
	char hexvalues[] = "0123456789ABCDEF";

	for (i = 0; n; i++, n /= 16)
		hex[i] = hexvalues[n % 16];
	if (i == 0)
	{
		add_to_buffer(buffer, '0');
		return (1);
	}
	for (i--, digs = 0; i >= 0; i--, digs++)
		add_to_buffer(buffer, hex[i]);
	free(hex);
	return (digs);
}
/**
 * p_oct - writes unsigned integer to buffer
 * @buffer: buffer to store chars for printing
 * @arg_list: input list queued at appropriate int to write to buffer
 * Return: number of chars wrote to buffer
 */
int p_oct(char *buffer, va_list arg_list)
{
	unsigned int n = va_arg(arg_list, int);
	int i, digs = 0;
	char *hex = _calloc(9, sizeof(char));
	char hexvalues[] = "0123456789abcdef";

	for (i = 0; n; i++, n /= 16)
		hex[i] = hexvalues[n % 16];
	if (i == 0)
	{
		add_to_buffer(buffer, '0');
		return (1);
	}
	for (i--, digs = 0; i >= 0; i--, digs++)
		add_to_buffer(buffer, hex[i]);
	free(hex);
	return (digs);
}

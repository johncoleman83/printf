#include "holberton.h"
/**
 * p_int - writes integers to buffer
 * @buffer: buffer to store chars for printing
 * @arg_list: input list queued at appropriate integer to write to buffer
 * Return: number of wrote to buffer
 */
int p_int(char *buffer, va_list arg_list)
{
	int n = va_arg(arg_list, int), size = 1, ones = n % 10, copy, nth,
		chars_written = 0;

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
 * p_binary - writes unsigned integer to buffer
 * @buffer: buffer to store chars for printing
 * @arg_list: input list queued at appropriate integer to write to buffer
 * Return: number of chars wrote to buffer
 */
int p_binary(char *buffer, va_list arg_list)
{
	unsigned int n = va_arg(arg_list, int);
	int i, chars_written = 0;
	char *binary = _calloc(33, sizeof(char));

	for (i = 0; n; i++, n /= 2)
		binary[i] = ((n % 2) + '0');
	if (i == 0)
	{
		add_to_buffer(buffer, '0');
		return (1);
	}
	for (i--; i >= 0; i--, chars_written++)
		add_to_buffer(buffer, binary[i]);
	free(binary);
	return (chars_written);
}

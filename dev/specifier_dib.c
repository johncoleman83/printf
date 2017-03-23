#include "holberton.h"
/**
 * p_int - writes integers to buffer
 * @arg_list: input list queued at appropriate integer to write to buffer
 * Return: number of wrote to buffer
 */
int p_int(va_list arg_list)
{
	int n, size, ones, copy, nth, chars_written;
	chars_written = 0;
	n = va_arg(arg_list, int);
	ones = n % 10;
	size = 1;
	n /= 10;
	copy = n;
	if (ones < 0)
	{
		ones *= -1, copy *= -1, n *= -1;
		_putchar('-');
		chars_written++;
	}
	if (copy > 0)
	{
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
	}
	_putchar('0' + ones);
	return (++chars_written);
}
/**
 * p_binary - writes unsigned integer to buffer
 * @arg_list: input list queued at appropriate integer to write to buffer
 * Return: number of chars wrote to buffer
 */
int p_binary(va_list arg_list)
{
	unsigned int n = va_arg(arg_list, unsigned int);
	int i, chars_written = 0;
	char *binary = _calloc(33, sizeof(char));

	for (i = 0; n; i++, n /= 2)
		binary[i] = ((n % 2) + '0');
	if (i == 0)
	{
		_putchar('0');
		return (1);
	}
	for (i--; i >= 0; i--, chars_written++)
		_putchar(binary[i]);
	free(binary);
	return (chars_written);
}

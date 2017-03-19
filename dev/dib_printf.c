#include "holberton.h"
/**
 * p_int - prints integers
 * @buffer: buffer to store chars for printing
 * @arg_list: input list queued at appropriate integer to print
 * Return: number of chars printed
 */
int p_int(char *buffer, va_list arg_list)
{
	int n = va_arg(arg_list, int), size = 1, ones = n % 10, copy, nth, digs = 0;

	n /= 10;
	copy = n;
	if (ones < 0)
	{
		ones *= -1, copy *= -1, n *= -1;
		buffer[digs++] = '-';
	}
	if (copy > 0)
	{
		while (copy / 10 != 0)
			copy /= 10, size *= 10;
		while (size > 0)
		{
			nth = n / size;
			buffer[digs++] = ('0' + nth);
			n -= nth * size;
			size /= 10;
		}
	}
	buffer[digs++] = ('0' + ones);
	return (digs);
}

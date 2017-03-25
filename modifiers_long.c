#include "holberton.h"
/**
 * p_longint - writes long integers to buffer
 * @arg_list: input list queued at appropriate integer to write
 * Return: number of wrote
 */
int p_longint(va_list arg_list)
{
	long int n, size, ones, copy;
	int nth, chars_written;

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
 * p_ulongint - writes unsigned long integers to buffer or stdout in decimal
 * @arg_list: input list queued at appropriate unsigned long int to write
 * Return: number of digits wrote
 */
int p_ulongint(va_list arg_list)
{
	unsigned long int n = va_arg(arg_list, int), copy, size;
	int nth, chars_written = 0;

	size = 1;
	copy = n;
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
 * p_longlowhex - writes unsigned long int in base hexidecimal
 * @arg_list: input list queued at appropriate int to write
 * Return: number of chars wrote
 */
int p_longlowhex(va_list arg_list)
{
	unsigned long int n = va_arg(arg_list, int);
	int i, chars_written = 0;
	char *hex = _calloc(17, sizeof(char));
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
 * p_longuphex - writes unsigned long integer in base hexidecimal upcase
 * @arg_list: input list queued at appropriate int to write
 * Return: number of chars wrote
 */
int p_longuphex(va_list arg_list)
{
	unsigned long int n = va_arg(arg_list, int);
	int i, chars_written = 0;
	char *hex = _calloc(17, sizeof(char));
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
 * p_longoct - writes unsigned long integer to buffer or stdout in base 8
 * @arg_list: input list queued at appropriate int to write
 * Return: number of chars wrote
 */
int p_longoct(va_list arg_list)
{
	unsigned long int n = va_arg(arg_list, int);
	int i, chars_written = 0;
	char *oct = _calloc(23, sizeof(char));

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

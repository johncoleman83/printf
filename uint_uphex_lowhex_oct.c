#include "holberton.h"
/**
 * p_uint - writes unsigned integers to buffer or stdout in decimal
 * @inv: the arguments inventory with most commonly used arguments
 */
void p_uint(inventory_t *inv)
{
	unsigned int n, copy, size;
	int nth;

	n = va_arg(*(inv->args), int);
	size = 1;
	copy = n;
	if (n < 10)
	{
		inv->c0 = ('0' + n);
		write_buffer(inv);
	}
	else
	{
		while (copy / 10 != 0)
			copy /= 10, size *= 10;
		while (size > 0)
		{
			nth = n / size;
			inv->c0 = ('0' + nth);
			write_buffer(inv);
			n -= nth * size;
			size /= 10;
		}
	}
}
/**
 * p_lowhex - writes unsigned integer to buffer in base hexidecimal downcase
 * @inv: the arguments inventory with most commonly used arguments
 */
void p_lowhex(inventory_t *inv)
{
	unsigned int n;
	int i, j;
	char *hex, *copy, *hexvalues;

	hexvalues = "0123456789abcdef";
	n = va_arg(*(inv->args), int);

	if (!n)
	{
		inv->c0 = '0';
		write_buffer(inv);
	}
	else
	{
		hex = _calloc(9, sizeof(char));
		for (i = 0; n; i++, n /= 16)
			hex[i] = hexvalues[n % 16];

		copy = _calloc(i + 1, sizeof(char));
		for (j = 0, i--; i >= 0; j++, i--)
			copy[j] = hex[i];
		puts_buffer(inv, copy);
		free(copy);
		free(hex);
	}
}
/**
 * p_uphex - writes unsigned integer to buffer in base hexidecimal upcase
 * @inv: the arguments inventory with most commonly used arguments
 */
void p_uphex(inventory_t *inv)
{
	unsigned int n;
	int i, j;
	char *hex, *copy, *hexvalues;

	hexvalues = "0123456789ABCDEF";
	hex = _calloc(9, sizeof(char));
	n = va_arg(*(inv->args), int);

	if (!n)
	{
		inv->c0 = '0';
		write_buffer(inv);
	}
	else
	{
		hex = _calloc(9, sizeof(char));
		for (i = 0; n; i++, n /= 16)
			hex[i] = hexvalues[n % 16];

		copy = _calloc(i + 1, sizeof(char));
		for (j = 0, i--; i >= 0; j++, i--)
			copy[j] = hex[i];
		puts_buffer(inv, copy);
		free(copy);
		free(hex);
	}
}
/**
 * p_oct - writes unsigned integer to buffer in base 8: octal
 * @inv: the arguments inventory with most commonly used arguments
 */
void p_oct(inventory_t *inv)
{
	unsigned int n;
	int i;
	char *oct;

	n = va_arg(*(inv->args), int);
	if (!n)
	{
		inv->c0 = '0';
		write_buffer(inv);
	}
	else
	{
		oct = _calloc(12, sizeof(char));
		for (i = 0; n; i++, n /= 8)
			oct[i] = (n % 8 + '0');
		for (i--; i >= 0; i--)
		{
			inv->c0 = oct[i];
			write_buffer(inv);
		}
		free(oct);
	}
}

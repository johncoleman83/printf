#include "holberton.h"
/**
 * p_longint - writes long integers to buffer
 * @inv: the arguments inventory with most commonly used arguments
 */
void p_longint(inventory_t *inv)
{
	long int n, size, ones, copy;
	int nth;

	n = va_arg(*(inv->args), long int);
	ones = n % 10;
	size = 1;
	n /= 10;
	copy = n;
	if (ones < 0)
	{
		ones *= -1, copy *= -1, n *= -1;
		inv->c0 = '-';
		write_buffer(inv);
	}
	if (copy > 0)
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
	inv->c0 = ('0' + ones);
	write_buffer(inv);
}
/**
 * p_ulongint - writes unsigned long integers to buffer or stdout in decimal
 * @inv: the arguments inventory with most commonly used arguments
 */
void p_ulongint(inventory_t *inv)
{
	unsigned long int n, copy, size;
	int nth;

	n = va_arg(*(inv->args), unsigned long int);
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
 * p_longlowhex - writes unsigned long int in base hexidecimal
 * @inv: the arguments inventory with most commonly used arguments
 */
void p_longlowhex(inventory_t *inv)
{
	unsigned long int n;
	int i;
	char *hex, *hexvalues;

	n = va_arg(*(inv->args), unsigned long int);
	hexvalues = "0123456789abcdef";

	if (!n)
	{
		inv->c0 = '0';
		write_buffer(inv);
	}
	else
	{
		hex = _calloc(17, sizeof(char));
		for (i = 0; n; i++, n /= 16)
			hex[i] = hexvalues[n % 16];
		puts_buffer(inv, hex);
		free(hex);
	}
}
/**
 * p_longuphex - writes unsigned long integer in base hexidecimal upcase
 * @inv: the arguments inventory with most commonly used arguments
 */
void p_longuphex(inventory_t *inv)
{
	unsigned long int n;
	int i;
	char *hex, *hexvalues;

	n = va_arg(*(inv->args), unsigned long int);
	hexvalues = "0123456789ABCDEF";

	if (!n)
	{
		inv->c0 = '0';
		write_buffer(inv);
	}
	else
	{
		hex = _calloc(17, sizeof(char));
		for (i = 0; n; i++, n /= 16)
			hex[i] = hexvalues[n % 16];
		puts_buffer(inv, hex);
		free(hex);
	}
}
/**
 * p_longoct - writes unsigned long integer to buffer or stdout in base 8
 * @inv: the arguments inventory with most commonly used arguments
 */
void p_longoct(inventory_t *inv)
{
	unsigned long int n;
	int i;
	char *oct;

	n = va_arg(*(inv->args), unsigned long int);
	if (!n)
	{
		inv->c0 = '0';
		write_buffer(inv);
	}
	else
	{
		oct = _calloc(23, sizeof(char));
		for (i = 0; n; i++, n /= 8)
			oct[i] = (n % 8 + '0');
		puts_buffer(inv, oct);
		free(oct);
	}
}

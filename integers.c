#include "bootcamp.h"

/**
 * print_integers - writes integers to buffer
 * @inv: the arguments inventory with most commonly used arguments
 * @n: integer to be printed, may be type casted to long int.
 */
void print_integers(inventory_t *inv, long int n)
{
	long int size, ones, copy;
	int nth;

	ones = n % 10;
	size = 1;
	n /= 10;
	copy = n;
	if (ones < 0)
	{
		ones *= -1, copy *= -1, n *= -1;
		inv->c0 = '-';
		if (inv->space)
			inv->space = 0, inv->buf_index--;
		write_buffer(inv);
	}
	else if (inv->c1 == '+')
	{
		inv->c0 = '+';
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
 * p_int - writes integers to buffer
 * @inv: the arguments inventory with most commonly used arguments
 */
void p_int(inventory_t *inv)
{
	int n;

	n = va_arg(*(inv->args), int);

	print_integers(inv, (long int)n);
}

/**
 * p_longint - writes long integers to buffer
 * @inv: the arguments inventory with most commonly used arguments
 */
void p_longint(inventory_t *inv)
{
	long int n;

	n = va_arg(*(inv->args), long int);

	print_integers(inv, n);
}

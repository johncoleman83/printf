#include "bootcamp.h"

/**
 * print_unsign - writes unsigned long integers to buffer
 * @inv: the arguments inventory with most commonly used arguments
 * @n: unsigned long int to print (function can be used for shorts as well)
 */
void print_unsign(inventory_t *inv, unsigned long int n)
{
	unsigned long int copy, size;
	int nth;

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
 * p_uint - writes unsigned integers to buffer or stdout in decimal
 * @inv: the arguments inventory with most commonly used arguments
 */
void p_uint(inventory_t *inv)
{
	unsigned int n;

	n = va_arg(*(inv->args), int);

	print_unsign(inv, (unsigned long int)n);
}

/**
 * p_ulongint - writes unsigned long integers to buffer or stdout in decimal
 * @inv: the arguments inventory with most commonly used arguments
 */
void p_ulongint(inventory_t *inv)
{
	unsigned long int n;

	n = va_arg(*(inv->args), unsigned long int);

	print_unsign(inv, n);
}

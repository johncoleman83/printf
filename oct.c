#include "bootcamp.h"

/**
 * print_oct - writes unsigned long integer to buffer or stdout in base 8
 * @inv: the arguments inventory with most commonly used arguments
 * @n: integer to be printed in octal
 * @size: the size to be malloc'd
 */
void print_oct(inventory_t *inv, unsigned long int n, int size)
{
	int i, j;
	char *oct, *copy;

	if (!n)
	{
		inv->c0 = '0';
		write_buffer(inv);
	}
	else
	{
		oct = _calloc(size, sizeof(char));
		if (oct)
		{
			for (i = 0; n; i++, n /= 8)
				oct[i] = (n % 8 + '0');
			copy = _calloc(i + 1, sizeof(char));
			if (copy)
			{
				for (j = 0, i--; i >= 0; j++, i--)
					copy[j] = oct[i];
				if (inv->c1 == '#')
				{
					inv->c0 = '0';
					write_buffer(inv);
				}
				puts_buffer(inv, copy);
				free(copy);
			}
			else
				inv->error = 1;
			free(oct);
		}
		else
			inv->error = 1;
	}
}

/**
 * p_oct - writes unsigned integer to buffer in base 8: octal
 * @inv: the arguments inventory with most commonly used arguments
 */
void p_oct(inventory_t *inv)
{
	unsigned int n;

	n = va_arg(*(inv->args), int);

	print_oct(inv, (unsigned long int)n, 12);
}

/**
 * p_longoct - writes unsigned long integer to buffer or stdout in base 8
 * @inv: the arguments inventory with most commonly used arguments
 */
void p_longoct(inventory_t *inv)
{
	unsigned long int n;

	n = va_arg(*(inv->args), unsigned long int);

	print_oct(inv, n, 23);
}

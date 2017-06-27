#include "holberton.h"

/**
 * print_hex - writes in base hexidecimal
 * @inv: the arguments inventory with most commonly used arguments
 * @n: unsigned long int number to be converted
 * @conv: the conversion string
 * @size: the size to be malloc'd
 */
void print_hex(inventory_t *inv, unsigned long int n, char *conv, int size)
{
	int i;
	char *hex;

	if (!n)
	{
		inv->c0 = '0';
		write_buffer(inv);
	}
	else
	{
		hex = _calloc(size, sizeof(char));
		for (i = 0; n; i++, n /= 16)
			hex[i] = conv[n % 16];
		puts_buffer(inv, hex);
		free(hex);
	}
}

/**
 * p_lowhex - writes unsigned integer to buffer in base hexidecimal downcase
 * @inv: the arguments inventory with most commonly used arguments
 */
void p_lowhex(inventory_t *inv)
{
	unsigned int n;
	char *conv;

	conv = "0123456789abcdef";
	n = va_arg(*(inv->args), int);

	print_hex(inv, (unsigned long int)n, conv, 9);
}

/**
 * p_uphex - writes unsigned integer to buffer in base hexidecimal upcase
 * @inv: the arguments inventory with most commonly used arguments
 */
void p_uphex(inventory_t *inv)
{
	unsigned int n;
	char *conv;

	conv = "0123456789ABCDEF";
	n = va_arg(*(inv->args), int);

	print_hex(inv, (unsigned long int)n, conv, 9);
}

/**
 * p_longlowhex - writes unsigned long int in base hexidecimal
 * @inv: the arguments inventory with most commonly used arguments
 */
void p_longlowhex(inventory_t *inv)
{
	unsigned long int n;
	char *conv;

	n = va_arg(*(inv->args), unsigned long int);
	conv = "0123456789abcdef";

	print_hex(inv, n, conv, 17);
}

/**
 * p_longuphex - writes unsigned long integer in base hexidecimal upcase
 * @inv: the arguments inventory with most commonly used arguments
 */
void p_longuphex(inventory_t *inv)
{
	unsigned long int n;
	char *conv;

	n = va_arg(*(inv->args), unsigned long int);
	conv = "0123456789ABCDEF";

	print_hex(inv, n, conv, 17);
}

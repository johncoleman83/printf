#include "bootcamp.h"

/**
 * print_hex - writes in base hexidecimal
 * @inv: the arguments inventory with most commonly used arguments
 * @n: unsigned long int number to be converted
 * @hexcase: the hexcase either upper or lower
 * @size: the size to be malloc'd
 */
void print_hex(inventory_t *inv, unsigned long int n, int hexcase, int size)
{
	int i, j;
	char *hex = NULL, *copy = NULL;
	const char *conv, *pre;
	static const char * const convset[] = {
		"0123456789abcdef", "0123456789ABCDEF", NULL };
	static const char * const preset[] = { "0x", "0X", NULL };

	conv = convset[hexcase];
	if (!n)
	{
		inv->c0 = '0';
		write_buffer(inv);
	}
	else
	{
		if (inv->c1 == '#')
		{
			pre = preset[hexcase];
			puts_buffer(inv, (char *)pre);
		}
		hex = _calloc(size, sizeof(char));
		if (hex)
		{
			for (i = 0; n; i++, n /= 16)
				hex[i] = conv[n % 16];
			copy = _calloc(i + 1, sizeof(char));
			if (copy)
			{
				for (j = 0, i--; i >= 0; j++, i--)
					copy[j] = hex[i];
				puts_buffer(inv, copy);
				free(copy);
			}
			else
				inv->error = 1;
			free(hex);
		}
		else
			inv->error = 1;
	}
}

/**
 * p_lowhex - writes unsigned integer to buffer in base hexidecimal downcase
 * @inv: the arguments inventory with most commonly used arguments
 */
void p_lowhex(inventory_t *inv)
{
	unsigned int n;

	n = va_arg(*(inv->args), int);

	print_hex(inv, (unsigned long int)n, LOWHEX, 9);
}

/**
 * p_uphex - writes unsigned integer to buffer in base hexidecimal upcase
 * @inv: the arguments inventory with most commonly used arguments
 */
void p_uphex(inventory_t *inv)
{
	unsigned int n;

	n = va_arg(*(inv->args), int);

	print_hex(inv, (unsigned long int)n, UPHEX, 9);
}

/**
 * p_longlowhex - writes unsigned long int in base hexidecimal
 * @inv: the arguments inventory with most commonly used arguments
 */
void p_longlowhex(inventory_t *inv)
{
	unsigned long int n;

	n = va_arg(*(inv->args), unsigned long int);

	print_hex(inv, n, LOWHEX, 17);
}

/**
 * p_longuphex - writes unsigned long integer in base hexidecimal upcase
 * @inv: the arguments inventory with most commonly used arguments
 */
void p_longuphex(inventory_t *inv)
{
	unsigned long int n;

	n = va_arg(*(inv->args), unsigned long int);

	print_hex(inv, n, UPHEX, 17);
}

#include "holberton.h"
/**
 * p_int - writes integers to buffer
 * @inv: the arguments inventory with most commonly used arguments
 */
void p_int(inventory_t *inv)
{
	int n, size, ones, copy, nth;

	n = va_arg(*(inv->args), int);
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
 * p_binary - writes unsigned integer to buffer
 * @inv: the arguments inventory with most commonly used arguments
 */
void p_binary(inventory_t *inv)
{
	unsigned int n = va_arg(*(inv->args), unsigned int);
	int i, j;
	char *binary, *copy;

	binary = _calloc(33, sizeof(char));

	for (i = 0; n; i++, n /= 2)
		binary[i] = ((n % 2) + '0');
	if (i == 0)
	{
		inv->c0 = '0';
		write_buffer(inv);
	}
	else
	{
		copy = _calloc(i + 1, sizeof(char));
		for (j = 0, i--; i >= 0; j++, i--)
			copy[j] = binary[i];

		puts_buffer(inv, copy);
		free(copy);
		free(binary);
	}
}

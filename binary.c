#include "bootcamp.h"

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
	if (binary)
	{
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
			if (copy)
			{
				for (j = 0, i--; i >= 0; j++, i--)
					copy[j] = binary[i];

				puts_buffer(inv, copy);
				free(copy);
			}
			else
				inv->error = 1;
		}
		free(binary);
	}
	else
		inv->error = 1;
}

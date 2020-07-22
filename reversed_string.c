#include "bootcamp.h"
/**
 * p_rev_string - writes string to buffer or stdout in reverse
 * @inv: the arguments inventory with most commonly used arguments
 * Return: number of chars wrote to buffer
 */
void p_rev_string(inventory_t *inv)
{
	int i = 0, j, length;
	char *string, *copy;

	string = va_arg(*(inv->args), char *);

	length = _strlen(string);
	if (length == 1)
	{
		inv->c0 = string[0];
		write_buffer(inv);
	}
	else
	{
		copy = _calloc(length + 1, sizeof(char));
		for (i = length - 1, j = 0; i >= 0; i--, j++)
			copy[j] = string[i];

		puts_buffer(inv, copy);
		free(copy);
	}
}

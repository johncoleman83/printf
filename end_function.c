#include "holberton.h"

/**
 * end_func - terminates _printf() in error cases
 * @inv: the arguments inventory with most commonly used arguments
 * Return: -1 always
 */
int end_func(inventory_t *inv)
{
	int return_value;

	va_end(*(inv->args));

	if (inv->error)
	{
		if (inv->i)
			puts_mod(inv->buffer);
		return_value = -1;
	}
	else
		return_value = inv->buf_index;

	free(inv->buffer);
	free(inv);

	return (return_value);
}

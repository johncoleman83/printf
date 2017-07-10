#include "holberton.h"

/**
 * end_func - terminates _printf() in error cases
 * @inv: the arguments inventory with most commonly used arguments
 * Return: -1 always
 */
int end_func(inventory_t *inv)
{
	int ret_value;

	ret_value = inv->error ? -1 : inv->buf_index;

	if (inv->i)
		puts_mod(inv->buffer);

	va_end(*(inv->args));
	if (inv->buffer)
		free(inv->buffer);
	free(inv);

	return (ret_value);
}

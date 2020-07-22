#include "bootcamp.h"

/**
 * end_func - terminates _printf() in error cases
 * @inv: the arguments inventory with most commonly used arguments
 * Return: -1 always
 */
int end_func(inventory_t *inv)
{
	int ret_value;

	if (inv)
	{
		ret_value = inv->error ? -1 : inv->buf_index;

		if (inv->i)
			puts_mod(inv->buffer, inv->buf_index);

		va_end(*(inv->args));
		if (inv->buffer)
			free(inv->buffer);
		free(inv);
	}
	else
		ret_value = -1;

	return (ret_value);
}

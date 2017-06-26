#include "holberton.h"

/**
 * end_func - terminates _printf() in error cases
 * @inv: the arguments inventory with most commonly used arguments
 * Return: -1 always
 */
int end_func(inventory_t *inv)
{
	unsigned int chars_written;
	int error;

	error = inv->error;
	chars_written = inv->buf_index;
	va_end(*(inv->args));
	free(inv->buffer);
	free(inv);

	if (error)
		return (-1);
	else
		return (chars_written);
}

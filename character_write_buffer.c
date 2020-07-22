#include "bootcamp.h"
/**
 * p_char - writes char to buffer or standard output
 * @inv: the arguments inventory with most commonly used arguments
 * Return: number of chars wrote to buffer
 */
void p_char(inventory_t *inv)
{
	inv->c0 = va_arg(*(inv->args), int);

	write_buffer(inv);
}
/**
 * p_percent - writes a percent symbol to buffer or stdout
 * @inv: the arguments inventory with most commonly used arguments
 * Return: number of chars wrote to buffer
 */
void p_percent(inventory_t *inv)
{
	inv->c0 = '%';

	if (inv->space)
	{
		inv->space = 0;
		inv->buffer[--(inv->buf_index)] = '\0';
	}

	write_buffer(inv);
}

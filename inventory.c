#include "bootcamp.h"

/**
 * build_inventory - builds variables inventory
 * @args_list: variadic arguments list
 * @format: format input string
 * Return: struct of arguments initialized
 */
inventory_t *build_inventory(va_list *args_list, const char *format)
{
	inventory_t *inv;

	inv = malloc(sizeof(inventory_t) * 1);

	if (inv)
	{
		inv->buffer = _calloc(BUFSIZE, sizeof(char));
		inv->buf_index = 0;
		inv->args = args_list;
		inv->fmt = format;
		inv->i = 0;
		inv->flag = 0;
		if (!inv->buffer)
			inv->error = 1;
		else
			inv->error = 0;
	}

	return (inv);
}

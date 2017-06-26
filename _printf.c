#include "holberton.h"

/**
 * build_inventory - builds variables inventory
 * Return: struct of arguments initialized
 */
inventory_t *build_inventory(va_list *args_list, const char *format)
{
	inventory_t *inv;

	inv = malloc(sizeof(inventory_t) * 1);

	inv->buffer = _calloc(BUFSIZE, sizeof(char));
	inv->buf_index = 0;
	inv->args = args_list;
	inv->fmt = format;
	inv->i = 0;
	inv->error = 0;

	return (inv);
}

/**
 * _printf - replication of some of the features from C function printf()
 * @format: character string of directives, flags, modifiers, & specifiers
 * Description: This function uses the variable arguments functionality and is
 * supposed to resemble printf().  Please review the README for more
 * information on how it works.
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args_list;
	inventory_t *inv;
	void (*temp_func)(inventory_t *);

	if (!format)
		return (-1);
	va_start(args_list, format);
	inv = build_inventory(&args_list, format);

	while (format[inv->i])
	{
		inv->c0 = format[inv->i];
		if (inv->c0 != '%')
			write_buffer(inv);
		else
		{
			inv->c1 = format[inv->i + 1], inv->c2 = format[inv->i + 2];
			temp_func = is_modifier(inv);
			if (temp_func)
				temp_func(inv);
			else
			{
				temp_func = match_specifier(inv);
				if (temp_func)
					temp_func(inv);
				else if (inv->c2)
					write_buffer(inv);
				else
				{
					inv->error = 1;
					return (end_func(inv));
				}
			}
		}
		inv->i++;
	}
	puts_mod(inv->buffer);
	return (end_func(inv));
}

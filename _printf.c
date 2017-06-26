#include "holberton.h"

/**
 * build_inventory - builds variables inventory
 * Return: struct of arguments initialized
 */
inventory_t *build_inventory(void)
{
	inventory_t *inv;

	inv = malloc(sizeof(inventory_t) * 1);

	inv->buffer = _calloc(BUFSIZE, sizeof(char));
	inv->buf_index = 0;
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
	int (*temp_func)(inventory_t *);

	if (!format)
		return (-1);
	inv = build_inventory();
	va_start(args_list, format);
	inv->args = &args_list;
	inv->fmt = format;
	while (format[inv->i])
	{
		if (format[inv->i] != '%')
			inv->buf_index += _putchar(format[inv->i]);
		else
		{
			inv->c1 = format[inv->i + 1], inv->c2 = format[inv->i + 2];
			temp_func = is_modifier(inv);
			if (temp_func)
			{
				inv->buf_index += temp_func(inv);
				inv->i += 2;
			}
			else
			{
				temp_func = match_specifier(inv->c1);
				if (temp_func)
				{
					inv->buf_index += temp_func(inv);
					inv->i++;
				}
				else if (_strlenconst(format) != 1)
					inv->buf_index += _putchar('%');
				else
				{
					inv->error = 1;
					return (end_func(inv));
				}
			}
		}
		inv->i++;
	}
	return (end_func(inv));
}

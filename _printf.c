#include "holberton.h"

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

	while (format[inv->i] && !inv->error)
	{
		inv->c0 = format[inv->i];
		if (inv->c0 != '%')
			write_buffer(inv);
		else
		{
			parse_specifiers(inv);
			temp_func = match_specifier(inv);
			if (temp_func)
				temp_func(inv);
			else if (inv->c1)
				write_buffer(inv);
			else
				inv->error = 1;
		}
		inv->i++;
	}
	return (end_func(inv));
}

/**
 * parse_specifiers - parses characters that follow the % character
 * @inv: the arguments inventory
 */
void parse_specifiers(inventory_t *inv)
{
	int j, i, space = 0;
	static const char flags[] = "hl+#";

	i = inv->i + 1;
	while (inv->fmt[i] == ' ')
		i++, inv->i++, space = 1;

	inv->c1 = inv->fmt[i++];

	if (space && inv->c1 != '+')
	{
		space = 0, inv->c0 = ' ';
		write_buffer(inv);
	}
	for (j = 0; flags[j] != '\0'; j++)
	{
		if (inv->c1 == flags[j])
		{
			while (inv->fmt[i] == ' ')
				i++, inv->i++, space = 1;
			if (space && inv->c1 != '+')
			{
				inv->c0 = ' ';
				write_buffer(inv);
			}
			break;
		}
	}

	inv->c2 = inv->c1 ? inv->fmt[i++] : '\0';
	inv->c3 = inv->c2 ? inv->fmt[i] : '\0';
}

#include "bootcamp.h"
/**
 * write_buffer - adds input char to buffer 1 at a time
 * @inv: the arguments inventory with most commonly used arguments
 */
void write_buffer(inventory_t *inv)
{
	unsigned int old, new;
	char *temp;

	if (inv->buffer)
	{
		inv->buffer[inv->buf_index++] = inv->c0;

		if ((inv->buf_index + 1) % BUFSIZE == 0)
		{
			old = inv->buf_index + 1;
			new = old + BUFSIZE;
			temp = _realloc(inv->buffer, old, new);
			if (!temp)
				inv->error = 1;
			else
				inv->buffer = temp;
		}
	}
}

/**
 * puts_buffer - puts string to buffer without newline
 * @inv: the arguments inventory with most commonly used arguments
 * @str: string to print
 */
void puts_buffer(inventory_t *inv, char *str)
{
	int i, l;

	l = _strlen(str);

	for (i = 0; i < l; i++)
	{
		inv->c0 = str[i];
		write_buffer(inv);
	}
}

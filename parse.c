#include "bootcamp.h"
/**
 * parse_specifiers - parses characters that follow the % character
 * @inv: the arguments inventory
 */
void parse_specifiers(inventory_t *inv)
{
	int j, i = inv->i + 1, space = 0;
	static const char flags[] = "hl+#";

	inv->space = 0;
	while (inv->fmt[i] == ' ')
		i++, inv->i++, space = 1;

	inv->c1 = inv->fmt[i++];
	if (space && inv->c1 != '+')
	{
		space = 0, inv->space = 1, inv->c0 = ' ';
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

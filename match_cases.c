#include "holberton.h"
/**
 * match_specifier - matches specifier function for each conversion specifier
 * also handles modifiers of short and long
 * @inv: the arguments inventory with most commonly used arguments
 * Return: pointer to the helper function or NULL
 */
void (*match_specifier(inventory_t *inv))(inventory_t *)
{
	int j, flag = 0, i = 0;
	char check;
	static const char const modifiers[] = "hl+#";
	static matches_t specifiers_list[] = {
		{'d', p_int}, {'i', p_int}, {'x', p_lowhex}, {'X', p_uphex},
		{'o', p_oct}, {'u', p_ulongint}, {'c', p_char}, {'s', p_string},
		{'%', p_percent}, {'b', p_binary}, {'p', p_pointer},
		{'r', p_rev_string}, {'R', p_rot13}, {'S', p_string_hex}, {'\0', NULL}
	};
	static matches_t modifiers_long[] = {
		{'d', p_longint}, {'i', p_longint}, {'x', p_longlowhex},
		{'X', p_longuphex}, {'o', p_longoct}, {'u', p_ulongint}, {'\0', NULL}
	};

	check = inv->c1;
	for (j = 0; modifiers[j] != '\0'; j++)
		if (modifiers[j] == inv->c1)
		{
			flag = 1;
			check = inv->c2;
		}
	while (TRUE)
	{
		if (specifiers_list[i].ch == '\0')
			return (NULL);
		if (specifiers_list[i].ch == check)
		{
			if (flag)
				inv->i += 2;
			else
				inv->i++;
			if (inv->c1 == 'l')
				return (modifiers_long[i].func);
			return (specifiers_list[i].func);
		}
		i++;
	}
}

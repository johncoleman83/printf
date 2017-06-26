#include "holberton.h"
/**
 * match_specifier - matches specifier function for each conversion specifier
 * @c: the specific character specifier from format input string
 * Return: pointer to the helper function or NULL
 */
int (*match_specifier(char c))(inventory_t *)
{
	int i;
	static matches_t specifiers_list[] = {
		{'c', p_char}, {'s', p_string}, {'%', p_percent},
		{'d', p_int}, {'i', p_int}, {'b', p_binary}, {'p', p_pointer},
		{'u', p_uint}, {'o', p_oct}, {'x', p_lowhex}, {'X', p_uphex},
		{'r', p_rev_string}, {'R', p_rot13}, {'S', p_string_hex},
		{'\0', NULL}
	};

	for (i = 0; specifiers_list[i].ch; i++)
		if (specifiers_list[i].ch == c)
			return (specifiers_list[i].func);
	return (NULL);
}
/**
 * is_modifier - matches modifier
 * @inv: the arguments inventory with most commonly used arguments
 * Return: pointer to the helper function or NULL
 */
int (*is_modifier(inventory_t *inv))(inventory_t *)
{
	int i;
	static matches_t modifiers_short[] = {
		{'d', p_int}, {'i', p_int},
		{'x', p_lowhex}, {'X', p_uphex},
		{'o', p_oct}, {'u', p_uint},
		{'\0', NULL}
	};
	static matches_t modifiers_long[] = {
		{'d', p_longint}, {'i', p_longint},
		{'x', p_longlowhex}, {'X', p_longuphex},
		{'o', p_longoct}, {'u', p_ulongint},
		{'\0', NULL}
	};

	switch (inv->c1)
	{
	case 'l':
		for (i = 0; modifiers_long[i].ch; i++)
			if (modifiers_long[i].ch == inv->c2)
				return (modifiers_long[i].func);
		break;
	case 'h':
		for (i = 0; modifiers_short[i].ch; i++)
			if (modifiers_short[i].ch == inv->c2)
				return (modifiers_short[i].func);
		break;
	default:
		break;
	}
	return (NULL);
}

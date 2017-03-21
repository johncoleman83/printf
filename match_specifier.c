#include "holberton.h"
/**
 * match_specifier - matches specifier function for each conversion specifier
 * @c: the specific character specifier from format input string
 * Return: pointer to the helper function or NULL
 */
int (*match_specifier(char c))(va_list)
{
	int i;
	specifiers_t specifiers_list[] = {
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

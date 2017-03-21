#include "holberton.h"
/**
 * get_directive - calls the correct helper function for given directive
 * @c: the specific directive for this case from input string
 * Return: pointer to the helper function or NULL
 */
int (*get_directive(char c))(char *, va_list)
{
	directive_t directives[] = {
		{'c', p_char}, {'s', p_string}, {'%', p_percent},
		{'d', p_int}, {'i', p_int}, {'b', p_binary},
		{'u', p_uint}, {'o', p_oct}, {'x', p_lowhex}, {'X', p_uphex},
		{'r', p_rev_string}, {'R', p_rot13},
		{'\0', NULL}
	};

	for (int i = 0; directives[i].ch; i++)
		if (directives[i].ch == c)
			return (directives[i].func);
	return (NULL);
}

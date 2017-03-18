#include "holberton.h"
/**
 * get_pflag - function that calls the correct helper function for printf flags
 * @c: the flag from input string
 * Return: pointer to the helper function or NULL
 */
void (*get_pflag(char c))(va_list)
{
	pflag_t flags[] = {
		{"c", p_char},
		{"s", p_string},
		{"%", p_percent},
		{NULL, NULL}
	};

	for (int i = 0; flags[i].ch; i++)
		if (flags[i].ch == c)
			return (flags[i].f);
	return (NULL);
}

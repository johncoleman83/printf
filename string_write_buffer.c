#include "bootcamp.h"
/**
 * p_string - writes string to buffer or stdout
 * @inv: the arguments inventory with most commonly used arguments
 * Return: number of chars wrote to buffer
 */
void p_string(inventory_t *inv)
{
	int l;
	char *string, *null_string;

	string = va_arg(*(inv->args), char *);
	null_string = "(null)";

	if (string == NULL)
		string = null_string;

	l = _strlen(string);
	if (l)
		puts_buffer(inv, string);
}

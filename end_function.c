#include "holberton.h"

/**
 * end_func - terminates _printf() in error cases
 * @arg_list: variable arguments list
 * Return: -1 always
 */
int end_func(va_list arg_list)
{
	va_end(arg_list);
	return (-1);
}

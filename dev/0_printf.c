#include "holberton.h"
/**
 * p_char - prints char
 * @arg_list: input list queued at appropriate char to print
 * Return: number of chars printed
 */
int p_char(va_list arg_list)
{
	_putchar(va_arg(arg_list, int));
	return (1);
}
/**
 * p_string - prints sting
 * @arg_list: input list queued at appropriate string to print
 * Return: number of chars printed
 */
int p_string(va_list arg_list)
{
	int i;
	char *str = va_arg(arg_list, char*), *nl_str = "(null)";

	if (str)
	{
		for (i = 0; str[i] != '\0'; i++)
			_putchar(str[i]);
		return (i);
	}
	for (i = 0; i < 6; i++)
		_putchar(nl_str[i]);
	return (6);
}
/**
 * p_percent - prints char
 * @arg_list: void, not used
 * Return: number of chars printed
 */
int p_percent(va_list arg_list)
{
	(void)arg_list;
	_putchar('%');
	return (1);
}

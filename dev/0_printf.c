#include "holberton.h"
/**
 * p_char - prints char
 * @buffer: buffer to store chars
 * @arg_list: input list queued at appropriate char to print
 * Return: number of chars printed
 */
int p_char(char *buffer, va_list arg_list)
{
	*buffer = va_arg(arg_list, int);
	return (1);
}
/**
 * p_string - prints sting
 * @buffer: buffer to store chars
 * @arg_list: input list queued at appropriate string to print
 * Return: number of chars printed
 */
int p_string(char *buffer, va_list arg_list)
{
	int i;
	char *str = va_arg(arg_list, char*), *nl_str = "(null)";

	if (str)
	{
		for (i = 0; str[i] != '\0'; i++)
			buffer[i] = str[i];
		return (i);
	}
	for (i = 0; i < 6; i++)
		buffer[i] = nl_str[i];
	return (6);
}
/**
 * p_percent - prints char
 * @buffer: buffer to store chars
 * @arg_list: void, not used
 * Return: number of chars printed
 */
int p_percent(char *buffer, va_list arg_list)
{
	(void)arg_list;
	buffer[0] = '%';
	return (1);
}

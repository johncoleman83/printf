#include "holberton.h"
/**
 * p_char - writes char to buffer
 * @buffer: buffer to store chars
 * @arg_list: input list queued at appropriate char to write to buffer
 * Return: number of chars wrote to buffer
 */
int p_char(char *buffer, va_list arg_list)
{
	add_to_buffer(buffer, va_arg(arg_list, int));
	return (1);
}
/**
 * p_string - writes string to buffer
 * @buffer: buffer to store chars
 * @arg_list: input list queued at appropriate string to print
 * Return: number of chars wrote to buffer
 */
int p_string(char *buffer, va_list arg_list)
{
	int i;
	char *str = va_arg(arg_list, char*), *nl_str = "(null)";

	if (str)
	{
		for (i = 0; str[i] != '\0'; i++)
			add_to_buffer(buffer, str[i]);
		return (i);
	}
	for (i = 0; i < 6; i++)
		add_to_buffer(buffer, nl_str[i]);
	return (6);
}
/**
 * p_percent - writes a percent symbol to buffer
 * @buffer: buffer to store chars
 * @arg_list: void, not used
 * Return: number of chars wrote to buffer
 */
int p_percent(char *buffer, va_list arg_list)
{
	(void)arg_list;
	add_to_buffer(buffer, '%');
	return (1);
}

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
 * p_percent - writes a percent symbol to buffer
 * @buffer: buffer to store chars
 * @arg_list: void, not used due to having printed a '%'
 * Return: number of chars wrote to buffer
 */
int p_percent(char *buffer, va_list arg_list)
{
	(void)arg_list;
	add_to_buffer(buffer, '%');
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
	char *string = va_arg(arg_list, char *), *null_string = "(null)";

	if (string == NULL)
		string = null_string;
	for (i = 0; string[i] != '\0'; i++)
		add_to_buffer(buffer, string[i]);
	return (i);
}
/**
 * p_rev_string - writes string to buffer in reverse
 * @buffer: buffer to store chars
 * @arg_list: input list queued at appropriate string to print
 * Return: number of chars wrote to buffer
 */
int p_rev_string(char *buffer, va_list arg_list)
{
	int i, length;
	char *str = va_arg(arg_list, char *), *null_str = "(null)";

	if (str == NULL)
		str = null_str;
	length = _strlen(str);
	for (i = length - 1; i >= 0; i--)
		add_to_buffer(buffer, str[i]);
	return (i);
}
/**
 * p_rot13 - translates string to ROT13 and writes to buffer
 * @buffer: buffer to store chars
 * @arg_list: input list queued at appropriate string to print
 * Return: string after conversion of ROT13
 */
int p_rot13(char *buffer, va_list arg_list)
{
	int i, j;
	char alphabet[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char rot_13[] =   "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
	char *str = va_arg(arg_list, char *), *nl_str = "(null)";

	if (str)
	{
		for (i = 0; str[i] != '\0'; i++)
			for (j = 0; j < 52; j++)
				if (str[i] == alphabet[j])
				{
					add_to_buffer(buffer, rot_13[j]);
					j = 52;
				}
		return (i);
	}
	for (i = 0; i < 6; i++)
		add_to_buffer(buffer, nl_str[i]);
	return (6);

}

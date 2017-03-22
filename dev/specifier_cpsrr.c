#include "holberton.h"
/**
 * p_char - writes char to buffer or standard output
 * @arg_list: input list queued at appropriate char to write to buffer
 * Return: number of chars wrote to buffer
 */
int p_char(va_list arg_list)
{
	unsigned int c = va_arg(arg_list, unsigned int);

	_putchar(c);
	return (1);
}
/**
 * p_percent - writes a percent symbol to buffer or stdout
 * @arg_list: void, not used due to having printed a '%'
 * Return: number of chars wrote to buffer
 */
int p_percent(va_list arg_list)
{
	(void)arg_list;

	_putchar('%');
	return (1);
}
/**
 * p_string - writes string to buffer or stdout
 * @arg_list: input list queued at appropriate string to print
 * Return: number of chars wrote to buffer
 */
int p_string(va_list arg_list)
{
	int i;
	char *string = va_arg(arg_list, char *), *null_string = "(null)";

	if (string == NULL)
		string = null_string;
	for (i = 0; string[i] != '\0'; i++)
		_putchar(string[i]);
	return (i);
}
/**
 * p_rev_string - writes string to buffer or stdout in reverse
 * @arg_list: input list queued at appropriate string to print
 * Return: number of chars wrote to buffer
 */
int p_rev_string(va_list arg_list)
{
	int i = 0, length;
	char *string = va_arg(arg_list, char *);

	length = _strlen(string);
	if (length == 1)
	{
		_putchar(string[0]);
		return (1);
	}
	for (i = length - 1; i >= 0; i--)
		_putchar(string[i]);
	return (length);
}
/**
 * p_rot13 - translates string to ROT13 and writes to stdout buffer
 * @arg_list: input list queued at appropriate string to print
 * Return: string after conversion of ROT13
 */
int p_rot13(va_list arg_list)
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
					_putchar(rot_13[j]);
					j = 52;
				}
		return (i);
	}
	for (i = 0; i < 6; i++)
		_putchar(nl_str[i]);
	return (6);

}

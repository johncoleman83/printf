#include "holberton.h"
/**
 * p_char - writes char to buffer or standard output
 * @arg_list: input list queued at appropriate char to write to buffer
 * Return: number of chars wrote to buffer
 */
int p_char(va_list arg_list)
{
	return (_putchar(va_arg(arg_list, int)));
}
/**
 * p_percent - writes a percent symbol to buffer or stdout
 * @arg_list: void, not used due to having printed a '%'
 * Return: number of chars wrote to buffer
 */
int p_percent(va_list arg_list)
{
	(void)arg_list;

	return (_putchar('%'));
}
/**
 * p_string - writes string to buffer or stdout
 * @arg_list: input list queued at appropriate string to print
 * Return: number of chars wrote to buffer
 */
int p_string(va_list arg_list)
{
	char *string = va_arg(arg_list, char *), *null_string = "(null)";

	if (string == NULL)
		string = null_string;
	return (puts_mod(string));
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
	char *str = va_arg(arg_list, char *);

	for (i = 0; str[i] != '\0'; i++)
	{
		for (j = 0; j < 52; j++)
		{
			if (str[i] == alphabet[j])
			{
				_putchar(rot_13[j]);
				break;
			}
		}
		if (j == 52)
			_putchar(str[i]);
	}
	return (i);
}

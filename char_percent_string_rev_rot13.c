#include "holberton.h"
/**
 * p_char - writes char to buffer or standard output
 * @inv: the arguments inventory with most commonly used arguments
 * Return: number of chars wrote to buffer
 */
int p_char(inventory_t *inv)
{
	return (_putchar(va_arg(*(inv->args), int)));
}
/**
 * p_percent - writes a percent symbol to buffer or stdout
 * @inv: the arguments inventory with most commonly used arguments
 * Return: number of chars wrote to buffer
 */
int p_percent(inventory_t *inv)
{
	(void)inv;

	return (_putchar('%'));
}
/**
 * p_string - writes string to buffer or stdout
 * @inv: the arguments inventory with most commonly used arguments
 * Return: number of chars wrote to buffer
 */
int p_string(inventory_t *inv)
{
	char *string = va_arg(*(inv->args), char *), *null_string = "(null)";

	if (string == NULL)
		string = null_string;
	return (puts_mod(string));
}
/**
 * p_rev_string - writes string to buffer or stdout in reverse
 * @inv: the arguments inventory with most commonly used arguments
 * Return: number of chars wrote to buffer
 */
int p_rev_string(inventory_t *inv)
{
	int i = 0, length;
	char *string = va_arg(*(inv->args), char *);

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
 * @inv: the arguments inventory with most commonly used arguments
 * Return: string after conversion of ROT13
 */
int p_rot13(inventory_t *inv)
{
	int i, j;
	char alphabet[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char rot_13[] =   "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
	char *str = va_arg(*(inv->args), char *);

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

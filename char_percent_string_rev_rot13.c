#include "holberton.h"
/**
 * p_char - writes char to buffer or standard output
 * @inv: the arguments inventory with most commonly used arguments
 * Return: number of chars wrote to buffer
 */
void p_char(inventory_t *inv)
{
	inv->c0 = va_arg(*(inv->args), int);

	write_buffer(inv);
}
/**
 * p_percent - writes a percent symbol to buffer or stdout
 * @inv: the arguments inventory with most commonly used arguments
 * Return: number of chars wrote to buffer
 */
void p_percent(inventory_t *inv)
{
	inv->c0 = '%';

	if (inv->space)
	{
		inv->space = 0;
		inv->buffer[--(inv->buf_index)] = '\0';
	}

	write_buffer(inv);
}
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
/**
 * p_rev_string - writes string to buffer or stdout in reverse
 * @inv: the arguments inventory with most commonly used arguments
 * Return: number of chars wrote to buffer
 */
void p_rev_string(inventory_t *inv)
{
	int i = 0, j, length;
	char *string, *copy;

	string = va_arg(*(inv->args), char *);

	length = _strlen(string);
	if (length == 1)
	{
		inv->c0 = string[0];
		write_buffer(inv);
	}
	else
	{
		copy = _calloc(length + 1, sizeof(char));
		for (i = length - 1, j = 0; i >= 0; i--, j++)
			copy[j] = string[i];

		puts_buffer(inv, copy);
		free(copy);
	}
}
/**
 * p_rot13 - translates string to ROT13 and writes to stdout buffer
 * @inv: the arguments inventory with most commonly used arguments
 * Return: string after conversion of ROT13
 */
void p_rot13(inventory_t *inv)
{
	int i, j, l;
	char *alphabet, *rot_13, *str, *copy;

	alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	rot_13 =   "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
	str = va_arg(*(inv->args), char *);
	l = str ? _strlen(str) : 0;

	if (l)
	{
		copy = _calloc(l + 1, sizeof(char));

		for (i = 0; str[i] != '\0'; i++)
		{
			for (j = 0; j < 52; j++)
			{
				if (str[i] == alphabet[j])
				{
					copy[i] = rot_13[j];
					break;
				}
			}
			if (j == 52)
				copy[i] = str[i];
		}

		puts_buffer(inv, copy);
		free(copy);
	}
}

#include "bootcamp.h"
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

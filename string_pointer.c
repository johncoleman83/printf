#include "bootcamp.h"
/**
 * p_string_hex - writes string to buffer or stdout ascii
 * @inv: the arguments inventory with most commonly used arguments
 */
void p_string_hex(inventory_t *inv)
{
	char *string, *temp, *hexvalues, *null_string;
	int c = 0, num;

	hexvalues = "0123456789ABCDEF";
	null_string = "(null)";
	string = va_arg(*(inv->args), char*);

	if (!string)
	{
		string = null_string;
		puts_buffer(inv, null_string);
	}
	else
	{
		temp = _calloc(5, sizeof(char));
		temp[0] = 92;
		temp[1] = 'x';
		while (string[c] != '\0')
		{
			num = string[c];
			if (num > 31 && num < 127)
			{
				inv->c0 = num;
				write_buffer(inv);
			}
			else
			{
				temp[2] = hexvalues[(num / 16) % 16];
				temp[3] = hexvalues[num % 16];
				puts_buffer(inv, temp);
			}
			c++;
		}
		free(temp);
	}
}
/**
 * p_pointer - writes pointer value (an address) to buffer in hexidecimal
 * @inv: the arguments inventory with most commonly used arguments
 */
void p_pointer(inventory_t *inv)
{
	int i, j;
	unsigned long int pointer_value;
	char *hex, *null_string, *hexvalues, *copy;
	void *pointer;

	pointer = va_arg(*(inv->args), void *);
	hexvalues = "0123456789abcdef";
	null_string = "(nil)";

	if (!pointer)
		puts_buffer(inv, null_string);
	else
	{
		hex = _calloc(13, sizeof(char));
		puts_buffer(inv, "0x");
		pointer_value = (unsigned long int)pointer;
		for (i = 0; pointer_value; i++, pointer_value /= 16)
			hex[i] = hexvalues[pointer_value % 16];
		copy = _calloc(i + 1, sizeof(char));
		for (j = 0, i--; i >= 0; j++, i--)
			copy[j] = hex[i];
		puts_buffer(inv, copy);
		free(copy);
		free(hex);
	}
}

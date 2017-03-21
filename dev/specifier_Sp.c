#include "holberton.h"
/**
 * p_string_hex - writes string to buffer switching non-alphas to hexidecimal
 * @buffer: buffer to store chars
 * @arg_list: input list queued at appropriate string to print
 * Return: number of chars wrote to buffer
 */
int p_string_hex(char *buffer, va_list arg_list)
{
	char *string = va_arg(arg_list, char*);
	int i, c = 0, chars_written = 0;
	unsigned int num;
	char *hex = _calloc(9, sizeof(char));
	char hexvalues[] = "0123456789ABCDEF";

	while (string[c] != '\0')
	{
		num = string[c];
		if (num > 31 && num < 127)
			add_to_buffer(buffer, (char)num);
		else
		{
			add_to_buffer(buffer, '\\');
			add_to_buffer(buffer, 'x');
			if (num == 0)
			{
				add_to_buffer(buffer, '0');
				chars_written++;
			}
			for (i = 0; num; i++, num /= 16)
				hex[i] = hexvalues[num % 16];
			for (i--; i >= 0; i--, chars_written++)
				add_to_buffer(buffer, hex[i]);
		}
		c++;
	}
	free(hex);
	return (chars_written);
}
/**
 * p_pointer - writes pointer value (an address) to buffer in hexidecimal
 * @buffer: buffer to store chars
 * @arg_list: input list queued at appropriate string to print
 * Return: number of chars wrote to buffer

int p_pointer(char *buffer, va_list arg_list)
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
*/

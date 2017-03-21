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
	int num;
	char hexvalues[] = "0123456789ABCDEF", *null_string = "(null)";

	if (!string)
		string = null_string;
	while (string[c] != '\0')
	{
		num = string[c];
		if (num > 31 && num < 127)
			add_to_buffer(buffer, num);
		else
		{
			add_to_buffer(buffer, 92);
			add_to_buffer(buffer, 'x');
			add_to_buffer(buffer, hexvalues[(num / 16) % 16]);
			add_to_buffer(buffer, hexvalues[num % 16]);
			chars_written += 3;
		}
		chars_written++;
		c++;
	}
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

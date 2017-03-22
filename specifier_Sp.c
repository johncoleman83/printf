#include "holberton.h"
/**
 * p_string_hex - writes string to buffer or stdout ascii
 * @arg_list: input list queued at appropriate string to print
 * Return: number of chars wrote to buffer
 */
int p_string_hex(va_list arg_list)
{
	char *string = va_arg(arg_list, char*);
	int c = 0, chars_written = 0;
	int num;
	char hexvalues[] = "0123456789ABCDEF", *null_string = "(null)";

	if (!string)
		string = null_string;
	while (string[c] != '\0')
	{
		num = string[c];
		if (num > 31 && num < 127)
			_putchar(num);
		else
		{
			_putchar(92);
			_putchar('x');
			_putchar(hexvalues[(num / 16) % 16]);
			_putchar(hexvalues[num % 16]);
			chars_written += 3;
		}
		chars_written++;
		c++;
	}
	return (chars_written);
}
/**
 * p_pointer - writes pointer value (an address) to buffer in hexidecimal
 * @arg_list: input list queued at appropriate string to print
 * Return: number of chars wrote to buffer
 */
int p_pointer(va_list arg_list)
{
	int i, chars_written = 0;
	void *pointer = va_arg(arg_list, void *);
	unsigned long int pointer_value;
	char *hex = _calloc(13, sizeof(char)), *null_string = "(nil)";
	char hexvalues[] = "0123456789abcdef";

	if (!pointer)
	{
		for (i = 0; null_string[i] != '\0'; i++)
			_putchar(null_string[i]);
		return (i);
	}
	_putchar('0');
	_putchar('x');
	chars_written++;
	pointer_value = (unsigned long int)pointer;
	for (i = 0; pointer_value; i++, pointer_value /= 16)
		hex[i] = hexvalues[pointer_value % 16];
	for (i--; i >= 0; i--, chars_written++)
		_putchar(hex[i]);
	free(hex);
	return (++chars_written);
}

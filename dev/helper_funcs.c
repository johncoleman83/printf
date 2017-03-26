#include "holberton.h"
/**
 * rev_string - reverses string
 * @string: pointer to the input string
 * Return: void
 */
void rev_string(char *string)
{
	int length = 0, c;
	char temp;

	while (string[length] != '\0')
		length++;
	for (c = 0; c < (length / 2); c++)
	{
		temp = string[c];
		string[c] = string[length - c - 1];
		string[length - c - 1] = temp;
	}
}
/**
 * _strlenconst - returns string length of input string
 * @s: string to check length of
 * Return: length of string
 */
int _strlenconst(const char *s)
{
	int len = 0;

	while (s[len] != '\0')
		len++;
	return (len);
}
/**
 * _strlen - returns string length of input string
 * @s: string to check length of
 * Return: length of string
 */
int _strlen(char *s)
{
	int len = 0;

	while (s[len] != '\0')
		len++;
	return (len);
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 * end_func - terminates _printf() in error cases
 * @arg_list: variable arguments list
 * Return: -1 always
 */
int end_func(va_list arg_list)
{
	va_end(arg_list);
	return (-1);
}

#include "holberton.h"
/**
 * rev_string - reverses string
 * @s: pointer to the input string
 * Return: void
 */
void rev_string(char *s)
{
	int length = 0, c, temp;

	while (s[length + 1] != '\0')
		length++;
	for (c = 0; c <= length / 2; c++)
	{
		temp = s[c], s[c] = s[length - c];
		s[length - c] = temp;
	}
}
/**
 * skip_spaces - skips through spaces after '%' directive
 * @format: input pointer to format string
 * Return: new index value corresponding with first non space
 */
int skip_spaces(const char *format)
{
	int i = 1;

	while (format[i] && format[i] == ' ')
		i++;
	return (i);
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

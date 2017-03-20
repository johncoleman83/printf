#include "holberton.h"
/**
 * _calloc - allocates memory for an array using malloc
 * @nmemb: elements of memory needed
 * @size: size in bytes of each element
 * Return: pointer to the allocated memory
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	unsigned int i;
	char *p;

	if (nmemb == 0 || size == 0)
		return (NULL);
	if (size >= UINT_MAX / nmemb || nmemb >= UINT_MAX / size)
		return (NULL);
	p = malloc(size * nmemb);
	if (p == NULL)
		return (NULL);
	for (i = 0; i < nmemb * size; i++)
		p[i] = '\0';
	return ((void *)p);
}
/**
 * rev_string - reverses string
 * @s: pointer to the input string
 * Return: void
 */
void rev_string(char *s)
{
	int length = 0, c, temp;

	while (s[length + 1] != 0)
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
 * _putchar - writes the character c to stdout
 * @c: The character to print
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

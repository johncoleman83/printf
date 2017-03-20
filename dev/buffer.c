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
 * add_to_buffer - adds input char to buffer 1 at a time, and updates buf_length
 * @buffer: buffer
 * @c: char to be added to buffer
 * Return: void
 */
void add_to_buffer(char *buffer, char c)
{
	*buffer = c;
}
/**
 * print_buffer - prints buffer to stdout using putchar
 * @buffer: char pointer to input buffer
 * @size: size of buffer
 * Return: void
 */
void print_buffer(char *buffer)
{
	int i;

	for (i = 0; buffer[i] != '\0'; i++)
		_putchar(buffer[i]);
}

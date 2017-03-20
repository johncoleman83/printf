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
 * Return: buffer length or new buffer length
 */
//void add_to_buffer(char *buffer, int buf_len, char c)
int add_to_buffer(char *buffer, char c)
{
	int i, buf_len = _strlen(buffer);

	if (buf_len > LINE_MAX - 2)
	{
		print_buffer(buffer);
		buffer[0] = c;
		for (i = 1; i < LINE_MAX; i++)
			buffer[i] = '\0';
		return (1);
	}
	*(buffer + buf_len) = c;
	return (1);
}
/**
 * print_buffer - prints buffer to stdout using putchar
 * @buffer: char pointer to input buffer
 * Return: void
 */
void print_buffer(char *buffer)
{
	int i;

	for (i = 0; buffer[i] != '\0'; i++)
		_putchar(buffer[i]);
}

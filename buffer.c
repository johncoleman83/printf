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
 * _realloc - reallocates a memory block using malloc and free
 * @ptr: pointer to reallocate memory
 * @old_size: size in bytes of allocated memory
 * @new_size: newsize of memory block in bytes
 *
 * Return: void pointer to new allocation of memory
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;
	unsigned int i;

	if (ptr == NULL)
	{
		p = _calloc(new_size, sizeof(char));
		return (p);
	}

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	if (old_size == new_size)
		return (ptr);

	p = _calloc(new_size, sizeof(char));
	if (p == NULL)
		return (NULL);

	for (i = 0; i < old_size && i < new_size; i++)
		p[i] = ((char *)ptr)[i];

	free(ptr);

	return (p);
}

/**
 * write_buffer - adds input char to buffer 1 at a time
 * @inv: the arguments inventory with most commonly used arguments
 */
void write_buffer(inventory_t *inv)
{
	inv->buffer[inv->buf_index++] = inv->c0;

	if (inv->buf_index % BUFSIZE == 0)
		_realloc(inv->buffer, inv->buf_index, inv->buf_index + BUFSIZE);
}

/**
 * print_buffer - prints input buffer
 * @buffer: buffer to print
 */
void print_buffer(char *buffer)
{
	int i = 0;

	while (buffer[i] != '\0')
		_putchar(buffer[i++]);
}

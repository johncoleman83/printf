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

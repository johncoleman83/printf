#include "holberton.h"
/**
 * print_buffer - prints buffer to stdout using putchar
 * @buffer: char pointer to input buffer
 * @size: size of buffer
 * Return: void
 */
void print_buffer(char *buffer, int size)
{
	int i;

	for (i = 0; i < size; i++)
		_putchar(buffer[i]);
}

#include "holberton.h"
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

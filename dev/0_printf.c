#include "holberton.h"
/**
 * p_char - prints char
 * @valist: input list queued at appropriate char to print
 * Return: number of chars printed
 */
int p_char(va_list valist)
{
	_putchar(va_arg(valist, int));
	return (1);
}
/**
 * p_string - prints sting
 * @valist: input list queued at appropriate string to print
 * Return: number of chars printed
 */
int p_string(va_list valist)
{
	int i;
	char *str = va_arg(valist, char*);

	for (i = 0; str[i] != '\0'; i++)
		_putchar(str[i]);
	return (i);
}
/**
 * p_percent - prints char
 * @valist: void, not used
 * Return: number of chars printed
 */
int p_percent(va_list valist)
{
	(void)valist;
	_putchar('%');
	return (1);
}

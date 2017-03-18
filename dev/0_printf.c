#include "holberton.h"
/**
 * p_char - prints char
 * @va_list: input list queued at appropriate char to print
 * Return: void
 */
void p_char(va_list valist)
{
	char c = va_arg(valist, char);

	_putchar(c);
}
/**
 * p_string - prints sting
 * @va_list: input list queued at appropriate string to print
 * Return: void
 */
void p_string(va_list valist)
{
	int i;
	char *str = va_arg(valist, char*);

	for (i = 0; str[i] != '\0'; i++)
		_putchar(str[i]);
}
/**
 * p_percent - prints char
 * @va_list: void, not used
 * Return: void
 */
void p_percent(va_list valist)
{
	void(valist);
	_putchar('%');
}

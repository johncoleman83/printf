#include "holberton.h"
#include <stdio.h>
/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int len;
    int len2;
	unsigned int ui = UINT_MAX;
	unsigned long int uli = ULONG_MAX;
	unsigned short int usi = USHRT_MAX;
    void *addr;

    len = _printf("Order, my function first.\n");
    len2 = printf("standard printf() second.\n");
    addr = (void *)0x7ffe637541f0;
    _printf("My Length:[%d, %i]\n", len, len);
    printf("Length:[%d, %i]\n", len2, len2);
    len = _printf("Negative:[%d]\n", -762534);
    len2 = printf("Negative:[%d]\n", -762534);
    _printf("My Length:[%d, %i]\n", len, len);
    printf("Length:[%d, %i]\n", len2, len2);
	printf("NULL check: ");
    _printf(NULL);
	putchar('\n');
    _printf("Unsigned:[%u]\n", ui);
    printf("Unsigned:[%u]\n", ui);
    _printf("Unsigned octal:[%o]\n", ui);
    printf("Unsigned octal:[%o]\n", ui);
    len = _printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    len2 = printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    _printf("My Length:[%d, %i]\n", len, len);
    printf("Length:[%d, %i]\n", len2, len2);
    _printf("Unsigned Short:[%hu]\n", usi);
    printf("Unsigned Short:[%hu]\n", usi);
    _printf("Unsigned octal Short:[%ho]\n", usi);
    printf("Unsigned octal Short:[%ho]\n", usi);
    len = _printf("Unsigned hexadecimal Short:[%hx, %hX]\n", usi, usi);
    len2 = printf("Unsigned hexadecimal Short:[%hx, %hX]\n", usi, usi);
    _printf("My Length:[%d, %i]\n", len, len);
    printf("Length:[%d, %i]\n", len2, len2);
    _printf("Unsigned long:[%lu]\n", uli);
    printf("Unsigned long:[%lu]\n", uli);
    _printf("Unsigned long octal:[%lo]\n", uli);
    printf("Unsigned long octal:[%lo]\n", uli);
    _printf("Unsigned long hexadecimal:[%lx, %lX]\n", uli, uli);
    printf("Unsigned long hexadecimal:[%lx, %lX]\n", uli, uli);
	len = _printf("long max: %ld\n", LONG_MAX);
	len2 = printf("long max: %ld\n", LONG_MAX);
    _printf("My Length:[%d, %i]\n", len, len);
    printf("Length:[%d, %i]\n", len2, len2);
	len = _printf("long min: %ld\n", LONG_MIN);
	len2 = printf("long min: %ld\n", LONG_MIN);
    _printf("My Length:[%d, %i]\n", len, len);
    printf("Length:[%d, %i]\n", len2, len2);
	len = _printf("another test: %hX - %hX = %hX\n", USHRT_MAX, 2048, USHRT_MAX - 2048);
	len2 = printf("another test: %hX - %hX = %hX\n", USHRT_MAX, 2048, USHRT_MAX - 2048);
    _printf("My Length:[%d, %i]\n", len, len);
    printf("Length:[%d, %i]\n", len2, len2);
    _printf("Character:[%c]\n", 'H');
    printf("Character:[%c]\n", 'H');
    len = _printf("String:[%s]\n", "Upward Not Northward !");
    len2 = printf("String:[%s]\n", "Upward Not Northward !");
    _printf("My Length:[%d, %i]\n", len, len);
    printf("Length:[%d, %i]\n", len2, len2);
    len = _printf("Address:[%p]\n", addr);
    len2 = printf("Address:[%p]\n", addr);
    _printf("My Length:[%d, %i]\n", len, len);
    printf("Length:[%d, %i]\n", len2, len2);
	_printf("print '%%hnewline' here:");
    len = _printf("%hy\n");
    _printf("\nLen:[%d]\n", len);
	printf("print '%%hnewline' here:");
    printf("\nLen:[%d]\n", len2);
	_printf("print '%%' here:");
    len = _printf("%");
    _printf("\nLen:[%d]\n", len);
	printf("print '%%' here:");
    printf("\nLen:[%d]\n", len2);
	_printf("*****************\nCUSTOME TO MY _PRINTF\n");
	len = _printf("Reverse, 'hello!' :[%r]\n", "hello!");
	len = _printf("rot13 of 'Holberton': [%R]\n", "Holberton");
	len = _printf("reversed 1 char: [%r]\n", "c");
    _printf("print percent symbol + 'r' with no args: [%%r]\n");
	_printf("print percent symbol + 'd' with no args: [%%d]\n");
    return (0);
}

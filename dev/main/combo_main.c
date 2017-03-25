#include "../holberton.h"
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
    _printf("Length:[%d, %i]\n", len, len);
    printf("Length:[%d, %i]\n", len2, len2);
    _printf("Negative:[%d]\n", -762534);
    printf("Negative:[%d]\n", -762534);
    len = _printf(NULL);
    len2 = printf(NULL);
    _printf("Length:[%d, %i]\n", len, len);
    printf("Length:[%d, %i]\n", len2, len2);
    _printf("Unsigned:[%u]\n", ui);
    printf("Unsigned:[%u]\n", ui);
    _printf("Unsigned octal:[%o]\n", ui);
    printf("Unsigned octal:[%o]\n", ui);
    _printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    _printf("Length:[%d, %i]\n", len, len);
    printf("Length:[%d, %i]\n", len2, len2);
    _printf("Unsigned Short:[%hu]\n", usi);
    printf("Unsigned Short:[%hu]\n", usi);
    _printf("Unsigned octal Short:[%ho]\n", usi);
    printf("Unsigned octal Short:[%ho]\n", usi);
    _printf("Unsigned hexadecimal Short:[%hx, %hX]\n", usi, usi);
    printf("Unsigned hexadecimal Short:[%hx, %hX]\n", usi, usi);
    _printf("Length:[%d, %i]\n", len, len);
    printf("Length:[%d, %i]\n", len2, len2);
    _printf("Unsigned long:[%lu]\n", uli);
    printf("Unsigned long:[%lu]\n", uli);
    _printf("Unsigned long octal:[%lo]\n", uli);
    printf("Unsigned long octal:[%lo]\n", uli);
    _printf("Unsigned long hexadecimal:[%lx, %lX]\n", uli, uli);
    printf("Unsigned long hexadecimal:[%lx, %lX]\n", uli, uli);
    _printf("Character:[%c]\n", 'H');
    printf("Character:[%c]\n", 'H');
    _printf("String:[%s]\n", "I am a string !");
    printf("String:[%s]\n", "I am a string !");
    len = _printf("Address:[%p]\n", addr);
    len2 = printf("Address:[%p]\n", addr);
    _printf("Length:[%d, %i]\n", len, len);
    printf("Length:[%d, %i]\n", len2, len2);
	_printf("print '%%' here:");
    len = _printf("%");
    _printf("\nLen:[%d]\n", len);
	printf("print '%%' here:");
    len2 = printf("%");
    printf("\nLen:[%d]\n", len2);
	len = _printf("Unknown:[%r]\n", "hello!");
    _printf("Length:[%d, %i]\n", len, len);
	len = _printf("rot13[%R]\n", "Holberton");
    _printf("Length:[%d, %i]\n", len, len);
	len = _printf("reversed 1 char[%r]\n", "c");
    _printf("Length:[%d, %i]\n", len, len);
    printf("Unknown:[%%r]\n");
    return (0);
}

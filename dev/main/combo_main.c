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
    unsigned int ui;
    void *addr;

    len = _printf("Let's try to printf a simple sentence.\n");
    len2 = printf("Let's try to printf a simple sentence.\n");
    ui = (unsigned int)INT_MAX + 1024;
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
    _printf("Character:[%c]\n", 'H');
    printf("Character:[%c]\n", 'H');
    _printf("String:[%s]\n", "I am a string !");
    printf("String:[%s]\n", "I am a string !");
    len = _printf("Address:[%p]\n", addr);
    len2 = printf("Address:[%p]\n", addr);
    _printf("Length:[%d, %i]\n", len, len);
    printf("Length:[%d, %i]\n", len2, len2);
    len = _printf("%");
    len2 = printf("%");
    _printf("Len:[%d]\n", len);
    printf("Len:[%d]\n", len2);
	len = _printf("Unknown:[%r]\n", "hello!");
    _printf("Length:[%d, %i]\n", len, len);
	len = _printf("rot13[%R]\n", "Holberton");
    _printf("Length:[%d, %i]\n", len, len);
	len = _printf("reversed 1 char[%r]\n", "c");
    _printf("Length:[%d, %i]\n", len, len);
    printf("Unknown:[%%r]\n");
    return (0);
}

#include "bootcamp.h"
/**
 * main - custom main file to test for my _printf()
 * Return: Always 0
 */
int main(void)
{
	int len;

	len = _printf("Let's try to printf a simple sentence:\n");
	_printf("Len :[%d]\n", len);

	len = _printf("'c': %c char 9999: %c:\n", 'c', 9999);
	_printf("Len :[%d]\n", len);

	len = _printf("'string': %s NULL: %s:\n", "string", NULL);
	_printf("Len :[%d]\n", len);

	len = _printf("percent: 1:%% 5:%%%%%, unknown directive: %y:\n");
	_printf("Len :[%d]\n", len);

	len = _printf("spaces after %%: %     s, spaces with no directive:%        :\n", "string");
	_printf("Len :[%d]\n", len);

	len = _printf("escapes:  :quote:\" quote:'hi' backslash: \\ :\n");
	_printf("Len :[%d]\n", len);

	len = _printf("integer: %d, max:%i, too large %i, char: %d, NULL: %d:\n", 1024, INT_MAX, 999999999999, 'c', NULL);
	_printf("Len :[%d]\n", len);

	len = _printf("hex: %x, max:%x, too large %X, char: %x, NULL: %X:\n", 31, UINT_MAX, 999999999999, 'c', NULL);
	_printf("Len :[%d]\n", len);

	len = _printf("oct: %o, max:%o, too large %o, char: %o, NULL: %o:\n", 31, UINT_MAX, 999999999999, 'c', NULL);
	_printf("Len :[%d]\n", len);

	len = _printf("unsigned: %u, max:%u, too large %u, char: %u, NULL: %u:\n", 4, UINT_MAX, 999999999999, 'c', NULL);
	_printf("Len :[%d]\n", len);

	len = _printf("String_Hex: %S, NULL: %S:\n", "Bootcamp\nSchool\t", NULL);
	_printf("Len :[%d]\n", len);

	len = _printf("pointer: %p, NULL: %p\n", &len, NULL);
	_printf("Len :[%d]\n", len);

	len = _printf("reversed string: %r NULL: %r:\n", "Bootcamp", NULL);
	_printf("Len :[%d]\n", len);

	len = _printf("rot13 string: %R NULL: %R:\n", "Bootcamp", NULL);
	_printf("Len :[%d]\n", len);

	len = _printf("give me binary or give me death: 2: %b, 0: %b, 4294967295: %b, 99999999999999: %b:\n", 2, 0, UINT_MAX, 99999999999999);
	_printf("Len :[%d]\n", len);

	return (0);
}

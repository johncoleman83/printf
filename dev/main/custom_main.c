#include "../holberton.h"
/**
 * main - custom main file to test for my _printf()
 * Return: Always 0
 */
int main(void)
{
    int len;

	len = _printf("Let's try to printf a simple sentence.\n");
	_printf("Len :[%d]\n", len);

	len = _printf("'c': %c char 1024: %c\n", 'c', 1024);
	_printf("Len :[%d]\n", len);

	len = _printf("'string': %s NULL: %s\n", "string", NULL);
	_printf("Len :[%d]\n", len);

	len = _printf("percent: 1:%% 5:%%%%%, unknown directive: %y:\n");
	_printf("Len :[%d]\n", len);

	len = _printf("spaces after %%: %     s, spaces with no directive:%        :\n", "string");
	_printf("Len :[%d]\n", len);

	len = _printf("percent:\%  quote:\" quote:'hi' backslash: \\ \n");
	_printf("Len :[%d]\n", len);

	len = _printf("integer: %d, too large %i, char: %d, NULL: %d\n", 1024, 999999999999, 'c', NULL);
	_printf("Len :[%d]\n", len);

	len = _printf("give me binary or give me death: 2: %b, 0: %b, 4294967295: %b\n", 2, 0, 4294967295);
	_printf("Len :[%d]\n", len);

	return (0);

// (EXPECTED for test case %y) warning: unknown conversion type character ‘y’ in format
}

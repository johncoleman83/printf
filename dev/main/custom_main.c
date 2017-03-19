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

	len = _printf("percent: %% & unknown directive: %y\n");
	_printf("Len :[%d]\n", len);

	len = _printf("integer: %d, too large %i, not int: %d\n", 1024, 999999999999, 'c');
	_printf("Len :[%d]\n", len);

	return (0);

// (EXPECTED for test case %y) warning: unknown conversion type character ‘y’ in format
}

#include "../holberton.h"
/**
 * main - my main file to test for my _printf()
 * Return: Always 0
 */
int main(void)
{
    int len;

	len = _printf("Let's try to printf a simple sentence.\n");
	printf("Len :[%d, %i]\n", len, len);

	len = _printf("'c': %c char 1024: %c\n", 'c', 1024);
	printf("Len :[%d, %i]\n", len, len);

	len = _printf("'string': %s NULL: %s\n", "string", NULL);
	printf("Len :[%d, %i]\n", len, len);

	len = _printf("percent: %% & unknown directive: %y\n");
	printf("Len :[%d, %i]\n", len, len);

	return (0);

// (EXPECTED for test case %y) warning: unknown conversion type character ‘y’ in format
}

#include "../holberton.h"
/**
 * main - Entry point
 * Return: Always 0
 */
int main(void)
{
    int len;

	len = printf("Let's try to printf a simple sentence.\n");
	printf("Len :[%d, %i]\n", len, len);

	len = printf("'c': %c char 1024: %c\n", 'c', 1024);
	printf("Len :[%d, %i]\n", len, len);

	len = printf("'string': %s NULL: %s\n", "string", NULL);
	printf("Len :[%d, %i]\n", len, len);

	len = printf("percent: %% & unknown directive: %y\n");
	printf("Len :[%d, %i]\n", len, len);

	return (0);

// (EXPECTED for test case %y) warning: unknown conversion type character ‘y’ in format
}

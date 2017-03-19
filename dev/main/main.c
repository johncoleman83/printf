#include "../holberton.h"
/**
 * main - main file to test for expected output of printf()
 * Return: Always 0
 */
int main(void)
{
    int len;

	len = printf("Let's try to printf a simple sentence.\n");
	printf("Len :[%d]\n", len);

	len = printf("'c': %c char 1024: %c\n", 'c', 1024);
	printf("Len :[%d]\n", len);

	len = printf("'string': %s NULL: %s\n", "string", NULL);
	printf("Len :[%d]\n", len);

	len = printf("percent: %% & unknown directive: %y\n");
	printf("Len :[%d]\n", len);

	len = printf("integer: %d, too large %i, not int: %d\n", 1024, 999999999999, 'c');
	printf("Len :[%d]\n", len);
	
	return (0);

// (EXPECTED for test case %y) warning: unknown conversion type character ‘y’ in format
}
